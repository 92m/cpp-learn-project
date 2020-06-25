
#include <assert.h>

template <class elemType>
class Array
{
public:
  // 构造函数之一
  explicit Array(int sz = DefaultArraySize);

  // 构造函数之二
  Array(elemType *array, int sz);

  // 构造函数之三
  // Array(const Array &rhs);

  // 共有方法-size()
  virtual int size() const { return _size; }; // #1

  // 共有方法-min()
  virtual elemType min() const; // #3a

  // 共有方法-max()
  virtual elemType max() const; // #3b

  // 共有方法-find()
  virtual int find(const elemType &value) const;

  // 重载符号 []
  elemType &operator[](int i) const;

  // 重载符号 ==
  bool operator==(const Array &array) const;

  // 重载符号 !=
  bool operator!=(const Array &array) const;

private:
  elemType *ia;
  int _size;
  static const int DefaultArraySize = 12;
  void init(int sz, elemType *array);
};

// 私有函数-init()
void Array::init(int sz, elemType *array)
{
  _size = sz;
  ia = new int[_size];
  for (int ix = 0; ix < _size; ++ix)
    if (!array)
      ia[ix] = 0;
    else
      ia[ix] = array[ix];
};

// 第一个构造函数实现
Array::Array(int sz) { init(sz, 0); }

// 第二个构造函数实现
Array::Array(elemType *array, int sz)
{
  init(sz, array);
}

// 第三个构造函数实现
// Array::Array(const Array &rhs)
// {
//   init(rhs.size, rhs.ia);
// }

// 重载符号[]
elemType &Array::operator[](int i) const
{
  assert(i >= 0 && i < _size);
  return ia[i];
}

// 重载符号==
bool Array::operator==(const Array &array) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] != array[index])
      return false;
  }
  return true;
}

// 重载符号!= (判断逻辑待补充)
bool Array::operator!=(const Array &array) const
{
  // ...
  return true;
}

// 公有函数-find()
// 如值在数组中找到
// 返回第一次出现的索引
// 否则返回 -1
int Array::find(const elemType &value) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] == value)
      return index;
  }
  return -1;
}
