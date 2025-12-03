#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long m;
    cin >> m;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j  = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if (sum % m == 0)
            {
                count++;
            }
        }
    }

    return 0;
}