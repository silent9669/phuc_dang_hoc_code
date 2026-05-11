#include <fstream>
#include <iostream>

using namespace std;

void uppercase(string output) {
  string s;
  if (!getline(cin, s))
    return;
  ofstream outputFile(output);
  if (!outputFile.is_open()) {
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 'a' + 'A';
    }
  }
  outputFile << s;

  outputFile.close();
}
