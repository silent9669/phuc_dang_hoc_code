#include <iostream>
#include <cmath>

using namespace std;

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,w,h;
    cin >> n >> w >> h;

    double size = sqrt(w*w + h*h);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        if (d <= size) {
            cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }

    return 0;
}