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
    int choice;
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


void play_game() {
    bool done = false;
    int choice;
    int dice_value;
    int num_rolls = 0;
    int point_num;
    while (!done) {
        print_game_menu();
        choice = get_choice();
        if (choice == 1) {
            dice_value = roll_dice();
            num_rolls++;
            cout << "You rolled: " << dice_value << "\n";
            if (num_rolls == 1) {
                switch (dice_value) {
                    case 2:
                    case 3:
                    case 12:
                        cout << "Craps!\n";
                        done = true;
                        break;
                    case 7:
                    case 11:
                        cout << "Win!\n";
                        done = true;
                        break;
                    default:
                        point_num = dice_value;
                }
            } else {
                if (dice_value == point_num) {
                    cout << "You win\n";
                    done = true;
                } else if (dice_value == 7) {
                    cout << "You lose\n";
                    done = true;
                }
            }
        } else if (choice == 2) {
            done = true;
        }
    }
}


void print_game_menu() {
    cout << "+---------------+\n";
    cout << "|   Game Menu   |\n";
    cout << "+---------------+\n";
    cout << "| 1. Roll Dice  |\n";
    cout << "| 2. Quit       |\n";
    cout << "+---------------+\n";
    cout << "\n";
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
