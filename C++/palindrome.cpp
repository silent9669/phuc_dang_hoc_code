
#include <iostream>

using namespace std;

bool isPalindrome(const char *str) {
  if (str == nullptr)
    return 0;

  int left = 0;
  int n = 0;
  while (str[n] != '\0') {
    n++;
  }
  int right = n - 1;

  while (left < right) {
    if (str[left] != str[right]) {
      return 0;
    }
    left++;
    right--;
  }
  return true;
}
