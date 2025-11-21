#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            cout<<i<< endl;
        }
    }

    return 0;
}