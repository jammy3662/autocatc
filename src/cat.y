%{

/* Prologue */

#include "cat.h"
#include "symbol.hh"

void caterror (const char*);

/* handle end of file */
int yywrap ();

using namespace CatLang;

%}

/* Declarations (Bison) */

%code requires
{
	#include "log.hh"
	#include "token.hh"
	#include "parser.hh"
	#include "symbol.hh"
	
	/*-----------------------------------------
	| Simple interface to wrap a symbol
	| Allows for multiple symbols in sequence
	|_________________________________________*/
	struct Statement: Array <CatLang::Symbol*>
	{
		Statement (CatLang::Symbol*);
	};
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
%token <token>  SIZEOF COUNTOF NAMEOF TYPEOF
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
	Token token;
	
	CatLang::Label label;
	
	Statement statement;
	
	CatLang::Symbol::Qualifiers qualifiers;
	CatLang::Type::Pointer pointer;
	CatLang::Type::Numeric basic_type;
	CatLang::Template templates;
	
	CatLang::Symbol* symbol;
	CatLang::Iterator* iterator;
	
	Array <CatLang::Symbol*> symbols;
	Array <CatLang::Label> labels;
	Array <CatLang::Variable> variables;
	
	Array <CatLang::Expression*> lengths;
	
	CatLang::Type raw_type;
	CatLang::Type* type;
	CatLang::Scope scope;
	opt <CatLang::Scope> scope_opt;
	CatLang::Variable variable;
	CatLang::Function function;
	CatLang::Expression* expression;
	CatLang::Expression range [2];
	
	struct
	{
		int count;
		struct { byte c_style: 1, constant: 1; }
		pointers [32];
	}
	indirection;
	
	bool boolean;
	int integer;
	
	CATSTYPE () {}
}

%type <scope> block
%type <scope> scope
%type <scope> braced-scope
%type <scope> enum-scope
%type <scope> tuple
%type <scope> parameters parameters-or-none
%type <scope> enum-block

%type <statement> statement
%type <symbol> line
%type <symbol> module

%type <templates> template
%type <templates> template-parameters

%type <label> label
%type <type> type
%type <raw_type> datatype
%type <basic_type> basic-type
%type <integer> longs
%type <integer> long

%type <expression> expression
%type <expression> initializer
%type <expression> expressions
%type <expression> arguments
%type <expression> argument
%type <expression> list-expression
%type <expression> value
%type <expression> meta-value
%type <token> const-value

%type <qualifiers> qualifiers
%type <type> type-qualifiers
%type <type> type-qualifier
%type <variables> variables
%type <variable> variable
%type <variables> instances
%type <variable> instance
%type <function> function

%type <expression> case-expression
%type <expression> range-expression
%type <scope_opt> else-block
%type <token>	struct-module-union

%type <lengths> lengths
%type <expression> length
%type <pointer> pointer
%type <indirection> indirection

%type <token> prefix-operator infix-operator postfix-operator
%type <token> arithmetic


%type <boolean> const

%type <iterator> c-iterator
%type <iterator> range-iterator
%type <iterator> type-iterator
%type <iterator> iterator

%type <token> semicolon colon

%start block

%%

/* Grammar Rules */

block:

	%empty { $$ = {}; }
	
|	block statement
	{
		$$ = $1;
		auto symbols = $2;
		
		for (int i = 0; i < symbols.count; ++i)
			if (nonzero symbols [i])
				$$.insert (symbols [i]);
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
		char* name = $2.names.back();
		// TODO: handle nested names (a.b.name)
		
		$$ = new Alias ($1.location, name, $4);
	}
	
|	label ':'
	{
		char* name = $1.names.back();
		// TODO: handle nested names (a.b.name)
		
		$$ = new Marker ($1.location, name);
	}
	
|	CASE case-expression colon
	{
		$$ = new Case ($1.location, $2);
	}
	
|	DEFAULT colon
	{
		$$ = new Case ($1.location);
	}
	
|	INCLUDE label semicolon
	{
		$$ = new Include ($1.location, $2); 
	}
	
|	CONTINUE semicolon
	{
		$$ = new Jump ($1.location, Jump::CONTINUE);
	}
	
|	BREAK semicolon
	{
		$$ = new Jump ($1.location, Jump::BREAK);
	}
	
|	GOTO label semicolon
	{
		$$ = new Jump ($1.location, $2);
	}
	
|	RETURN expression semicolon %prec ATOMIC
	{
		$$ = new Return ($1.location, $2);
	}
	
|	RETURN semicolon
	{
		$$ = new Return ($1.location);
	}
	
