#include <iostream>
using namespace std;

bool calc(long long a, long long b, long long c) {
    return (a + b == c || a + c == b || b + c == a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;

    // test case 1
    cin >> a >> b >> c;
    if (calc(a, b, c)) cout << "yes\n";
    else cout << "no\n";

    // test case 2
    cin >> a >> b >> c;
    if (calc(a, b, c)) cout << "yes\n";
    else cout << "no\n";

    return 0;
}