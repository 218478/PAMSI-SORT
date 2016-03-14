#ifndef IList_HH
#define IList_HH

template < typename type >
class IList
{
public: 
	virtual void Add(type item, int index) throw(IndexOutOfRangeException) = 0;
	virtual void Remove(int index) throw(IndexOutOfRangeException) = 0;
	virtual type Get(int index) throw(IndexOutOfRangeException) = 0;
	virtual int Size() = 0;
	virtual bool IsEmpty() = 0;
};

#endif