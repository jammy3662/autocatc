#ifndef TOKEN_H
#define TOKEN_H

#include "ints.h"
#include "cat.tab.h"

struct Location
{
	short line = 1, column = 1;
	char* source_file;
};

struct Token
{
	enum {

	// Shortcut: storing symbols like '(' and ';' as their literal values

	PAREN_L = '(', // (
		PAREN = PAREN_L, // ()
	PAREN_R = ')', // )
	BRACKET_L = '[', // [
		BRACKET = BRACKET_L, // []
	BRACKET_R = ']', // ]
	BRACE_L = '{', // {
	BRACE_R = '}', // }

	BANG = '!', // !
	HASH = '#', // #
	USD = '$', DOLLAR = USD, // $
	MOD = '%', // %
	AMP = '&', // &
	STAR = '*', // *
	PLUS = '+', // +
	COMMA = ',', // ,
	MINUS = '-', // -
	DOT = '.', // .
	SLASH = '/', // /
	COLON = ':', // :
	SEMI = ';', // ;
	LEFT = '<', // <
	RIGHT = '>', // >
	EQUAL = '=', // =
	QUESTION = '?', // ?
	AT = '@', // @
	POWER = '^', // ^
	UNDERSCORE = '_', // _
	PIPE = '|', // |
	TILDE = '~', // ~

	x2 = 128,
	x3 = 256,

	AND = AMP + x2, // &&
	OR = PIPE + x2, // ||
	INCREMENT = PLUS + x2, // ++
	DECREMENT = MINUS + x2, // --
	SHIFT_L = LEFT + x2, // <<
	SHIFT_R = RIGHT + x2, // >>
	COMPARE = EQUAL + x2, // ==
	INEQUAL, // !=
	AT_MOST, // <=
	AT_LEAST, // >=

	ROTATE_L = LEFT + x3, // <<<
	ROTATE_R = RIGHT + x3, // >>>

	TAIL, // ..
	ELLIPSES, // ...

	INCLUDE,

	LOCAL,
	STATIC,
	INLINE,
	EXTERN,
	CONST,

	SIZEOF, COUNTOF, NAMEOF, TYPEOF,

	SIGNED, UNSIGNED, COMPLEX, IMAGINARY,

	BIT, CHAR, BYTE, SHORT, INT, FLOAT,
	LONG, DOUBLE,

	BREAK, CONTINUE, RETURN, GOTO,

	IF, ELSE, SWITCH, CASE, DEFAULT,

	DO, WHILE, FOR,

	NAME,

	CONST_INT,
	CONST_FLOAT,
	CONST_CHAR,
	CONST_STR,

	COM_LINE,
	COM_BLOCK,

	END_FILE = EOF,

	};
	
	int kind;
	Location location;
	
	char* text;
	union
	{
		long long int integer;
		long double decimal;
	};
};

extern struct current
{
	bool line_comment = false;
	byte block_comment_depth = 0;
	
	char* comment = 0;
	
	Location location;
	Token token;
}
current;

#endif
