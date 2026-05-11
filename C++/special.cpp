#include <iostream>

using namespace std;

bool isPrime(int k) {
  if (k < 2)
    return false;
  for (int i = 2; i * i <= k; ++i) {
    if (k % i == 0)
      return false;
  }
  return true;
}

int sumDigits(int k) {
  int sum = 0;
  while (k > 0) {
    sum += k % 10;
    k /= 10;
  }
  return sum;
}

bool isSpecialNumber(int n) {
  if (!isPrime(n)) {
    return false;
  }
  int digitSum = sumDigits(n);
  return isPrime(digitSum);
}
