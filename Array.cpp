#include <iostream>
#include "IRunnable.hpp"
using namespace std;

enum ExpandingType
{
	by_one,
	two_times,
	by_hundred
};

class Array : public IRunnable
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
	
	public : virtual bool Prepare(int size)
	{
		Size = size;
		return true;
	}
	
	public : virtual bool Run()
	{
		for(int i = 0; i < Size; i++)
		{
			Add2(i);
		}
		return true;
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