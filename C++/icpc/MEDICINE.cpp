#include  <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    cin >> name;

    int seen[256] = {0};
    
    int age = 0;
    for (int i = 0; i < name.size(); i ++){
        char c = name[i];

        if (seen[c] == 0){
            age ++;
            seen [c] = 1;
        }
    }
    cout << age << endl;

    return 0;
}