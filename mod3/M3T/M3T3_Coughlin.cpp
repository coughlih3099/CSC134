// CSC 134
// M3T3 - Craps
// Harley Coughlin
// 09/25/2024

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll() {
    // get a random number from 1 to 6
    int die = (rand() % 6) + 1;
    return die;
}

int main() {
    int die1, die2, total;
    int seed;

    cout << "Welcome to the craps table.\n";
    // cout << "Enter your lucky number: ";
    // cin >> seed;
    /* cout << "Enter your two dice rolls\n";
    * cout << "Die 1: ";
    * cin >> die1;
    * cout << "Die 2: ";
    * cin >> die2;
    */

    seed = time(0);
    srand(seed);
    die1 = roll();
    die2 = roll();
    //die1 = (rand() % 6) + 1;
    //die2 = (rand() % 6) + 1;

    total = die1 + die2;
    cout << "You rolled " << die1 << " + " << die2 << " = " << total << "\n";

    if (total == 7 || total == 11) {
        cout << "You win!" << endl;
    } else if (total == 2 || total == 3 || total == 12) {
        cout << "Craps!" << endl;
    } else {
        //TODO: handle "rolling a point"
        cout << "You're point is: " << total << "\n";
        cout << "We'll handle this later." << endl;
    }

    return 0;
}
