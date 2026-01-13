#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;

  int count = 0;
  int temp = 1;
  for (size_t i = 1; i <= n; i++){
    count += temp;
    temp += 2;
  }
  cout << count;
  
  return 0;
}
