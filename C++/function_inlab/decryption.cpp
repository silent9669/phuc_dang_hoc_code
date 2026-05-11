#include <iostream>

using namespace std;

void encrypt(char *text, int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z')
      text[i] = (text[i] - 'a' + shift) % 26 + 'a';
    else if (text[i] >= 'A' && text[i] <= 'Z')
      text[i] = (text[i] - 'A' + shift) % 26 + 'A';
  }
}

void decrypt(char *text, int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z')
      text[i] = (text[i] - 'a' - shift % 26 + 26) % 26 + 'a';
    else if (text[i] >= 'A' && text[i] <= 'Z')
      text[i] = (text[i] - 'A' - shift % 26 + 26) % 26 + 'A';
  }
}
