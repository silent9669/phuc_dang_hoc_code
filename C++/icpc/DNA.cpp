#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string sample;

    cin >> sample >> n;

    vector<string> stored_sample(n);
    for (int i = 0; i < n; i ++){
        cin >> stored_sample[i];
    }

    vector<int> similar_sample;

    for (int i = 0; i < n; i++){
        string current_sample = stored_sample[i];

        if (current_sample.size() != sample.size()){
            continue;
        }

        int diff = 0;
        for (int j = 0; j < sample.size(); j++){
            if (current_sample[j] != sample[j]){
                diff ++;
            }
        }

        if (diff <= 2){
            similar_sample.push_back(i + 1);
        }
    }

    for (int i = 0; i < similar_sample.size(); i ++){
        cout << similar_sample[i];
        if (i < similar_sample.size() - 1){
            cout << " ";
        }
    }
    

    return 0;
}
