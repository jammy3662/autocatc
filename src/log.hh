/*
| 
|  Logging errors, warnings, and notes
| 
*/

#ifndef LOG_H
#define LOG_H

#include "token.hh"

struct Log
{
	Location location;
	char* message;
	
	enum Level
	{ NOTE, WARNING, ERROR, }
	severity;
};

#endif
