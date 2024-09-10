// CSC 134
// M3HW - Bronze
// Harley Coughlin
// 09/10/2024


#include <iostream>
#include <limits>
#include <string>

using namespace std;

void print_main_menu();
void chat_bot();


int main() {
    bool keep_going = true;
    int choice;
    while (keep_going) {
        print_main_menu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                chat_bot();
                break;
            case 5:
                chat_bot();
                break;
            case 6:
                cout << "\nGoodbye!\n" << endl;
                keep_going = false;
                break;
            default:
                cout << "Please choose a valid option\n";
        }
    }
}


/**
* prints the main menu
*/
void print_main_menu() {
    cout << "\nM3HW: The Menu!\n";
    cout << "---------------\n";
    cout << "1. Question 1 (chat bot)\n";
    cout << "5. All of the above\n";
    cout << "6. Quit\n";
    cout << "Please enter 1-6: ";
}

/**
* chat bot that follows a specific script
* prints 3 different responses
*/
void chat_bot() {
    string reply;
    cout << "\nQuesion 1. Chat bot\n";
    cout << "-------------------\n";
    for (int i = 1; i <= 3; i++) {
        cout << "Sample Run " << i << "\n";
        cout << "Hello, I'm a C++ program!\n";
        cout << "Do you like me? Please type yes or no.\n";
        cin >> reply;
        if (reply == "yes") {
            cout << "That's great! I'm sure we'll get along.\n";
        } else if (reply == "no") {
            cout << "Well, maybe you'll learn to like me later.\n";
        } else {
            cout << "If you're not sure... That's OK.\n";
        }
        cout << "\n";
    }
}
