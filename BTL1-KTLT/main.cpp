/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2026
 * Date: 27.01.2026
 */

// The library here is concretely set, students are not allowed to include any
// other libraries.

#include "water_seven.h"
using namespace std;

int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const string filename = "opw_tc_01_input";
  char character[FIXED_CHARACTER][MAX_NAME];
  int hp[FIXED_CHARACTER];
  int skill[FIXED_CHARACTER];
  int shipHP, repairCost;
  char duel[FIXED_CHARACTER][MAX_NAME];
  int conflictIndex;
  char cipherText[MAX_NAME] = "AQ 7XK#96"; // Example from PDF
  char resultText[MAX_NAME];

  if (!readInput(filename, character, hp, skill, shipHP, repairCost))
    cout << "can not read" << endl;
  else
    cout << "read" << endl;

  cout << "Damage: " << damageEvaluation(shipHP, repairCost) << endl;

  conflictIndex = conflictSimulation(character, hp, skill, shipHP, repairCost);
  cout << "Conflict Index: " << conflictIndex << endl;

  resolveDuel(character, hp, skill, conflictIndex, repairCost, duel);
  cout << "Duel team members:" << endl;
  for (int i = 0; i < FIXED_CHARACTER; i++) {
    if (strlen(duel[i]) > 0) {
      cout << duel[i] << endl;
    }
  }

  decodeCP9Message(character, hp, skill, conflictIndex, repairCost, cipherText,
                   resultText);
  cout << "Decoded message: " << resultText << endl;

  return 0;
}
