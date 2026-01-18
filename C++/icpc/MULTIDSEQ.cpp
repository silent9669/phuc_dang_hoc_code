#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    if (k == 1) {
        cout << n % MOD << '\n';
        return 0;
    }

    vector<int> dp_prev(n + 1, 1);
    vector<int> dp_cur (n + 1, 0);

    for (int step = 2; step <= k; ++step) {
        fill(dp_cur.begin(), dp_cur.end(), 0);

        for (int d = 1; d <= n; ++d) {
            int add = dp_prev[d];
            if (add == 0) continue;

              for (int m = d; m <= n; m += d) {
                int tmp = dp_cur[m] + add;
                  if (tmp >= MOD) tmp -= MOD;
                    dp_cur[m] = tmp;
            }
        }
        dp_prev.swap(dp_cur);
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp_prev[i];
    cout << ans % MOD << '\n';
    return 0;
}
