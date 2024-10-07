// CSC 134
// M4Lab1
// Harley Coughlin
// 10/07/2024


#include <iostream>

using namespace std;

int main() {
    cout << "M4Lab1\n";
    string emoji = "👽";
    const int ROWS = 9;
    const int COLS = 9;

    // print sideways
    for (int i = 0; i < ROWS; i++) {
        cout << emoji << " ";
    }
    cout << endl;


    // print down
    for (int j = 0; j < COLS; j++) {
        cout << emoji << "\n";
    }


    // put both together
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << emoji << " ";
        }
        cout << "\n";
    }
    return 0;
}