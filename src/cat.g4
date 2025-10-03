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

#define SCI ([eE] SIGN DIGIT*)

#define F_SUFFIX [fFlL]
#define I_SUFFIX [uUlL]

#define HEX ( '0'[xX]  (NIBBLE | SPACER)+ )
#define OCT ( '0'[oO]? (DIGIT  | SPACER)+ )
#define BIN ( '0'[bB]  (DIGIT  | SPACER)+ )
#define HOL ( DIGIT (DIGIT | SPACER)*	)

#define DEC \
( \
	(HOL? '.' HOL)  \
|	(HOL  '.' HOL?) \
)

INT_CONST:   SIGN? (HEX | OCT | BIN | HOL) I_SUFFIX?;

FLOAT_CONST: SIGN? DEC SCI? F_SUFFIX?;

CHAR_CONST:  'L'?  Q (BS  Q |  NQ)*  Q;

STR_CONST:   'L'? QQ (BS QQ | NQQ)* QQ;

NAME: (LETTER | SPACER) (LETTER | DIGIT | SPACER)*;

LINE_COMMENT: '//' ~[\r\n]* -> channel (HIDDEN);

BLOCK_COMMENT: '/*' .*? '*/' -> channel (HIDDEN);

L_PAREN: '(';

WHITESPACE: [ \t\\r\n] -> skip;

CHAR: . -> skip;

// .*? means on error, abort and start new statement
block: (statement .*?)*;

statement:

	NAME ':'
|	'case' (expression | range_expression) ':'?
|	'default' ':'?
|	'continue' ';'?
|	'break' ';'?
|	'goto' NAME ';'?
|	'return' expression? ';'?
|	'if' expression scope ('else' scope)?
|	'switch' expression scope
|	'while' expression scope
|	'do' 'while' expression scope
|	'do' scope 'while' expression ';'?
|	'for' iterator scope
|	'iterator' iterator_define ';'?
|	'operator' definable_operator tuple scope
|	line
;

line:

	note line
|	'alias' NAME '=' label ';'?
|	'macro' NAME  .*? '#'
|	'include' label ('as' NAME)? ';'?
|	generics? qualifier* module (instances ';'?)?
|	generics? qualifier* function
|	qualifier* variables ';'?
|	expression ';'?
|	stack_frame
|	';'
;

note: 'note' STR_CONST+;

stack_frame: qualifier* braced_scope;

module:

	('struct' | 'union' | 'module') label scope
|	'enum' label enum_scope
;

scope:

	braced_scope
|	':'? block ('...' | EOF)
|	braced_scope block ('...' | EOF )
;

braced_scope: '{' block '}';

enum_scope:

	'{'  instances? '}'
|	':'? instances? ('...' | EOF)
;

generics: '[' label+ ']';

iterator:

	'(' iterator ')'
|	loop_iterator
|	label ':' range_expression
|	label ':' expression
;

iterator_define:

	'(' iterator_define ')'
|	loop_iterator
|	range_expression
|	expression
;

loop_iterator: line expression ';' line;

label: '.'? NAME ('.' NAME)*;

variable: type instance;

variables:

	// prevent parsing functions as variables
	{_input->LA (1) != catParser::L_PAREN}?
	type instances;

instances: instance (',' instance)*;

instance: label dimensionality (initializer | '..')?;

dimensionality: ('[' expression ']')*;

initializer: '=' expression;

function: type label tuple scope;

tuple: '(' parameters? ')';

parameters: variable (',' variable)*;

type:

	type_qualifier* datatype pointer*
|	type tuple pointer
;

datatype:

	'let'
|	builtin
|	tuple
|	'typeof' label
|	label
;

expression:

	atomic
|	prefix expression
|	expression infix expression
|	expression postfix
|	expression ',' expression
|	expression expression
;

atomic:

	'(' expression? ')'
|	'[' expression? ']'
|	value
;

value:

	label
|	literal
|	meta label
;

literal: INT_CONST | FLOAT_CONST | CHAR_CONST | STR_CONST;

range_expression: expression '..' expression;

pointer:

	'~' 'const'? // cat-style pointer
|	'*' 'const'? // c-style pointer
|	'!' 'const'? // c++ reference-style pointer (const keyword is extraneous, it will always be const)
;

builtin:

	'bit'
|	'char'
|	'byte'
|	'short' 'int'?
|	'long'+ 'int'?
|	'int'
|	'float'
|	'long'+ 'double'
;

qualifier: 'local' | 'static' | 'extern' | 'inline';

type_qualifier: 'const' | 'signed' | 'unsigned' | 'complex' | 'imaginary';

meta: 'sizeof' | 'countof' | 'nameof' | 'stringof';

prefix:

	'++'
|	'--'
|	'+'
|	'-'
|	'!'
|	'&'
|	'*'
|	'~'
;

postfix: '++' | '--';

infix:

	('and' | '&&')
|	( 'or' | '||')
	
|	'==' | '!='
	
|	'<' | '<=' | '>=' | '>'
	
|	arithmetic
|	arithmetic '='
|	'='
;

arithmetic:

	  '+' |  '-'
|	  '*' |  '/' | '%'
|	  '&' |  '^' | '|'
|	 '<<' | '>>'
|	'<<<' | '>>>'
;

definable_operator:

	'++' | '--' |   '+' |   '-' | '%'
|	 '&' |  '*' |   '~' |   '/'
|	'<<' | '>>' | '<<<' | '>>>'
;
