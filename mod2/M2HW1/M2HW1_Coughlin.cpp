/*
 *  CSC134
 *  M2HW1 - Silver
 *  Harley Coughlin
 *  08/26/2024
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
using namespace std;

void print_menu();
void banking_sim();
void general_crates();
void pizza_party();
void cheering();

int main() {
    bool keep_going = true;
    int choice;
    while (keep_going) {
        print_menu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                banking_sim();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                general_crates();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 3:
                pizza_party();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 4:
                cheering();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 5:
                // I feel like there could be a better way to do this
                banking_sim();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                general_crates();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                pizza_party();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cheering();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 6:
                cout << "\nGoodbye!\n" << endl;
                keep_going = false;
                break;
            default:
                cout << "Hey man, that wasn't 1-6\n\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}


void print_menu() {
    cout << "\nM2HW1: The Menu!\n";
    cout << "----------------\n";
    cout << "1. Question 1 (banking sim)\n";
    cout << "2. Question 2 (general crates)\n";
    cout << "3. Question 3 (pizza party)\n";
    cout << "4. Question 4 (cheering)\n";
    cout << "5. All of the above\n";
    cout << "6. Quit\n";
    cout << "Please enter 1-6 (there's no validation, so): ";
}


void banking_sim() {
    /* 
     *  Question 1
     *  Write a program that simulates banking transactions
     *  suggestions: allow whitespace in name, print all money w/ 2 decimal places.
     */
    cout << "\nQuestion 1: \n";

    double account_balance, amount_deposit, amount_withdrawal, account_total;
    string user_name;

    cout << "Please enter your name: ";
    getline(cin, user_name);
    cout << "Please enter the starting account balance: ";
    cin >> account_balance;
    cout << "Please enter amount of deposit: ";
    cin >> amount_deposit;
    cout << "Please enter amount of withdrawal: ";
    cin >> amount_withdrawal;
    cout << "\n";

    account_total = account_balance + amount_deposit - amount_withdrawal;

    // creating a "random" number
    // fun that since its seed is the user_name, you'll get the same value
    // each time the same name is put in, adding "consistency"
    seed_seq seed1(user_name.begin(), user_name.end());
    minstd_rand generator(seed1);
    cout << "---------Account Details---------\n";
    cout << "Account name: " << user_name << "\n";
    cout << "Account number: " << generator() << "\n";
    cout << "Account balance: $" << fixed << setprecision(2) << account_total
         << "\n" << endl;
}


void general_crates() {
    /*
    * Question 2: modify M2Lab1, 
    * cost per ft^3 = 0.3, 
    * charge per ft^3 = 0.52,
    * suggestions: print all money with 2 decimal places
    */
    cout << "\nQuestion 2:\n";
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    double length, width, height, volume;
    double cost, charge, profit;

    cout << std::setprecision(2) << std::fixed << std::showpoint;
    cout << "Enter the dimensions of the crate (in feet):\n";
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge - cost;

    cout << "-----------------\n";
    cout << "The volume of the crate is " << volume << " cubic feet.\n";
    cout << "Cost to build: $" << cost << "\n";
    cout << "Charge to customer: $" << charge << "\n";
    cout << "Profit: $" << profit << "\n" << endl;
}


void pizza_party() {
    /*
    * Question 3: pizza party
    * we're throwing a pizza party,
    * each visitor gets 3 slices,
    * ask the amount of pizzas being ordered,
    * amount of slices per pizza, and how many visitors.
    * output how many pieces of pizza are leftover.
    * no suggestions.
    */
    cout << "\nQuestion 3\n";
    const int SLICES_PER_VISITOR = 3;
    int amount_of_pizzas, slices_per_pizza, amount_of_visitors, leftover_pizza;
    cout << "How many pizzas are you ordering? ";
    cin >> amount_of_pizzas;
    cout << "How many slices per pizza? ";
    cin >> slices_per_pizza;
    cout << "How many visitors are attending? ";
    cin >> amount_of_visitors;

    int total_slices_ordered = (amount_of_pizzas * slices_per_pizza);
    int slices_needed = (amount_of_visitors * SLICES_PER_VISITOR);
    leftover_pizza = total_slices_ordered - slices_needed;
    int pizzas_still_needed = abs(leftover_pizza) / slices_per_pizza;

    cout << "-----------------\n";
    if (leftover_pizza < 0) {
        cout << "You didn't order enough pizza! You're " << abs(leftover_pizza);
        // aren't ternaries fun?
        cout << ((leftover_pizza == 1) ? " slices " : " slice ");
        cout << "short. You need to order at least ";
        cout << ((pizzas_still_needed < 1) ? 1 : pizzas_still_needed);
        cout << " more pizza\n" << endl;
    } else if (leftover_pizza == 0) {
        cout << "Nice! You ordered the perfect amount of pizza!\n" << endl;
    } else {
        cout << "You bought too much pizza! You have ";
        cout << leftover_pizza << " slices left\n" << endl;
    }
}

void cheering() {
    cout << "TODO: Implement" << endl;
}
