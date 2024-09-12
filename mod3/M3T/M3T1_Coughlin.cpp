// CSC 134
// M3T1 - Area of Rectangles
// Harley Coughlin
// 09/12/2024


#include <iostream>
#include <limits>

using namespace std;

double get_double();


int main() {
    double rectangles[2][2];
    double area1, area2;
    cout << "This program calculates the area of two triangles\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                cout << "Enter the length for triangle " << i + 1 << ": ";
            } else {
                cout << "Enter the width for triangle " << i + 1 << ": ";
            }
            rectangles[i][j] = get_double();
        }
    }
    area1 = rectangles[0][0] * rectangles[0][1];
    area2 = rectangles[1][0] * rectangles[1][1];
    cout << "Area 1: " << area1 << "\n";
    cout << "Area 2: " << area2 << endl;
    return 0;
}

/**
* Prompts user for a double
* @return double > 0
*/
double get_double() {
    double user_input = -1;
    cin >> user_input;
    while (cin.fail() || user_input <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid decimal number greater than 0.0: ";
        cin >> user_input;
    }
    return user_input;
}


