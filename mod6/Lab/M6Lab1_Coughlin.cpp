// CSC 134
// M6Lab1 - Raspberry Roulette
// Harley Coughlin
// 11/13/2024

#include <iostream>

using namespace std;

// constants
const int NUM_ROUNDS = 3;
const int RED = 1;  // live
const int BLACK = 0;  // blank

int main() {
    int chamber[] = {BLACK, BLACK, RED, BLACK, RED};

    for (int round : chamber) {
        if (round == RED) {
            cout << "RED ";
        }
        if (round == BLACK) {
            cout << "BLACK ";
        }
    }
    cout << endl;

    return 0;
}