#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void calMoney(string price, string buy) {
    ifstream fPrice(price);
    int N;
    fPrice >> N;
    int priceMap[10001] = {0};
    for (int i = 0; i < N; i++) {
        int id, p;
        fPrice >> id >> p;
        priceMap[id] = p;
    }
    fPrice.close();

    ifstream fBuy(buy);
    int M;
    fBuy >> M;

    string tokens[10000];
    int tCount = 0;
    while (fBuy >> tokens[tCount]) tCount++;
    fBuy.close();

    int idx = 0;
    for (int i = 0; i < M; i++) {
        string name = tokens[idx++];
        int sum = 0;
        while (idx < tCount && tokens[idx][0] >= '0' && tokens[idx][0] <= '9') {
            int id  = stoi(tokens[idx++]);
            int qty = stoi(tokens[idx++]);
            sum += priceMap[id] * qty;
        }
        cout << name << " " << sum << endl;
    }
}
