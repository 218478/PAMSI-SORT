#include <iostream>
#include "Array.hh"
#include "TimeCounter.hh"
using namespace std;

int main()
{
	int size;
	int laps;
	long * times;
	long averageTime = 0;
	
	Array *runner = new Array();
	TimeCounter *stoper = new TimeCounter();
	
	cout << "Number of elements: ";
	cin >> size;
	
	
	cout << "Laps: ";
	cin >> laps;
	times = new long[laps];
	
	for(int i = 0; i < laps; i++)
	{
		if(!runner->Prepare(size))
		{
			cout << "Can't prepare runner." << endl;
			return 0;
		}
		stoper->Start();
		if(!runner->Run())
		{
			cout << "Runner can't finish." << endl;
			return 0;
		}
		stoper->Stop();
		times[i] = stoper->GetElapsedTime();
	}
	
	for(int i = 0; i < laps; i++)
	{
		cout << "Lap " << i << " : " << times[i]/1000.0 << " s" << endl;
		averageTime += times[i];
	}
	averageTime = averageTime/laps;
	cout << "Average time: " << averageTime / 1000.0 << " s" << endl;
}