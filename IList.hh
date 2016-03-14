#ifndef IList_HH
#define IList_HH

template < typename type >
class IList
{
public: 
	virtual void Add(type item, int index);
	virtual void Remove(int index);
	virtual type Get(int index);
	virtual int Size();
	virtual bool IsEmpty();
};

#endif