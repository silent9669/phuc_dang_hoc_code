#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[25000];

    int sum = 0;
    for (int i = 0; i < n - 1; i ++) {
        cin >> arr[i];
        arr[i] = arr[i] - 1;
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}