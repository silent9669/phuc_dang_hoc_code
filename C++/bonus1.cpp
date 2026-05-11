#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int longestString(const string &s) {
  int n = s.length();
  int maxLength = 0;
  int index1 = 0;

  vector<int> pos(26, -1);
  for (int i = 0; i < n; ++i) {
    int charIndex = s[i] - 'a';

    if (pos[charIndex] >= index1) {
      index1 = pos[charIndex] + 1;
    }

    pos[charIndex] = i;

    int currentMax = i - index1 + 1;
    if (currentMax > maxLength) {
      maxLength = currentMax;
    }
  }
  return maxLength;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream inputFile("LONGEST.INP");
  fstream outputFile("LONGEST.OUT");

  if (!inputFile.is_open())
    return 0;

  string s;
  if (inputFile >> s) {

    int result = longestString(s);

    outputFile << result << endl;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
