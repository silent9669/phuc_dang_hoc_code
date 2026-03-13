#include "water_seven.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
// Task 0
bool readInput(const string &filename,
               char character[FIXED_CHARACTER][MAX_NAME],
               int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER], int &shipHP,
               int &repairCost) {

  ifstream inputfile(filename);

  if (!inputfile)
    return false;
  string name;
  int val1, val2;

  int count = 0;
  while (inputfile >> name >> val1 >> val2) {
    // check name = GOING_MERRY
    if (name == "GOING_MERRY") {
      shipHP = val1;
      repairCost = val2;

      if (shipHP < 0) {
        shipHP = 0;
      } else if (shipHP > 1000) {
        shipHP = 1000;
      }

      if (repairCost < 0) {
        repairCost = 0;
      } else if (repairCost > 3000) {
        repairCost = 3000;
      }
      continue;
    }

    // loop check nhan vat
    int check = -1;
    for (int i = 0; i < count; i++) {
      if (strcmp(character[i], name.c_str()) == 0) {
        check = i;
        break;
      }
    }

    // add nhan vat moi
    if (check == -1) {
      strcpy(character[count], name.c_str());
      hp[count] = val1;
      skill[count] = val2;

      if (hp[count] < 0) {
        hp[count] = 0;
      } else if (hp[count] > 1000) {
        hp[count] = 1000;
      }

      if (skill[count] < 0) {
        skill[count] = 0;
      } else if (skill[count] > 100) {
        skill[count] = 100;
      }

      count++;
    } else {
      // update chi so nhan vat
      hp[check] = val1;
      skill[check] = val2;

      if (hp[check] < 0) {
        hp[check] = 0;
      } else if (hp[check] > 1000) {
        hp[check] = 1000;
      }
      if (skill[check] < 0) {
        skill[check] = 0;
      } else if (skill[check] > 100) {
        skill[check] = 100;
      }
    }
  }
  return true;
}

// Task 1
int damageEvaluation(int shipHP, int repairCost) {
  // xet dieu kien dung
  if (shipHP >= 455) {
    return repairCost;
  }

  // lay sum digit cua shipHP
  int digitSum = 0;
  int temp = shipHP;
  while (temp > 0) {
    digitSum += temp % 10;
    temp /= 10;
  }

  // handle bad cases
  if (digitSum <= 1) {
    return repairCost;
  }
  // check perfect number
  int sum = 1;
  for (int i = 2; i <= sqrt(digitSum); i++) {
    if (digitSum % i == 0) {
      sum += i;
      sum += digitSum / i;
    }
  }

  if (sum == digitSum) {
    return ceil(repairCost * 1.5);
  }

  return repairCost;
}

// Task 2
int conflictSimulation(char character[FIXED_CHARACTER][MAX_NAME],
                       int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
                       int shipHP, int repairCost) {
  // tim skill luffy & usopp
  int skill_Luffy, skill_Usopp;
  for (int i = 0; i < FIXED_CHARACTER; i++) {
    if (strcmp(character[i], "LUFFY") == 0) {
      skill_Luffy = skill[i];
    }
    if (strcmp(character[i], "USOPP") == 0) {
      skill_Usopp = skill[i];
    }
  }
  int conflictIndex =
      skill_Luffy - skill_Usopp + (repairCost / 100) + ((500 - shipHP) / 50);

  // tinh final conflictIndex
  int event_count = 0;
  while (conflictIndex < 255) {
    if (event_count >= 10) {
      return conflictIndex;
    }

    int id = conflictIndex % 6;
    if (id == 0) {
      conflictIndex += 255;
    } else if (id == 1) {
      conflictIndex += 20;
    } else if (id == 2) {
      conflictIndex += 50;
    } else if (id == 3) {
      conflictIndex += 70;
    } else if (id == 4) {
      conflictIndex += 90;
    } else if (id == 5) {
      conflictIndex += 100;
    }
    event_count++;
  }

  return conflictIndex;
}

