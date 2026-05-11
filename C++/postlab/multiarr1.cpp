#include <iostream>
#include <string>
#include <vector>

bool is_prime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
int specialCells(int arr[][1000], int row, int col) {
  int rowSum[1000] = {0};
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      rowSum[i] += arr[i][j];
    }
  }

  int colSum[1000] = {0};
  for (int j = 0; j < col; j++) {
    for (int i = 0; i < row; i++) {
      colSum[j] += arr[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (is_prime(rowSum[i]) && is_prime(colSum[j]))
        count++;
    }
  }

  return count;
}
