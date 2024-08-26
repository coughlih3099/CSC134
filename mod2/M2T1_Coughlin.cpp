// CSC134
// M2T1
// Harley Coughlin
// 08/25/2024

#include <iomanip>
#include <iostream>

using namespace std; // my lsp likes to yell at me for this

int main() {
    // Declare variables
    double meal_price = 5.99;
    double tax_percent = .08;
    double tax_amount, total;

    // Calculate the values
    tax_amount = meal_price * tax_percent;
    total = tax_amount + meal_price;

    // Print the results
    cout << "The meal price is: $" << meal_price << "\n";
    cout << "The tax percentage is: " << tax_percent * 100 << "%\n";
    cout << "The tax amount is: $" << fixed << setprecision(2) << tax_amount << "\n";
    cout << "The total is: $" << fixed << setprecision(2) << total << endl;

    return 0;
}
