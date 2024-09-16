// CSC 134
// M3T1 - 
// Harley Coughlin
// 09/16/2024


#include <iostream>

using namespace std;

int main() {
    // setup variables
    double width1, width2, length1, length2;
    double area1, area2;

    cout << "M3T1 - Area of two rectangles" << endl;
    cout << "Width of first rectangle: ";
    cin >> width1;
    cout << "Length of first rectangle: ";
    cin >> length1;
    cout << "Width of second rectangle: ";
    cin >> width2;
    cout << "Length of second rectangle: ";
    cin >> length2;
    cout << "\n";

    // calc area
    area1 = width1 * length1;
    area2 = width2 * length2;

   // print results
   cout << "Area of first triangle: " << area1 << "\n";
   cout << "Area of second triangle: " << area2 << endl;
}