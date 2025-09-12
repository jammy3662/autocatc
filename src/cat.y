%{

/* Prologue */

#include "cat.h"
#include "symbol.hh"

#define new(TYPE) (TYPE*)calloc(sizeof(TYPE),1)
#define newn(TYPE, CT) (TYPE*)calloc(sizeof(TYPE),CT)

void caterror (const char*);

/* handle end of file */
int yywrap ();

using namespace CatLang;

std::vector <Symbol*> scopes;

Symbol* SymbolFrom (Variable*);
Symbol* SymbolFrom (Function*);

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
	
	struct { CatLang::Symbol* setup, *proceed; CatLang::Expression* condition; }
	* iterator;
	
	struct { unsigned byte is_local: 1, is_static: 1, is_extern: 1, is_inline: 1; } qualifiers;
	
	CatLang::Type::Numeric::Representation type_qualifier;
	
	std::vector <char*>* members;
	
	std::vector <CatLang::Variable*>* variables;
	CatLang::Variable* variable;
	CatLang::Function* function;
	
	CatLang::Type* type;
	
	std::vector <CatLang::Expression*>* lengths;
	
	CatLang::Type::Pointer pointer;
	
	struct
	{
		int count;
		CatLang::Type::Pointer pointers [32];
	}
	indirection;
	
	bool boolean;
}

%type <scope> block
%type <scope> scope
%type <scope> braced-scope
%type <scope> enum-scope
%type <scope> tuple
%type <scope> parameters parameters-or-none
%type <scope> enum-instances

%type <symbol> statement
%type <symbol> line
%type <symbol> module

%type <label> label
%type <type> type

%type <expression> expression
%type <expression> initializer
%type <expression> expressions
%type <expression> list-expression
%type <expression> value
%type <expression> meta-value
%type <token> const-value

%type <qualifiers> qualifiers
%type <type_qualifier> type-qualifiers
%type <type_qualifier> type-qualifier
%type <variables> variables
%type <variable> variable
%type <variables> instances
%type <variable> instance
%type <function> function

%type <case_range> case-expression
%type <expression> range
%type <scope> else-block
%type <token>	struct-module-union

%type <members> members
%type <lengths> lengths
%type <expression> length
%type <pointer> pointer
%type <indirection> indirection

%type <boolean> const

%type <iterator> iterator

%type <token> semicolon colon

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
		$$->scope.continue_action = $2->proceed;
		$$->scope.insert ($2->setup);
	}
	
| module
|	line

semicolon:
	%empty %prec EMPTY { $$ = & current.token; }
|	';'

colon:
	%empty %prec EMPTY { $$ = & current.token; }
|	':'

label:
	
	NAME members
	{
		$$ = new (Label);
		$$->location = $1->location;
		$$->names = *$2; free ($2);
		$$->names.insert ($$->names.begin(), $1->text);
	}

members:
	
	%empty { $$ = new (std::vector<char*>); }
|	members '.' NAME { $$ = $1; $$->push_back ($3->text); }

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
		$$->setup = $1;
		$$->condition = $3;
		$$->proceed = $5;
	}

line:
	
	braced-scope
	{
		$$ = new (Symbol);
		$$->kind = Symbol::SCOPE;
		$$->location = $1->location;
		
		$$->scope = *$1; free ($1);
		$$->scope.kind = Scope::STACK;
	}
	
|	qualifiers variables semicolon
	{
		// because multiple variables are in one statement,
		// create a "list statement" to ensure all variables are inserted into their scope
		$$ = new (Symbol);
		$$->kind = Symbol::VARIABLE_LIST;
		$$->location = $2->front()->location;
		
		$$->is_local = $1.is_local;
		$$->is_static = $1.is_static;
		$$->is_extern = $1.is_extern;
		$$->is_inline = $1.is_inline;
		
		$$->variable_list = *$2; free ($2);
	}
	
|	qualifiers function
	{
		$$ = new (Symbol);
		$$->kind = Symbol::FUNCTION;
		$$->location = $2->location;
		
		$$->function = *$2; free ($2);
	}
	
|	expressions semicolon
	{
		$$ = new (Symbol);
		$$->kind = Symbol::EXPRESSION;
		$$->location = $1->location;
		
		memcpy (& $$->expression, $1, sizeof (Expression));
		free ($1);
	}
	
