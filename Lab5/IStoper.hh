#ifndef IStoper_HH
#define IStoper_HH

#include <string>  // to deal with file names

class IStoper
{
	public : virtual void Start() = 0;
	public : virtual void Stop() = 0;
	public : virtual long GetElapsedTime() = 0;
        public : virtual bool DumpToFile(std::string file_name) = 0;
};

#endif
