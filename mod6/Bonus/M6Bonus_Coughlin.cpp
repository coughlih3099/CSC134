// CSC 134
// M6Bonus - Using Arrays/Vectors
// Harley Coughlin
// 12/01/2024
#include <iostream>
#include <random>
#include <string>
#include <limits>
#include <vector>

using namespace std;

void menu();
int get_int(int start, int end);
void question_one();
void question_two();
int question_two_get_int(bool values);
void question_three();

int main() {
    bool keep_running = true;
    int user_input;
    while (keep_running) {
        menu();
        user_input = get_int(1, 5);
        switch (user_input) {
            case 1:
                question_one();
                break;
            case 2:
                question_two();
                break;
            case 3:
                question_three();
                break;
            case 4:
                question_one();
                question_two();
                question_three();
            case 5:
                keep_running = false;
                break;
        }
    }
    return 0;
}

void menu() {
    cout << "\nM6 Bonus - The Menu\n" << "1. Cable Company\n"
         << "2. Adding Machine\n" << "3. Simple Graphics\n" << "4. All\n"
         << "5. Quit\n";
}

/**
 * @brief Gets int input within a range from the user with validation
 * @param start The starting int of the range
 * @param end The ending int of the range
 * @return An int within the range of start-end
 */
int get_int(int start, int end) {
    int return_value = 0;
    cout << "Enter an int within range" << start << "-" << end << ": ";
    cin >> return_value;
    while (cin.fail() || return_value < start || return_value > end) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
        cout << "Enter an int within range" << start << "-" << end << ": ";
        cin >> return_value;
    }
    return return_value;
}

/**
 * Waiting in line at the Cable Company
 * Create a FIFO datastructure using an array or vector.
 */
void question_one() {
    cout << "\nQuestion 1 - Waiting in line at the Cable Company\n";
    const int AMOUNT_OF_CUSTOMERS = 5;
    const int STARTING_TICKET_NUMBER = 99;
    // Create the vector and reserve the space for the amount of customers
    vector<int> customers_vector;
    customers_vector.reserve(AMOUNT_OF_CUSTOMERS);

    // Set the values in the vector
    for (int i = 0; i < AMOUNT_OF_CUSTOMERS; i++) {
        customers_vector.push_back(STARTING_TICKET_NUMBER + i);
    }

    // Read out the numbers
    cout << "The customer service window is now open.\n";
    for (const int& number : customers_vector) {
        cout << "Now serving ticket #" << number << '\n';
    }
    cout << "All customers have been served.\n\n";
}

int question_two_get_int(bool values) {
    int return_value = 0;
    if (values) {
        cout << "Enter a value: ";
    } else {
        cout << "How many values to add? ";
    }
    cin >> return_value;
    while (cin.fail() || return_value < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
        if (values) {
            cout << "Enter a value: ";
        } else {
            cout << "How many values to add (int greater than 0)? ";
        }
        cin >> return_value;
    }
    return return_value;
}

/**
 * Adding machine
 * Ask the user how many values to add. Ask the user to enter the values.
 * Add the values to a vector, print all values, and then the sum of all values.
 */
void question_two() {
    cout << "\nQuestion two - Adding machine\n";
    vector<int> values;
    int user_value;
    int total = 0;
    user_value = question_two_get_int(false);
    values.reserve(user_value);
    for (int i = 0; i < values.capacity(); i++) {
        user_value = question_two_get_int(true);
        values.push_back(user_value);
    }
    cout << "You entered: ";
    for (int i = 0; i < values.size(); i++) {
        total += values[i];
        cout << values[i];
        if (values[i] != values.size()) {
            cout << ", ";
        } else {
            cout << "\n";
        }
    }
    cout << "Total is: " << total << "\n";
}

/**
 * Simple Graphics
 */
void question_three() {
    const int HEIGHT = 10;
    const int WIDTH = 10;
    int user_input;
    // Making random
    mt19937 rng(random_device {}());
    uniform_int_distribution<int> dist(0, 9);

    int x, y;

    string graph[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = ".";
        }
    }

    cout << "How many frames of animation? ";
    cin >> user_input;
    while (cin.fail() || user_input < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
        cout << "How many frames of animation? ";
        cin >> user_input;
    }
    for (int i = 0; i < user_input; i++) {
        x = dist(rng);
        y = dist(rng);
        graph[x][y] = "#";
        cout << "Frame " << i + 1 << '\n';
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                cout << graph[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
