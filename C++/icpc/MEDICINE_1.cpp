#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    set<char> unique_chars;

    // Chèn từng ký tự vào set
    for (int i = 0; i < name.size(); i++) {
        unique_chars.insert(name[i]);
    }

    // Kích thước của set chính là số lượng ký tự khác nhau
    cout << unique_chars.size() << endl;

    return 0;
}