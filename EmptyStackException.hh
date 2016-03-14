#ifndef EmptyStackException_HH
#define EmptyStackException_HH

#include <iostream>

class EmptyStackException
{
public: 
	EmptyStackException(){ cout << "EmptyStackException" << endl; }
};

#endif