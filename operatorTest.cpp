#include <iostream>
#include <windows.h>

using namespace std;

class cls
{
private:
  int ar[6];

public:
  cls();
  int &operator[](int i); //����"[]"������
};

cls::cls()
{
  int i;

  for (i = 0; i < 6; i++)
  {
    ar[i] = i + 1;
  }
}

int &cls::operator[](int i) //�������ã������ſ��ԶԷ���ֵ��ֵ
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