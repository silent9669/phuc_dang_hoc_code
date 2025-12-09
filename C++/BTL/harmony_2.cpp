#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (size_t i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);
        if (!(c == ' ' || c == '\'' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'p' || c == 'k' || c == 'h' || c == 'l' || c == 'm' ||
            c == 'n' || c == 'w')) {
            cout << -1 << endl;
            return 0;
            }
    }

    int result = 0;
    unsigned long i = 0;

    while (i < s.length()) {
        char c = tolower(s[i]);


        if (c == ' ' || c == '\'') {
            i++;
            continue;
        }

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            // Check for vowel pair
            if (i + 1 < s.length()) {
                char c2 = tolower(s[i + 1]);
                string pair = string(1, c) + c2;

                if (pair == "ai" || pair == "ae" || pair == "ao" || pair == "au" ||
                    pair == "ei" || pair == "eu" || pair == "oi" || pair == "ou" ||
                    pair == "ui" || pair == "iu") {
                    result++;
                    i += 2;
                    continue;
                    }
            }

            result++;
            i++;
        } else {

            i++;
        }
    }

    cout << result << endl;
    return 0;
}