#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int magazineCount[26] = {0};
    int ransomNoteCount[26] = {0};

    for (char c : ransomNote) {
      ransomNoteCount[c - 'a']++;
    }

    for (char c : magazine) {
      magazineCount[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (ransomNoteCount[i] > magazineCount[i])
        return false;
    }

    return true;
  }
};

TEST_CASE("TESTING") {
  Solution sol;

  CHECK(sol.canConstruct("a", "b") == 0);
  CHECK(sol.canConstruct("aa", "ab") == 0);
  CHECK(sol.canConstruct("aa", "aab") == 1);
}
