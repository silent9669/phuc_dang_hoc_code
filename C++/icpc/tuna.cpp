#include <iostream>
#include <string>
#include <vector>   
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;


    int sum = 0;
    int a = 0;
    for (int i = 0; i < n; i ++){
        int p1, p2;
        cin >> p1 >> p2;

        if (abs(p1 - p2) <= x){
            sum += max(p1, p2);
        }
        else {
            cin >> a;
            sum += a;
        }
    }

    cout << sum;
    
    return 0;
}
