#include <iostream>
#include <iomanip>
using namespace std;

// CSC 134
// M2Lab1 - Case Study
// Harley Coughlin
// 09/09/2024

int main() {
    // setup variable
    string name;
    int length;
    int width;
    int height;
    int volume; // in cubic ft

    // price relaped variables - in $
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double PRICE_PER_CUBIC_FOOT = 0.5;
    double cost;
    double customer_price;
    double profit;

    // say hi
    /*
    cout << "Hi, what's your name? ";
    cin >> name;
    cout << "Nice to meet you, " << name << "\n\n";
    */

    // ask user questions
    cout << "Let's get the crate dimensions. (in feet)" << endl;
    cout << "What's the length? ";
    cin >> length;
    cout << "What's the width? ";
    cin >> width;
    cout << "Finally, what's the height? ";
    cin >> height;
    cout << "\n";

    // TODO: calculations
    volume = length * width * height;
    // cost calcs
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * PRICE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    // output
    cout << "Crate is: " << length << " x " << width << " x " << height << "\n";
    cout << "Total volume is: " << volume << " cubic feet." << "\n\n";
    // TODO: output cost, price, and profit
    cout << setprecision(2) << fixed;
    cout << "Cost for the crate is:" << setw(4) << "$" << cost << "\n";
    cout << "Customer Price is:" << setw(8) << "$" << customer_price << "\n";
    cout << "Profit for the crate is: $" << profit << endl;

    return 0;

}