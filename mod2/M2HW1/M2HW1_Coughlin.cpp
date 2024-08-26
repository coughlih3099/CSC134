/*
 *  CSC134
 *  M2HW1 - Bronze
 *  Harley Coughlin
 *  08/26/2024
 */

#include <iostream>
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
    cin >> user_name;
    cout << "Please enter the starting account balance: ";
    cin >> account_balance;
    cout << "Please enter amount of deposit: ";
    cin >> amount_deposit;
    cout << "Please enter amount of withdrawal: ";
    cin >> amount_withdrawal;
    cout << "\n";

    account_total = account_balance + amount_deposit - amount_withdrawal;

    cout << "---------Account Details---------\n";
    cout << "Account name: " << user_name << "\n";
    // TODO(coughlih3099):
    // replace with randnumber
    cout << "Account number: 000001\n";
    cout << "Account balance: $" << account_total << endl;
}

