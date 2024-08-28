// CSC 134
// M1Lab
// Harley Coughlin
// 08/26/2024

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name;
    int num_apples;
    double price_per_apple;
    double total_cost;

    cout << "What is your name? ";
    cin >> name;
    cout << "How many apples in stock? ";
    cin >> num_apples;
    cout << "How much is one apple? ";
    cin >> price_per_apple;
    cout << endl;

    cout << "Welcome to the " << name << " orchard!" << endl;

    total_cost = num_apples * price_per_apple;

    cout << fixed << setprecision(2);

    cout << "You have " << num_apples << " apples" << endl;
    cout << "Each apple costs $" << price_per_apple << endl;
    cout << "The total is: $" << total_cost << endl;
}