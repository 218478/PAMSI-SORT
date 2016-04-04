#include "QuickSortArray.hh"

#include <fstream>  // to deal with file streams
#include <string>   // to deal with strings
#include <cstdlib>  // to deal with pseudo-randomness

bool QuickSortArray::Prepare(int size) {
  ExpandingType alloc_type = two_times;
  srand(time(NULL));
  for (int i = 0; i < size; i++)  // adding with doubling array size
    tablica.Add(alloc_type, static_cast<int>(rand()));

  return true;
}


bool QuickSortArray::Run() {
  tablica.QuickSort();
}
