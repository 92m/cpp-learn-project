#include <iostream>
#include <windows.h>
#include <assert.h>

using namespace std;

class IntArray
{
public:
  // 构造函数之一
  explicit IntArray(int sz = DefaultArraySize);

  // 构造函数之二
  IntArray(int *array, int sz);

  // 构造函数之三
  // IntArray(const IntArray &rhs);

  // 共有方法-size()
  int size() const { return _size; }; // #1

  // 共有方法-min()
  int min() const; // #3a

  // 共有方法-max()
  int max() const; // #3b

  // 共有方法-find()
  int find(int value) const;

  // 重载符号 []
  int &operator[](int i) const;

  // 重载符号 ==
  bool operator==(const IntArray &array) const;

  // 重载符号 !=
  bool operator!=(const IntArray &array) const;

private:
  int *ia;
  int _size;
  static const int DefaultArraySize = 12;
  void init(int sz, int *array);
};

// 私有函数-init()
void IntArray::init(int sz, int *array)
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
IntArray::IntArray(int sz) { init(sz, 0); }

// 第二个构造函数实现
IntArray::IntArray(int *array, int sz)
{
  init(sz, array);
}

// 第三个构造函数实现
// IntArray::IntArray(const IntArray &rhs)
// {
//   init(rhs.size, rhs.ia);
// }

// 重载符号[]
int &IntArray::operator[](int i) const
{
  assert(i >= 0 && i < _size);
  return ia[i];
}

// 重载符号==
bool IntArray::operator==(const IntArray &array) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] != array[index])
      return false;
  }
  return true;
}

// 重载符号!= (判断逻辑待补充)
bool IntArray::operator!=(const IntArray &array) const
{
  // ...
  return true;
}

// 公有函数-find()
// 如值在数组中找到
// 返回第一次出现的索引
// 否则返回 -1
int IntArray::find(int value) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] == value)
      return index;
  }
  return -1;
}

int main()
{

  int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  IntArray array(20);

  IntArray array2(ia, 10);

  IntArray array3, array4;

  cout << "array：" << array.size() << endl;

  cout << "array2[7]：" << array2[7] << endl;

  cout << "find()：" << array2.find(7) << endl;

  if (array3 == array4)
  {
    cout << "array3 is equal with array4." << endl;
  }
  else
  {
    cout << "array3 no~ equal with array4." << endl;
  }

  system("pause");
}