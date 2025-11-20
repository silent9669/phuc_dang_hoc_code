#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
int main(){
    int slayerLevel, hp, hasTalisman, demonPresence, demonRank, allyCount, bossHP, totalDamage, specialMoveReady;
    double breathingMastery, swordSharpness;
    char timeOfDay;
    cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay
    >> demonPresence >> demonRank >> swordSharpness >> allyCount
    >> bossHP >> totalDamage >> specialMoveReady;
    cout << fixed << setprecision(1);

    //scene 1
    double power = slayerLevel * 10.0 + (double)hp / 10.0 + breathingMastery * 50.0;
    if(power >= 120){
        cout << "[Scene 1] Rank: Hashira (power = " << power << ")" << endl;
    }
    else if(power >= 80){
        cout << "[Scene 1] Rank: Elite (power = " << power << ")" << endl;
    }
    else {
        cout << "[Scene 1] Rank: Novice (power = " << power << ")" << endl;
    }

    //scene 2
    if (hasTalisman == 0){
        cout << "[Scene 2] Denied: No talisman." << endl;
    }
    else if (timeOfDay != 'D' && timeOfDay != 'N'){
        cout << "[Scene 2] Warning: invalid timeOfDay." << endl;
    }
    else if (timeOfDay == 'N' && demonPresence == 1){
        cout << "[Scene 2] Open silently." << endl;
    }
    else{
        cout << "[Scene 2] Open cautiously." << endl;
    }

    //scene 3
    double adv = (101.0 - demonRank * 15.0) + swordSharpness * 0.4 + (double)allyCount * 5.0;
    if (adv >= 100){
        cout << "[Scene 3] Engage head-on (adv = " << adv << ")" << endl;
    }
    else if (adv >= 60){
        cout << "[Scene 3] Harass and probe (adv = " << adv << ")" << endl;
    }
    else {
        cout << "[Scene 3] Retreat and regroup (adv = " << adv << ")" << endl;
    }

    //scene 4
    int finalHP = bossHP - totalDamage;
    if (finalHP <= 0){
        cout << "[Scene 4] Boss defeated! (finalHP = 0)" << endl;
    }
    else if (finalHP > 0 && specialMoveReady == 1 && finalHP <= 50){
        cout << "[Scene 4] Use special move to finish! (finalHP = " << finalHP << ")" << endl;
    }
    else {
        cout << "[Scene 4] Withdraw to heal. (finalHP = " << finalHP << ")" << endl;
    }

    return 0;
}
