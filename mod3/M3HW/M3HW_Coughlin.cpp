// CSC 134
// M3HW - Bronze
// Harley Coughlin
// 09/10/2024


#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void print_main_menu();
void chat_bot();
void receipt_calculator();


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
            case 2:
                receipt_calculator();
                break;
            case 5:
                chat_bot();
                receipt_calculator();
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


void print_main_menu() {
    cout << "\nM3HW: The Menu!\n";
    cout << "---------------\n";
    cout << "1. Question 1 (chat bot)\n";
    cout << "2. Question 2 (receipt calculator)\n";
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
    cout << "\nQuestion 1. Chat bot\n";
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


/**
* Prompts user for meal price
* @return user_input
*/
double get_double() {
    double user_input = -1;
    cin >> user_input;
    while (cin.fail() || user_input <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number greater than 0: ";
        cin >> user_input;
    }
    return user_input;
}


/**
* prompts user for dine in or takeout
* @return true if dining in
*/
bool get_dining_preference() {
    int user_input;
    const bool dining_in = true;
    const bool to_go = false;
    cout << "Please enter 1 if dining in, or 2 if it is to go: ";
    cin >> user_input;
    while (cin.fail() || user_input < 1 || user_input > 2) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter 1 or 2: ";
        cin >> user_input;
    }
    return user_input == 1 ? dining_in : to_go;
}


/**
* Asks for the price of a meal, asks if dine-in or take out,
* if the order is dine-in add a 15% tip,
* total is calculated using an 8% tax
*/
void receipt_calculator() {
    const double TAX_RATE = 0.08;
    const double TIP_RATE = 0.15;
    double tip_amount = 0;
    double total, tax_amount;
    bool dining_in;
    double meal_price = 0;

    cout << "\nQuestion 2. Receipt Calculator\n";
    cout << "-------------------------------\n";
    cout << "Please enter the price of the meal: $";
    do {
        meal_price = get_double();
    } while (meal_price <= 0);
    dining_in = get_dining_preference();
    if (dining_in) {
        tip_amount = meal_price * TIP_RATE;
    }
    tax_amount = meal_price * TAX_RATE;
    total = meal_price + tax_amount + tip_amount;
    // well I don't like how things are lining up so yeah, some formatting
    int for_formatting = static_cast<int>(meal_price) * 1000;
    int count = 0;
    while (for_formatting > 0) {
        for_formatting /= 10;
        count++;
    }
    cout << "--------------------------\n";
    cout << setprecision(2) << fixed;
    cout << "The meal price is: $" << meal_price << "\n";
    if (dining_in) {
        cout << "The tip is :" << setw(8) << "$" << setw(count) << setfill(' ') << tip_amount << "\n";
    }
    cout << "The tax is:" << setw(9) << "$" << setw(count) << setfill(' ') << tax_amount << "\n";
    cout << "The total is :" << setw(6) << "$" << total << "\n";
}