|	';' { $$ = 0; } // empty statement, dont create a symbol for this

scope:

	braced-scope
|	colon block ELLIPSES { $$ = $2; $$->location = $1->location; }
|	';'                  { $$ = new (Scope); $$->location = $1->location; }

braced-scope:
	'{' block '}' { $$ = $2; $$->location = $1->location; }

enum-scope:
	'{' enum-instances '}' { $$ = $2; }
|	colon enum-instances ELLIPSES { $$ = $2; }
|	';'
	{
		$$ = new (Scope);
		$$->kind = Scope::ENUM;
		$$->location = $1->location;
	}

enum-instances:
	%empty
	{
		$$ = new (Scope);
		$$->kind = Scope::ENUM;
		$$->location = current.location;
	}
	
|	instances
	{
		$$ = new (Scope);
		$$->kind = Scope::ENUM;
		$$->location = $1->front()->location;
		
		Symbol* list = new (Symbol);
		list->kind = Symbol::VARIABLE_LIST;
		list->location = $1->front()->location;
		
		$$->insert (list);
	}

module:
	qualifiers struct-module-union label scope
	{
		$$ = new (Symbol);
		$$->kind = Symbol::SCOPE;
		$$->location = $2->location;
		
		$$->scope = *$4; free ($4);
		
		$$->scope.name = $3->names.back();
		$$->scope.kind = $2->integer;
		
		// TODO: find target scope using path label
	}
	
|	qualifiers ENUM label enum-scope
	{
		$$ = new (Symbol);
		$$->kind = Symbol::SCOPE;
		$$->location = $2->location;
		
		$$->scope = *$4; free ($4);
		
		
		$$->scope.name = $3->names.back();
		$$->scope.kind = Scope::ENUM;
		
		// TODO: find target scope using path label
	}

struct-module-union:

	STRUCT { $$->integer = Scope::STRUCT; }
|	MODULE { $$->integer = Scope::MODULE; }
|	UNION { $$->integer = Scope::UNION; }

qualifiers:
	%empty %prec EMPTY { $$ = {false, false, false, false}; }
|	qualifiers LOCAL  { $$.is_local = true; }
|	qualifiers STATIC { $$.is_static = true; }
|	qualifiers EXTERN { $$.is_extern = true; }
|	qualifiers INLINE { $$.is_inline = true; }

variable:
	
	type instance
	{
		$$ = $2;
		
		Type* type = & $2->type;
		
		while (type->data is Type::ARRAY or type->data is Type::POINTER)
		{
			if (type->data is Type::ARRAY)
				type = type->array.contents;
			else
				type = type->pointer.pointee;
		}
		
		*type = *$1; free ($1);
	}

variables:
	
	type instances
	{
		$$ = $2;
		
		for (auto instance: *$2)
		{
			Type* type = & instance->type;
			
			while (type->data is Type::ARRAY or type->data is Type::POINTER)
			{
				if (type->data is Type::ARRAY)
					type = type->array.contents;
				else
					type = type->pointer.pointee;
			}
			
			*type = *$1; free ($1);
		}
	}

instances:
	
	instance
	{
		$$ = new (std::vector <Variable*>);
		$$->push_back ($1);
	}
	
|	instances ',' instance
	{
		$$ = $1;
		$$->push_back ($3);
	}

instance:
	
	label lengths initializer
	{
		$$ = new (Variable);
		$$->name = $1->names.back();
		$$->location = $1->location;
		$$->initializer = $3;
		$$->is_variadic = false;
		
		Type* type = & $$->type;
		
		for (auto length : *$2)
		{
			type->data = Type::ARRAY;
			type->array.count = length;
			
			type->array.contents = new (Type);
			type = type->array.contents;
		}
		
		// TODO: find target scope using path label
	}
	
|	label lengths TAIL
	{
		$$ = new (Variable);
		$$->name = $1->names.back();
		$$->location = $1->location;
		$$->initializer = 0;
		$$->is_variadic = true;
		
		Type* type = & $$->type;
		
		for (auto length : *$2)
		{
			type->data = Type::ARRAY;
			type->array.count = length;
			
			type->array.contents = new (Type);
			type = type->array.contents;
		}
		
		// TODO: find target scope using path label
	}
	
|	error { $$ = 0; }

