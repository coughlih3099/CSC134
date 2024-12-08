// CSC 134
// M7T2 - Silver
// Harley Coughlin
// 12/08/2024

#include <iostream>
#include <limits>

using namespace std;

class Rectangle {
 private:
    double width;
    double length;

 public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

double get_double();

int main() {
    Rectangle box;
    double rectWidth;
    double rectLength;

    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    rectWidth = get_double();
    cout << "What is the length? ";
    rectLength = get_double();

    box.setWidth(rectWidth);
    box.setLength(rectLength);

    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;

    return 0;
}

double get_double() {
    double user_input;
    cin >> user_input;
    while (cin.fail() || user_input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a double greater than 0: ";
        cin >> user_input;
    }
    return user_input;
}


void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setLength(double len) {
    length = len;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getArea() const {
    return width * length;
}
