//
// Created by phucdang on 25/11/25.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin>>m>>n;

    int square = m * n;
    int square2 = 0;
    int count = 0;

    while(square2 <= square)
    {
        square2 += 2;
        count++;
        if (square2 <= square)
        {
            continue;
        }
        if (square2 > square)
        {
            count --;
        }
    }

    cout<<count<<endl;


    return 0;
}