#include <iostream>

using namespace std;

/*
int getValueAtIndex(int *ptr, int k) { return ptr[k]; }

void swap(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

int *zeros(int n) {
  if (n <= 0)
    return nullptr;

  return new int[n]();
}

void shallowCopy(int *&newArr, int *&arr) { newArr = arr; }

int **deepCopy(int **matrix, int r, int c) {
  if (r <= 0 || c <= 0 || matrix == 0)
    return nullptr;

  int **newMatrx = new int *[r];

  for (int i = 0; i < r; i++) {
    newMatrx[i] = new int[c];

    for (int j = 0; j < c; j++) {
      newMatrx[i][j] = matrix[i][j];
    }
  }

  return newMatrx;
}

void deleteMatrix(int **&matrix, int r) {
  if (matrix == nullptr)
    return;

  for (int i = 0; i < r; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;

  matrix = nullptr;
}
*/

void insertRow(int **&matrix, int r, int c, int *rowArr, int row) {
  int **newMatrix = new int *[r + 1];

  for (int i = 0; i < row; i++) {
    newMatrix[i] = matrix[i];
  }

  newMatrix[row] = new int[c];
  for (int j = 0; j < c; j++) {
    newMatrix[row][j] = rowArr[j];
  }

  for (int i = row; i < r; i++) {
    newMatrix[i + 1] = matrix[i];
  }

  delete[] matrix;

  matrix = newMatrix;
}
