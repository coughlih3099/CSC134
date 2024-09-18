// CSC 134
// M3Lab2 - Grades
// Harley Coughlin
// 09/13/2024


#include <iostream>
#include <limits>

using namespace std;


int get_numeric_grade();
char get_grade_letter(int number_grade);


int main() {
    bool keep_going = true;
    int number_grade;
    char grade_letter;
    cout << "Enter your numerical grade: ";
    number_grade = get_numeric_grade();
    grade_letter = get_grade_letter(number_grade);
    cout << "Your letter grade is: " << grade_letter << endl;
    return 0;
}


int get_numeric_grade() {
    int user_input;
    cin >> user_input;
    while (cin.fail() || user_input < 0 || user_input > 100) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer between 0 and 100: ";
        cin >> user_input;
    }
    return user_input;
}


char get_grade_letter(int number_grade) {
    char grade_letter;
    if (number_grade < 60) {
        grade_letter = 'F';
    } else if (number_grade < 70) {
        grade_letter = 'D';
    } else if (number_grade < 80) {
        grade_letter = 'C';
    } else if (number_grade < 90) {
        grade_letter = 'B';
    } else if (number_grade <= 100) {
        grade_letter = 'A';
    }
    return grade_letter;
}
