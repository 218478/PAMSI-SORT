#ifndef TimeCounter_HH
#define TimeCounter_HH

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <typeinfo>
#include <string>
#include <fstream>
#include "IStoper.hh"
using namespace std;

class TimeCounter : public IStoper
{
	long startTime;
	long endTime;
	long timeSpan;
	
	public : virtual void Start()
	{
		startTime = GetTime();
	}
	
	public : virtual void Stop()
	{
		endTime = GetTime();
	}
	
	public : virtual long GetElapsedTime()
	{
		if(endTime >= startTime)
		{
			return endTime-startTime;			
		}
		else
		{
			cout << "Error" << endl;
			return 0.0;
		}
	}
	
	public : virtual bool DumpToFile(std::string file_name)
	{
            std::ofstream my_file;  // strumien plikow
            file_name += ".csv";

            my_file.open(file_name.c_str(), std::fstream::app | std::fstream::out);
            try {
              my_file.exceptions(my_file.failbit);
            }
            catch(const std::ios_base::failure& ex) {
              std::cerr << "Error! Couldn't find or open a file" << ex.what()
                        << std::endl;
            }

            if (my_file.is_open()) {
              my_file << GetElapsedTime() << std::endl;
            }
            my_file.close();
            return true;
	}
	
	private : long GetTime()
	{
		 struct timeval tv;

		 gettimeofday(&tv, NULL);

		 long ret = tv.tv_usec;
		 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
		 ret /= 1000;

		 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
		 ret += (tv.tv_sec * 1000);
		 return ret;
	}
	
	private : void Reset()
	{
		startTime = 0;
		endTime = 0;
		timeSpan = 0;
	}	
};

#endif
