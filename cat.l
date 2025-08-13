%option header-file="lex.yy.h"

%{

#include "token.h"
#include "cat.tab.h"

struct current current;

#define remove_quotes false

void advance()
{
	current.location.column += strlen (yytext);
	current.token.location = current.location;
}

#define copy_yy(ID) ID = yytext
#define copy_yy_current copy_yy(current.token.text)

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

"(" { advance(); copy_yy_current; return ('('); }
")" { advance(); copy_yy_current; return (')'); }
"[" { advance(); copy_yy_current; return ('['); }
"]" { advance(); copy_yy_current; return (']'); }
"{" { advance(); copy_yy_current; return ('{'); }
"}" { advance(); copy_yy_current; return ('}'); }

"!" { advance(); copy_yy_current; return ('!'); }
"#" { advance(); copy_yy_current; return ('#'); }
"$" { advance(); copy_yy_current; return ('$'); }
"%" { advance(); copy_yy_current; return ('%'); }
"&" { advance(); copy_yy_current; return ('&'); }
"*" { advance(); copy_yy_current; return ('*'); }
"+" { advance(); copy_yy_current; return ('+'); }
"," { advance(); copy_yy_current; return (','); }
"-" { advance(); copy_yy_current; return ('-'); }
"." { advance(); copy_yy_current; return ('.'); }
"/" { advance(); copy_yy_current; return ('/'); }
":" { advance(); copy_yy_current; return (':'); }
";" { advance(); copy_yy_current; return (';'); }
"<" { advance(); copy_yy_current; return ('<'); }
">" { advance(); copy_yy_current; return ('>'); }
"=" { advance(); copy_yy_current; return ('='); }
"?" { advance(); copy_yy_current; return ('?'); }
"@" { advance(); copy_yy_current; return ('@'); }
"^" { advance(); copy_yy_current; return ('^'); }
"_" { advance(); copy_yy_current; return ('_'); }
"|" { advance(); copy_yy_current; return ('|'); }
"~" { advance(); copy_yy_current; return ('~'); }

"&&" { advance(); copy_yy_current; return (AND); }
"||" { advance(); copy_yy_current; return (OR); }
"++" { advance(); copy_yy_current; return (INCREMENT); }
"--" { advance(); copy_yy_current; return (DECREMENT); }
"<<" { advance(); copy_yy_current; return (SHIFT_L); }
">>" { advance(); copy_yy_current; return (SHIFT_R); }
"==" { advance(); copy_yy_current; return (COMPARE); }
"!=" { advance(); copy_yy_current; return (INEQUAL); }
"<=" { advance(); copy_yy_current; return (AT_MOST); }
">=" { advance(); copy_yy_current; return (AT_LEAST); }

"<<<" { advance(); copy_yy_current; return (ROTATE_L); }
">>>" { advance(); copy_yy_current; return (ROTATE_R); }

".."  { advance(); copy_yy_current; return (TAIL); }
"..." { advance(); copy_yy_current; return (ELLIPSES); }

"include"	{ advance(); copy_yy_current; return (INCLUDE); }
"inline"	{ advance(); copy_yy_current; return (INLINE); }
"extern"	{ advance(); copy_yy_current; return (EXTERN); }

"sizeof"	{ advance(); copy_yy_current; return (SIZEOF); }
"countof"	{ advance(); copy_yy_current; return (COUNTOF); }
"nameof"	{ advance(); copy_yy_current; return (NAMEOF); }
"typeof"	{ advance(); copy_yy_current; return (TYPEOF); }

"local"		{ advance(); copy_yy_current; return (LOCAL); }
"static"	{ advance(); copy_yy_current; return (STATIC); }
"const"		{ advance(); copy_yy_current; return (CONST); }

"signed"		{ advance(); copy_yy_current; return (SIGNED); }
"unsigned"	{ advance(); copy_yy_current; return (UNSIGNED); }
"complex"		{ advance(); copy_yy_current; return (COMPLEX); }
"imaginary"	{ advance(); copy_yy_current; return (IMAGINARY); }
"long"			{ advance(); copy_yy_current; return (LONG); }
"double"		{ advance(); copy_yy_current; return (DOUBLE); }

"bit"		{ advance(); copy_yy_current; return (BIT); }
"char"	{ advance(); copy_yy_current; return (CHAR); }
"byte"	{ advance(); copy_yy_current; return (BYTE); }
"short"	{ advance(); copy_yy_current; return (SHORT); }
"int"		{ advance(); copy_yy_current; return (INT); }
"float"	{ advance(); copy_yy_current; return (FLOAT); }

"break"			{ advance(); copy_yy_current; return (BREAK); }
"continue"	{ advance(); copy_yy_current; return (CONTINUE); }
"return"		{ advance(); copy_yy_current; return (RETURN); }
"goto"			{ advance(); copy_yy_current; return (GOTO); }

"while"	{ advance(); copy_yy_current; return (WHILE); }
"do"		{ advance(); copy_yy_current; return (DO); }
"for"		{ advance(); copy_yy_current; return (FOR); }

"if"			{ advance(); copy_yy_current; return (IF); }
"else"		{ advance(); copy_yy_current; return (ELSE); }
"switch"	{ advance(); copy_yy_current; return (SWITCH); }
"case"		{ advance(); copy_yy_current; return (CASE); }
"default"	{ advance(); copy_yy_current; return (DEFAULT); }

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
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0[\`_0-9]* {
	
	// octal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0?[xX][\`_0-9a-fA-F]* {
	
	// hexadecimal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0?[bB][\`_0-9]* {
	
	// binary constant
	advance();
	
	remove_characters (text, 'b','B','_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text, 0, 2);
	return (CONST_INT);
}

([+-]?([0-9][\`_0-9]*)?\.[0-9][\`_0-9]*[fF]?)|([+-]?[1-9][\`_0-9][fF]?) {
	
	// TODO modify regex to support scientific notation
	// decimal constant
	advance();
	
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.decimal = std::stold (text);
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
