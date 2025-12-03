#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,n,w;
    cin>>k>>n>>w;

    int cost = 0;
    for (int i=1;i<=w;i++)
    {
        int temp = i * k;
        cost += temp;
    }

    if (cost < n)
    {
        cout<<0;
    }
    else
    {
        cout << cost - n;
    }

    return 0;
}