#include <cstring>
#include <iostream>

using namespace std;

void deleteWord(string s, string s1) {

  if (s1.empty()) {
    cout << s << endl;
    return;
  }
  size_t pos = s.find(s1);

  while (pos != string::npos) {
    s.erase(pos, s1.length());
    pos = s.find(s1);
  }

  cout << s << endl;
}
