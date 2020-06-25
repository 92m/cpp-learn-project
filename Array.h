
#include <assert.h>

template <class elemType>
class Array
{
public:
  // ���캯��֮һ
  explicit Array(int sz = DefaultArraySize);

  // ���캯��֮��
  Array(elemType *array, int sz);

  // ���캯��֮��
  // Array(const Array &rhs);

  // ���з���-size()
  virtual int size() const { return _size; }; // #1

  // ���з���-min()
  virtual elemType min() const; // #3a

  // ���з���-max()
  virtual elemType max() const; // #3b

  // ���з���-find()
  virtual int find(const elemType &value) const;

  // ���ط��� []
  elemType &operator[](int i) const;

  // ���ط��� ==
  bool operator==(const Array &array) const;

  // ���ط��� !=
  bool operator!=(const Array &array) const;

private:
  elemType *ia;
  int _size;
  static const int DefaultArraySize = 12;
  void init(int sz, elemType *array);
};

// ˽�к���-init()
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

// ��һ�����캯��ʵ��
Array::Array(int sz) { init(sz, 0); }

// �ڶ������캯��ʵ��
Array::Array(elemType *array, int sz)
{
  init(sz, array);
}

// ���������캯��ʵ��
// Array::Array(const Array &rhs)
// {
//   init(rhs.size, rhs.ia);
// }

// ���ط���[]
elemType &Array::operator[](int i) const
{
  assert(i >= 0 && i < _size);
  return ia[i];
}

// ���ط���==
bool Array::operator==(const Array &array) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] != array[index])
      return false;
  }
  return true;
}

// ���ط���!= (�ж��߼�������)
bool Array::operator!=(const Array &array) const
{
  // ...
  return true;
}

// ���к���-find()
// ��ֵ���������ҵ�
// ���ص�һ�γ��ֵ�����
// ���򷵻� -1
int Array::find(const elemType &value) const
{
  for (int index = 0; index < _size; ++index)
  {
    if (ia[index] == value)
      return index;
  }
  return -1;
}