|	IF expression scope else-block
	{
		$$ = new Conditional ($1.location, Conditional::IF, $2, $3, $4);
	}
	
|	SWITCH expression scope
	{
		$$ = new Conditional ($1.location, Conditional::SWITCH, $2, $3);
	}
	
|	WHILE expression scope
	{
		$$ = new Conditional ($1.location, Conditional::WHILE, $2, $3);
	}
	
|	DO WHILE expression scope
	{
		$$ = new Conditional ($1.location, Conditional::DO_WHILE, $3, $4);
	}
	
|	DO scope WHILE expression semicolon
	{
		$$ = new Conditional ($1.location, Conditional::DO_WHILE, $4, $2);
	}
	
|	FOR iterator scope
	{
		$$ = new For ($1.location, $2, $3);
	}
	
|	ITERATOR iterator { $$ = $2; }
	
| module { $$ = $1; }
|	line { $$ = $1; }

semicolon:
	%empty %prec EMPTY { $$ = current.token; }
|	';'

colon:
	%empty %prec EMPTY { $$ = current.token; }
|	':'

template:
	
	'[' template-parameters ']' { $$ = $2; }

template-parameters:
	
	%empty %prec EMPTY
	{
		$$ = {};
	}
	
|	template-parameters label
	{
		$$ = $1;
		$$.append ($2);
	}

label:
	
	NAME
	{
		$$.location = $1.location;
		$$.names = {};
		$$.names.append ($1.text);
	}
	
|	label '.' NAME
	{
		$$ = $1;
		$$.names.append ($3.text);
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

else-block:
	%empty { $$.valid = false; }
|	ELSE scope { $$ = Scope ($1.location, $2); }

iterator:

	'(' iterator ')' { $$ = $2; }
|	c-iterator
|	range-iterator
|	type-iterator

c-iterator:
	
	line ';' expression ';' line
	{
		$$ = new Iterator::Loop ($1->location, $1, $3, $5);
	}

range-iterator:
	
	NAME ':' range-expression
	{
		$$ = new Iterator::Range ($1.location, $1.text, $3);
	}

type-iterator:
	
	NAME ':' expression
	{
		$$ = new Iterator::Custom ($1.location, $1.text, $3);
	}

line:
	
	braced-scope
	{
		$$ = new Scope ($1);
	}
	
|	qualifiers variables semicolon
	{
		auto variables = $2;
		$$ = variables.ptr;
		
		for (int i = 0; i < variables.count; ++i)
		{
			$$ [i].qualifiers = $1;
		}
	}
	
|	template qualifiers function
	{
		auto function = $3;
		function.qualifiers = $2;
		function.templates = $1;
		
		$$ = new Function (function);
	}
	
|	expressions semicolon
	{
		$$ = $1;
	}
	
|	';' { $$ = 0; } // empty statement, dont create a symbol for this

scope:

	braced-scope
	
|	colon block ELLIPSES
	{
		$$ = Scope ($1.location, $2);
	}
|	';'
	{
		$$ = Scope ($1.location);
	}

braced-scope:
	
	'{' block '}'
	{
		$$ = Scope ($1.location, $2);
	}

enum-scope:
	
	'{' enum-block '}'
	{ $$ = Enum ($1.location, $2); }
	
|	colon enum-block ELLIPSES
	{ $$ = Enum ($1.location, $2); }
	
|	';'
	{ $$ = Enum ($1.location); }

enum-block:
	
	%empty
	{
		$$ = Enum (current.location);
	}
	
|	instances
	{
		$$ = Enum ($1[0].location, $1.ptr);
	}

module:
	
	qualifiers struct-module-union label scope
	{
		$$ = new Module ($2.location, (Module::Form) $2.integer, $3.names.back());
		$$->qualifiers = $1;
		
		// TODO: find target scope using path label
	}
	
|	qualifiers ENUM label enum-scope
	{
		$$ = new Enum ($2.location, $3.names.back(), $4);
		$$->qualifiers = $1;
		
		// TODO: find target scope using path label
	}

struct-module-union:

	STRUCT { $$ = $1; $$.integer = Module::STRUCT; }
|	MODULE { $$ = $1; $$.integer = Module::MODULE; }
|	UNION { $$ = $1; $$.integer = Module::UNION; }

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
		$$.type = $1;
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
		$$ = new <Array <Variable*>> ();
		$$->append ($1);
	}
	
|	instances ',' instance
	{
		$$ = $1;
		$$->append ($3);
	}

