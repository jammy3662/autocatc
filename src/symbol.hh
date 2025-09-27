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
	
	inline
	char* name () {	return names.last(); } 
	
	Label () = default;
	Label (Location);
	Label (Location, char* first);
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
	fast longness = 0;
	
	enum Scalar
	{ BIT, CHAR, BYTE, SHORT, INT, LONG,
		FLOAT, DOUBLE, };
	unsigned byte scalar: 3;
	
	Numeric (Location, fast scalar, fast longness = 0);
};

struct Type::Pointer: Type
{
	Type* underlying_type;
	
	fast num_pointers = 0;
	
	struct Indirection
	{ char constness: 1, c_style: 1; }
	indirection [8];
	
	Pointer (Location, Type*, ::Array <Indirection>);
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

struct Template: Array<Reference>, Tag {};

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
struct Operator;

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
	nametable = new std::unordered_multimap <std::string, fast>; // index into members by name
	
	// for a given scope, there can only be one definition per operator/opcode
	std::unordered_map <fast, Operator*>*
	operators = new std::unordered_map <fast, Operator*>;
	
	Iterator*
	iterator;
	
	int insert (Symbol*); // returns index of insert within parent
	
	Symbol* find (Label path); // find in this scope or its nested scopes
	Symbol* lookup (Label path); // find in any accessible part of the symbol table
	
	Scope () = default;
	Scope (Location, Scope);
	Scope (Location);
};

fast thing;

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
	Expression* range;
	char* instance_name;
	
	Range (Location, char* name, Expression* range);
	Range (Location, Expression* range);
};

struct Iterator::Custom: Iterator
{
	Reference container;
	char* instance_name;
	
	Custom (Location, char* name, Reference);
	Custom (Location, Reference);
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
	Enum (Array <Variable>);
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
	Iterator* iterator;
	
	For (Location, Iterator*, Scope);
};

struct Instance
{
	Array <Expression*> dimensionality;
	opt <Expression*> initializer;
	bool variadic = false;
};

struct Variable: Symbol, Instance
{
	Type* type;
	
	Variable () = default;
	Variable (Location, char* name, Array <Expression*> dimensionality, Expression* initializer = 0);
	Variable (Location, char* name, Expression* initializer = 0);
	Variable (Location, Variable);
};

struct Function: Symbol
{
	Type* return_type;
	Scope parameters;
	opt <Scope*> body;
	
	Function (Location, Function);
	Function (Location, Type*, Reference path, Scope parameters);
	Function (Location, Type*, Reference path, Scope parameters, Scope body);
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
	
	MetaExpression (Location, fast kind, Expression*);
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
