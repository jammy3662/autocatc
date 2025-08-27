#include <stdio.h>
#include <string.h>

#include "lex.yy.h"
#include "cat.tab.h"
#include "token.h"
#include "ints.h"

#define PROGRAM_NAME "autocatc"

extern int yydebug;

int test_scanner();
int (*test)() = test_scanner;

int main (int argc, char** argv)
{
	yydebug = 1;
	
	yyin = stdin;
	
	enum Arg {FILE, FLAG};
	Arg inputs [argc];
	
	for (int i = 0; i < argc; ++i)
	{
		if (zero strcmp (argv[i], "--help"))
		{
			printf (PROGRAM_NAME " [--help | SRC_FILE1 SRC_FILE2 ...]\n"
							"SRC_FILE defaults to standard input\n");
			return 0;
		}
		else
		if (zero strcmp (argv[i], "scan"))
			test = test_scanner,
			inputs [i] = FLAG;
		else
		if (zero strcmp (argv[i], "parse"))
			test = yyparse,
			inputs [i] = FLAG;
		else
			inputs [i] = FILE;
	}
	
	if (argc > 1)
	{
		for (int i = 1; i <	argc; ++i)
		{
			if (inputs [i] isnt FILE) continue;
			
			yyin = fopen (argv[i], "r");
			
			if (!yyin)
			{
				fprintf (stderr, "File couldn't open (%s)\n", argv[i]);
				return 1;
			}
			
			current.location.source_file = argv[i];
			printf ("-- Parsing '%s' --\n", argv[i]);
			test();
		}
	}
	else
	{
		yyin = stdin;
		current.location.source_file = "stdin";
		printf (PROGRAM_NAME " - Reading from standard input\n");
		return test();
	}
	
	return 0;
}

int test_scanner()
{
	int result;
	
	do
	{
		result = yylex();
		auto text = current.token.text;
		
		if (result is 0) continue;
		switch (current.token.kind) {
			case COMMENT_LINE...COMMENT_BLOCK: continue; default: break; }
		
		printf ("%s\t\t\t%i (%s:%i:%i)\n", text, result, current.location.source_file, current.token.location.line, current.token.location.column);
	}
	while (nonzero result);
	
	if (yyin isnt stdin) fclose (yyin);
	
	return result;
}
