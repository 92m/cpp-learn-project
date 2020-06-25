#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void swpn(int &p1, int &p2)
{
     int p;
     p = p1;
     p1 = p2;
     p2 = p;
}

int main()
{
     int ival = 1024;
     int ival2 = ival + 1;

     int *pint = &ival;

     cout << "ival:" << ival << "; "
          << "ival2:" << ival2 << "; " << endl;

     *pint = *pint + 1;

     cout << "*pint:" << *pint << "; "
          << "pint:" << pint << endl;

     int a = 10, b = 20;

     swpn(a, b);

     cout << a << " " << b << endl;

     system("pause");
}
