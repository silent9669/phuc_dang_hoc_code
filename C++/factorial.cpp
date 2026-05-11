#include <iostream>

using namespace std;
long factorial(int n) {
  if (n < 0)
    return -1;

  long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }

  return fact;
}

int main(int narg, char **argv) {
  int N;
  cin >> N;
  long result;

  result = factorial(N);

  cout << result << endl;
  return 0;
}
