#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elf {
    int val;
    int id;
};

// Comparator to sort elves by attack/health value
bool compareElves(const Elf& a, const Elf& b) {
    return a.val < b.val;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<Elf> elves(n);
    for (int i = 0; i < n; ++i) {
        cin >> elves[i].val;
        elves[i].id = i + 1; // 1-based indexing
    }
    
    // Case 0: m = 0 is impossible because the last duel always leaves 1 survivor.
    if (m == 0) {
        cout << "-1\n";
        return;
    }
    
    // Case m > n/2: Impossible because we need m victims for m survivors to attack.
    // Exception: If m=1, termination is "no pairs", which is satisfied automatically.
    // Note: If m=1, n >= 2 (problem constraint), so n-m >= 1 is always valid.
    if (m > n - m) {
        // This condition covers 2m > n.
        // For m=1, this is 1 > n-1 => n < 2. Since n>=2, this never triggers for m=1.
        cout << "-1\n";
        return;
    }
    
    sort(elves.begin(), elves.end(), compareElves);
    
    // Total operations needed = n - m
    cout << n - m << "\n";
    
    // Phase 1: Chain elimination of "Fodder"
    // We use indices 0 to n-2m-1 as attackers
    // They attack the next elf in the sorted list.
    // Since attacker.val < victim.val, attacker dies.
    // The last attack is p[n-2m-1] attacks p[n-2m].
    for (int i = 0; i < n - 2 * m; ++i) {
        cout << elves[i].id << " " << elves[i+1].id << "\n";
    }
    
    // Phase 2: Survivors execute Victims
    // Victims are at indices [n-2m ... n-m-1]
    // Survivors are at indices [n-m ... n-1]
    // Each Survivor attacks one Victim.
    // Since Survivor.val > Victim.val, Victim dies, Survivor is marked.
    for (int i = 0; i < m; ++i) {
        // Survivor index: n - m + i
        // Victim index: n - 2*m + i
        cout << elves[n - m + i].id << " " << elves[n - 2 * m + i].id << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
