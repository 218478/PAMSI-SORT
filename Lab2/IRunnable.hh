#ifndef IRunnable_HH
#define IRunnable_HH

class IRunnable
{
	public : int Size;
	
	public : virtual bool Prepare(int size) {};
	public : virtual bool Run() {};
};

#endif