%{

/* Prologue */

#define YYDEBUG 1

#include "lex.yy.h"

void yyerror (const char*);

/* handle end of file */
int yywrap ();

%}

/* Declarations (Bison) */

%glr-parser
%debug

/* tokens not part of the language */
%token UNUSED

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

%token END_FILE

/* Token Precedence */

/* prefix */
%right PREFIX GROUP LIST INCREMENT_PRE DECREMENT_PRE POSITIVE NEGATIVE '!' COMPLEMENT DEREFERENCE ADDRESS META

/* postfix */
%left POSTFIX	INCREMENT_POST DECREMENT_POST

/* infix */
%left '*' '/' '%'
%left '+' '-'
%left SHIFT_L SHIFT_R
%nonassoc '<' AT_MOST '>' AT_LEAST
%nonassoc COMPARE INEQUAL
%left '&'
%left '^'
%left '|'
%left AND
%left OR
%right '='
%left ','

%start unit

%%

/* Grammar Rules */

optional_semicolon:
	';'
|	%empty

optional_colon:
	':'
|	%empty

unit:

	statements
|	%empty

statements:
	
	statements statement
|	statement

statement:

	declaration
|	include
|	braced_scope
| expression
|	control
|	jump
| case
| marker
| ';'

scope:

	braced_scope
|	implicit_scope

braced_scope:

	'{' statements '}'

implicit_scope:

	optional_colon statements ELLIPSES

enum_scope:
	
	'{' instances '}'
|	optional_colon instances ELLIPSES

include:
	
	INCLUDE name optional_semicolon

declaration:

	qualified_declaration
| object_declaration
|	function_declaration
|	structure_declaration
| enum_declaration

qualified_declaration:
	
	qualifiers declaration

structure_declaration:
	
	STRUCT label scope
|	UNION label scope
|	MODULE label scope
|	enum_declaration

enum_declaration:

	ENUM label	enum_scope
|	ENUM label ':' type enum_scope

control:

	switch
|	if_else
|	do_while
|	for

switch:

	SWITCH expression scope

if_else:

	IF expression scope
| IF expression scope ELSE scope
| IF expression scope ELSE IF scope

do_while:

	WHILE expression scope
|	DO scope WHILE expression

for:

	FOR statement expression statement scope

jump:
	loop
|	goto
| return

loop:

	CONTINUE optional_semicolon
|	BREAK optional_semicolon

goto:

	GOTO NAME optional_semicolon

return:

	RETURN expression optional_semicolon
|	RETURN optional_semicolon

case:

	CASE expression optional_colon
	DEFAULT optional_colon

named_marker:

	label ':'

marker:

	named_marker
|	case

qualifiers:

	qualifiers qualifier
|	qualifier

qualifier:

	LOCAL
|	STATIC
|	EXTERN
| INLINE

math_qualifier:

	SIGNED
|	UNSIGNED
|	COMPLEX
|	IMAGINARY
|	LONG
|	DOUBLE

builtin_type:

	BIT
|	CHAR
|	BYTE
|	short
|	INT
|	FLOAT

short:

	SHORT
|	SHORT	INT

type_qualifiers:
	
	type_qualifiers type_qualifier
|	type_qualifier

type_qualifier:
	
	CONST
|	math_qualifier

type:
	
	type_qualifiers underlying_type indirection
|	underlying_type indirection

underlying_type:
	
	datatype
|	TYPEOF name

indirection:
	
	cat_ptrs
|	c_ptrs
| %empty

cat_ptrs:
	
	cat_ptrs cat_ptr
|	cat_ptr

cat_ptr:
	
	'~' CONST
|	'~'

c_ptrs:
	
	c_ptrs c_ptr
|	c_ptr

c_ptr:
	
	'*' CONST
|	'*'

datatype:
	
	builtin_type
|	NAME

label:

	name
|	'_'

name:

	name '.' NAME
|	NAME

instances:

	instances ',' instance
|	instance

instance:

	label
|	label '=' single_expression
|	counted_instance
|	counted_instance '=' single_expression

counted_instance:
	
	label
|	label '[' expression ']'

object_declaration:
	
	variable_declaration optional_semicolon
|	function_declaration

variable_declarations:
	
	variable_declarations ',' variable_declaration
|	variable_declaration

variable_declaration:

	type instances

function_declaration:
	
	type label tuple ';'
|	type label tuple scope

tuple:
	
	'(' variable_declarations ')'
|	'(' ')'

expression:
	
	expression ',' single_expression
|	single_expression

single_expression:
	
	object_value
| const_value
| operation
| '(' expression ')'
|	'[' expression ']'

const_value:
	
	CONST_INT
|	CONST_FLOAT
|	CONST_CHAR 
|	CONST_STRING

object_value:

	name

operation:
	
	prefix_operation
|	infix_operation
|	postfix_operation

prefix_operation:
		
	prefix_operator expression
|	'~' expression

prefix_operator:

	'(' %prec GROUP
| '[' %prec LIST	
|	INCREMENT %prec INCREMENT_POST
|	DECREMENT %prec DECREMENT_POST
|	'+' %prec POSITIVE
|	'-' %prec NEGATIVE
|	'!' %prec '!'
| '~' %prec COMPLEMENT
| '*' %prec DEREFERENCE
| '&' %prec ADDRESS
|	SIZEOF %prec META
| COUNTOF %prec META
| NAMEOF %prec META

postfix_operation:
	
	expression postfix_operator

postfix_operator:

	INCREMENT %prec INCREMENT_PRE
|	DECREMENT %prec DECREMENT_PRE
| '(' %prec GROUP
| '[' %prec LIST

infix_operation:

	expression infix_operator expression
	expression assign_operator expression

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

int yywrap ()
{
	return END_FILE;
}
