// CSC 134
// M7T2 - Bronze
// Harley Coughlin
// 12/08/2024

#include <iostream>

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


int main() {
    Rectangle box;
    double rectWidth;
    double rectLength;

    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? ";
    cin >> rectLength;

    box.setWidth(rectWidth);
    box.setLength(rectLength);

    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;

    return 0;
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
