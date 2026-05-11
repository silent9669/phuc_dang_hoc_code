#include <iostream>

using namespace std;

void reverse(char str[]) {
  int n = strlen(str);
  int left = 0;
  int right = n - 1;

  while (left < right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char str[] = "this is my school";
  reverse(str);
  cout << str;

  return 0;
}
