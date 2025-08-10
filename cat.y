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

	qualifiers object_declaration
|	qualifiers function_declaration
|	qualifiers structure_declaration
| qualifiers enum_declaration

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
|	%empty

qualifier:

	LOCAL
|	STATIC
|	EXTERN
| INLINE

optional_const_qualifier:
	
	CONST
|	%empty

math_qualifiers:
	
	math_qualifiers math_qualifier
|	math_qualifier
|	%empty

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
	
	optional_const_qualifier math_qualifiers
|	math_qualifiers optional_const_qualifier

type:
	
	type_qualifiers datatype

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

	counted_instance
|	counted_instance '=' single_expression

counted_instance:
	
	label
|	label '[' expression ']'

object_declaration:
	
	variable_declaration ';'
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
	
	meta_value
|	object_value

object_value:

	name

meta_value:

	sizeof
|	countof
|	nameof
| typeof

sizeof:

	SIZEOF expression

countof:

	COUNTOF	expression

nameof:

	NAMEOF name

typeof:

	TYPEOF name

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
