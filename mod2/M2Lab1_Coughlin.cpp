// CSC 134
// M2Lab1
// Harley Coughlin
// 08/25/2024

#include <ios>
#include <iostream>
#include <iomanip>


int main() {
    using std::cout, std::cin, std::endl;

    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;

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

    cout << "The volume of the crate is " << volume << " cubic feet.\n";
    cout << "Cost to build: $" << charge << endl;
    cout << "Charge to customer: $" << charge << endl;
    cout << "Profit: $" << profit << endl;
    return 0;
}