instance:
	
	label lengths initializer
	{
		$$ = new <Variable> ();
		$$->name = $1->names.back();
		$$->location = $1->location;
		$$->initializer = $3;
		$$->is_variadic = false;
		
		Type* type = & $$->type;
		
		for (auto length : *$2)
		{
			type->data = Type::ARRAY;
			type->array.count = length;
			
			type->array.contents = new <Type> ();
			type = type->array.contents;
		}
		
		// TODO: find target scope using path label
	}
	
|	label lengths TAIL
	{
		$$ = new <Variable> ();
		$$->name = $1->names.back();
		$$->location = $1->location;
		$$->initializer = 0;
		$$->is_variadic = true;
		
		Type* type = & $$->type;
		
		for (auto length : *$2)
		{
			type->data = Type::ARRAY;
			type->array.count = length;
			
			type->array.contents = new <Type> ();
			type = type->array.contents;
		}
		
		// TODO: find target scope using path label
	}
	
|	error { $$ = 0; }

lengths:
	%empty %prec EMPTY { $$ = new <Array <Expression*>> (); }
|	lengths length { $$ = $1; $$->append ($2); }

length:
	'[' expression ']' { $$ = $2; }

initializer:
	%empty %prec EMPTY { $$ = 0; }
|	'=' expression { $$ = $2; }

function:
	
	type label tuple scope
	{
		$$ = new <Function> ();
		
		$$->name = $2->names.back();
		$$->parameters = $3;
		$$->body = $4;
	}

tuple:
	'(' parameters-or-none ')' { $$ = $2; }

parameters-or-none:
	%empty %prec EMPTY { $$ = new <Scope> (); }
|	parameters

parameters:

	variable
	{
		$$ = new <Scope> ();
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
	}

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

indirection:
	
	%empty { $$.count = 0; }
	
|	indirection pointer
	{
		$$.pointers [$$.count] = $2;
	}

pointer:
	'~' const { $$.constness = $2; $$.c_style = false; }
|	'*' const { $$.constness = $2; $$.c_style = true; }
| '@' const { $$.constness = true; $$.c_style = false; }

const:
	%empty { $$ = false; }
|	CONST  { $$ = true; }

datatype:

	basic-type
	{
		$$ = new <Type> ();
		$$->data = Type::NUMERIC;
		$$->number = $1;
	}
	
|	tuple
	{
		$$ = new <Type> ();
		$$->data = Type::USER;
		$$->user_def.ptr = $1;
		
		// TODO: ptr should be a Symbol* not Scope*
		// construct a Symbol around tuple
	}
	
|	TYPEOF label
	{
		$$ = new <Type> ();
		$$->data = Type::META;
		$$->path = $2;
	}
	
|	label
	{
		$$ = new <Type> ();
		$$->data = Type::UNRESOLVED;
		$$->path = $1;
	}

basic-type:
	
	BIT         { $$.scalar = Type::Numeric::BIT; }
|	CHAR        { $$.scalar = Type::Numeric::CHAR; }
|	BYTE        { $$.scalar = Type::Numeric::BYTE; }
|	SHORT int   { $$.scalar = Type::Numeric::SHORT; }
|	longs int   { $$.scalar = Type::Numeric::LONG; $$.is_long = $1; }
|	INT         { $$.scalar = Type::Numeric::INT; }
|	FLOAT       { $$.scalar = Type::Numeric::FLOAT; }
|	long DOUBLE { $$.scalar = Type::Numeric::DOUBLE; $$.is_long = $1; }

longs:
	
	LONG { $$ = 0;}
|	longs LONG { $$ = 1; }

long:
	
	%empty { $$ = 0; }
|	LONG { $$ = 1; }

int:
	%empty
|	INT

expressions:

	expression %prec ','
|	expressions ',' expression
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::COMMA;
		$$->location = $1->location;
		
		$$->operands [0] = $1;
		$$->operands [1] = $3;
	}

list-expression:

	expression %prec ','
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::LIST;
		$$->location = $1->location;
		
		$$->list.append ($1);
	}
	
|	list-expression ',' expression
	{
		$$ = $1;
		$$->list.append ($3);
	}
	

expression:

	'(' expressions ')' { $$ = $2; }
|	'[' list-expression ']' { $$ = $2; }
|	value
	
|	prefix-operator expression %prec PREFIX
	{
		$$ = new <Expression> ();
		$$->opcode = $1->integer;
		$$->location = $1->location;
		
		$$->operand = $2;
	}
	
|	expression postfix-operator %prec POSTFIX
	{
		$$ = new <Expression> ();
		$$->opcode = $2->integer;
		$$->location = $1->location;
		
		$$->operand = $1;
	}
	
|	expression infix-operator expression %prec INFIX
	{
		$$ = new <Expression> ();
		$$->opcode = $2->integer;
		$$->location = $1->location;
		
		$$->operands [0] = $1;
		$$->operands [1] = $3;
	}
	
