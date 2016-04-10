#ifndef Array_HH
#define Array_HH

#include <iostream>
#include <cstdlib>    // to deal with pseudo-randomness
#include <algorithm>  // to find the min in the array, becayse I'm lazy
#include "IArray.hh"
using namespace std;

enum ExpandingType
{
	by_one,
	two_times,
	by_hundred,
	one_and_half_times
};

template < typename type >
class Array : public IArray<type>
{
protected:
	long int arraySize;
	long int numberOfElements;
	type * array;
	type * ptr;	
	
	public : Array()
	{
		numberOfElements = 0;
		arraySize = 10;
		array = new type[arraySize];
		ptr = array;
	}
	
	public : ~Array()
	{
		delete [] array;
	}
	
	public : virtual void Add(type value)
	{
		Add2(value);
	}

	public : virtual type Get(int index)
	{
		return array[index];
	}
	
	public : virtual void Set(type item, int index)
	{
		array[index] = item;
	}
	
	public : virtual int GetNumberOfElements()
	{
		return numberOfElements;
	}

 public : type MinimumElement() {
   type temp = array[0];
   for(int i = 1; i < GetNumberOfElements(); i++) {
     if (array[i] < array[i-1])
       temp = array[i];
   }
   minimum = temp;
   return temp;
 }


 private : int minimum;
  
 private : void QuickSortImplementation(type tablica[], int lewy, int prawy) {

   // pessimistic case
   int pivot = minimum;
   //   // normal algorithm
   //   int pivot = tablica[(lewy+prawy)/2];
   int i,j,x;
   i=lewy;
   j=prawy;
   do{
     while (tablica[i]<pivot) i++;
     while (tablica[j]>pivot) j--;
     if (i<=j){
       x=tablica[i];
       tablica[i]=tablica[j];
       tablica[j]=x;
       i++; j--;
     }
   }while (i<=j);
   if (j>lewy) QuickSortImplementation(tablica,lewy, j);
   if (i<prawy) QuickSortImplementation(tablica, i, prawy);
   
 }
  
 public : void QuickSort() {
   QuickSortImplementation( array, 0, GetNumberOfElements()-1 );
 }

 private : void Merge(type arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    // create temp arrays
    // should make it dynamic, because data amount is too large
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++; }
        else {
            arr[k] = R[j];
            j++; }
        
        k++; }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++; }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++; }
}

  // l is for left index and r is right index of the
  // sub-array of arr to be sorted
 private : void MergeSortImplementation(type arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        MergeSortImplementation(arr, l, m);
        MergeSortImplementation(arr, m+1, r);
 
        Merge(arr, l, m, r);
    }
}

  
 public: void MergeSort() {
   MergeSortImplementation( array, 0, GetNumberOfElements()-1 );
 }

	
	private : void Add1(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize++;
			type * tempArray = new type[arraySize];
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

	private : void Add2(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize*=2;
			type * tempArray = new type[arraySize];
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

	private : void Add3(type value)
	{
		if(numberOfElements < arraySize)
		{
			*ptr = value;
			ptr++;
		}
		else
		{
			arraySize += 100;
			type * tempArray = new type[arraySize];
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
	
	private : void Add4(type value)
		{
			if(numberOfElements < arraySize)
			{
				*ptr = value;
				ptr++;
			}
			else
			{
				arraySize*=1.5;
				type * tempArray = new type[arraySize];
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


	public : void Add(ExpandingType expandingType, type value)
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
		case one_and_half_times:
			Add4(value);
			break;
		default:
			cout << "Wrong expanding type!" << endl;
			break;
		}
	}
};

#endif
