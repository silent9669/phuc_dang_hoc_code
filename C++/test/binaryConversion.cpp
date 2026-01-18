#include <iostream>

using namespace std;

void binaryConversion(int n) {
  cin >> n;
  if (n == 0) {
    cout << "0";
    return;
  }
  string binary = "";
  while (n > 0) {
    binary = to_string(n % 2) + binary;
    n = n / 2;
  }
  cout << binary;
}

void decimalConversion(string binary) {
  int decimal = 0;
  int base = 1;
  int length = binary.length();
  for (int i = length - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += base;
    }
    base = base * 2;
  }
  cout << decimal;
}

void hexadecimalConversion(int n) {
  cin >> n;
  if (n == 0) {
    cout << "0";
    return;
  }
  string hex = "";
  char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  while (n > 0) {
    hex = hexChars[n % 16] + hex;
    n = n / 16;
  }
  cout << hex;
}

void octalConversion(int n) {
  cin >> n;
  if (n == 0) {
    cout << "0";
    return;
  }
  string octal = "";
  while (n > 0) {
    octal = to_string(n % 8) + octal;
    n = n / 8;
  }
  cout << octal;
}

int main() {
  int n;
  string binary;
  cout << "Binary Conversion of Decimal Number:" << endl;
  binaryConversion(n);
  cout << endl << "Decimal Conversion of Binary Number:" << endl;
  cin >> binary;
  decimalConversion(binary);
  cout << endl << "Hexadecimal Conversion of Decimal Number:" << endl;
  hexadecimalConversion(n);
  cout << endl << "Octal Conversion of Decimal Number:" << endl;
  octalConversion(n);
  return 0;
}