|	label arguments %prec ATOMIC
	{
		// TODO: function call OR type cast
		// note that function calls with empty arguments are matched by the variable access expression
		
		$$ = new <Expression> ();
		$$->opcode = Expression::CALL;
		$$->location = $1->location;
		
		$$->call.function.path = *$1; free ($1);
		$$->call.arguments = $2;
	}

arguments:
	
	argument %prec ','
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::LIST;
		$$->location = $1->location;
		
		$$->list.append ($1);
	}
	
|	arguments ',' argument
	{
		$$ = $1;
		$$->list.append ($3);
	}

argument:
	
	label ':' expression %prec ':'
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::ASSIGN;
		$$->location = $1->location;
		
		Expression* reference = new <Expression> ();
		reference->opcode = Expression::VARIABLE;
		reference->location = $1->location;
		reference->variable.path = *$1; free ($1);
		
		$$->operands [0] = reference;
		$$->operands [1] = $3;
	}
	
|	expression %prec EMPTY

value:
	
	label %prec NAME
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::VARIABLE;
		$$->location = $1->location;
		$$->variable.path = *$1; free ($1);
	}
	
|	const-value
	{
		$$ = new <Expression> ();
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
		$$ = new <Expression> ();
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.SIZEOF;
		$$->meta.value = $2;
	}
	
|	COUNTOF expression
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.COUNTOF;
		$$->meta.value = $2;
	}
	
|	NAMEOF expression
	{
		$$ = new <Expression> ();
		$$->opcode = Expression::META;
		$$->location = $1->location;
		$$->meta.kind = $$->meta.NAMEOF;
		$$->meta.value = $2;
	}

prefix-operator:

	'!' { $$ = $1; $1->integer = Expression::NOT; }
|	'~' { $$ = $1; $1->integer = Expression::COMPLEMENT; }
|	INCREMENT { $$ = $1; $1->integer = Expression::PRE_INCREMENT; }
|	DECREMENT { $$ = $1; $1->integer = Expression::PRE_DECREMENT; }
|	'+' { $$ = $1; $1->integer = Expression::PLUS; }
|	'-' { $$ = $1; $1->integer = Expression::MINUS; }
|	'*' { $$ = $1; $1->integer = Expression::DEREFERENCE; }
|	'&' { $$ = $1; $1->integer = Expression::ADDRESS; }

postfix-operator:

	INCREMENT %prec POSTFIX { $$ = $1; $1->integer = Expression::POST_INCREMENT; }
|	DECREMENT %prec POSTFIX { $$ = $1; $1->integer = Expression::POST_DECREMENT; }

infix-operator:

	AND { $$ = $1; $1->integer = Expression::BOTH; }
|	OR { $$ = $1; $1->integer = Expression::EITHER; }	
|	COMPARE { $$ = $1; $1->integer = Expression::EQUALS; }
|	INEQUAL { $$ = $1; $1->integer = Expression::INEQUAL; }
|	'<' { $$ = $1; $1->integer = Expression::LESS; }
| AT_MOST { $$ = $1; $1->integer = Expression::LESS_OR_EQUAL; }
| '>' { $$ = $1; $1->integer = Expression::MORE; }
| AT_LEAST { $$ = $1; $1->integer = Expression::MORE_OR_EQUAL; }
|	arithmetic
|	arithmetic '=' { $$ = $1; $1->integer += Expression::ASSIGN; }
|	'=' { $$ = $1; $1->integer = Expression::ASSIGN; }

arithmetic:

	'*' { $$ = $1; $1->integer = Expression::MULTIPLY; }
|	'/' { $$ = $1; $1->integer = Expression::DIVIDE; }
|	'%' { $$ = $1; $1->integer = Expression::MOD; }
|	'&' { $$ = $1; $1->integer = Expression::AND; }
|	'+' { $$ = $1; $1->integer = Expression::PLUS; }
|	'-' { $$ = $1; $1->integer = Expression::MINUS; }
|	'^' { $$ = $1; $1->integer = Expression::XOR; }
|	'|' { $$ = $1; $1->integer = Expression::OR; }
|	SHIFT_L { $$ = $1; $1->integer = Expression::SHIFT_LEFT; }
|	SHIFT_R { $$ = $1; $1->integer = Expression::SHIFT_RIGHT; }
|	ROTATE_L { $$ = $1; $1->integer = Expression::ROTATE_LEFT; }
|	ROTATE_R { $$ = $1; $1->integer = Expression::ROTATE_RIGHT; }

%%

/* Epilogue */

void caterror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}

CATSTYPE () {}
