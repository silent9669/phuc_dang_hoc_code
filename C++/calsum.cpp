#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void calSum(string fileName) {
  ifstream inputFile(fileName);

  if (!inputFile.is_open())
    return;

  long long sum = 0;
  int num;

  while (inputFile >> num) {
    if (num >= 0) {
      sum += num;
    }
  }

  inputFile.close();

  cout << sum;
}
