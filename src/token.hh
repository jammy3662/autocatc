#ifndef TOKEN_H
#define TOKEN_H

//#include "ints.h"

struct Location
{
	short line, column;
	char* source_file;
};

struct Token
{
	int kind;
	Location location;
	
	char* text;
	
	union
	{
		long long int integer;
		long double decimal;
	};
};

extern struct current
{
	char* comment = 0;
	
	Location location = {1, 1};
	Token token;
}
current;

#endif
