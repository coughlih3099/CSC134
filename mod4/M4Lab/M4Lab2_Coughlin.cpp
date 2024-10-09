// CSC 134
// M3T3 - Craps
// Harley Coughlin
// 10/09/2024

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool play_round();
int roll();

int main() {
    int die1, die2, total;
    int seed;
    bool is_winner;

    cout << "Welcome to the craps table.\n";

    seed = time(0);
    srand(seed);

    is_winner = play_round();
    if (is_winner) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
    // die1 = roll();
    // die2 = roll();
    // die1 = (rand() % 6) + 1;
    // die2 = (rand() % 6) + 1;
    // total = die1 + die2;
    // cout << "You rolled " << die1 << " + " << die2 << " = " << total << "\n";
    // if (total == 7 || total == 11) {
    //     cout << "You win!" << endl;
    // } else if (total == 2 || total == 3 || total == 12) {
    //     cout << "Craps!" << endl;
    // } else {
    //     //TODO: handle "rolling a point"
    //     cout << "You're point is: " << total << "\n";
    //     cout << "We'll handle this later." << endl;
    // }

    return 0;
}

bool play_round() {
    bool is_winner = false;
    int die1 = roll();
    int die2 = roll();
    int total = die1 + die2;
    int point;

    cout << "You rolled "
         << "die1" << " + "
         << "die2" << " = "
         << total << endl;

    if (total == 7 || total == 11) {
        is_winner = true;
    } else if (total == 2 || total == 3 || total == 12) {
        is_winner = false;
    } else {
        cout << "Your point is: " << total << endl;
        point = total;
        total = roll() + roll();

        do {
            total = roll() + roll();
            cout << "Come on lucky " << point << " rolled: " << total << endl;
            if (total == 7) {
                is_winner = false;
            }
            if (total == point) {
                is_winner = true;
            }
        } while (total != 7 && total != point);


    }
    return is_winner;
}

int roll() {
    int die = (rand() % 6) + 1;
    return die;
}
