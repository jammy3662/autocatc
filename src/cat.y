%{

/* Prologue */

#include "cat.h"
#include "symbol.hh"

#define new(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define newn(TYPE, CT) (TYPE*)malloc(sizeof(TYPE)*CT)

void caterror (const char*);

/* handle end of file */
int yywrap ();

using namespace CatLang;

std::vector <Symbol*> scopes;

%}

/* Declarations (Bison) */

%code requires
{
	#include <vector>

	#include "log.hh"
	#include "token.hh"
	#include "symbol.hh"
}

%define api.prefix {cat}

%glr-parser
%debug

%token <token>  '(' ')' '[' ']' '{' '}'
%token <token>  '!' '#' '$' '%' '&' '*' '+' ','
%token <token>  '-' '.' '/' ':' ';' '<' '>' '='
%token <token>  '?' '@' '^' '_' '|' '~'

%token <token>  AND /* && */
%token <token>  OR /* || */
%token <token>  INCREMENT /* ++ */
%token <token>  DECREMENT /* -- */
%token <token>  SHIFT_L /*	<< */
%token <token>  SHIFT_R /* >> */
%token <token>  ROTATE_L /* <<< */
%token <token>  ROTATE_R /* >>> */
%token <token>  COMPARE /* == */
%token <token>  INEQUAL /* != */
%token <token>  AT_MOST /* <= */
%token <token>  AT_LEAST /* >= */

%token <token>  TAIL /* .. */
%token <token>  ELLIPSES /* ... */

%token <token>  CONST_INT
%token <token>  CONST_FLOAT
%token <token>  CONST_STRING
%token <token>  CONST_CHAR

%token <token>  COMMENT_LINE
%token <token>  COMMENT_BLOCK

%token <token>  NAME

%token <token>  BIT CHAR BYTE SHORT INT FLOAT

%token <token>  ALIAS
%token <token>  INCLUDE INLINE
%token <token>  SIZEOF COUNTOF NAMEOF TYPEOF
%token <token>  LOCAL STATIC	CONST EXTERN
%token <token>  SIGNED	UNSIGNED COMPLEX IMAGINARY LONG DOUBLE
%token <token>  BREAK CONTINUE RETURN GOTO
%token <token>  STRUCT UNION MODULE ENUM
%token <token>  WHILE DO FOR
%token <token>  IF	ELSE SWITCH
%token <token>  CASE DEFAULT

/* Token Precedence */

%nonassoc EMPTY

%nonassoc TAIL

%nonassoc ';' ','

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

%right PREFIX
%right '(' '{' '[' '!' '~' ':' WHILE

%left POSTFIX
%left ')' ']' INCREMENT DECREMENT

%nonassoc CONST_INT CONST_FLOAT CONST_STRING CONST_CHAR
%nonassoc SIZEOF COUNTOF NAMEOF
%nonassoc NAME
%nonassoc ATOMIC

%union
{
	Token* token;
	
	CatLang::Label* label;
	CatLang::Symbol* symbol;
	
	CatLang::Scope* scope;
	
	CatLang::Expression* expression;
	
	CatLang::Expression* case_range [2];
	
	struct { CatLang::Symbol* init, *cont; CatLang::Expression* condition; }
	* iterator;
}

%type <scope> block
%type <scope> scope
%type <scope> braced-scope

%type <symbol> statement
%type <symbol> line
%type <symbol> declare-namespace

%type <label> label

%type <expression> expression

%type <case_range> case-expression
%type <expression> range
%type <scope> else-block

%type <iterator> iterator

%start block

%%

/* Grammar Rules */

block:

	%empty
	{
		$$ = new (Scope);
	}
|	block statement
	{
		$$ = $1;
		$$->insert ($2);
	}

statement:

	error statement
	{
		// TODO: structured and intuitive error handling
		
		// [!] On error, abort and start a new statement
		$$ = $2;
	}
	
| ALIAS NAME '=' label semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::ALIAS;
		$$->location = $1->location;
		
		$$->alias.name = $2->text;
		$$->alias.path = *$4; free ($4);
	}
	
