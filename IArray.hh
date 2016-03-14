#ifndef IArray_HH
#define IArray_HH

template < typename type >
class IArray
{
public: 
	virtual void Add(type item) = 0;
	virtual type Get() {};
};

#endif