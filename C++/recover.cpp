#include <iostream>

using namespace std;

void recover(char signal[]) {
  for (int i = 0; signal[i] != '\0'; i++) {
    if (signal[i] >= 'a' && signal[i] <= 'z')
      signal[i] = signal[i] - 'a' + 'A';
    else if (signal[i] >= 'A' && signal[i] <= 'Z') {
      signal[i] = signal[i] - 'A' + 'a';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char signal[] = "I waNT tO hAVe 10 MaRk In FudaMenTAL of PRogRamInG couRsE.";
  recover(signal);
  cout << signal;
  return 0;
}
