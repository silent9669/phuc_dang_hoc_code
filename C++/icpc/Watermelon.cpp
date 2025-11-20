#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    if (n > 2 && n % 2 == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}