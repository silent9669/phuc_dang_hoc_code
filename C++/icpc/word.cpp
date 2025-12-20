#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  if (!(cin >> s)) return 0;
  
  int count_normal = 0;
  int count_caps = 0;
  for (size_t i = 0; i < s.size(); i++){
    if (s[i] >= 'a' && s[i] <= 'z'){
      count_normal++;
    } else if (s[i] >= 'A' && s[i] <= 'Z'){
      count_caps++;
    }
  }

  if (count_normal >= count_caps){
    for (size_t i = 0; i < s.size(); i++){
      s[i] = tolower(s[i]);
    }
  } else {
    for (size_t i = 0; i < s.size(); i++){
      s[i] = toupper(s[i]);
    }
  }
  
  cout << s << "\n";

  return 0;
}
