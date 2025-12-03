#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int score = 0;
    int n;
    cin >> n;
    vector<char> myVector(n);

    for (int i = 0; i < n; i++){
        cin >> myVector[i];
    }

    for (int j = 0; j < n - 1; j ++){
        if (myVector[j] == myVector[j+1]){
            score ++;
        }
    }


    cout << score;


    return 0;
}