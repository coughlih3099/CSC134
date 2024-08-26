/*
 *  CSC134
 *  M2HW1 - Bronze
 *  Harley Coughlin
 *  08/26/2024
 */

#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

void banking_sim();

int main() {
    banking_sim();
    return 0;
}


void banking_sim() {
    /* 
     *  Question 1
     *  Write a program that simulates banking transactions
     *  suggestions: allow whitespace in name, print all money w/ 2 decimal places.
     */
    cout << "Question 1: \n";

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
    cout << "Account balance: $" << fixed << setprecision(2) << account_total << endl;
}

