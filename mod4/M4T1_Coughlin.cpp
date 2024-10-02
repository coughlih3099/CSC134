// CSC 134
// M4T1 - Basic Loops
// Harley Coughlin
// 09/30/2024

#include <iostream>

using namespace std;

//updated to use multiple functions
void q1();
void q2();

int main() {
    q1();
    q2();

    return 0;
}


// Question 1
void q1() {
    cout << "M4T1\n";
    // part 1 - simple loop
    cout << "Simple loop\n";
    int num = 0;
    while (num < 5) {
        cout << "num = " << (num + 1) << "\n";
        num++;
    }
    cout << "Finished" << endl;
    return;
}


// Question 2
void q2() {

    // part 2 - numbers and squares
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 10;

    //header
    cout << "\n";
    cout << "Number\t\tNumber Squared\n";
    cout << "----------------------------\n";
    int num = MIN_NUMBER;
    while (num <= MAX_NUMBER) {
        cout << num << "\t\t" << (num * num) << "\n";
        num++;
    }
    return;
}
