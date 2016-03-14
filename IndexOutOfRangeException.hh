#ifndef IndexOutOfRangeException_HH
#define IndexOutOfRangeException_HH

#include <iostream>

class IndexOutOfRangeException
{
public: 
	IndexOutOfRangeException()
	{ 
		cout << "Index Out Of Range Exception" << endl; 
	}
};

#endif