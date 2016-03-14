#include <iostream>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
#include "Stack.hh"
using namespace std;

int main()
{
	/*int size;
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
	
	cout << "Runner size: " << runner->GetNumberOfElements() << endl;*/
	
	Stack<int> *myStack = new Stack<int>();
	
	cout << "Is empty? " << myStack->IsEmpty() << endl;
	cout << "Elements : " << myStack->Size() << endl;
	
	for(int i = 0; i < 5; i++)
	{
		myStack->Push(i);
		cout << "Pushed: " << myStack->Top() << endl;
	}
	cout << "Is empty? " << myStack->IsEmpty() << endl;
	cout << "Elements : " << myStack->Size() << endl;
	
	for(int i = 0; i < 7; i++)
	{
		cout << "Poped: " << myStack->Pop() << endl;
	}
	cout << "Is empty? " << myStack->IsEmpty() << endl;
	cout << "Elements : " << myStack->Size() << endl;
	
}