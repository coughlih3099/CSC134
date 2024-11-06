#include <iostream>
#include <iomanip>
using namespace std;

// CSC 134
// M5HW1
// Gabriel Bennett, Harley Coughlin
// 11/04/2024

void printMenu();
void rainfall();
string getMonth();
double getRainfall(string month);
void blockVolume();
double getDouble(string side);
void romanNumeral();
int getNum();
void geometryCalculator();
void printGeometryCalculatorMenu();
void areaCircle();
void areaRectangle();
void areaTriangle();
void distanceTraveled();

int main() {
    int decision;

    printMenu();
    cin >> decision;
    while(decision != 6) {
        switch (decision) {
            case 1:
                rainfall();
                break;
            case 2:
                blockVolume();
                break;
            case 3:
                romanNumeral();
                break;
            case 4:
                geometryCalculator();
                break;
            case 5:
                distanceTraveled();
                break;
        }
        printMenu();
        cin >> decision;
    }
    
}

void printMenu() {
    cout << "Please select a program." << endl;
    cout << "1. Average Rainfall" << endl;
    cout << "2. Area of a Block" << endl;
    cout << "3. Roman Numeral Converter" << endl;
    cout << "4. Geometry Calculator" << endl;
    cout << "5. Distance Traveled" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter the number: ";
}

void rainfall() {
    string month1, month2, month3;
    double rainfall1, rainfall2, rainfall3;
    double average;
    month1 = getMonth();
    rainfall1 = getRainfall(month1);
    month2 = getMonth();
    rainfall2 = getRainfall(month2);
    month3 = getMonth();
    rainfall3 = getRainfall(month3);
    average = (rainfall1 + rainfall2 + rainfall3) / 3;
    cout << fixed << setprecision(2) << "The average rainfall for " <<
            month1 << ", " << month2 << ", and " << month3 <<
            " is " << average << " inches." << endl;
}

string getMonth() {
    string month;
    cout << "Enter month: ";
    cin >> month;
    return month;
}

double getRainfall(string month) {
    double rainfall;
    cout << "Enter rainfall for " << month << ": ";
    cin >> rainfall;
    return rainfall;
}

void blockVolume() {
    double width, length, height, volume;

    width = getDouble("width");
    length = getDouble("length");
    height = getDouble("height");

    volume = width * length * height;

    cout << "The volume is: " << volume << endl;
}

double getDouble(string side) {
    double value;
    cout << "Enter the " << side << " value, it can't be less than or equal to 0: ";
    cin >> value;
    while (value <= 0) {
        cout << "Please enter a value greater than 0: ";
        cin >> value;
    }
    return value;
}

void romanNumeral() {
    int num = 0;
    string roman;
    while (num < 1 || num > 10) {
        num = getNum();
    }
    switch(num) {
        case 1:
            roman = "I";
            break;
        case 2:
            roman = "II";
            break;
        case 3:
            roman = "III";
            break;
        case 4:
            roman = "IV";
            break;
        case 5:
            roman = "V";
            break;
        case 6:
            roman = "VI";
            break;
        case 7:
            roman = "VII";
            break;
        case 8:
            roman = "VIII";
            break;
        case 9:
            roman = "IX";
            break;
        case 10:
            roman = "X";
            break;
    }
    cout << "The Roman numeral version of " << num << " is " << roman << "." << endl;
}

int getNum() {
    int num;
    cout << "Enter a number (1 - 10): ";
    cin >> num;
    return num;
}

void geometryCalculator() {
    int choice;
    printGeometryCalculatorMenu();
    cin >> choice;
    while (choice != 4) {
        switch(choice) {
            case 1:
                areaCircle();
                break;
            case 2:
                areaRectangle();
                break;
            case 3:
                areaTriangle();
                break;
            case 4:
                break;
            default:
                cout << "Error: Please input a valid number." << endl;
        }
        printGeometryCalculatorMenu();
        cin >> choice;
    }
    
}

void printGeometryCalculatorMenu() {
    cout << "\n1. Calculate the Area of a Circle\n"
         << "2. Calculate the Area of a Rectangle\n"
         << "3. Calculate the Area of a Triangle\n"
         << "4. Quit\n"
         << "Enter your choice (1 - 4): ";
}

void areaCircle() {
    double radius;
    radius = getDouble("radius");
    double area = 3.14159 * (radius * radius);
    cout << "The area is: " << area << endl;
}

void areaRectangle() {
    double length, width;
    length = getDouble("length");
    width = getDouble("width");
    double area = length * width;
    cout << "The area is: " << area << endl;
}

void areaTriangle() {
    double base, height;
    base = getDouble("base");
    height = getDouble("height");
    double area = base * height * 0.5f;
    cout << "The area is: " << area << endl;    
}

void distanceTraveled() {
    int time;
    double speed, distance;
    speed = getDouble("speed");
    cout << "How many hours has it traveled? ";
    cin >> time;
    while(time < 1) {
        cout << "The time must be 1 or greater" << endl;
        cout << "How many hours has it traveled? ";
        cin >> time;
    }
    cout << "Hour" << setw(22) << "Distance Traveled" << endl;
    cout << "--------------------------------" << endl;
    for(int i = 1; i <= time; i++) {
        cout << i << setw(10) << i * speed << endl;
    }
}
