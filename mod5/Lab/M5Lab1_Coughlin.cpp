// CSC 134
// M5Lab1 - Choose Your Own Adventure
// Harley Coughlin
// 10/21/2024

#include <iostream>
#include "getinputcpp.h"
using namespace std;

// Function Prototypes
// Any functions you make will need to
// be listed here, in this format, at the top.
// This is so the compiler knows to save
// room for them in the final program.
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
// TODO: add more choices here
void choice_order_food();
void choice_break_lock();

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You're in front of a spooky old house..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    // call choice 2 here
    choice_back_door();
  } else if (3 == choice) {
    // call choice 3 here
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_front_door() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_back_door() {
    clear_input(cin);
    cout << "You sneak around the back and find a slightly cracked cellar door with a rusted lock." << endl;
    cout << "What do you do?" << endl;
    string prompt = "1. Bust the lock open\n2. Go home\nChoose: ";
    int choice = get_input<int>(cin, prompt);
    if (choice == 1) {
        choice_break_lock();
    } else if (choice == 2) {
        choice_go_home();
    } else {
        choice_back_door();
    }
}

void choice_go_home() {
    clear_input(cin);
    string prompt = "1. Order some food\n2. Go to bed\nChoose: ";
    cout << "You decide to go home" << endl;
    cout << "Safe at home, do you:" << endl;
    int choice = get_input<int>(cin, prompt);
    if (choice == 1) {
        choice_order_food();
    } else if (choice == 2) {
        cout << "You go to sleep." << endl;
        cout << "*** Game Over ***" << endl;
    }
}

void choice_break_lock() {
    cout << "You try to break the lock, yet fail." << endl;
    cout << "*** Game Over ***" << endl;
}

// any new choices go here
void choice_order_food() {
    cout << "You order food." << endl;
}
