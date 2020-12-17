#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void swpn(int &p1, int &p2)
{
     int p;
     p = p1;
     p1 = p2;
     p2 = p;
}

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;
typedef struct {
    lept_type type;
}lept_value;

int main()
{
     int ival = 1024;
     int ival2 = ival + 1;

     int *pint = &ival;

     lept_value c;

     cout << "ival:" << ival << "; "
          << "ival2:" << ival2 << "; " << endl;

     *pint = *pint + 1;

     cout << "*pint:" << *pint << "; "
          << "pint:" << pint << endl;

     int a = 10, b = 20;

     swpn(a, b);

     cout << a << " " << b << endl;

     cout << "枚举 LEPT_NULL:" << LEPT_TRUE << endl;

     cout << "枚举 c.type:" << c.type << endl;

     system("pause");
}
