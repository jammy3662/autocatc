#ifndef SYMBOL_DOT_H
#define SYMBOL_DOT_H

#include <sstream>
#include <map>
#include <vector>

#include "token.hh"
#include "log.hh"

#include "ints.hh"

namespace CatLang {

struct Scope;

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
	};
	
	DataType data = NONE;
	
	unsigned byte
	immutability: 1,
	locality: 1,
	staticness: 1,
	constness: 1;
	
	struct Numeric
	{
		enum Representation
		{ SIGNED, UNSIGNED, REAL, IMAGINARY, COMPLEX };
		unsigned byte representation: 3;
		
		unsigned byte isLong: 1;
		
		enum Scalar
		{ BIT, CHAR, BYTE, SHORT, INT, LONG,
			FLOAT, DOUBLE, };
		unsigned byte scalar: 3;
	};
		
	struct User
	{
		Scope* structure;
	};
	
	struct Pointer
	{
		Type* pointee;
		bool constness: 1;
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
		Numeric numeric;
		User user_def;
		Pointer pointer;
		Array array;
		Function function;
	};
};

struct Label
{
	std::vector <char*> names;
};

struct Tag { char* name; };

struct Variable: Tag
{
	Type type;
	Expression* initializer;
};

struct Function: Tag
{
	Type return_type;
	Scope* parameters;
	Scope* body;
};

struct Scope: Tag
{
	enum Kind
	{
		STRUCT,
		MODULE,
		UNION,
		STACK,
		CONDITIONAL,
		ENUM
	};
	
	std::vector <struct Symbol*> members;
	std::vector <Variable> fields; // index into members
	std::multimap <std::string, fast> nametable;// index into members
};

struct Expression
{
	enum Opcode {
		#include "opcode.def"
	};
	
	union Constant
	{
		most int i, Int;
		long double f, Float;
		char* str;
		char c, chr;
	};
	
	
	Opcode opcode;
	bool constant_value = false;
	
	union
	{
		Variable* variable;
		Constant constant;
		Expression* operands [2];
	};
};

struct Symbol
{
	enum Kind
	{
		VARIABLE,
		EXPRESSION,
		FUNCTION,
		
		SCOPE,
		
		MARKER,
		CASE,
		INCLUDE,
		CONTINUE,
		BREAK,
		RETURN,
		
		ALIAS,
		MACRO /* symbol with compile parameters (analagous to templates in c++) */,
		TEMPLATE = MACRO,
		
		UNRESOLVED,
	};
	
	Location location;
	struct Scope* parent;
	
	std::vector <Log> logs;
	
	char* comment;
	
	unsigned byte
	is_local: 1, // hidden from outer scopes
	is_static: 1, // only one instance of symbol
	is_extern:	1; // allocate in parent's container, not in parent
	
	union
	{
		struct { Label name; Symbol* symbol; } Alias;
		struct { fast index; } Marker;
		struct { fast index; struct Expression* expression; } Case;
		struct { Symbol* symbol; } Include;
		struct { struct Expression* value; } Return;
		Scope scope;
		Variable variable;
		Function function;
		Expression expression;
	};
	
	Symbol () {}
};

Symbol* findin (char* name, Symbol* scope); // look for a symbol only within the scope, not its outer scopes
Symbol* lookup (char* name, Symbol* scope);
Symbol* lookup (char* name, Symbol* scope, byte type);

}

#endif
