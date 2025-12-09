#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int year = n + 1; year <= 10000; year++)
    {
        string s = to_string(year);
        set<char> digits(s.begin(), s.end());

        if (digits.size() == s.length())
        {
            cout <<year;
            return 0;
        }
    }

    return 0;
}