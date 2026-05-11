#include <iostream>
#include <string>
#include <vector>

bool is_odd(int n) {
  if (n & 1)
    return true;
  else
    return false;
}
int subMatrix(int arr[][1000], int row, int col) {
  int count = 0;
  for (int i = 0; i < row - 1; i++) {
    for (int j = 0; j < col - 1; j++) {
      int sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
      if (is_odd(sum))
        count++;
    }
  }
  return count;
}
