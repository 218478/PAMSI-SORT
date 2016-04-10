#ifndef MERGE_SORT_ARRAY_HH
#define MERGE_SORT_ARRAY_HH

#include "Array.hh"
#include "IRunnable.hh"


class MergeSortArray: public IRunnable {
 private:
  Array<int> tablica;

 public:
  virtual bool Prepare(int size);
  virtual bool Run();
};

#endif  // MERGE_SORT_ARRAY_HH
