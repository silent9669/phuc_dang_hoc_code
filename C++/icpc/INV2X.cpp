#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++){
        cin >> nums[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i ++){
        for (int j = i + 1; j < n; j ++){

            if (nums[i] > 2*nums[j]){
                count ++;
            }
        }
    }
    cout << count << endl;


    return 0;
}