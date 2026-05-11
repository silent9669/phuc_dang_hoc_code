#include <cstring>
#include <iostream>

using namespace std;
void printFirstRepeatedWord(char str[]) {
  char wordArray[100][32];
  int repeated = 0;
  int i = 0;
  bool found = 0;

  while (str[i] != '\0') {
    while (str[i] == ' ') {
      i++;
    }

    if (str[i] == '\0') {
      break;
    }

    int index = 0;
    while (str[i] != '\0' && str[i] != ' ') {
      if (index < 30) {
        wordArray[repeated][index++] = str[i];
      }
      i++;
    }

    wordArray[repeated][index] = '\0';
    for (int p = 0; p < repeated; p++) {
      int k = 0;
      bool match = 1;

      while (wordArray[repeated][k] != '\0' || wordArray[p][k] != '\0') {
        if (wordArray[repeated][k] != wordArray[p][k]) {
          match = 0;
          break;
        }
        k++;
      }

      if (match) {
        cout << wordArray[repeated];
        found = 1;
        break;
      }
    }

    if (found) {
      return;
    }

    repeated++;
  }

  if (!found) {
    cout << "No Repetition";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char str[] = "car taxi bike bike car taxi";
  printFirstRepeatedWord(str);
  return 0;
}
