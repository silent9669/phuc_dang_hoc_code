#include <iostream>

using namespace std;

int diagonalProduct(int arr[][1000], int row, int col) {
  int product = 1;
  for (int i = 0; i < row; i++)
    product *= arr[i][i];
  return product;
}
