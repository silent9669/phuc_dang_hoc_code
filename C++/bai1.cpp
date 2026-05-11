#include <iostream>
using namespace std;

void splitArray(int *A, int n, int *&B, int &nB, int *&C, int &nC) {
  nB = 0;
  nC = 0;

  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0)
      nB++;
    else
      nC++;
  }

  B = new int[nB];
  C = new int[nC];

  int ib = 0;
  int ic = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0)
      B[ib++] = A[i];
    else
      C[ic++] = A[i];
  }
}
