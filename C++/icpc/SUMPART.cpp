#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n & 1) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}