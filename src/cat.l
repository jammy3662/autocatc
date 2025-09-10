%option prefix="cat"
%option header-file="cat.h"

%{

#include "token.hh"
#include "cat.tab.h"

struct current current;

#define remove_quotes false

void advance()
{
	current.token.location = current.location;
	current.location.column += strlen (yytext);
	current.token.text = yytext;
}

// return value and also store in current.context 
#define return(_) current.token.kind = _; return _;

// remove cat-format characters
#define remove_characters(RESULT, ...) \
\
	char* RESULT = (char*) malloc (strlen (yytext) * sizeof (char)); \
\
{ \
	char to_remove[] = {__VA_ARGS__}; \
\
	char* c = yytext; \
	for (; nonzero *c; ++c) \
	{ \
		for (char ch_rm : to_remove) if (*c is ch_rm) continue; \
\
		RESULT [c-yytext] = *c; \
	} \
	RESULT [c-yytext] = 0; \
}

%}

%%

"(" { advance(); return ('('); }
")" { advance(); return (')'); }
"[" { advance(); return ('['); }
"]" { advance(); return (']'); }
"{" { advance(); return ('{'); }
"}" { advance(); return ('}'); }

"!" { advance(); return ('!'); }
"#" { advance(); return ('#'); }
"$" { advance(); return ('$'); }
"%" { advance(); return ('%'); }
"&" { advance(); return ('&'); }
"*" { advance(); return ('*'); }
"+" { advance(); return ('+'); }
"," { advance(); return (','); }
"-" { advance(); return ('-'); }
"." { advance(); return ('.'); }
"/" { advance(); return ('/'); }
":" { advance(); return (':'); }
";" { advance(); return (';'); }
"<" { advance(); return ('<'); }
">" { advance(); return ('>'); }
"=" { advance(); return ('='); }
"?" { advance(); return ('?'); }
"@" { advance(); return ('@'); }
"^" { advance(); return ('^'); }
"_" { advance(); return ('_'); }
"|" { advance(); return ('|'); }
"~" { advance(); return ('~'); }

"&&" { advance(); return (AND); }
"||" { advance(); return (OR); }
"++" { advance(); return (INCREMENT); }
"--" { advance(); return (DECREMENT); }
"<<" { advance(); return (SHIFT_L); }
">>" { advance(); return (SHIFT_R); }
"==" { advance(); return (COMPARE); }
"!=" { advance(); return (INEQUAL); }
"<=" { advance(); return (AT_MOST); }
">=" { advance(); return (AT_LEAST); }

"<<<" { advance(); return (ROTATE_L); }
">>>" { advance(); return (ROTATE_R); }

".."  { advance(); return (TAIL); }
"..." { advance(); return (ELLIPSES); }

"alias" { advance(); return (ALIAS); }

"include"	{ advance(); return (INCLUDE); }
"inline"	{ advance(); return (INLINE); }
"extern"	{ advance(); return (EXTERN); }

"sizeof"	{ advance(); return (SIZEOF); }
"countof"	{ advance(); return (COUNTOF); }
"nameof"	{ advance(); return (NAMEOF); }
"typeof"	{ advance(); return (TYPEOF); }

"local"		{ advance(); return (LOCAL); }
"static"	{ advance(); return (STATIC); }
"const"		{ advance(); return (CONST); }

"struct"	{ advance(); return (STRUCT); }
"module"	{ advance(); return (MODULE); }
"union"	{ advance(); return (UNION); }
"enum"	{ advance(); return (ENUM); }

"signed"		{ advance(); return (SIGNED); }
"unsigned"	{ advance(); return (UNSIGNED); }
"complex"		{ advance(); return (COMPLEX); }
"imaginary"	{ advance(); return (IMAGINARY); }
"long"			{ advance(); return (LONG); }
"double"		{ advance(); return (DOUBLE); }

"bit"		{ advance(); return (BIT); }
"char"	{ advance(); return (CHAR); }
"byte"	{ advance(); return (BYTE); }
"short"	{ advance(); return (SHORT); }
"int"		{ advance(); return (INT); }
"float"	{ advance(); return (FLOAT); }

"break"			{ advance(); return (BREAK); }
"continue"	{ advance(); return (CONTINUE); }
"return"		{ advance(); return (RETURN); }
"goto"			{ advance(); return (GOTO); }

"while"	{ advance(); return (WHILE); }
"do"		{ advance(); return (DO); }
"for"		{ advance(); return (FOR); }

"if"			{ advance(); return (IF); }
"else"		{ advance(); return (ELSE); }
"switch"	{ advance(); return (SWITCH); }
"case"		{ advance(); return (CASE); }
"default"	{ advance(); return (DEFAULT); }

[_a-zA-Z][\`_a-zA-Z0-9]* {
	
	// name / identifier
	advance();
	
	remove_characters (text, '`');
	
	current.token.text = text;
	return (NAME);
}

[+-]?[1-9][\`_0-9] {
	
	// integer constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::strtoll (text, 0, 10);
	return (CONST_INT);
}

[+-]?0[\`_0-9]* {
	
	// octal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::strtoll (text, 0, 8);
	return (CONST_INT);
}

[+-]?0?[xX][\`_0-9a-fA-F]* {
	
	// hexadecimal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::strtoll (text, 0, 16);
	return (CONST_INT);
}

[+-]?0?[bB][\`_0-9]* {
	
	// binary constant
	advance();
	
	remove_characters (text, 'b','B','_','`');
	
	current.token.text = text;
	current.token.integer = std::strtoll (text, 0, 2);
	return (CONST_INT);
}

([+-]?([0-9][\`_0-9]*)?\.[0-9][\`_0-9]*[fF]?)|([+-]?[1-9][\`_0-9][fF]?) {
	
	// TODO modify regex to support scientific notation
	// decimal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.decimal = std::strtold (text, 0);
	return (CONST_FLOAT);
}

L?\'(\\.|[^\\"])*\' {
	
	// (multi-)character constant
	advance();
	
	fast len = strlen (yytext);
	char* text = (char*) malloc (len * sizeof (char));
	
	if (remove_quotes)
		strncpy (text, yytext + 1, len-2);
	else
		strcpy (text, yytext);
	
	current.token.text = text;
	return (CONST_CHAR);
}

L?\"(\\.|[^\\"])*\" {
	
	// string constant
	advance();
	
	fast len = strlen (yytext);
	char* text = (char*) malloc (len * sizeof (char));
	
	if (remove_quotes)
		strncpy (text, yytext + 1, len-2);
	else
		strcpy (text, yytext);
	
	current.token.text = text;
	return (CONST_STRING);
}

\/\/.* {
	
	// line comment
	advance();
	
	current.comment = yytext;
	current.token.text = yytext;
	
	return (COMMENT_LINE);
}

\/\*(.|[\n\t\r\v])*?\*\/ {
	
	// open block comment
	
	current.comment = yytext;
	current.token.text = yytext;
	current.token.location = current.location;
	
	char* cur = yytext;
	for (; nonzero *cur; ++cur)
	{
		if (*cur is '\n' or *cur is '\v')
			current.location.line += 1,
			current.location.column = 1;
		else
			current.location.column += 1;
	}
	
	return (COMMENT_BLOCK);
}

\n {
	current.location.line++;
	current.location.column = 1;
}

. { current.location.column++; }

%%

int yywrap ()
{
	return (-1);
}
