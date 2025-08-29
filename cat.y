%{

/* Prologue */

#define YYDEBUG 1

#include "scanner.h"

void yyerror (const char*);

/* handle end of file */
int yywrap ();

%}

/* Declarations (Bison) */

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

/* infix */
%left '='
%left OR
%right AND
%left '|'
%left '^'
%left '&'
%nonassoc COMPARE INEQUAL
%nonassoc '<' AT_MOST '>' AT_LEAST
%left SHIFT_L SHIFT_R
%left '+' '-'
%left '*' '/' '%'

/* postfix */
%left ')' ']' INCREMENT_POST DECREMENT_POST

/* prefix */
%right '(' '[' INCREMENT_PRE DECREMENT_PRE POSITIVE NEGATIVE '!' '~' DEREFERENCE ADDRESS

%right '{' ':'

%start block

%%

/* Grammar Rules */

block:

	lines
|	%empty  %prec EMPTY

lines:
	
	lines line
|	line

line:

	note statement
|	statement

note:
	
	note comment
|	comment

comment:

	COMMENT_LINE
|	COMMENT_BLOCK

label:

	label '.'	NAME
|	NAME

statement:

	error statement
|	NAME ':'
|	CASE expression ':'
|	DEFAULT ':'
|	INCLUDE label end
|	CONTINUE end
|	BREAK end
|	GOTO NAME end
|	RETURN expression end
|	IF expression scope
|	SWITCH expression scope
|	WHILE expression scope
|	DO WHILE expression scope
|	FOR line expression line scope
|	declaration
|	expressions
|	'{' block '}'

scope:
	
	braced_scope
|	implicit_scope

braced_scope:

	'{' block '}'

implicit_scope:
	
	following block ELLIPSES

following:
	':'
|	%empty  %prec EMPTY

end:
	';'
|	%empty  %prec EMPTY

declaration:
	
	qualifiers STRUCT label scope
|	qualifiers MODULE label scope
|	qualifiers UNION label scope
|	qualifiers ENUM label '{' variables '}'
|	qualifiers ENUM label following variables ELLIPSES
|	qualifiers ENUM label following variables ';'
|	qualifiers variables end
|	function

qualifiers:
	
	qualifiers qualifier
|	qualifier  %prec NAME
| %empty  %prec EMPTY

qualifier:
	
	LOCAL | STATIC |
	EXTERN | INLINE

parameters:
	
	variables ',' variable
|	variable

variable:
	
	type instance

variables:
	
	type instances %prec NAME

instances:

	instances ',' instance
|	instance  %prec EMPTY

instance:
	
	label lengths initializer

lengths:

	lengths length
|	length
|	%empty  %prec EMPTY 

length:

	'[' expression ']'

initializer:

	'=' expression
|	%empty  %prec EMPTY

function:
	
	type label tuple ';'
|	type label tuple scope

tuple:
	
	'(' parameters ')'

type:
	
	type_qualifiers datatype pointers

type_qualifiers:
	
	type_qualifiers type_qualifier
|	type_qualifier
|	%empty  %prec EMPTY

type_qualifier:
	
	CONST
|	SIGNED
|	UNSIGNED
|	COMPLEX
|	IMAGINARY

datatype:
	
	basic_type
|	tuple
|	TYPEOF label

basic_type:
	
	BIT |	CHAR | BYTE  | SHORT |
	INT | LONG | FLOAT | DOUBLE

pointers:
	
	pointers pointer
|	pointer
| %empty  %prec EMPTY

pointer:
	
	cat_pointer | c_pointer

cat_pointer:

	'~' CONST
|	'~'

c_pointer:
	
	'*' CONST
|	'*'

expressions:
	
	expressions ',' expression
|	expression

expression:
	
	operation
|	value  %prec VALUE

value:
	
	object_value
| const_value
| meta_value
| '(' expression ')'
|	'[' expression ']'

const_value:

	CONST_INT
|	CONST_FLOAT
|	CONST_CHAR 
|	CONST_STRING

object_value: EMPTY {}
	
	label

meta_value:

	SIZEOF label
|	COUNTOF label
|	NAMEOF label

operation:	
	prefix_operation
|	infix_operation
|	postfix_operation

prefix_operation:
	prefix_operator value

prefix_operator:

	'!'
|	'~'
|	INCREMENT  %prec INCREMENT_PRE
|	DECREMENT  %prec DECREMENT_PRE
|	'+'  %prec POSITIVE
|	'-'  %prec NEGATIVE
| '*'  %prec DEREFERENCE
| '&'  %prec ADDRESS

postfix_operation:
	value postfix_operator

postfix_operator:

	INCREMENT  %prec INCREMENT_POST
|	DECREMENT  %prec DECREMENT_POST

infix_operation:
	value infix_operator value
|	value assign_operator value

infix_operator:

	infix_assignable_operator	
|	AND	|	OR
|	'<' | AT_MOST | '>' | AT_LEAST
|	COMPARE | INEQUAL

infix_assignable_operator:

	'*' | '/' | '%'
|	'+' | '-'
|	SHIFT_L | SHIFT_R
|	ROTATE_L | ROTATE_R
|	'&' | '^' | '|'

assign_operator:
	
	'='
|	infix_assignable_operator '='

%%

/* Epilogue */

void yyerror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}
