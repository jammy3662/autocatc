#include <stdio.h>
#include <string.h>

#include "catLexer.h"
#include "catParser.h"
#include "catListener.h"

#include "cext/ints.hh"

#define PROGRAM_NAME "autocatc"

int test_scanner();
int (*test)() = test_scanner;

FILE* in = stdin;

int main (int argc, char** argv)
{
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
			//test = catparse,
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
			
			in = fopen (argv[i], "r");
			
			if (no in)
			{
				fprintf (stderr, "File couldn't open (%s)\n", argv[i]);
				return 1;
			}
			
			printf ("-- Parsing '%s' --\n", argv[i]);
			test();
		}
	}
	if (zero files_input)
	{
		in = stdin;
		printf (PROGRAM_NAME " - Reading from standard input\n");
		return test();
	}
	
	return 0;
}

int test_scanner()
{
	int result;
	
	// TODO: visit the parse tree
	
	if (in isnt stdin) fclose (in);
	
	return result;
}
