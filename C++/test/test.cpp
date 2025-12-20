#include<iostream>
using namespace std;
int reverseNum(int n)
{
  string m = to_string(n);
  reverseNum(m.begin(), m.end());
  return stoi(m);
}
int main()
{
    int n;
    cin>>n;
    cout<<reverseNum(n);
    return 0;
}

