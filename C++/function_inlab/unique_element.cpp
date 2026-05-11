#include <iostream>

using namespace std;

bool checkElementsUniqueness(int *arr, int n) {
  int count[1001] = {0};
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    if (count[arr[i]] > 1)
      return false;
  }
  return true;
}
