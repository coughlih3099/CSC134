// CSC 134
// M2T2
// Harley Coughlin
// 08/25/2024


#include <iostream>

using namespace std;


int main() {
    // This program will simulate an apple orchard.
    // The owner's name
    string name;
    // number of apples owned
    int apples = 100;
    // price per apple
    double pricePerApple = 0.25;

    // calculate the total price of the apples
    double totalPrice = apples * pricePerApple;

    // print all the info about the orchard
    cout << "Welcome to " << name;
    cout << "'s apple orchard." << endl;
    cout << "We have " << apples;
    cout << " apples in stock" << endl;
    cout << "Apples are currently $";
    cout << pricePerApple << " each." << endl;

    // Final line, to print totalPrice
    cout << "If you want them all, that will be $" << totalPrice << endl;

    return 0;
}
