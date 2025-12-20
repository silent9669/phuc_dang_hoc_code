#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> x(n);
    vector<int> y(n);

    // Đọc vào tọa độ các điểm
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Khởi tạo tổng khoảng cách là 0
    long long sum = 0; // Dùng long long để tránh tràn số nếu N lớn và tọa độ lớn

    // Duyệt qua tất cả các cặp điểm (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            // Tính khoảng cách Manhattan giữa điểm i và điểm j
            long long current_distance = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            
            // Cộng dồn vào tổng
            sum += current_distance; // <-- Dòng đã được sửa
        }
    }

    cout << sum << endl;
    
    return 0;
}
