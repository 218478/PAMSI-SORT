#ifndef IList_HH
#define IList_HH

template < typename type >
class IList
{
public: 
	virtual void Add(type item, int index)
				throw(IndexOutOfRangeException);
	virtual void Remove(int index)
				throw(IndexOutOfRangeException);
	virtual type Get(int index)
				throw(IndexOutOfRangeException);
	virtual int Size();
	virtual bool IsEmpty();
};

#endif