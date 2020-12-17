#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int main()
// {
//   int ival = 1024, ival2 = 2048;
//   int *pi = &ival;
//   int **ppi = &pi;
//   int *pi2 = *ppi;

//   *pi = 1234;
//   *pi = abs(*pi);
//   cout << "ival1 :" << ival << endl;
//   cout << "ival2 : " << ival2 << endl;
//   cout << "pi : " << pi << endl;
//   cout << "*pi : " << *pi << endl;
//   cout << "pi2 : " << pi2 << endl;
//   cout << "*pi2 : " << *pi2 << endl;

//   system("pause");

//   return 0;
// }

// int foobar(int pi)
// {
//   *pi = 1024;
//   return *pi;
// }

int main()
{
  int i = -1;
  int ic = i;
  int *pic = &ic;

  int &refi = i;

  int *&refi2 = pic;

  int min_val = 0;

  refi = min_val;

  cout << "i : " << i << endl;

  cout << "&refi : " << refi << endl;

  cout << "&refi2 : " << &refi2 << endl;

  // �������� int ���͵Ķ���
  int ival = 1024, ival2 = 2048;

  // ����һ�����ú�һ������
  int &rval = ival, rval2 = ival2;

  // ����һ������ һ��ָ���һ������
  int ival3 = 1024, *pi = &ival3, &ri = ival3;

  // ������������
  int &rval3 = ival3, &rval4 = ival2;

  double dval = 3.1415926;

  // ����const���úϷ�

  const int &ir = 1024;
  const int &ir2 = dval;
  const double &dr = dval + 11.1;

  int ia1[4][3] = {
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {9, 10, 11}};

  int ia[9] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
  int *pbegin = ia;
  int *pend = ia + 9;
  while (pbegin != pend)
  {
    cout << *pbegin << "\n";
    ++pbegin;
  }
  int ie[10] = {0,
                23,
                12,
                121,
                12,
                12,
                12,
                21342,
                43,
                433};

  const int elem_size = 10;

  vector<int> ivec(ie, ie + 9);
  if (!ivec.empty())
  {
    for (int ix = 0; ix < ivec.size(); ++ix)
    {
      cout << ivec[ix] << "--ix--" << ix << "\n";
    }
  }

  string word;
  vector<string> text;

  while (cin >> word)
  {
    text.push_back(word);
    cout << "add:" << word << "\n";
  }

  cout << "words read are: \n";
  for (vector<string>::iterator it = text.begin(); it != text.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;

  system("pause");
}

bool is_equal(const int *ia, int ia_size, const vector<int> &ivec)
{
  string *iater = &ia[0];
  string *iater_end = &ia[ia_size];

  if (ivec.size() == ia_size)
  {
    for (vector<string>::iterator i = ivec.begin(); i != ivec.end(); ++i)
    {
      // if (iater != *i)
      // {
      //   return false;
      // }
      ++iater;
    }
  }
  return true;
}