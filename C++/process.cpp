#include <cstring>
#include <iostream>

using namespace std;

void process(const char str[], char outstr[]) {
  int i = 0;
  int j = 0;

  while (str[i] == ' ') {
    i++;
  }

  if (str[i] == '\0') {
    outstr[0] = '\0';
    return;
  }

  while (str[i] != '\0') {
    if (str[i] != ' ') {

      outstr[j++] = str[i];
    } else {

      if (j > 0 && outstr[j - 1] != ' ') {
        outstr[j++] = ' ';
      }
    }
    i++;
  }

  if (j > 0 && outstr[j - 1] == ' ') {
    j--;
  }

  outstr[j] = '\0';
}
