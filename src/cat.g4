grammar cat;

options
{
	language = Cpp;
}

fragment
Q: '\'';
fragment
NQ: ~['];
fragment
QQ: '"';
fragment
NQQ: ~["];
fragment
BS: '\\';

fragment
SPACER: '_' | '`';

fragment
SIGN:   '+' | '-';

fragment
DIGIT:  [0-9] ;

fragment
LETTER: [a-zA-Z];

fragment
NIBBLE: [a-fA-F0-9];

#define SCI ([eE] SIGN DIGIT+)

#define F_SUFFIX [fFlL]
#define I_SUFFIX [uUlL]

#define HEX ( '0'[xX]  (NIBBLE | SPACER)+ )
#define OCT ( '0'[oO]? (DIGIT  | SPACER)+ )
#define BIN ( '0'[bB]  (DIGIT  | SPACER)+ )
#define HOL ( DIGIT (DIGIT | SPACER)+	)

#define DEC \
( \
	(HOL? '.' HOL)  \
| (HOL  '.' HOL?) \
)

INT_CONST: SIGN? (HEX | OCT | BIN | HOL) I_SUFFIX?;

FLOAT_CONST: SIGN? DEC SCI? F_SUFFIX?;

CHAR_CONST:  'L'?  Q (BS  Q |  NQ)*  Q;

STR_CONST:   'L'? QQ (BS QQ | NQQ)* QQ;


NAME: (LETTER | SPACER) (LETTER | DIGIT | SPACER)*;

start: EOF;
