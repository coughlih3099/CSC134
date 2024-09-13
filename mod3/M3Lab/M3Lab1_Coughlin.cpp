// CSC 134
// MLab1 - Ifs
// Harley Coughlin
// 09/13/2024


#include <iostream>
#include <limits>

using namespace std;


int get_choice();


int main() {
    int choice;
    bool keep_going = true;
    cout << "You are at a crossroads, do you take the popular path?\n";
    cout << "Or do you take the path less traveled?\n";
    cout << "------------------------------------------------------\n";
    cout << "Enter 1 for the popular path,\n2 for the path less traveled: ";
    choice = get_choice();
    cout << "\n";
    if (choice == 1) {
        cout << "Congratulations, the path, while in disrepair, is traversable\n";
    } else {
        cout << "Since the path is less traveled, it is poorly maintained\n";
        cout << "and is also home to a band of brigrands\n";
    }
    cout << "Good luck with your travels" << endl;
    return 0;
}


int get_choice() {
    int user_input;
    cin >> user_input;
    while (cin.fail() || user_input < 1 || user_input > 2) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter 1 or 2: ";
        cin >> user_input;
    }
    return user_input;
}
