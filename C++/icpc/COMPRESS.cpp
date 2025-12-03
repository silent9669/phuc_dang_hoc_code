#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();

    // i là độ dài đoạn con T đang thử (len)
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) // Chỉ xét nếu độ dài T là ước của độ dài S
        {
            bool flag = true;

            // SỬA LỖI 1 & 2: Duyệt toàn bộ chuỗi để kiểm tra tính lặp lại
            for (int j = 0; j < n; j++)
            {
                // So sánh ký tự thứ j với ký tự tương ứng trong đoạn mẫu (độ dài i)
                if (s[j] != s[j % i])
                {
                    flag = false;
                    break;
                }
            }

            // SỬA LỖI 3: Chỉ in và thoát KHI VÀ CHỈ KHI flag đúng
            if (flag)
            {
                cout << n / i; // In số K
                for (int j = 0; j < i; j++)
                {
                    cout << s[j]; // In chuỗi T
                }
                cout << endl;
                return 0; // Tìm thấy kết quả ngắn nhất thì mới dừng chương trình
            }
            // Nếu flag == false, vòng lặp for sẽ tiếp tục thử giá trị i lớn hơn
        }
    }

    return 0;
}