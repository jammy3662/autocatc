#ifndef TOKEN_H
#define TOKEN_H

//#include "ints.h"

struct Location
{
	short line = 1, column = 1;
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
	
	Location location;
	Token token;
}
current;

#endif
