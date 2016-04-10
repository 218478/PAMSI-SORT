#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
#include "ListTest.hh"
#include "QuickSortArray.hh"
#include "MergeSortArray.hh"
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
  QuickSortArray quick_sort_test;
  MergeSortArray merge_sort_test;

  data_sizes.Enqueue(10);
  data_sizes.Enqueue(100);
  data_sizes.Enqueue(1000);
  data_sizes.Enqueue(1000000);  // milion
  data_sizes.Enqueue(1000000000);  // miliard

  // for debug
  //  data_sizes.ShowQueue();

  TimeCounter *stoper = new TimeCounter();

  while (!data_sizes.IsEmpty()) {
    std::ostringstream ss_quick_sort;
    std::ostringstream ss_merge_sort;
    int rozmiar = data_sizes.Dequeue();

    // quick sort part
    ss_quick_sort << "results/QuickSort_" << rozmiar;
    stoper->Start();
    quick_sort_test.Prepare(rozmiar);
    quick_sort_test.Run();
    stoper->Stop();
    stoper->DumpToFile(ss_quick_sort.str());

    // merge sort part
    ss_merge_sort << "results/MergeSort_" << rozmiar;
    stoper->Start();
    merge_sort_test.Prepare(rozmiar);
    merge_sort_test.Run();
    stoper->Stop();
    stoper->DumpToFile(ss_merge_sort.str());
}
  return 0;
}
