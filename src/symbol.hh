#ifndef SYMBOL_DOT_H
#define SYMBOL_DOT_H

#include <sstream>
#include <unordered_map>

#include "token.hh"
#include "log.hh"

#include "cext/optional.hh"
#include "cext/array.hh"
#include "cext/ints.hh"

namespace CatLang {

struct Scope;

struct Tag
{
	Location location;
};

struct Label: Tag
{
	Array <char*> names;
};

/*-------------------------------------
 | Refers to a symbol
 | by direct pointer or unresolved path
 |_____________________________________*/
struct Reference: Tag
{
	Label path;
	struct Symbol* ptr = 0;
	
	Reference (Label Path)
	{ path = Path; }
	
	Reference (struct Symbol* symbol)
	{ ptr = symbol; }
};

struct Type: Tag
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
	
	enum Representation
	{ DEFAULT, SIGNED, UNSIGNED, REAL, IMAGINARY, COMPLEX };
	
	DataType data;
	
	unsigned byte
	locality: 1,
	staticness: 1,
	constness: 1,
	representation: 3;
	
	struct Numeric;
	struct Pointer;
	struct Array;
	struct Function;
};

struct Type::Numeric: Type
{
	byte is_long: 1;
	
	enum Scalar
	{ BIT, CHAR, BYTE, SHORT, INT, LONG,
		FLOAT, DOUBLE, };
	unsigned byte scalar: 3;
};

struct Type::Pointer: Type
{
	Type* pointee;
	bool constness: 1, c_style: 1;
};

struct Type::Array: Type
{
	Type* contents;
	struct Expression* count;
};

struct Type::Function: Type
{
	Type* returned;
	Type* parameters;
	Scope* body;
};

using Template = Array <Reference>;

struct Symbol: Tag
{
	enum Kind
	{
		NONE = 0,
		UNRESOLVED,
		
		INCLUDE,
		VARIABLE, EXPRESSION, FUNCTION,
		SCOPE, ITERATOR, OPERATOR,
		MARKER, CASE, DEFAULT,
		GOTO, CONTINUE, BREAK, RETURN,
		
		ALIAS,
		MACRO /* symbol with compile parameters (analagous to templates in c++) */,
		TEMPLATE = MACRO,
	};
	
	Template templates;
	
	fast kind = NONE;
	Scope* parent = 0;
	
	Array <Log> logs;
	
	char* comment = 0;
	
	struct Qualifiers
	{
		unsigned byte
		is_local: 1, // hidden from outer scopes
		is_static: 1, // only one instance of symbol
		is_extern: 1, // allocate in parent's container, not in parent
		is_inline: 1; // copy definition directly into its scope
	}
	qualifiers;
};

struct Expression: Symbol
{
	enum Opcode
	{
		#include "opcode.def"
	};
	
	Type* type;
	fast opcode;
	bool constant = false;
};

struct Iterator;

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
	
	Array <Symbol*>
	members;
	Array <fast>
	fields; // index into members
	
	std::unordered_multimap <std::string, fast>*
	nametable = 0; // index into members by name
	
	// for a given scope, there can only be one definition per operator/opcode
	std::unordered_map <fast, Symbol*>*
	operators;
	
	Iterator*
	iterator;
	
	void insert (Symbol*);
	
	Symbol* find (Label path); // find in this scope or its nested scopes
	Symbol* lookup (Label path); // find in any accessible part of the symbol table
	
	Scope () = default;
	Scope (Location, Scope);
	Scope (Location);
};


struct Iterator: Symbol
{
	struct Loop;
	struct Range;
	struct Custom;
};

struct Iterator::Loop: Iterator
{
	Symbol* init;
	Expression* condition;
	Symbol* on_continue;
	
	Loop (Location, Symbol* init, Expression* condition, Symbol* on_continue);
};

struct Iterator::Range: Iterator
{
	char* name;
	Expression* range;
	
	Range (Location, char* name, Expression* range);
};

struct Iterator::Custom: Iterator
{
	char* name;
	Reference container;
	
	Custom (Location, char* name, Reference);
};

struct Module: Scope
{
	 enum Form { STRUCT, MODULE, UNION };
	 
	 Module (Location, fast, char* name);
	 Module (Location, Module);
};

struct Enum: Scope
{
	Enum (Location);
	Enum (Location, Scope);
	Enum (Location, struct Variable []);
	Enum (Location, char* name, Scope);
};

struct Conditional: Scope
{
	Expression* condition;
	opt <Scope> otherwise;
	
	Conditional (Location, fast, Expression*, Scope, opt <Scope>);
	Conditional (Location, fast, Expression*, Scope);
};

struct For: Scope
{
	For (Location, Iterator*, Scope);
};

struct Instance
{
	opt <Expression*> initializer;
	bool variadic = false;
};

struct Variable: Symbol, Instance
{
	Type* type;
	
	Variable () = default;
	Variable (Location, char* name, Expression* = 0);
	Variable (Location, Variable);
};

struct Function: Symbol
{
	Type* return_type;
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
	
	Jump (Location, fast);
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

struct PairExpression: Expression
{
	PairExpression (Location, Expression*, Expression*);
};

struct CallExpression: Expression
{
	Reference function;
	opt <Expression*> arguments;
	
	
	CallExpression (Location, Reference, Expression*);
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

struct UnaryExpression: Expression
{
	Expression* operand;
	
	UnaryExpression (Location, Opcode, Expression*);
};

struct BinaryExpression: Expression
{
	union
	{
		Expression* operands [2];
		struct {Expression *left, *right;};
	};
	
	BinaryExpression (Location, Expression*, Opcode, Expression*);
};

struct ListExpression: Expression
{
	Array <Expression*> expressions;
	
	ListExpression (Location);
};

}

#endif
