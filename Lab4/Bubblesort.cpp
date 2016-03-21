#include <iostream>
#include <cstdlib>
//#include <Array.hh>
using namespace std;

class Bubblesort
{
private :
	//int * Array<int> sortArray;
	int *array;
	
public :
	//int* Sort(Array<int> arrayToSort, int size)
	int* Sort(int arrayToSort[], int size)
	{
		/*for(int i = 0; i < size; i++)
		{
			sortArray->Add(arrayToSort->Get(i));
		}*/
		
		array = arrayToSort;
		int n = size;
		for(int i = n; i > 1; i--)
		{
			for(int j = 0; j < i-1; j++)
			{
				//if(sortArray->Get(j) > sortArray->Get(j+1))
				if(array[j] > array[j+1])
				{
					Swap(j,j+1);
				}
			}
		}
		return array;
	}
	
	void Swap(int index1, int index2)
	{
		int tempValue = array[index1];
		array[index1] = array[index2];
		array[index2] = tempValue;
		
		/*int tempValue = sortArray->Get(index1);
		sortArray->Set(sortArrat->Get(index2), index1);
		sortArray->Set(tempValue,index2);*/
	}
};

int main()
{
	Bubblesort *bubbleSorter = new Bubblesort();
	int size = 20;	
	
	srand(time(NULL));
	
	int *tab = new int[size];
	for(int i = 0; i < size; i++)
	{
		tab[i] = rand() % size;
	}
	
	cout << endl <<"Before sort: ";
	for(int i =0; i <size; i++)
	{
		cout << tab[i] << ",";
	}
	
	tab = bubbleSorter->Sort(tab, size);
	
	cout << endl << endl << "After sort: ";
	for(int i =0; i < size; i++)
	{
		cout << tab[i] << ",";
	}
	cout << endl << endl;
}