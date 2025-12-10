#include <bits/stdc++.h>
using namespace std;

void random(int n, float p) {
    // Trường hợp đặc biệt khi p = 0.5
    if (p == 0.5) {
        cout << fixed << setprecision(9) << 0.5 << endl;
        return;
    }
    
    // Sử dụng logarit để tính lũy thừa một cách chính xác hơn
    long double log_base = log(1.0L - 2.0L * p);
    long double log_power = n * log_base;
    
    // Tính e^(log_power) để lấy kết quả
    long double power = exp(log_power);
    
    long double result = 0.5L + 0.5L * power;
    
    cout << fixed << setprecision(9) << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    float p;
    cin >> n >> p;
    
    random(n, p);
    
    return 0;
}
