#ifndef TOKEN_H
#define TOKEN_H

#include <vector>
#include <sstream>

#include "ints.h"

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

	AMPx2 = AMP + x2, // &&
	PIPEx2 = PIPE + x2, // ||
	PLUSx2 = PLUS + x2, // ++
	MINUSx2 = MINUS + x2, // --
	LEFTx2 = LEFT + x2, // <<
	RIGHTx2 = RIGHT + x2, // >>
	EQUALx2 = EQUAL + x2, // ==

	LEFTx3 = LEFT + x3, // <<<
	RIGHTx3 = RIGHT + x3, // >>>

	TAIL, // ..
	ELLIPSES, // ...

	ARROW, // -> (legacy / c)

	NAME,

	INT_CONST,
	FLOAT_CONST,
	CHAR_CONST,
	STR_CONST,

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
