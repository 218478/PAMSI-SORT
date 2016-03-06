#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <ctime>
using namespace std;

enum ExpandingType
{
	by_one,
	two_times,
	by_hundred
};

long GetTime()
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

class Array
{
	long int arraySize;
	long int numberOfElements;
	int * array;
	int * ptr;

	public : Array()
	{
		numberOfElements = 0;
		arraySize = 10;
		array = new int[arraySize];
		ptr = array;
	}
	
	public : ~Array()
	{
		delete [] array;
	}


	private : void Add1(int value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize++;
			int * tempArray = new int[arraySize];
			for(int i = 0; i < arraySize-1; i++)
			{
				tempArray[i] = array[i];
			}
			tempArray[arraySize-1] = value;
			delete [] array;
			array = tempArray;
			ptr = &tempArray[arraySize];
		}
		numberOfElements++;
	}

	private : void Add2(int value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize*=2;
			int * tempArray = new int[arraySize];
			for(int i = 0; i < (arraySize/2); i++)
			{
				tempArray[i] = array[i];
			}
			delete [] array;
			array = tempArray;
			ptr = &array[(arraySize/2)];
			*ptr = value;
			ptr++;
		}
		numberOfElements++;
	}

	private : void Add3(int value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize += 100;
			int * tempArray = new int[arraySize];
			for(int i = 0; i < arraySize-100; i++)
			{
				tempArray[i] = array[i];
			}
			delete [] array;
			array = tempArray;
			ptr = &tempArray[arraySize-100];
			*ptr = value;
			ptr++;
		}
		numberOfElements++;
	}

	public : void Add(ExpandingType expandingType, int value)
	{
		switch (expandingType)
		{
		case by_one:
			Add1(value);
			break;
		case two_times:
			Add2(value);
			break;
		case by_hundred:
			Add3(value);
			break;
		default:
			cout << "Wrong expanding type!" << endl;
			break;

		}
	}

	public : int Display(int i)
	{
		return array[i];
	}

	public : void DisplayAll()
	{
		for(int i = 0; i < arraySize; i++)
		{
			cout << "Array[" << i << "] = " << array[i] << endl;
		}
	}

};

int main()
{
	int n;
	ExpandingType expandingType = two_times;
	long timeStart;
	long timeEnd;

	cout << "Podaj ilosc elementow: " << endl;
	cin >> n;

	Array tab1;

	timeStart = GetTime();
	for(int i=0; i < n; i++)
	{
		tab1.Add(expandingType, i);
		//cout << "Tab1[" << i << "] : " << tab1.Display(i) << endl;
	}
	timeEnd = GetTime();

	cout << "Execute time: " << (timeEnd-timeStart)/1000.0 << " s" << endl;
}