// Task 3
void resolveDuel(char character[FIXED_CHARACTER][MAX_NAME],
                 int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
                 int conflictIndex, int repairCost,
                 char duel[FIXED_CHARACTER][MAX_NAME]) {

  // tim skill luffy usopp
  int skill_Luffy = 0, skill_Usopp = 0;
  for (int i = 0; i < FIXED_CHARACTER; i++) {
    if (strcmp(character[i], "LUFFY") == 0) {
      skill_Luffy = skill[i];
    }
    if (strcmp(character[i], "USOPP") == 0) {
      skill_Usopp = skill[i];
    }
  }

  // tinh usopp resistance
  int U = skill_Usopp + (conflictIndex / 20) + (repairCost / 500);

  // tim index crewmate con lai
  int members[5];
  int members_count = 0;
  for (int i = 0; i < FIXED_CHARACTER; i++) {
    if (strcmp(character[i], "LUFFY") != 0 &&
        strcmp(character[i], "USOPP") != 0) {
      members[members_count++] = i;
    }
  }

  // tim smallest cost
  int best_cost = INT_MAX;
  int best_mask = -1;
  int best_count = INT_MAX;
  for (int mask = 0; mask < 32; mask++) {
    int total_cost = 0;
    int count = 0;
    int total_support = 0;

    // chon nhan vat
    for (int i = 0; i < 5; i++) {
      if (mask & (1 << i)) {
        int index = members[i];
        total_support += skill[index];
        total_cost += (hp[index] % 10) + 1;
        count++;
      }
    }

    // check luffy co win usopp ko ?
    if (skill_Luffy + total_support >= U) {
      if (total_cost < best_cost ||
          total_cost == best_cost && count < best_count) {
        best_cost = total_cost;
        best_count = count;
        best_mask = mask;
      }
    }
  }

  // copy name nhan vat vao array duel
  int duel_count = 0;
  for (int i = 0; i < 5; i++) {
    if (best_mask & (1 << i)) {
      int index = members[i];
      strcpy(duel[duel_count++], character[index]);
    }
  }
}

// Task 4
void decodeCP9Message(char character[FIXED_CHARACTER][MAX_NAME],
                      int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
                      int conflictIndex, int repairCost, char cipherText[],
                      char resultText[]) {
  // checkSum
  string message = "";
  int checkSum1 = 0;

  for (int i = 0; i < strlen(cipherText); i++) {
    if (cipherText[i] == '#') {
      break;
    } else {
      message += cipherText[i];
      checkSum1 += (int)cipherText[i];
    }
  }
  checkSum1 %= 100;

  int checkSum2 = (cipherText[strlen(cipherText) - 2] - '0') * 10 +
                  (cipherText[strlen(cipherText) - 1] - '0');

  if (checkSum1 != checkSum2) {
    strcpy(resultText, "");
    return;
  }

  // block reversal
  int key = (conflictIndex + repairCost) % 26;
  int B = (key % 5) + 4;

  string reversed_message = "";
  for (int i = 0; i < message.length(); i += B) {
    string block = message.substr(i, B);
    reverse(block.begin(), block.end());
    reversed_message += block;
  }

  // decode message
  string plainText = "";
  for (char c : reversed_message) {
    if (c >= 'A' && c <= 'Z') {
      char decode = (c - 'A' - key + 26) % 26 + 'A';
      plainText += decode;
    } else if (c >= 'a' && c <= 'z') {
      char decode = (c - 'a' - key + 26) % 26 + 'a';
      plainText += decode;
    } else if (c >= '0' && c <= '9') {
      char decode = (c - '0' - (key % 10) + 10) % 10 + '0';
      plainText += decode;
    } else {
      plainText += c;
    }
  }

  // tim keyword cp9 hoac ennies lobby
  if (plainText.find("CP9") != string::npos ||
      plainText.find("ENIESLOBBY") != string::npos) {
    strcpy(resultText, (plainText + "_TRUE").c_str());
  } else {
    strcpy(resultText, (plainText + "_FALSE").c_str());
  }
}

// Task 5
int analyzeDangerLimit(int grid[MAX_GRID][MAX_GRID], int rows, int cols) {

  int maxRowSum = 0;
  int maxCell = -1;

  // loop tim maxRowSum & maxCell
  for (int i = 0; i < rows; i++) {
    int rowSum = 0;
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] >= 0) {
        rowSum += grid[i][j];
      }
      maxCell = max(maxCell, grid[i][j]);
    }
    maxRowSum = max(maxRowSum, rowSum);
  }
  int dangerLimit = maxRowSum + maxCell;
  return dangerLimit;
}

bool evaluateRoute(int grid[MAX_GRID][MAX_GRID], int rows, int cols,
                   int dangerLimit) {

  // check start va end point reachable or NOT
  if (grid[0][0] == -1 || grid[rows - 1][cols - 1] == -1) {
    return false;
  }

  int dp[MAX_GRID][MAX_GRID];

  // flag INT_MAX
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      dp[i][j] = INT_MAX;
    }
  }

  // base case
  dp[0][0] = grid[0][0];

  // fill value tu ben trai
  for (int j = 1; j < cols; j++) {
    if (grid[0][j] != -1 && dp[0][j - 1] != INT_MAX) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
  }

  // fil value tu ben phai
  for (int i = 1; i < rows; i++) {
    if (grid[i][0] != -1 && dp[i - 1][0] != INT_MAX) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
  }

  // fill value cac o con lai
  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      if (grid[i][j] != -1) {
        int from_top = dp[i - 1][j];
        int from_left = dp[i][j - 1];

        // tim best path
        int best = min(from_top, from_left);
        if (best != INT_MAX) {
          dp[i][j] = best + grid[i][j];
        }
      }
    }
  }

  return dp[rows - 1][cols - 1] <= dangerLimit;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
