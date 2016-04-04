#ifndef QUICK_SORT_ARRAY_HH
#define QUICK_SORT_ARRAY_HH

#include "Array.hh"
#include "IRunnable.hh"


class QuickSortArray: public IRunnable {
 private:
  Array<int> tablica;

 public:
  virtual bool Prepare(int size);
  virtual bool Run();
};

#endif  // QUICK_SORT_ARRAY_HH
