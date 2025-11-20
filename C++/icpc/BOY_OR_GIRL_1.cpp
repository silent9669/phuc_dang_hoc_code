#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    set<char> unique;
    for (int i = 0; i < name.size(); i ++){
        unique.insert(name[i]);
    }
    
    if (unique.size() & 1){
        cout << "IGNORE HIM!";
    }
    else{
        cout << "CHAT WITH HER!";
    }
    
    return 0;
}