#include <cstring>
#include <iostream>

using namespace std;

int find(char str[], char substr[]) {
  int n = 0;
  int m = 0;

  while (str[n] != '\0') {
    n++;
  }

  while (substr[m] != '\0') {
    m++;
  }
  if (m == 0) {
    return 0;
  }
  if (m > n) {
    return -1;
  }

  for (int i = 0; i <= n - m; i++) {
    int j = 0;

    while (j < m && str[i + j] == substr[j]) {
      j++;
    }

    if (j == m) {
      return i;
    }
  }

  return -1;
}
