#include <iostream>

void mostFrequentCharacter(char *str, char &res, int &freq) {
  int count[26] = {0};

  for (int i = 0; str[i] != 0; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      count[str[i] - 'a']++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      count[str[i] - 'A']++;
    }
  }

  freq = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] > freq) {
      freq = count[i];
      res = 'a' + i;
    }
  }
}
