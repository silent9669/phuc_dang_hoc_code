#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        int arr[1000];

        for (int i = 0; i < x; i++)
        {
            cin >> arr[i];
        }

        int count = 0;
        for (int i = 0; i < x - 1; i++)
        {
            if (abs(arr[i] - arr[i + 1]) == 1)
            {
                count++;
            }
        }

        if (2 * count > (x-1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
