
#include <iostream>
using namespace std;

void splitByCondition(int *A, int n, int *&B, int &nB, int *&C, int &nC,
                      bool (*condition)(int)) {
  nB = 0;
  nC = 0;
  for (int i = 0; i < n; i++) {
    if (condition(A[i]))
      nB++;
    else
      nC++;
  }
  B = new int[nB];
  C = new int[nC];
  int ib = 0, ic = 0;
  for (int i = 0; i < n; i++) {
    if (condition(A[i]))
      B[ib++] = A[i];
    else
      C[ic++] = A[i];
  }
}

bool isPositive(int x) { return x > 0; }
bool isDivisibleBy3(int x) { return x % 3 == 0; }
