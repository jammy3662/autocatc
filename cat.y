%{

/* Prologue */

#define YYDEBUG 1

#include "cat.h"

void caterror (const char*);

/* handle end of file */
int yywrap ();

%}

/* Declarations (Bison) */

%define api.prefix {cat}

%glr-parser
%debug

%token '(' ')' '[' ']' '{' '}'
%token '!' '#' '$' '%' '&' '*' '+' ','
%token '-' '.' '/' ':' ';' '<' '>' '='
%token '?' '@' '^' '_' '|' '~'

%token AND /* && */
%token OR /* || */
%token INCREMENT /* ++ */
%token DECREMENT /* -- */
%token SHIFT_L /*	<< */
%token SHIFT_R /* >> */
%token ROTATE_L /* <<< */
%token ROTATE_R /* >>> */
%token COMPARE /* == */
%token INEQUAL /* != */
%token AT_MOST /* <= */
%token AT_LEAST /* >= */

%token TAIL /* .. */
%token ELLIPSES /* ... */

%token CONST_INT
%token CONST_FLOAT
%token CONST_STRING
%token CONST_CHAR

%token COMMENT_LINE
%token COMMENT_BLOCK

%token NAME

%token BIT CHAR BYTE SHORT INT FLOAT

%token INCLUDE INLINE
%token SIZEOF COUNTOF NAMEOF TYPEOF
%token LOCAL STATIC	CONST EXTERN
%token SIGNED	UNSIGNED COMPLEX IMAGINARY LONG DOUBLE
%token BREAK CONTINUE RETURN GOTO
%token STRUCT UNION MODULE ENUM
%token WHILE DO FOR
%token IF	ELSE SWITCH
%token CASE DEFAULT

/* Token Precedence */

%nonassoc EMPTY
%nonassoc NAME

%nonassoc VALUE

%nonassoc ';' ','

%nonassoc CONST_INT CONST_FLOAT CONST_STRING CONST_CHAR
%nonassoc SIZEOF COUNTOF NAMEOF

%right '='

%left OR
%right AND
%left '|'
%left '^'
%left '&'
%nonassoc COMPARE INEQUAL
%nonassoc '<' AT_MOST '>' AT_LEAST
%left SHIFT_L SHIFT_R ROTATE_L ROTATE_R
%left '+' '-'
%left '*' '/' '%'

%left INFIX

/* prefix */
%right '(' '[' '!' '~' PREFIX

/* postfix */
%left ')' ']' POSTFIX INCREMENT DECREMENT

%right '{' ':'

%start block

%%

/* Grammar Rules */

block:

	%empty
|	statements

statements:
	
	statement
|	statements statement

statement:

	error statement
|	line
|	NAME ':'
|	CASE expression colon
|	DEFAULT colon
|	INCLUDE label semicolon
|	CONTINUE semicolon
|	BREAK semicolon
|	GOTO NAME semicolon
|	RETURN expression semicolon
|	RETURN semicolon
|	IF expression scope else-block
|	SWITCH expression scope
|	WHILE expression scope
|	DO WHILE expression scope
|	FOR iterator scope
| declare-namespace

semicolon:
	%empty %prec EMPTY
|	';'

colon:
	%empty %prec EMPTY
|	':'

label:
	NAME members

members:
	%empty
|	members '.' NAME

else-block:
	%empty
|	ELSE scope

iterator:
	'(' iterator ')'
|	line expression ';' line

line:
	braced-scope
|	declare-variables
|	declare-function
|	expressions semicolon
|	';'

scope:
	braced-scope
|	colon block ELLIPSES
|	';'

braced-scope:
	'{' block '}'

enum-scope:
	'{' optional_instances '}'
|	colon optional_instances ELLIPSES
| ';'

optional_instances:
	%empty
|	instances

declare-namespace:
	qualifiers struct-module-union label scope
|	qualifiers ENUM enum-scope

struct-module-union:
	STRUCT
|	MODULE
|	UNION

declare-variables:
	qualifiers variables semicolon

declare-function:
	qualifiers function

qualifiers:
	%empty %prec EMPTY
|	qualifiers qualifier

qualifier:
	LOCAL
|	STATIC
|	EXTERN
|	INLINE

variable:
	type instance

variables:
	type instances

instances:
	instance
|	instances ',' instance

instance:
	label lengths initializer

lengths:
	%empty %prec EMPTY
|	lengths length

length:
	'[' expression ']'

initializer:
	%empty %prec EMPTY
|	'=' expression

function:
	type label tuple scope

tuple:
	'(' parameters-or-none ')'

parameters-or-none:
	%empty %prec EMPTY
|	parameters

parameters:

	variable
|	parameters ',' variable

type:
	type-qualifiers datatype indirection

type-qualifiers:
	%empty
|	type-qualifiers type-qualifier

type-qualifier:

	CONST
|	SIGNED
| UNSIGNED
|	COMPLEX
|	IMAGINARY

indirection:
	%empty
|	indirection pointer

pointer:
	'~' const
|	'*' const

const:
	%empty
|	CONST

datatype:

	basic-type
|	tuple
|	TYPEOF label
|	label

basic-type:
	BIT
|	CHAR
|	BYTE
|	SHORT int
|	longs int
|	INT
|	FLOAT
| long DOUBLE

longs:
	LONG
|	longs LONG

long:
	%empty
|	LONG

int:
	%empty
|	INT

expressions:
	expression %prec ','
|	expressions ',' expression

expression:

	'(' expressions ')'
|	'[' expressions ']'
|	value
|	prefix_operator expression %prec PREFIX
|	expression infix_operator expression %prec INFIX
|	expression postfix_operator %prec POSTFIX
| label expression %prec '('

value:
	
	label %prec NAME
| const_value
| meta_value

const_value:

	CONST_INT
|	CONST_FLOAT
|	CONST_CHAR 
|	CONST_STRING

meta_value:

	SIZEOF label
|	COUNTOF label
|	NAMEOF label


prefix_operator:

	'!'
|	'~'
|	INCREMENT
|	DECREMENT
|	'+'
|	'-'
| '*'
| '&'

postfix_operator:

	INCREMENT %prec POSTFIX
|	DECREMENT %prec POSTFIX

infix_operator:

	AND	|	OR | COMPARE | INEQUAL
|	'<' | AT_MOST | '>' | AT_LEAST
|	arithmetic
| arithmetic '='
| '='

arithmetic:
	'*' | '/' | '%' | '&'
|	'+' | '-' | '^' | '|'
| SHIFT_L | SHIFT_R
| ROTATE_L | ROTATE_R

%%

/* Epilogue */

void caterror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}
