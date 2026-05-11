#include <climits>
#include <iostream>

using namespace std;

int findMaxColumn(int arr[][1000], int row, int col) {
  int maxSum = INT_MIN;
  int maxCol = 0;

  for (int j = 0; j < col; j++) {
    int sum = 0;
    for (int i = 0; i < row; i++)
      sum += arr[i][j];
    if (sum >= maxSum) {
      maxSum = sum;
      maxCol = j;
    }
  }

  return maxCol;
}
