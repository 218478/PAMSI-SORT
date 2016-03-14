#ifndef IStack_HH
#define IStack_HH

template < typename type >
class IStack
{
public: 
	virtual void Push(type item);
	virtual type Pop() 
				throw(EmptyStackException);
	virtual type Top()
				throw(EmptyStackException);
	virtual int Size();
	virtual bool IsEmpty();
};

#endif