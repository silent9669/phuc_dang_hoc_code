#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    for (int i = a; i <= b; i++) {
        if (i < 2) {
            continue;
        }

        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }

        if (count == 2) {
            cout << i << endl;
        }
    }

    return 0;
}