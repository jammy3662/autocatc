#ifndef SYMBOL_DOT_H
#define SYMBOL_DOT_H

#include <sstream>
#include <map>

#include "token.hh"
#include "log.hh"

#include "cext/optional.hh"
#include "cext/array.hh"
#include "cext/ints.hh"

namespace CatLang {

struct Scope;

struct Label
{
	Array <char*> names;
	Location location;
};

/*-------------------------------------
 | Refers to a symbol
 | by direct pointer or unresolved path
 |_____________________________________*/
struct Reference
{
	Label path;
	struct Symbol* ptr = 0;
	
	Reference (Label Path)
	{ path = Path; }
	
	Reference (struct Symbol* symbol)
	{ ptr = symbol; }
};

struct Type
{
	enum DataType
	{
		//- Special types -//
		NONE	= -1,
		VOID = 0,
		NUMERIC,
		POINTER,
		ARRAY,
		FUNCTION,
		USER /* tuple, struct, union, or enum */,
		META,
		UNRESOLVED, // type defined elsewhere
	};
	
	DataType data;
	
	unsigned byte
	locality: 1,
	staticness: 1,
	constness: 1;
	
	struct Numeric
	{
		enum Representation
		{ SIGNED, UNSIGNED, REAL, IMAGINARY, COMPLEX };
		unsigned byte representation: 3;
		
		byte is_long: 1;
		
		enum Scalar
		{ BIT, CHAR, BYTE, SHORT, INT, LONG,
			FLOAT, DOUBLE, };
		unsigned byte scalar: 3;
	};
	
	struct Pointer
	{
		Type* pointee;
		bool constness: 1, c_style: 1;
	};
	
	struct Array
	{
		Type* contents;
		struct Expression* count;
	};

	struct Function
	{
		Type* returned;
		Type* parameters;
		Scope* body;
	};
	
	union
	{
		Numeric number;
		Reference user_def;
		Pointer pointer;
		Array array;
		Function function;
		Label path;
	};
};

struct Symbol
{
	enum Kind
	{
		NONE = 0,
		
		VARIABLE,
		EXPRESSION,
		FUNCTION,
		
		SCOPE,
		ITERATOR,
		
		MARKER,
		GOTO,
		CASE,
		DEFAULT,
		INCLUDE,
		CONTINUE,
		BREAK,
		RETURN,
		
		ALIAS,
		MACRO /* symbol with compile parameters (analagous to templates in c++) */,
		TEMPLATE = MACRO,
		
		UNRESOLVED,
	};
	
	fast kind = NONE;
	Location location = {};
	Scope* parent = 0;
	
	Array <Log> logs = {};
	
	char* comment = 0;
	
	struct Qualifiers
	{
		unsigned byte
		is_local: 1, // hidden from outer scopes
		is_static: 1, // only one instance of symbol
		is_extern:	1, // allocate in parent's container, not in parent
		is_inline: 1; // copy definition directly into its scope
	}
	qualifiers = {};
};

struct Expression: Symbol
{
	enum Opcode
	{
		#include "opcode.def"
	};
	
	Type type;
	fast opcode;
	bool constant = false;
};

using Template = Array <Reference>;

struct Scope: Symbol
{
	enum Kind
	{
		STRUCT, MODULE, UNION,
		STACK, ENUM,
		
		IF, SWITCH,
		WHILE, DO_WHILE, FOR
	}
	kind;
	
	Template templates;
	
	Array <Symbol*> members;
	Array <fast> fields; // index into members
	
	std::multimap <std::string, fast>* nametable = {}; // index into members
	
	void insert (Symbol*);
	
	Symbol* find (Label path); // find in this scope or its nested scopes
	Symbol* lookup (Label path); // find in any accessible part of the symbol table
};

struct Iterator: Symbol
{
	Symbol* setup;
	Expression* condition;
	Symbol* proceed;
	
	Reference container;
	
	Iterator (Location, Symbol*, Expression*, Symbol*);
	Iterator (Location, Reference);
};

struct Module: Scope
{
	 opt <Iterator*> iterator;
	 
	 enum Kind { STRUCT, MODULE, UNION };
	 
	 Module (Location, Kind, Scope);
};

struct Conditional: Scope
{
	Expression* condition;
	opt <Scope*> otherwise;
	
	enum Selection { IF = Scope::IF, SWITCH = Scope::SWITCH, WHILE = Scope::WHILE, DO_WHILE = Scope::DO_WHILE };
	
	Conditional (Location, Selection, Expression*, Scope, opt <Scope> = {});
};

struct For: Scope
{
	For (Location, Iterator*, Scope);
};

struct Variable: Symbol
{
	Type type;
	opt <Expression*> initializer;
	bool variadic = false;
};

struct Function: Symbol
{
	Type return_type;
	Scope parameters;
	opt <Scope*> body;
};

struct Include: Symbol, Reference
{
	Include (Location, Reference);
};

struct Alias: Symbol, Reference
{
	Alias (Location, char* name, Reference);
};

struct Marker: Symbol
{
	fast index;
	
	Marker (Location);
	Marker (Location, char* name);
};

struct Case: Symbol
{
	fast index;
	Expression* pattern;
	
	Case (Location, Expression*);
	Case (Location);
};

struct Jump: Symbol
{
	enum Destination { CONTINUE = Symbol::CONTINUE, BREAK = Symbol::BREAK, GOTO = Symbol::GOTO	}
	destination;
	
	Reference marker;
	
	Jump (Location, Destination);
	Jump (Location, Reference);
};

struct Return: Symbol
{
	opt <Expression*> value;
	
	Return (Location, Expression*);
	Return (Location);
};

struct MetaExpression: Expression
{
	enum Kind
	{ SIZEOF, COUNTOF, NAMEOF, STRINGOF }
	kind;
	
	Expression* expression;
};

struct CallExpression: Expression
{
	Reference function;
	opt <Expression*> arguments;
};

struct ReferenceExpression: Expression, Reference
{
	ReferenceExpression (Location, Reference);
};

struct LiteralExpression: Expression
{
	char* constant;
	
	LiteralExpression (Location, char*);
};

struct UnaryOperation: Expression
{
	Expression* operand;
	
	UnaryOperation (Location, Opcode, Expression);
};

struct BinaryOperation: Expression
{
	union
	{
		Expression* operands [2];
		struct {Expression* left, right;};
	};
	
	BinaryOperation (Location, Expression*, Opcode, Expression*);
};

struct ListExpression: Expression
{
	Array <Expression*> expressions;
};

}

#endif
