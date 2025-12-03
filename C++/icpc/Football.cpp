#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    int count = 1;
    for (int i = 1; i < n.length(); i++)
    {
        if (n[i] == n[i - 1])
        {
            count++;
            if (count == 7)
            {
                cout << "YES";
                return 0;
            }
        }
        else
        {
            count = 1;
        }
    }
    cout << "NO";

    return 0;
}