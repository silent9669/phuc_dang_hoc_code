#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        sum = a + b + c;
        if (sum >= 2) {
            count ++;
        }
    }

    cout << count << endl;

    return 0;
}