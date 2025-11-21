#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        for (int j = 0; j < t; j++) {
            string s;
            cin >> s;
            nums.insert(s);
        }
    }

    cout << nums.size();

    return 0;
}