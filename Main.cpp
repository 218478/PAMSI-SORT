#include <iostream>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
using namespace std;

int main()
{
	int size;
	int laps = 10;
	long * times = new long[laps];;
	long averageTime = 0;
	
	ArrayRunner *runner = new ArrayRunner();
	TimeCounter *stoper = new TimeCounter();
	
	cout << "Number of elements: ";
	cin >> size;
	
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
		cout << "Lap " << (i+1) << " : " << times[i]/1000.0 << " s" << endl;
		averageTime += times[i];
	}
	averageTime = averageTime/laps;
	cout << "Average time: " << averageTime / 1000.0 << " s" << endl;
}