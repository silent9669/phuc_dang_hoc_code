#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin>>n))
    {
        return 0;
    }

    // greedy algorithm
    int steps = (n + 5 - 1) / 5;
    cout<<steps<<endl;

    return 0;
}