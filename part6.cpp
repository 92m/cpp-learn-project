#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <iostream>

using namespace std;
void even_odd(const vector<int> *pvec, vector<int> *pvec_even, vector<int> *pvec_odd)
{
  // 声明 const_iterator用以遍历pvec
  vector<int>::const_iterator c_iter = pvec->begin();
  vector<int>::const_iterator c_iter_end = pvec->end();

  for (; c_iter != c_iter_end; ++c_iter)
  {
    if (*c_iter % 2)
    {
      pvec_odd->push_back(*c_iter);
    }
    else
    {
      pvec_even->push_back(*c_iter);
    }
  }
}
int main()
{
  // vector<int> ivec;
  // cout << "ivec: size: " << ivec.size()
  //      << " capacity: " << ivec.capacity() << endl;
  // for (int ix = 0; ix < 24; ++ix)
  // {
  //   ivec.push_back(ix);
  //   cout << "ivec: size: " << ivec.size()
  //        << " capacity: " << ivec.capacity() << endl;
  // }

  // system("pause");

  vector<string> svec;
  list<int> ilist;
  string text_word;
  const int list_size = 64;

  while (cin >> text_word)
  {
    svec.push_back(text_word);
  }

  if (svec.empty() == true)
  {
    cout << "svev.empty()" << svec.empty() << endl;
  }

  int ias[4] = {0, 1, 2, 3};

  for (int ix = 0; ix < 4; ++ix)
  {
    ilist.push_front(ias[ix]);
  }

  list<int> elist(list_size);

  int ia[] = {1, 5, 34};
  int ia2[] = {1, 2, 3};
  int ia3[] = {6, 13, 21, 29, 38, 55, 67, 89};
  vector<int> ivec;

  vector<int>::iterator ivec_begin = ivec.begin();
  vector<int>::iterator ivec_end = ivec.end();

  for (; ivec_begin != ivec_end; ++ivec_begin)
  {
    cout << ivec_begin << " " << endl;
  }

  system("pause");
}