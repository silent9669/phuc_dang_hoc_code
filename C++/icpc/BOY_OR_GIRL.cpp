#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    cin >> name;

    int seen[256] = {0};
    int count = 0;
    for (int i = 0; i < name.size(); i ++){
        char c = name[i];

        if (seen[c] == 0){
            count ++;
            seen[c] = 1;
        }
    }

    if (count & 1){
        cout << "IGNORE HIM!";
    }
    else {
        cout << "CHAT WITH HER!";
    }

    return 0;
}