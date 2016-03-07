#include <iostream>
#include <sys/time.h>
#include <ctime>
#include "IStoper.hpp"
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
		if(endTime > startTime)
		{
			timeSpan = (endTime - startTime) / 1000.0;
			//cout << "Execute time: " << timeSpan << " s" << endl;
			return timeSpan;			
		}
		else
		{
			cout << "Error";
			return 0;
		}
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
