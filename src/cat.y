%{

/* Prologue */

#include "cat.h"
#include "symbol.hh"

void caterror (const char*);

/* handle end of file */
int yywrap ();

using namespace CatLang;

Array <Scope> scope_stack;
#define current_scope scope_stack.last()

Location location_buffer;

%}

/* Declarations (Bison) */

%code requires
{
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

%token <token>  ALIAS TEMPLATE ITERATOR OPERATOR
%token <token>  INCLUDE INLINE
%token <token>  SIZEOF COUNTOF NAMEOF TYPEOF STRINGOF
%token <token>  LOCAL STATIC	CONST EXTERN
%token <token>  SIGNED	UNSIGNED COMPLEX IMAGINARY LONG DOUBLE
%token <token>  BREAK CONTINUE RETURN GOTO
%token <token>  STRUCT UNION MODULE ENUM
%token <token>  WHILE DO FOR
%token <token>  IF	ELSE SWITCH
%token <token>  CASE DEFAULT
%token <token>	AS

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

%left PAIR

%right PREFIX
%right '(' '{' '[' '!' '~' ':' WHILE

%left POSTFIX
%left ')' ']' INCREMENT DECREMENT

%right META

%nonassoc LOCAL STATIC EXTERN INLINE
%nonassoc CONST_INT CONST_FLOAT CONST_STRING CONST_CHAR
%nonassoc SIZEOF COUNTOF NAMEOF STRINGOF
%nonassoc NAME
%nonassoc ATOMIC

%union
{
	Token token;
	
	CatLang::Label label;
	
	CatLang::Symbol::Qualifiers qualifiers;
	CatLang::Type::Pointer::Indirection pointer;
	CatLang::Type::Numeric basic_type;
	CatLang::Template templates;
	
	CatLang::Symbol* symbol;
	CatLang::Iterator* iterator;
	
	Array <CatLang::Symbol*> symbols;
	Array <CatLang::Label> labels;
	Array <CatLang::Variable> variables;
	
	Array <CatLang::Expression*> dimensionality;
	
	CatLang::Type type_base;
	CatLang::Type* type;
	CatLang::Scope scope;
	CatLang::Scope* scope_ptr;
	opt <CatLang::Scope> scope_opt;
	CatLang::Variable variable;
	CatLang::Function function;
	CatLang::Expression* expression;
	CatLang::Expression range [2];
	
	Array <CatLang::Type::Pointer::Indirection>
	indirection;
	
	bool boolean;
	int integer;
}

%type <scope> block scope braced-scope
%type <scope> enum-scope
%type <scope> tuple
%type <scope> parameters
%type <scope> enum-block

%type <symbol> statement
%type <symbol> line
%type <symbol> module

%type <templates> template
%type <templates> template-parameters

%type <token>	definable-operator

%type <label> label
%type <type> type
%type <type_base> datatype
%type <basic_type> basic-type
%type <integer> longs
%type <integer> long

%type <expression> expression atomic
%type <expression> initializer
%type <expression> value
%type <token> literal meta

%type <qualifiers> qualifiers
%type <type_base> type-qualifiers type-qualifier
%type <variables> variables
%type <variable> variable
%type <variables> instances
%type <variable> instance counted-instance
%type <function> function

%type <expression> case-expression
%type <expression> range-expression
%type <scope_opt> else-block
%type <token>	struct-module-union

%type <dimensionality> dimensionality
%type <pointer> pointer
%type <indirection> indirection

%type <token> prefix-operator infix-operator postfix-operator
%type <token> arithmetic


%type <boolean> const

%type <iterator> iterator c-iterator iterator-define

%type <token> semicolon colon

%start block

%%

/* Grammar Rules */

block:

	%empty
	{
		$$ = {};
		scope_stack.append ($$);
	}
	
|	block statement
	{
		$$ = scope_stack.last();
	}


statement:

	error statement
	{
		// TODO: structured and intuitive error handling
		
		// on error, abort and start a new statement
		$$ = $2;
	}
	
| ALIAS label '=' label semicolon
	{
		$$ = new Alias ($1.location, $2, $4);
		current_scope.insert ($$);
	}
	
|	label ':'
	{
		$$ = new Marker ($1.location, $1.name());
		current_scope.insert ($$);
	}
	
|	CASE case-expression colon
	{
		$$ = new Case ($1.location, $2);
		current_scope.insert ($$);
	}
	
|	DEFAULT colon
	{
		$$ = new Case ($1.location);
		current_scope.insert ($$);
	}
	
|	INCLUDE label semicolon
	{
		$$ = new Include ($1.location, $2);
		current_scope.insert ($$);
	}
	
|	CONTINUE semicolon
	{
		$$ = new Jump ($1.location, Jump::CONTINUE);
		current_scope.insert ($$);
	}
	
|	BREAK semicolon
	{
		$$ = new Jump ($1.location, Jump::BREAK);
		current_scope.insert ($$);
	}
	
|	GOTO label semicolon
	{
		$$ = new Jump ($1.location, $2);
		current_scope.insert ($$);
	}
	
|	RETURN expression semicolon %prec ATOMIC
	{
		$$ = new Return ($1.location, $2);
		current_scope.insert ($$);
	}
	
|	RETURN semicolon
	{
		$$ = new Return ($1.location);
		current_scope.insert ($$);
	}
	
|	IF expression scope else-block
	{
		$$ = new Conditional ($1.location, Conditional::IF, $2, $3, $4);
		current_scope.insert ($$);
	}
	
|	SWITCH expression scope
	{
		$$ = new Conditional ($1.location, Conditional::SWITCH, $2, $3);
		current_scope.insert ($$);
	}
	
|	WHILE expression scope
	{
		$$ = new Conditional ($1.location, Conditional::WHILE, $2, $3);
		current_scope.insert ($$);
	}
	
|	DO WHILE expression scope
	{
		$$ = new Conditional ($1.location, Conditional::DO_WHILE, $3, $4);
		current_scope.insert ($$);
	}
	
|	DO scope WHILE expression semicolon
	{
		$$ = new Conditional ($1.location, Conditional::DO_WHILE, $4, $2);
		current_scope.insert ($$);
	}
	
|	FOR iterator scope
	{
		$$ = new For ($1.location, $2, $3);
		current_scope.insert ($$);
	}
	
|	ITERATOR iterator-define
	{
		$$ = $2;
		current_scope.insert ($$);
	}
	
|	OPERATOR definable-operator tuple scope
	{
		
	}
	
|	template qualifiers function
	{
		auto function = $3;
		function.qualifiers = $2;
		function.templates = $1;
		
		$$ = new Function (location_buffer, function);
		current_scope.insert ($$);
	}
	
|	line
	{
		$$ = $1;
		current_scope.insert ($$);
	}
	
| template module
	{
		$$ = $2;
		$2->templates = $1;
		current_scope.insert ($$);
	}


line:
	
	qualifiers braced-scope
	{
		$$ = new Scope ($2);
		$$->qualifiers = $1;
	}
	
|	qualifiers variables semicolon
	{
		$$ = {};
		
		auto variables = $2;
		
		for (int i = 0; i < variables.count; ++i)
		{
			auto variable = new Variable (variables [i]);
			variable->qualifiers = $1;
			current_scope.insert (variable);
		}
	}
	
|	expression semicolon { $$ = $1; }
	
|	';' { $$ = 0; } // empty statement, dont create a symbol for this


module:
	
	qualifiers struct-module-union label scope
	{
		$$ = new Module ($2.location, (Module::Form) $2.integer, $3);
		$$->qualifiers = $1;
		
		// TODO: find target scope using path label
	}
	
|	qualifiers ENUM label enum-scope
	{
		$$ = new Enum ($2.location, $3, $4);
		$$->qualifiers = $1;
		
		// TODO: find target scope using path label
	}


scope:

	colon block ELLIPSES { $$ = Scope ($1.location, $2); }
|	';' { $$ = Scope ($1.location); }
|	braced-scope


braced-scope:
	
	'{' block '}' { $$ = Scope ($1.location, $2); }


enum-scope:
	
	'{' enum-block '}' { $$ = Enum ($1.location, $2); }
|	colon enum-block ELLIPSES { $$ = Enum ($1.location, $2); }
|	';' { $$ = Enum ($1.location); }


enum-block:
	
	%empty { $$ = Enum (current.location); }
|	instances { $$ = Enum ($1); }


template:
	
	TEMPLATE '<' template-parameters '>' { $$ = $3; location_buffer = $1.location; }


template-parameters:
	
	%empty %prec EMPTY { $$ = {}; }
	
|	template-parameters label
	{
		$$ = $1;
		$$.append ($2);
	}


iterator:

	'(' iterator ')' { $$ = $2; }
	
|	c-iterator
	
|	NAME ':' range-expression
	{
		$$ = new Iterator::Range ($1.location, $1.text, $3);
	}
	
|	NAME ':' expression
	{
		$$ = new Iterator::Custom ($1.location, $1.text, $3);
	}


iterator-define:
	
	'(' iterator-define ')' { $$ = $2; }
	
|	c-iterator
	
|	range-expression
	{
		$$ = new Iterator::Range ($1->location, $1);
	}
	
|	expression %prec ATOMIC
	{
		$$ = new Iterator::Custom ($1->location, $1);
	}


c-iterator:
	
	line ';' expression ';' line
	{
		$$ = new Iterator::Loop ($1->location, $1, $3, $5);
	}


label:
	
	NAME
	{
		$$ = Label ($1.location, $1.text);
	}
	
|	label '.' NAME
	{
		$$ = $1;
		$$.names.append ($3.text);
	}


variable:
	
	type instance
	{
		$$ = $2;
		$$.type = $1;
	}


variables:
	
	type instances
	{
		auto instances = $$ = $2;
		
		for (int i = 0; instances.count; ++i)
			instances [i].type = $1;
	}


instances:
	
	instance
	{
		$$ = {};
		$$.append ($1);
	}
	
|	instances ',' instance
	{
		$$ = $1;
		$$.append ($3);
	}


instance:
	
	counted-instance initializer
	{
		$$ = $1;
		$$.initializer = $2;
	}
	
|	counted-instance TAIL
	{
		$$ = $1;
		$$.variadic = true;
	}


counted-instance:

	label %prec EMPTY	{ $$ = Variable ($1.location, $1); }
	
|	label dimensionality %prec '[' { $$ = Variable ($1.location, $1, $2); }


dimensionality:
	'[' expression ']' { $$ = {}; $$.append ($2); }
|	dimensionality '[' expression ']' { $$ = $1; $$.append ($3); }

initializer:
	%empty %prec EMPTY { $$ = 0; }
|	'=' expression { $$ = $2; }


function:
	
	type label tuple scope
	{
		$$ = Function ($1->location, $1, $2, $3, $4);
	}


tuple:
	'(' parameters ')' { $$ = $2; }


parameters:

	%empty %prec EMPTY { $$ = Scope (current.location); }
	
|	parameters ',' variable
	{
		$$ = $1;
		$$.insert (new Variable ($3));
	}


type:
	
	type-qualifiers datatype indirection
	{
		// TODO
		/*
		Type* type = new <Type> ();
		
		int idx = 0;
		for (; idx < $3.count; ++idx);
		{
			type->data = Type::POINTER;
			type->pointer = $3.pointers [idx];
			type->pointer.pointee = new <Type> ();
			
			type = type->pointer.pointee;
		}
		
		*type = *$2; free ($2);
		
		if (type->data is Type::NUMERIC)
		{
			type->number.representation = $1;
		}
		*/
	}


datatype:

	basic-type { $$ = $1; }
	
|	tuple
	{
		// TODO
	}
	
|	TYPEOF label
	{
		// TODO
	}
	
|	label
	{
		// TODO
	}


case-expression:
	
	expression %prec EMPTY
|	range-expression %prec TAIL


range-expression:
	
	expression TAIL expression
	{
		$$ = new BinaryExpression
		($1->location, $1, Expression::RANGE, $3);
	}


expression:
	
	atomic
	
|	meta expression %prec META
	{
		new MetaExpression (location_buffer, $1.integer, $2);
	}
	
|	prefix-operator expression %prec PREFIX
	{
		$$ = new UnaryExpression ($1.location, $1.integer, $2);
	}
	
|	expression infix-operator expression %prec INFIX
	{
		$$ = new BinaryExpression ($1->location, $1, $2.integer, $3);
	}
	
|	expression postfix-operator %prec POSTFIX
	{
		$$ = new UnaryExpression ($1->location, $2.integer, $1);
	}
	
|	expression ',' expression %prec ','
	{
		ListExpression* list;
		
		if ($$->opcode isnt Expression::LIST)
		{
			list = new ListExpression ($1->location); 
			list->expressions.append ($1);
			list->expressions.append ($3);
			$$ = list;
		}
		
		else
		{
			list = (ListExpression*) ($$ = $1);
			list->expressions.append ($3);
		}
	}
	
|	expression expression %prec INFIX
	{
		// TODO: function call OR multiplication
		// note that function calls with empty arguments are matched by the variable access (value) expression
		
		$$ = new PairExpression
		($1->location, $1, $2);
	}


atomic:

	'(' expression ')' { $$ = $2; }
|	'[' expression ']' { $$ = $2; }
|	value


value:
	
	label %prec NAME { $$ = new ReferenceExpression ($1.location, $1); }
	
|	literal { $$ = new LiteralExpression ($1.location, $1.text); }


indirection:
	
	%empty { $$ = {}; }
	
|	indirection pointer
	{
		$$ = $1;
		$$.append ($2);
	}


pointer:
	'~' const { $$.constness = $2; $$.c_style = false; }
| '@' const { $$.constness = true; $$.c_style = false; }
|	'*' const { $$.constness = $2; $$.c_style = true; }


basic-type:
	
	BIT
	{ $$ = Type::Numeric ($1.location, Type::Numeric::BIT); }
|	CHAR
	{ $$ = Type::Numeric ($1.location, Type::Numeric::CHAR); }
|	BYTE
	{ $$ = Type::Numeric ($1.location, Type::Numeric::BYTE); }
|	SHORT int
	{ $$ = Type::Numeric ($1.location, Type::Numeric::SHORT); }
|	longs int
	{ $$ = Type::Numeric (location_buffer, Type::Numeric::LONG, $1); }
|	INT
	{ $$ = Type::Numeric ($1.location, Type::Numeric::INT); }
|	FLOAT
	{ $$ = Type::Numeric ($1.location, Type::Numeric::FLOAT); }
|	long DOUBLE
	{ $$ = Type::Numeric (location_buffer, Type::Numeric::DOUBLE, $1); }


qualifiers:
	%empty %prec EMPTY { $$ = {false, false, false, false}; }
|	qualifiers LOCAL  { $$.is_local = true; }
|	qualifiers STATIC { $$.is_static = true; }
|	qualifiers EXTERN { $$.is_extern = true; }
|	qualifiers INLINE { $$.is_inline = true; }


type-qualifiers:
	
	%empty { $$ = {}; }
	
|	type-qualifiers type-qualifier
	{
		if ($1.constness)
			$$.constness = true;
		
		if ($1.representation isnt Type::DEFAULT)
			$$.representation = $1.representation;
	}


type-qualifier:

	CONST     { $$.representation = Type::DEFAULT; $$.constness = true; }
|	SIGNED    { $$.representation = Type::SIGNED; $$.constness = false; }
|	UNSIGNED  { $$.representation = Type::UNSIGNED; $$.constness = false; }
|	COMPLEX   { $$.representation = Type::COMPLEX; $$.constness = false; }
|	IMAGINARY { $$.representation = Type::IMAGINARY; $$.constness = false; }


struct-module-union:

	STRUCT { $$ = $1; $$.integer = Module::STRUCT; }
|	MODULE { $$ = $1; $$.integer = Module::MODULE; }
|	UNION { $$ = $1; $$.integer = Module::UNION; }


meta:

	SIZEOF { $$ = $1; $$.integer = MetaExpression::SIZEOF; location_buffer = $1.location; }
|	COUNTOF { $$ = $1; $$.integer = MetaExpression::COUNTOF; location_buffer = $1.location; }
|	NAMEOF { $$ = $1; $$.integer = MetaExpression::NAMEOF; location_buffer = $1.location; }
|	STRINGOF { $$ = $1; $$.integer = MetaExpression::STRINGOF; location_buffer = $1.location; }


prefix-operator:

	'!' { $$ = $1; $$.integer = Expression::NOT; }
|	'~' { $$ = $1; $$.integer = Expression::COMPLEMENT; }
|	INCREMENT { $$ = $1; $$.integer = Expression::PRE_INCREMENT; }
|	DECREMENT { $$ = $1; $$.integer = Expression::PRE_DECREMENT; }
|	'+' { $$ = $1; $$.integer = Expression::PLUS; }
|	'-' { $$ = $1; $$.integer = Expression::MINUS; }
|	'*' { $$ = $1; $$.integer = Expression::DEREFERENCE; }
|	'&' { $$ = $1; $$.integer = Expression::ADDRESS; }


postfix-operator:

	INCREMENT %prec POSTFIX { $$ = $1; $$.integer = Expression::POST_INCREMENT; }
|	DECREMENT %prec POSTFIX { $$ = $1; $$.integer = Expression::POST_DECREMENT; }


infix-operator:

	AND { $$ = $1; $$.integer = Expression::BOTH; }
|	OR { $$ = $1; $$.integer = Expression::EITHER; }	
|	COMPARE { $$ = $1; $$.integer = Expression::EQUALS; }
|	INEQUAL { $$ = $1; $$.integer = Expression::INEQUAL; }
|	'<' { $$ = $1; $$.integer = Expression::LESS; }
| AT_MOST { $$ = $1; $$.integer = Expression::LESS_OR_EQUAL; }
| '>' { $$ = $1; $$.integer = Expression::MORE; }
| AT_LEAST { $$ = $1; $$.integer = Expression::MORE_OR_EQUAL; }
|	arithmetic
|	arithmetic '=' { $$ = $1; $$.integer += Expression::ASSIGN; }
|	'=' { $$ = $1; $$.integer = Expression::ASSIGN; }
|	','


arithmetic:

	'*' { $$ = $1; $$.integer = Expression::MULTIPLY; }
|	'/' { $$ = $1; $$.integer = Expression::DIVIDE; }
|	'%' { $$ = $1; $$.integer = Expression::MOD; }
|	'&' { $$ = $1; $$.integer = Expression::AND; }
|	'+' { $$ = $1; $$.integer = Expression::PLUS; }
|	'-' { $$ = $1; $$.integer = Expression::MINUS; }
|	'^' { $$ = $1; $$.integer = Expression::XOR; }
|	'|' { $$ = $1; $$.integer = Expression::OR; }
|	SHIFT_L { $$ = $1; $$.integer = Expression::SHIFT_LEFT; }
|	SHIFT_R { $$ = $1; $$.integer = Expression::SHIFT_RIGHT; }
|	ROTATE_L { $$ = $1; $$.integer = Expression::ROTATE_LEFT; }
|	ROTATE_R { $$ = $1; $$.integer = Expression::ROTATE_RIGHT; }


definable-operator:
	
	INCREMENT { $$ = $1; $$.integer = Expression::PRE_INCREMENT; }
|	DECREMENT { $$ = $1; $$.integer = Expression::PRE_DECREMENT; }
|	'+' { $$ = $1; $$.integer = Expression::PLUS; }
|	'-' { $$ = $1; $$.integer = Expression::MINUS; }
|	'!' { $$ = $1; $$.integer = Expression::NOT; }
|	'&' { $$ = $1; $$.integer = Expression::AND; }
|	'*' { $$ = $1; $$.integer = Expression::XOR; }
|	'|' { $$ = $1; $$.integer = Expression::OR; }
|	SHIFT_L { $$ = $1; $$.integer = Expression::SHIFT_LEFT; }
|	SHIFT_R { $$ = $1; $$.integer = Expression::SHIFT_RIGHT; }
|	ROTATE_L { $$ = $1; $$.integer = Expression::ROTATE_LEFT; }
|	ROTATE_R { $$ = $1; $$.integer = Expression::ROTATE_RIGHT; }


else-block:
	%empty { $$.valid = false; }
|	ELSE scope { $$ = Scope ($1.location, $2); }


longs:
	
	LONG { $$ = 1; location_buffer = $1.location; }
|	longs LONG { $$ += 1; }


long:
	
	%empty { $$ = 0; location_buffer = current.location; }
|	LONG { $$ = 1; location_buffer = $1.location; }


int:
	%empty
|	INT


const:
	%empty { $$ = false; }
|	CONST  { $$ = true; }


literal:

	CONST_INT
|	CONST_FLOAT
|	CONST_CHAR 
|	CONST_STRING


semicolon:
	%empty %prec EMPTY { $$ = current.token; }
|	';'

colon:
	%empty %prec EMPTY { $$ = current.token; }
|	':'


%%

/* Epilogue */

void caterror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}
