#include <iostream>
#include <windows.h>
#include <assert.h>

using namespace std;

class IntArray
{
public:
  // ���캯��֮һ
  explicit IntArray(int sz = DefaultArraySize);

  // ���캯��֮��
  IntArray(int *array, int sz);

  // ���캯��֮��
  // IntArray(const IntArray &rhs);

  // ���з���-size()
  int size() const { return _size; }; // #1

  // ���з���-min()
  int min() const; // #3a

  // ���з���-max()
  int max() const; // #3b

  // ���з���-find()
  int find(int value) const;

  // ���ط��� []
  int &operator[](int i) const;

  // ���ط��� ==
  bool operator==(const IntArray &array) const;

  // ���ط��� !=
  bool operator!=(const IntArray &array) const;

private:
  int *ia;
  int _size;
  static const int DefaultArraySize = 12;
  void init(int sz, int *array);
};

// ˽�к���-init()
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

// ��һ�����캯��ʵ��
IntArray::IntArray(int sz) { init(sz, 0); }

// �ڶ������캯��ʵ��
IntArray::IntArray(int *array, int sz)
{
  init(sz, array);
}

// ���������캯��ʵ��
// IntArray::IntArray(const IntArray &rhs)
// {
//   init(rhs.size, rhs.ia);
// }

// ���ط���[]
int &IntArray::operator[](int i) const
{
  assert(i >= 0 && i < _size);
  return ia[i];
}

// ���ط���==
bool IntArray::operator==(const IntArray &array) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] != array[index])
      return false;
  }
  return true;
}

// ���ط���!= (�ж��߼�������)
bool IntArray::operator!=(const IntArray &array) const
{
  // ...
  return true;
}

// ���к���-find()
// ��ֵ���������ҵ�
// ���ص�һ�γ��ֵ�����
// ���򷵻� -1
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

  cout << "array��" << array.size() << endl;

  cout << "array2[7]��" << array2[7] << endl;

  cout << "find()��" << array2.find(7) << endl;

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