|	NAME ':'
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::MARKER;
		$$->location = $1->location;
		
		$$->marker.name = $1->text;
	}
	
|	CASE case-expression colon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::CASE;
		$$->location = $1->location;
		
		$$->case_marker.expression = $2 [0];
		$$->case_marker.fallthrough = $2 [1];
	}
	
|	DEFAULT colon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::CASE;
		$$->location = $1->location;
		
		// (should be zero already, but just in case)
		$$->case_marker.expression = 0;
	}
	
|	INCLUDE label semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::INCLUDE;
		$$->location = $1->location;
		
		$$->include.path = *$2; free ($2);
	}
	
|	CONTINUE semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::CONTINUE;
		$$->location = $1->location;
	}
	
|	BREAK semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::BREAK;
		$$->location = $1->location;
	}
	
|	GOTO NAME semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::GOTO;
		$$->location = $1->location;
		
		$$->go_to.marker = $2->text;
	}
	
|	RETURN expression semicolon %prec ATOMIC
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::RETURN;
		$$->location = $1->location;
		
		$$->return_marker.value = $2;
	}
	
|	RETURN semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::RETURN;
		$$->location = $1->location;
		
		// (should already be 0, but just in case)
		$$->return_marker.value = 0;
	}
	
|	IF expression scope else-block
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$3; free ($3);
		$$->scope.kind = Scope::IF;
		$$->scope.condition = $2;
		$$->scope.alternate = $4;
	}
	
|	SWITCH expression scope
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$3; free ($3);
		$$->scope.kind = Scope::SWITCH;
		$$->scope.condition = $2;
	}
	
|	WHILE expression scope
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$3; free ($3);
		$$->scope.kind = Scope::WHILE;
		$$->scope.condition = $2;
	}
	
|	DO WHILE expression scope
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$4; free ($4);
		$$->scope.kind = Scope::DO_WHILE;
		$$->scope.condition = $3;
	}
	
|	DO scope WHILE expression semicolon
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$2; free ($2);
		$$->scope.kind = Scope::DO_WHILE;
		$$->scope.condition = $4;
	}
	
|	FOR iterator scope
	{
		$$ = new (Symbol);
		
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$3; free ($3);
		$$->scope.kind = Scope::FOR;
		$$->scope.condition = $2->condition;
		$$->scope.continue_action = $2->cont;
		$$->scope.insert ($2->init);
	}
	
| declare-namespace
|	line

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

case-expression:
	
	expression range
	{
		$$ [0] = $1;
		$$ [1] = $2;
	}

range:
	%empty %prec EMPTY { $$ = 0; }
|	TAIL expression { $$ = $2; }

else-block:
	%empty { $$ = 0; }
|	ELSE scope { $$ = $2; }

iterator:
	'(' iterator ')' { $$ = $2; }
|	line ';' expression ';' line
	{
		$$->init = $1;
		$$->condition = $3;
		$$->cont = $5;
	}

line:
	braced-scope
|	declare-variables
|	declare-function
|	expressions semicolon
|	';'

scope:

	braced-scope
|	colon block ELLIPSES { $$ = $2; }	
|	';'                  { $$ = new (Scope); }

braced-scope:
	'{' block '}' { $$ = $2; }

enum-scope:
	'{' optional_instances '}'
|	colon optional_instances ELLIPSES
|	';'

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
|	label lengths TAIL

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
|	UNSIGNED
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
|	long DOUBLE

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
|	label expression %prec '('

value:
	
	label %prec NAME
|	const_value
|	meta_value

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
|	'*'
|	'&'

postfix_operator:

	INCREMENT %prec POSTFIX
|	DECREMENT %prec POSTFIX

infix_operator:

	AND	|	OR | COMPARE | INEQUAL
|	'<' | AT_MOST | '>' | AT_LEAST
|	arithmetic
|	arithmetic '='
|	'='

arithmetic:
	'*' | '/' | '%' | '&'
|	'+' | '-' | '^' | '|'
|	SHIFT_L | SHIFT_R
|	ROTATE_L | ROTATE_R

%%

/* Epilogue */

void caterror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}
