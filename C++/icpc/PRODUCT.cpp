#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;

    int product = a * b;
    if (product > 0){
        cout << 1;
    }
    else if (product == 0){
        cout << 0;
    }
    else {
        cout << -1;
    }

    return 0;
}