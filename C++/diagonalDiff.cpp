#include <iostream>
#include <string>
#include <vector>

using namespace std;

int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
  int sum1 = 0, sum2 = 0;

  for (int i = 0; i < row; i++) {
    int j = i - (x - y);
    if (j >= 0 && j < col)
      sum1 += arr[i][j];
  }

  for (int i = 0; i < row; i++) {
    int j = (x + y) - i;
    if (j >= 0 && j < col)
      sum2 += arr[i][j];
  }

  return abs(sum1 - sum2);
}
