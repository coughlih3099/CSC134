// CSC 134
// M4HW1 - Times Tables - Gold
// Harley Coughlin
// 10/09/2024


/**
 * Basic Functionality:
 * output of the program should look like "5 times 1 is 5."
 * 
 * Bronze:
 * Use a while loop to print the 5 times tables using the above format from 1 to 12.
 * 
 * Silver:
 * Instead of doing 5, ask user for a number between 1 and 12
 * 
 * Gold:
 * Add input validation.
 */


#include <iostream>
#include <limits>
#include <cassert>
#include <cstdint>


using namespace std;


int get_user_number();


int main() {
    const int TIMES_MIN = 1;
    const int TIMES_MAX = 12;
    cout << "Enter a number (1-12): ";
    int user_number = get_user_number();
    assert(user_number >= 1 && "User number is less than 1.");
    assert(user_number <= 12 && "User number is greater than 12.");

    cout << "M4HW1 - Times Tables\n\n";
    for (int i = TIMES_MIN; i <= TIMES_MAX; i++) {
        cout << user_number << " times " << i << " is " << user_number * i << "\n";
    }


    return 0;
}

int get_user_number() {
    int user_number;
    cin >> user_number;
    while (cin.fail() || user_number < 1 || user_number > 12){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number between 1 and 12: ";
        cin >> user_number;
    }
    assert(user_number >= 1 && "User number is less than 1.");
    assert(user_number <= 12 && "User number is greater than 12.");
    return user_number;
}