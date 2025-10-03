#include <stdio.h>
#include <string.h>
#include <iostream>

#include <antlr4-runtime/antlr4-runtime.h>
#include "catLexer.h"
#include "catParser.h"
#include "catListener.h"

#include "cext/optional.hh"
#include "cext/ints.hh"

#define PROGRAM_NAME "autocatc"

int test_scanner ();
int test_parser ();
int (*test)() = test_scanner;

std::ifstream in;

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
			test = test_parser,
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
			
			in.open (argv[i], std::ios_base::in);
			
			if (no in or not in.is_open())
			{
				fprintf (stderr, "File couldn't open (%s)\n", argv[i]);
				return 1;
			}
			
			test ();
		}
	}
	if (zero files_input)
	{
		printf (PROGRAM_NAME " - Reading from standard input\n");
		return test();
	}
	
	return 0;
}

antlr4::ANTLRInputStream antlrInput ()
{
	using namespace antlr4;
	
	ANTLRInputStream input;
	
	printf ("Okay...\n");
	
	if (in.is_open())
	
		printf ("Opened input file.\n"),
		input.load (in),
		printf ("Opened ANTLR input stream.\n");
	
	else
	
		printf ("Defaulting to stdin for input,,,\n"),
		input.load (std::cin);
	
	return input;
}

int test_scanner()
{
	int result;
	
	using namespace antlr4;
	
	ANTLRInputStream input = antlrInput ();
	
	catLexer lexer (&input);
	CommonTokenStream tokens (&lexer);
	
	tokens.fill ();
	
	for (auto token: tokens.getTokens())
	{
		printf ("%s\n", token->getText().c_str());
	}
	
	
	return result;
}

int test_parser ()
{
	int result;
	
	using namespace antlr4;
	
	ANTLRInputStream input = antlrInput ();
	
	catLexer lexer (&input);
	CommonTokenStream tokens (&lexer);
	catParser parser (&tokens);
	
	
	tree::ParseTree* tree = parser.block ();
	
	printf ("%s\n", tree->toStringTree (&parser, true).c_str ());
	
	return result;
}
