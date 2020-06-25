#ifndef IntArrayRC_H
#define IntArrayRC_H
#include "Array.h"
class IntArrayRC : public IntArray
{
public:
  IntArrayRC(int sz = DefaultArraySize);
  // IntArrayRC(int *array, int array_size);
  // IntArrayRC(const IntArrayRC &rhs);
  virtual int &operator[](int);

private:
  void check_range(int);
  static const int DefaultArraySize = 12;
};

inline int &
    IntArrayRC::operator[](int index)
{
  check_range(index);
  return ia[index];
}
#endif