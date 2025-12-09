#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, l, r;
    if (!(cin >> n >> l >> r)) return;

    // Strategy:
    // We construct the Prefix XORs (P) implicitly.
    // Ideally P[i] = i for all i. This makes all P values unique.
    // To satisfy f(l, r) = 0, we must have P[r] == P[l-1].
    // So we force P[r] = l - 1.

    // Logic proof:
    // 1. Uniqueness: The sequence 0, 1, 2...n has distinct values.
    //    We replace P[r] with (l-1). Since l < r, (l-1) was already at index l-1.
    //    Now (l-1) appears twice: at index l-1 and index r.
    //    This is the ONLY duplicate pair.
    // 2. Non-zero elements: Since P is increasing (mostly), adjacent elements
    //    are distinct, so a[i] = P[i] ^ P[i-1] is never 0.

    int prev_p = 0; // P[0] is 0
    for (int i = 1; i <= n; ++i) {
        int curr_p;
        if (i == r) {
            curr_p = l - 1; // Force the collision
        } else {
            curr_p = i;     // Keep distinct
        }

        // Recover a[i]
        cout << (prev_p ^ curr_p) << (i == n ? "" : " ");
        prev_p = curr_p;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}