#include <stdio.h>
#include <string.h>

#include "cat.h"
#include "cat.tab.h"
#include "token.h"
#include "ints.h"

#define PROGRAM_NAME "autocatc"

extern int catdebug;

int test_scanner();
int (*test)() = test_scanner;

int main (int argc, char** argv)
{
	catdebug = 1;
	
	catin = stdin;
	
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
			test = catparse,
			inputs [i] = FLAG;
		else
			inputs [i] = FILE;
	}
	
	bool files_input = false;
	
	if (argc > 1)
	{
		for (int i = 1; i <	argc; ++i)
		{
			if (inputs [i] isnt FILE) continue;
			else files_input = true;
			
			catin = fopen (argv[i], "r");
			
			if (!catin)
			{
				fprintf (stderr, "File couldn't open (%s)\n", argv[i]);
				return 1;
			}
			
			current.location.source_file = argv[i];
			printf ("-- Parsing '%s' --\n", argv[i]);
			test();
		}
	}
	if (not files_input)
	{
		catin = stdin;
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
		result = catlex();
		auto text = current.token.text;
		
		if (result is 0) continue;
		switch (current.token.kind) {
			case COMMENT_LINE...COMMENT_BLOCK: continue; default: break; }
		
		printf ("%s\t\t\t%i (%s:%i:%i)\n", text, result, current.location.source_file, current.token.location.line, current.token.location.column);
	}
	while (nonzero result);
	
	if (catin isnt stdin) fclose (catin);
	
	return result;
}
