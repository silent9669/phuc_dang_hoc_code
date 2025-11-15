#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, N;
    cin >> X >> N;
    int arr[100];

    int budget = X;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        int remain = budget - arr[i];
        budget = X + remain;
    }

    cout << budget;

    return 0;
}
