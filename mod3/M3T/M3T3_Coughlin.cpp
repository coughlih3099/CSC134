// CSC 134
// M3T3 - RNG
// Harley Coughlin
// 09/13/2024

#include <iostream>
#include <limits>
#include <random>

using namespace std;


void print_main_menu();
int get_choice();
int roll_dice();


int main() {
    int num_rolls = 0;
    int choice;
    int dice_value;
    bool keep_playing = true;
    cout << "Let's play some Craps!\n";
    while (keep_playing) {
        print_main_menu();
        choice = get_choice();
        if (choice == 1) {
        } else if (choice == 2) {
            keep_playing = false;
        }
    }
    return 0;
}


void print_main_menu() {
    cout << "+-------------------+\n";
    cout << "|     Main Menu     |\n";
    cout << "+-------------------+\n";
    cout << "| 1. Start New Game |\n";
    cout << "| 2. Quit           |\n";
    cout << "+-------------------+\n";
    cout << "\n";
}


int get_choice() {
    int user_input;
    cin >> user_input;
    while (cin.fail() || user_input <= 0) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid integer greater than 0: ";
    }
    return user_input;
}


int roll_dice() {
    int die_1, die_2, total;
    random_device r;
    seed_seq seed(r(), r());
    default_random_engine rando(seed);
    uniform_int_distribution dice(1, 6);
    die_1 = dice(rando);
    die_2 = dice(rando);
    total = die_1 + die_2;
    return total;
}
