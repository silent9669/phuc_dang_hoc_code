int recursiveSum(int arr[], int size) {

  if (size <= 0) {
    return 0;
  }

  return arr[size - 1] + recursiveSum(arr, size - 1);
}

long int decimalToBinary(int decimal_number) {
  if (decimal_number == 0)
    return 0;

  return (decimal_number % 2) + 10 * decimalToBinary(decimal_number / 2);
}

bool palindrome(string strg) {
  int left = 0;
  int right = strg.length() - 1;
  while (left < right) {
    if (strg[left] != strg[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

bool palindromeRecursion(string s) {
  if (s.length() <= 1) {
    return true;
  }

  if (s[0] != s[s.length() - 1]) {
    return false;
  }

  return palindromeRecursion(s.substr(1, s.length() - 2));
}

int main() {
  string input;
  while (true) {
    getline(cin, input);

    if (input.empty() || input[0] == '*') {
      break;
    }

    cout << palindrome(input) << " " << palindromeRecursion(input) << endl;
  }

  return 0;
}
