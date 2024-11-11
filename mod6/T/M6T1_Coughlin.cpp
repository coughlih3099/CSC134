// CSC 134
// M6T1 - Arrays
// Harley Coughlin
// 11/11/2024

#include <iostream>

using namespace std;

const int NUM_DAYS = 5;
int cars[NUM_DAYS];

// prototypes
void partOne();
void partTwo();
void printChart();

int main() {
    cout << "Part 1: " << endl;
    partOne();
    cout << "\nPart 2:" << endl;
    partTwo();
    return 0;
}


void partOne() {
    // Set up variables
    // for each day monday - friday:
    // - ask how many cars
    // - add them to the total
    // when done, report the total and average

    double total = 0;
    int todays_count = 0;
    double average = 0;
    for (int day = 1; day <= NUM_DAYS; day++) {
        cout << "Please enter the count for day " << day << " of " << NUM_DAYS << ": ";
        cin >> todays_count;
        total += todays_count;
    }
    average = total / NUM_DAYS;
    cout << "For all " << NUM_DAYS << " days:" << endl;
    cout << "Total cars: " << total << endl;
    cout << "Average: " << average << endl;
}


void partTwo() {
    // Set up variables
    // for each day monday - friday:
    // - ask how many cars
    // - add them to the total
    // when done, report the total and average


    double total = 0;
    int todays_count = 0;
    double average = 0;
    for (int day = 0; day < NUM_DAYS; day++) {
        cout << "Please enter the count for day " << day + 1 << " of " << NUM_DAYS << ": ";
        cin >> todays_count;
        cars[day] = todays_count;
        total += todays_count;
    }
    average = total / NUM_DAYS;
    cout << "For all " << NUM_DAYS << " days:" << endl;
    cout << "Total cars: " << total << endl;
    cout << "Average: " << average << endl;
    printChart();
}


void printChart() {
    for (int i = 0; i < NUM_DAYS; i++) {
        for (int j = 0; j < cars[i]; j++) {
            cout << '#';
        }
        cout << '\n';
    }
}