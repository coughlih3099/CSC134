// CSC 134
// M4T2 - Input Validation
// Harley Coughlin
// 10/02/2024

#include <iostream>

using namespace std;

void counting();

int main()
{
    // counting();

    // Input validation example
    const int MIN_PLAYERS = 1;
    const int MAX_PLAYERS = 4;
    int num_players;
    cout << "How many players? (" << MIN_PLAYERS << "-" << MAX_PLAYERS << "): ";
    cin >> num_players;
    while (num_players < MIN_PLAYERS || num_players > MAX_PLAYERS) {
        cout << "Please enter a number between " << MIN_PLAYERS << " and " << MAX_PLAYERS << ": ";
        cin >> num_players;
    }
    cout << "You're playing with " << num_players << " players." << endl;

    // ready to start?
    string ready;
    do {
        cout << "waiting...\n";
        cout << "Are all players ready? (yes/no) ";
        cin >> ready;
    } while (ready != "yes");

    return 0;
}

void counting() {
    cout << "Version 1: While\n";
    int num = 0;
    while (num < 5) {
        cout << num << "\n";
        num++;
    }
    cout << endl;
    cout << "Version 2: For\n";
    for (int n = 0; n < 5; n++) {
        cout << n << "\n";
    }
    cout << endl;
}
