#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class battle{
    private:
        int slayerLevel;
        int hp;
        double breathingMastery;
        int hasTalisman;
        char timeOfDay;
        int demonPresence;
        int demonRank;
        double swordSharpness;
        int allyCount;
        int bossHP;
        int totalDamage;
        int specialMoveReady;
    public:
        battle(int slayerLevel,int hp,double breathingMastery,
        int hasTalisman,char timeOfDay,int demonPresence,
        int demonRank,double swordSharpness,int allyCount,
        int bossHP,int totalDamage,int specialMoveReady){
            this -> slayerLevel = slayerLevel;
            this -> hp = hp;
            this -> breathingMastery = breathingMastery;
            this -> hasTalisman = hasTalisman;
            this -> timeOfDay = timeOfDay;
            this -> demonPresence = demonPresence;
            this -> demonRank = demonRank;
            this -> swordSharpness = swordSharpness;
            this -> allyCount = allyCount;
            this -> bossHP = bossHP;
            this -> totalDamage = totalDamage;
            this -> specialMoveReady = specialMoveReady;
        }

        void scene_1(){
            cout << "[Scene 1] Rank: ";
            double power = slayerLevel * 10 + hp/10 + breathingMastery * 50;
            if(power >= 120){
                cout << "Hashira (power = " << power << ")" << endl;
            }
            else if (80 <= power && power < 120){
                cout << "Elite (power = " << power << ")" << endl;
            }
            else {
                cout << "Novice (power = " << power << ")" << endl;
            }
        }

        void scene_2(){
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
        }

        void scene_3(){
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
        }

        void scene_4(){
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
        }
};

int main(){
    int slayerLevel;
    int hp;
    double breathingMastery;
    int hasTalisman;
    char timeOfDay;
    int demonPresence;
    int demonRank;
    double swordSharpness;
    int allyCount;
    int bossHP;
    int totalDamage;
    int specialMoveReady;

    cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman
    >> timeOfDay >> demonPresence >> demonRank >> swordSharpness
    >> allyCount >> bossHP >> totalDamage >> specialMoveReady;

    cout << fixed << setprecision(1);

    battle s(slayerLevel, hp, breathingMastery, hasTalisman, timeOfDay,
    demonPresence, demonRank, swordSharpness, allyCount, bossHP,
    totalDamage, specialMoveReady);

    s.scene_1();
    s.scene_2();
    s.scene_3();
    s.scene_4();

    return 0;
}