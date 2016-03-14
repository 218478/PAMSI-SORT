#ifndef IQueue_HH
#define IQueue_HH

template < typename type >
class IQueue
{	
public: 
	virtual void Enqueue(type item) = 0;
	virtual type Dequeue() throw(EmptyQueueException) = 0;
	virtual type Front() throw(EmptyQueueException) = 0;
	virtual int Size() = 0;
	virtual bool IsEmpty() = 0;
};

#endif