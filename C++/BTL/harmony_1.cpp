#include <bits/stdc++.h>
using namespace std;
int computeStamina(string moves, int hp, double breathingMastery) {
    double staminaUsed = 0;

    for (char move : moves) {
        if (move == 'A') {
            staminaUsed += 1 - breathingMastery;
        }
        else if (move == 'B') {
            staminaUsed += 2 - breathingMastery;
        }
        else if (move == 'C') {
            staminaUsed += 3 - breathingMastery;
        }
    }

    double remainingHP = hp - staminaUsed;

    if (remainingHP < 0) {
        return 0;
    }

    return (int)remainingHP;
}

int main()
{
    cout << computeStamina("ABCAAC", 100, 0.5) << endl;
    cout << computeStamina("ABCABCABC", 99, 0.5) << endl;
    cout << computeStamina("B", 1000, 0.0) << endl;
}