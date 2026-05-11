#include <iostream>
#include <string>

using namespace std;

struct SCP {
  int id;
  int objClass;
  string speConProcedures;
  string description;
  string *addendums;
  int numAddendums;
};

void addAddendum(SCP &obj, string addendum) {
  int newSize = obj.numAddendums + 1;
  string *newAddendums = new string[newSize];

  for (int i = 0; i < obj.numAddendums; i++) {
    newAddendums[i] = obj.addendums[i];
  }

  newAddendums[newSize - 1] = addendum;

  if (obj.addendums != nullptr) {
    delete[] obj.addendums;
  }

  obj.addendums = newAddendums;
  obj.numAddendums = newSize;
}
