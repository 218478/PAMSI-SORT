#ifndef IQueue_HH
#define IQueue_HH

template < typename type >
class IQueue
{	
public: 
	virtual void Enqueue(type item);
	virtual type Dequeue()
				throw(EmptyQueueException);
	virtual type Front();
				throw(EmptyQueueException);
	virtual int Size();
	virtual bool IsEmpty();
};

#endif