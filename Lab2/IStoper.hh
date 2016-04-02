#ifndef IStoper_HH
#define IStoper_HH

class IStoper
{
	public : virtual void Start() {};
	public : virtual void Stop() {};
	public : virtual long GetElapsedTime() {};
	public : virtual bool DumpToFile() {};
};

#endif