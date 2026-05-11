#include <iostream>
using namespace std;

void sortArray(int *A, int n, bool (*cmp)(int, int)) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (cmp(A[j], A[j + 1])) {
        int tmp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = tmp;
      }
}

bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }
