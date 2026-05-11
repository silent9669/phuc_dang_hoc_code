#include <cstring>
#include <iostream>

using namespace std;

void cutString(string s, int index) {
  if (index < 0 || index >= s.length())
    return;
  cout << s.substr(index);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "Truong Dai Hoc Bach Khoa";
  int index = 5;

  cutString(s, index);

  return 0;
} 
