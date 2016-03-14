#ifndef IStack_HH
#define IStack_HH

template < typename type >
class IStack
{
public: 
	virtual void Push(type item) = 0;
	virtual type Pop() /*throw(EmptyStackException)*/ = 0;
	virtual type Top() /*throw(EmptyStackException)*/ = 0;
	virtual int Size() = 0;
	virtual bool IsEmpty() = 0;
};

#endif