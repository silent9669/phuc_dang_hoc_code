#include <fstream>
#include <iostream>
#include <string>

void studentGrading(std::string fileName) {
  std::ifstream f(fileName);
  int N;
  f >> N;

  int countA = 0, countB = 0, countC = 0, countD = 0;

  for (int i = 0; i < N; i++) {
    double nmdt, ktlt, dsa, ppl;
    f >> nmdt >> ktlt >> dsa >> ppl;

    double gpa = (nmdt + ktlt + dsa + ppl) / 4.0;
    bool no_sub_below_5 = (nmdt >= 5 && ktlt >= 5 && dsa >= 5 && ppl >= 5);

    if (gpa >= 8 && no_sub_below_5)
      countA++;
    else if (gpa >= 6.5 && no_sub_below_5)
      countB++;
    else if (gpa >= 5 && no_sub_below_5)
      countC++;
    else
      countD++;
  }

  std::cout << "A: " << countA << '\n';
  std::cout << "B: " << countB << '\n';
  std::cout << "C: " << countC << '\n';
  std::cout << "D: " << countD << '\n';

  f.close();
}