lengths:
	%empty %prec EMPTY { $$ = new (std::vector <Expression*>); }
|	lengths length { $$ = $1; $$->push_back ($2); }

length:
	'[' expression ']' { $$ = $2; }

initializer:
	%empty %prec EMPTY { $$ = 0; }
|	'=' expression { $$ = $2; }

function:
	
	type label tuple scope
	{
		$$ = new (Function);
		
		$$->name = $2->names.back();
		$$->parameters = $3;
		$$->body = $4;
	}

tuple:
	'(' parameters-or-none ')' { $$ = $2; }

parameters-or-none:
	%empty %prec EMPTY { $$ = new (Scope); }
|	parameters

parameters:

	variable
	{
		$$ = new (Scope);
		$$->kind = Scope::STRUCT;
		
		$$->insert (SymbolFrom ($1));
	}
	
|	parameters ',' variable
	{
		$$ = $1;
		$$->insert (SymbolFrom ($3));
	}

type:
	
	type-qualifiers datatype indirection
	{
		$$ = new (Type);
		
		Type* type = $$;
		
		int idx = 0;
		for (; idx < $3.count; ++idx);
		{
			type->data = Type::POINTER;
			type->pointer = $3.pointers [idx];
			type->pointer.pointee = new Type;
			
			type = type->pointer.pointee;
		}
		
		// TODO: if datatype is numeric, use type-qualifiers
	}

type-qualifiers:
	%empty { $$ = Type::Numeric::Representation::SIGNED; }
|	type-qualifiers type-qualifier { $$ = $2; }

type-qualifier:

	SIGNED    { $$ = Type::Numeric::Representation::SIGNED; }
|	UNSIGNED  { $$ = Type::Numeric::Representation::UNSIGNED; }
|	COMPLEX   { $$ = Type::Numeric::Representation::COMPLEX; }
|	IMAGINARY { $$ = Type::Numeric::Representation::IMAGINARY; }

indirection:
	
	%empty { $$.count = 0; }
	
|	indirection pointer
	{
		$$.pointers [$$.count] = $2;
	}

pointer:
	'~' const { $$.constness = $2; $$.c_style = false; }
|	'*' const { $$.constness = $2; $$.c_style = true; }

const:
	%empty { $$ = false; }
|	CONST  { $$ = true; }

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
	{
		$$ = new (Expression);
		$$->opcode = Expression::COMMA;
		$$->location = $2->location;
		
		$$->operands [0] = $1;
		$$->operands [1] = $3;
	}

list-expression:

	expression %prec ','
	{
		$$ = new (Expression);
		$$->opcode = Expression::LIST;
		$$->location = $1->location;
		
		$$->list.push_back ($1);
	}
	
|	list-expression ',' expression
	{
		$$ = $1;
		$$->list.push_back ($3);
	}
	

expression:

	'(' expressions ')' { $$ = $2; }
|	'[' list-expression ']' { $$ = $2; }
|	value
|	prefix_operator expression %prec PREFIX
	{}
	
|	expression infix_operator expression %prec INFIX
	{}
	
|	expression postfix_operator %prec POSTFIX
	{}
	
|	label expression %prec '('
	{
		$$ = new (Expression);
		$$->opcode = Expression::CALL;
		$$->location = $1->location;
		
		$$->call.function.path = *$1; free ($1);
		$$->call.arguments = $2;
	}

value:
	
	label %prec NAME
	{
		$$ = new (Expression);
		$$->opcode = Expression::VALUEOF;
		$$->location = $1->location;
		$$->variable.path = *$1; free ($1);
	}
	
|	const-value
	{
		$$ = new (Expression);
		$$->opcode = Expression::LITERAL;
		$$->location = $1->location;
		$$->constant = $1->text;
	}
		
|	meta-value

const-value:

	CONST_INT
|	CONST_FLOAT
|	CONST_CHAR 
|	CONST_STRING

meta-value:

	SIZEOF expression
	{
		$$ = new (Expression);
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.SIZEOF;
		$$->meta.value = $2;
	}
	
|	COUNTOF expression
	{
		$$ = new (Expression);
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.COUNTOF;
		$$->meta.value = $2;
	}
	
|	NAMEOF expression
	{
		$$ = new (Expression);
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.NAMEOF;
		$$->meta.value = $2;
	}

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
