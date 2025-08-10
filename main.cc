#include <stdio.h>
#include <string.h>

#include "ints.h"
#include "lex.yy.h"
#include "cat.tab.h"

#define PROGRAM_NAME "autocatc"

extern int yydebug;

int main (int argc, char** argv)
{
	yydebug = 1;
	
	yyin = stdin;
	
	for (int i = 0; i < argc; ++i)
	{
		if (!strcmp(argv[i], "--help"))
		{
			printf (PROGRAM_NAME " [--help | SRC_FILE1 SRC_FILE2 ...]\n"
							"SRC_FILE defaults to standard input\n");
			return 0;
		} 
	}
	
	if (argc > 1)
	{
		for (int i = 1; i <	argc; ++i)
		{
			yyin = fopen (argv[i], "r");
			if (!yyin)
			{
				fprintf (stderr, "File couldn't open (%s)\n", argv[i]);
				return 1;
			}
			printf ("-- Parsing '%s' --\n", argv[i]);
		}
	}
	else
	{
		yyin = stdin;
		printf (PROGRAM_NAME " - Reading from standard input\n");
	}
	
	int parse = yyparse ();
	
	if (yyin isnt stdin) fclose (yyin);
	
	return parse;
}
