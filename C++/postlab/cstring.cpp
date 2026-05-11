#include <cstring>
#include <iostream>

using namespace std;

void process(const char *name, char *outstr) {
  int out_index = 0;
  bool new_word = true;

  for (int i = 0; name[i] != '\0'; i++) {
    char ch = name[i];

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (new_word)
        outstr[out_index++] = (ch >= 'a') ? ch - 'a' + 'A' : ch;
      else {
        outstr[out_index++] = (ch >= 'A' && ch <= 'Z') ? ch - 'A' + 'a' : ch;
      }
      new_word = false;
    }

    else if (ch == ' ') {
      if (out_index > 0 && outstr[out_index - 1] != ' ') {
        outstr[out_index++] = ' ';
        new_word = true;
      }
    }
  }

  if (out_index > 0 && outstr[out_index - 1] == ' ')
    out_index--;

  outstr[out_index] = '\0';
}
