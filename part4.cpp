#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int ival1 = 21 / 6;
  int ival2 = 21 / 7;

  cout << "ival1:" << ival1 << endl;
  cout << "ival2:" << ival2 << endl;

  int byte_value = 32;
  int ival = 8;
  // overflow of byte_value's available memory
  byte_value = 12, 888;
  cout << "byte_value: " << byte_value << endl;

  system("pause");
}