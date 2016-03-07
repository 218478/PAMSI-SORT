#include <iostream>
#include "IRunnable.hpp"
#include "IStoper.hpp"
using namespace std;

int main()
{
	int size;
	IRunnable runner = new Array();
	IStoper stoper = new TimeCounter();
	
	cout << "Number of elements: ";
	cin >> size;
	
	if(!runner.Prepare(size))
	{
		cout << "Can't prepare runner." << endl;
		return 0;
	}
	
	stoper.Start();
	if(!runner.Run())
	{
		cout << "Runner can't finish." << endl;
		return 0;
	}
	stoper.Stop();
	
	cout << "Execution time: " << stoper.GetElapsedTime() << " s" << endl;
}