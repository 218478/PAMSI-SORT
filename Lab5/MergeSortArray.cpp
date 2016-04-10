#include "MergeSortArray.hh"

#include <cstdlib>  // to deal with pseudo-randomness

bool MergeSortArray::Prepare(int size) {
  ExpandingType alloc_type = two_times;
  srand(time(NULL));
  for (int i = 0; i < size; i++)  // adding with doubling array size
    tablica.Add(alloc_type, static_cast<int>(rand()));

  return true;
}

bool MergeSortArray::Run() {
  tablica.MergeSort();
}
