// CSC 134
// M4HW1 - Times Tables - Bronze
// Harley Coughlin
// 10/09/2024


/**
 * Basic Functionality:
 * output of the program should look like "5 times 1 is 5."
 * 
 * Bronze:
 * Use a while loop to print the 5 times tables using the above format from 1 to 12.
 */


#include <iostream>


using namespace std;


int main() {
    const int NUMBER = 5;
    const int TIMES_MIN = 1;
    const int TIMES_MAX = 12;

    cout << "M4HW1 - Times Tables\n\n";
    for (int i = TIMES_MIN; i <= TIMES_MAX; i++) {
        cout << NUMBER << " times " << i << " is " << NUMBER * i << "\n";
    }


    return 0;
}