#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
#include "ListTest.hh"
#include "QuickSortArray.hh"
#include "Queue.hh"

using namespace std;

int main()
{
	// int size;
	// int laps = 10;
	// long * times = new long[laps];;
	// long averageTime = 0;
	
	// cout << "Number of elements: ";
	// cin >> size;
	
	// string myString[size];
	
	// ifstream file("words.txt");
	// for(int i = 0; i < size; i++)
	// {
	// 	file >> myString[i];
	// }
	
	// ListTest *runner = new ListTest(myString);
	// TimeCounter *stoper = new TimeCounter();

	// if(!runner->Prepare(size))
	// {
	// 	cout << "Can't prepare runner." << endl;
	// 	return 0;
	// }
	// srand(time(NULL));	
	// for(int i = 0; i < laps; i++)
	// {
	// 	stoper->Start();
	// 	string wordToFind = myString[rand() % size];
	// 	cout << "Finding word " << wordToFind << endl;
	// 	if(!runner->Run(wordToFind))
	// 	{
	// 		cout << "Runner can't finish." << endl;
	// 		return 0;
	// 	}
	// 	stoper->Stop();
	// 	times[i] = stoper->GetElapsedTime();
	// }
	
	// for(int i = 0; i < laps; i++)
	// {
	// 	cout << "Lap " << (i+1) << " : " << times[i]/1000.0 << " s" << endl;
	// 	averageTime += times[i];
	// }
	// averageTime = averageTime/laps;
	// cout << "Average time: " << averageTime / 1000.0 << " s" << endl;
	
	// //cout << "Runner size: " << runner->GetNumberOfElements() << endl;

  Queue<int> data_sizes;
  QuickSortArray tested_element;
  data_sizes.Enqueue(10);
  data_sizes.Enqueue(100);
  data_sizes.Enqueue(1000);
  data_sizes.Enqueue(1000000);  // milion
  data_sizes.Enqueue(1000000000);  // miliard

  data_sizes.ShowQueue();

  TimeCounter *stoper = new TimeCounter();

  
  while (!data_sizes.IsEmpty()) {
    int rozmiar = data_sizes.Dequeue();
    stoper->Start();
    tested_element.Prepare(rozmiar);
    tested_element.Run();
    stoper->Stop();
    std::cout << "Czas dla " << rozmiar << "-elementow to: "
              << stoper->GetElapsedTime() << std::endl;
  }
}
