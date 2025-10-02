#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "ints.hh"

template <typename T>
struct opt
{
	T value;
	byte valid;
	
	T operator = (T Value)
	{ valid = true; return (value = Value); }
	
	bool operator ! ()
	{ return not valid; }
	
	operator T& () const
	{ return value; }
};

#endif
