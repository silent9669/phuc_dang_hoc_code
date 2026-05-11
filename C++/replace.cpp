#include <cstring>
#include <iostream>

using namespace std;

void replaceString(string s, string s1, string s2) {
  size_t pos = s.rfind(s1);

  if (pos != string::npos) {
    s.replace(pos, s1.length(), s2);
  }

  cout << s << endl;
}
