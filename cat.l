%option header-file="lex.yy.h"

%{

#include "token.h"
#include "cat.tab.h"

typedef std::string string;

// return value and also store in current context 
#define return(_) current.token.kind = _; return _;

// remove cat-format characters
#define remove_characters(RESULT, ...) \
\
	string str = yytext; \
\
	char to_remove[] = {__VA_ARGS__}; \
\
	for (char c : to_remove) \
	{ \
		auto position = str.find (c); \
		while (position isnt string::npos) \
			str.erase (position); \
	} \
	char* RESULT = (char*) str.c_str();

%}

%%

"!" { return ('!'); }
"#" { return ('#'); }
"$" { return ('$'); }
"%" { return ('%'); }
"&" { return ('&'); }
"*" { return ('*'); }
"+" { return ('+'); }
"," { return (','); }
"-" { return ('-'); }
"." { return ('.'); }
"/" { return ('/'); }
":" { return (':'); }
";" { return (';'); }
"<" { return ('<'); }
">" { return ('>'); }
"=" { return ('='); }
"?" { return ('?'); }
"@" { return ('@'); }
"^" { return ('^'); }
"_" { return ('_'); }
"|" { return ('|'); }
"~" { return ('~'); }

"&&" { return (AND); }
"||" { return (OR); }
"++" { return (INCREMENT); }
"--" { return (DECREMENT); }
"<<" { return (SHIFT_L); }
">>" { return (SHIFT_R); }
"==" { return (COMPARE); }

"<<<" { return (ROTATE_L); }
">>>" { return (ROTATE_R); }

".."  { return (TAIL); }
"..." { return (ELLIPSES); }

[_a-zA-Z][\`_a-zA-Z0-9]* {
	
	// name / identifier
	remove_characters (text, '`');
	
	current.token.text = text;
	return (NAME);
}

[+-]?[1-9][\`_0-9] {
	
	// integer constant
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0[\`_0-9]* {
	
	// octal constant
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0?[xX][\`_0-9a-fA-F]* {
	
	// hexadecimal constant
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text);
	return (CONST_INT);
}

[+-]?0?[bB][\`_0-9]* {
	
	// binary constant
	remove_characters (text, 'b','B','_','`');
	
	current.token.text = text;
	current.token.integer = std::stoll (text, 0, 2);
	return (CONST_INT);
}

([+-]?([0-9][\`_0-9]*)?\.[0-9][\`_0-9]*[fF]?)|([+-]?[1-9][\`_0-9][fF]?)  {
	
	// TODO modify regex to support scientific notation
	// decimal constant
	remove_characters (text, '_','`');
	
	current.token.text = text;
	current.token.decimal = std::stold (text);
	return (CONST_FLOAT);
}

L?\'(\\.|[^\\"])*\' {
	
	// (multi-)character constant
	string str = yytext;
	
	// remove the delimiting quotes
	str.erase (0);
	str.erase (str.size()-1);
	char* text = (char*) str.c_str();
	
	current.token.text = text;
	return (CONST_CHAR);
}

L?\"(\\.|[^\\"])*\" {
	
	// string constant
	string str = yytext;
	
	// remove the delimiting quotes
	str.erase (0);
	str.erase (str.size()-1);
	char* text = (char*) str.c_str();
	
	current.token.text = text;
	return (CONST_STRING);
}

\/\/(.*)\n {
	
	// line comment
	if (current.line_comment or
	    current.block_comment_depth > 0)
		// last line was a comment too, add onto that
		current.comment << yytext;
	else
	{
		// start a new line comment
		current.line_comment = true;
		current.comment.str("");
		current.comment << yytext;
	}
	
	// not the return() macro because
	// we don't want comments to replace the earlier token
	return COMMENT_LINE;
}

\/\* {
	
	// open block comment
	current.block_comment_depth += 1;
}

\*\/ {
	
	// close block comment
	if (current.block_comment_depth > 0)
	
		current.block_comment_depth -= 1;
	
	else
		
		// TODO: some kind of error
		fprintf (stderr, "closing block comment unmatched\n");
}

\n {
	
	// newline (escaped AND unescaped)
	current.token.location.line++;
}

%%
