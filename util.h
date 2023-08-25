#include <bits/stdc++.h>
using namespace std;

// TODO: Under-development: Unsure if actually useful or not.
// Heuristic: I needed the functionalities here in at least two homeworks.
class Util
{
private:
  int homework = 1;
  int number = 1;

public:
  Util() {}
  Util(int homework, int number) : homework(homework) {}

  void PrintHomework(string name, string delim = "\n")
  {
    cout << delim;
    cout << "H" << homework << "." << number << ": ";
    cout << name << ": ";
    cout << delim;
    this->number++;
  }

  // src: https://stackoverflow.com/questions/19094340/stdvector-as-a-template-function-argument
  template <typename T, typename A>
  vector<T, A> PrintVec(const vector<T, A> &v)
  {
    int len = (int)v.size();
    for (int i = 0; i < len; ++i)
      cout << v[i] << ' ';
    cout << '\n';

    return v;
  }
};
