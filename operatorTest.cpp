#include <iostream>
#include <windows.h>

using namespace std;

class cls
{
private:
  int ar[6];

public:
  cls();
  int &operator[](int i); //重载"[]"操作符
};

cls::cls()
{
  int i;

  for (i = 0; i < 6; i++)
  {
    ar[i] = i + 1;
  }
}

int &cls::operator[](int i) //返回引用，这样才可以对返回值赋值
{
  return ar[i];
}

int main(void)
{
  cls c;

  printf("c[1] = %d\n", c[1]);

  c[4] = 16;

  printf("c[4] = %d\n", c[4]);

  return 0;
}