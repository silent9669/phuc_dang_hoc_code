#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[100];

    int max = 0;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    cout << max - min << endl;

    return 0;
}