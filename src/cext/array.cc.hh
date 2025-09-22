#ifndef CONTAINER_DOT_H_HEADER_ONLY
#ifndef CONTAINER_DOT_H_IMPL
#define CONTAINER_DOT_H_IMPL

#include "array.hh"

#include <stdlib.h>
#include <string.h>

#define no !

fast roundNearest (float f)
{
	return (fast) (f + 0.5);
}

template <typename T>
void Array<T>::allocate (fast n)
{
	clear ();
	count = 0;
	available = n;
	ptr = (T*) realloc (ptr, n * sizeof(T));
	memset (ptr, 0, n *	sizeof (T));
}

template <typename T>
fast Array<T>::expand ()
{
	if (not available) allocate (1);
	
	fast prev = available;
	// add 50% size of the current used elements
	available = roundNearest ((float)available * 1.5);
	
	if (no ptr) allocate (1);
	
	T* oldptr = ptr;
	ptr = (T*) realloc (ptr, available * sizeof(T));
	if (ptr == 0)
	{
		fprintf (stderr, "Out of memory\n");
		return 0;
	}
	memset (oldptr, 0, (oldptr - ptr) * sizeof(T));
	
	return available - prev;
}

template <typename T>
fast Array<T>::append (T next)
{
	fast added;
	
	if (count >= available)
		added = expand ();
	else if (available - count > (available/3))
		shrink ();
	
	ptr [count] = next;
	
	count++;
	return added;
}

template <typename T>
fast Array<T>::shrink ()
{
	fast unused = available - count;
	ptr = (T*) realloc (ptr, count * sizeof(T));
	available = count;
	return unused;
}

template <typename T>
void Array<T>::clear ()
{
	if (no ptr) return;
	
	free (ptr);
	
	*this = {};
}

template <typename T>
T& Array<T>::front () const
{
	return ptr [0];
}

template <typename T>
T& Array<T>::back () const
{
	return ptr [count-1];
}

#endif
#endif
