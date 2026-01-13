#include <bits/stdc++.h>

using namespace std;

void solve(){
  string s;
  cin >> s;

  int count = 0;
  for (char c : s){
    if (c == 'Y'){
      count++;
    }
  }

  if (count > 1){
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while(n--){
    solve();
  }

  return 0;
}
