#include <iostream>
#include <cstring>

using namespace std;



void printFirstRepeatedWord(char str[]) {
    char danhSachTu[100][31];
    int soTuDaGhep = 0;
    int i = 0;
    bool timThayLap = false;
    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        int viTriKyTu = 0;
        while (str[i] != '\0' && str[i] != ' ') {
            if (viTriKyTu < 30) {
                danhSachTu[soTuDaGhep][viTriKyTu++] = str[i];
            }
            i++;
        }
        danhSachTu[soTuDaGhep][viTriKyTu] = '\0';
        for (int p = 0; p < soTuDaGhep; p++) {
            int k = 0;
            bool trungKhop = true;
            
            while (danhSachTu[soTuDaGhep][k] != '\0' || danhSachTu[p][k] != '\0') {
                if (danhSachTu[soTuDaGhep][k] != danhSachTu[p][k]) {
                    trungKhop = false;
                    break;
                }
                k++;
            }

            if (trungKhop) {
                std::cout << danhSachTu[soTuDaGhep] << std::endl;
                timThayLap = true;
                break;
            }
        }

        if (timThayLap) {
            return;
        }

        soTuDaGhep++;
    }

    if (!timThayLap) {
        std::cout << "No Repetition" << std::endl;
    }
}

