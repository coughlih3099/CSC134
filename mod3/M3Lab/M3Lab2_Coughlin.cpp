// CSC 134
// M3Lab2 - Grades
// Harley Coughlin
// 09/13/2024


#include <iostream>
#include <limits>

using namespace std;


int get_grade();


int main() {
    return 0;
}


int get_grade() {
    int user_input;
    cin >> user_input;
    while (cin.fail() || user_input < 0 || user_input > 100) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer between 0 and 100: ";
        cin >> user_input;
    }
    return user_input;
}
