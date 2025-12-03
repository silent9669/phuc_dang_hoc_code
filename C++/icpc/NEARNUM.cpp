#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    sum = (n/1000) + (n / 100)%10 + (n / 10)%10 + n % 10;

    while (sum % 4 != 0)
    {
        n++;
        sum = (n /1000) + (n / 100) % 10 + (n / 10) % 10 + n % 10;
    }

    cout << n << endl;

    return 0;
}
