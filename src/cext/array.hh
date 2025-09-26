#ifndef ARRAY_DOT_H
#define ARRAY_DOT_H

#include "ints.hh"

template <typename T>
struct Array
{
	fast count = 0, available = 0;
	
	T* ptr = 0;
	
	fast append (T next); // returns # of new elements allocated
	void allocate (fast num);
	fast expand (); // allocate 50% more space (returns # new elements)
	fast shrink (); // deallocate all unused elements (returns # unused elements)
	void clear (); // deallocate all memory
	
	T pop (); // remove last element
	
	T& operator [] (fast idx) const {return ptr[idx];};
	operator T* () const {return ptr;}
	
	T& first () const;
	T& last () const;
};

#include "array.cc.hh"

#endif
