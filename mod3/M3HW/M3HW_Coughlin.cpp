// CSC 134
// M3HW - Gold
// Harley Coughlin
// 09/10/2024


#include <ctime>
#include <iostream>
#include <iomanip>
#include <limits>
#include <random>

using namespace std;

void print_main_menu();
void chat_bot();
void receipt_calculator();
void cyoa();
void math_practice();
int get_int();


int main() {
    bool keep_going = true;
    int choice;
    while (keep_going) {
        print_main_menu();
        choice = get_int();
        switch (choice) {
            case 1:
                chat_bot();
                break;
            case 2:
                receipt_calculator();
                break;
            case 3:
                cyoa();
                break;
            case 4:
                math_practice();
                break;
            case 5:
                chat_bot();
                receipt_calculator();
                cyoa();
                math_practice();
                break;
            case 6:
                cout << "\nGoodbye!\n" << endl;
                keep_going = false;
                break;
            default:
                cout << "Please choose a valid option\n";
        }
    }
}


void print_main_menu() {
    cout << "\nM3HW: The Menu!\n";
    cout << "---------------\n";
    cout << "1. Question 1 (chat bot)\n";
    cout << "2. Question 2 (receipt calculator)\n";
    cout << "3. Question 3 (choose your own adventure)\n";
    cout << "4. Question 4 (math practice)\n";
    cout << "5. All of the above\n";
    cout << "6. Quit\n";
    cout << "Please enter 1-6: ";
}

/**
* @return an int >= 0
*/
int get_int() {
    int user_input = -1;
    cin >> user_input;
    while (cin.fail() || user_input < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid integer 0 or greater: ";
        cin >> user_input;
    }
    return user_input;
}


/**
* chat bot that follows a specific script
* prints 3 different responses
*/
void chat_bot() {
    string reply;
    cout << "\nQuestion 1. Chat bot\n";
    cout << "-------------------\n";
    for (int i = 1; i <= 3; i++) {
        cout << "Sample Run " << i << "\n";
        cout << "Hello, I'm a C++ program!\n";
        cout << "Do you like me? Please type yes or no.\n";
        cin >> reply;
        if (reply == "yes") {
            cout << "That's great! I'm sure we'll get along.\n";
        } else if (reply == "no") {
            cout << "Well, maybe you'll learn to like me later.\n";
        } else {
            cout << "If you're not sure... That's OK.\n";
        }
        cout << "\n";
    }
}


/**
* Prompts user for meal price
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


/**
* prompts user for dine in or takeout
* @return true if dining in
*/
bool get_dining_preference() {
    int user_input;
    const bool dining_in = true;
    const bool to_go = false;
    cout << "Please enter 1 if dining in, or 2 if it is to go: ";
    cin >> user_input;
    while (cin.fail() || user_input < 1 || user_input > 2) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter 1 or 2: ";
        cin >> user_input;
    }
    return user_input == 1 ? dining_in : to_go;
}


/**
* Asks for the price of a meal, asks if dine-in or take out,
* if the order is dine-in add a 15% tip,
* total is calculated using an 8% tax
*/
void receipt_calculator() {
    const double TAX_RATE = 0.08;
    const double TIP_RATE = 0.15;
    double tip_amount = 0;
    double total, tax_amount;
    bool dining_in;
    double meal_price = 0;

    cout << "\nQuestion 2. Receipt Calculator\n";
    cout << "-------------------------------\n";
    cout << "Please enter the price of the meal: $";
    meal_price = get_double();
    dining_in = get_dining_preference();
    if (dining_in) {
        tip_amount = meal_price * TIP_RATE;
    }
    tax_amount = meal_price * TAX_RATE;
    total = meal_price + tax_amount + tip_amount;
    // well I don't like how things are lining up so yeah, some formatting
    int for_formatting = static_cast<int>(meal_price) * 1000;
    int count = 0;
    while (for_formatting > 0) {
        for_formatting /= 10;
        count++;
    }
    cout << "--------------------------\n";
    cout << setprecision(2) << fixed;
    cout << "The meal price is: $" << meal_price << "\n";
    if (dining_in) {
        cout << "The tip is :" << setw(8) << "$" << setw(count) << setfill(' ') << tip_amount << "\n";
    }
    cout << "The tax is:" << setw(9) << "$" << setw(count) << setfill(' ') << tax_amount << "\n";
    cout << "The total is :" << setw(6) << "$" << total << "\n";
}


/**
* Choose your own adventure game, offers the user 2 choices,
* one answer leads to a game over, the other leads to a second choice
* of two actions. From there, one leads to defeat, the other to victory.
*/
void cyoa() {
    int user_input = -1;
    cout << "\nQuestion 3: Choose Your Own Adventure\n";
    cout << "-------------------------------------\n";
    cout << "You're fishing on a moonlit night. The water of the lake ";
    cout << "is still save for the gentle lapping against the hull of your rowboat.\n";
    cout << "You feel a tug on the line and pull with all your strength.\n";
    cout << "To your surprise, a fog fills the air and when it clears, you find ";
    cout << "sitting across from you in your boat, some form of humanoid creature.\n";
    cout << "The creature has seaweed in place of hair, and is somehow rather ";
    cout << "smartly dressed, at least from the waist up, wearing a black, button-up shirt,\n";
    cout << "with a lime green tie, and a shiny, bright-green jacket,";
    cout << "adorned with various fishing lures.\n";
    cout << "It's outfit becomes a bit more confusing as its wearing, ";
    cout << "a pastel pink tutu covers its scaly, green legs.\n";
    cout << "Even more astonishingly, the creature addresses you, ";
    cout << "\"Hi there\", says the creature. Responding rather timidly, \n";
    cout << "you ask, \"Who are you?\", to which the creature reponds, \n";
    cout << "\"I'm Old Gregg. Pleased to meet cha.\"\n";
    cout << "Shaken by Gregg's sudden appearance and flippant attitude you\n";
    cout << "worriedly inquire, \"What do you want?\", Gregg flips the question\n";
    cout << "asking the same of you. To which you hurriedly respond, \"Just\n";
    cout << "taking the air. Not fishing,\" however, your hook is caught in\n";
    cout << "Gregg's hair and he doesn't let you get far on your excuse\n";
    cout << "Gregg proceeds to question you, \"You ever drunk Bailey's from a shoe?\"\n";
    cout << "The question catches you off-guard, giving you pause on further questioning.\n";
    cout << "Gregg contiues before giving you time to process his questions,\n";
    cout << "\"I like you; what do you think of me?\", Gregg asks.\n";
    cout << "\n";
     while (user_input < 1 || user_input > 2) {
        cout << "+-------------------+\n";
        cout << "|How do you respond?|\n";
        cout << "|-------------------|\n";
        cout << "|1. I don't know sir|\n";
        cout << "|-------------------|\n";
        cout << "|2. I don't like you|\n";
        cout << "+-------------------+\n";
        cout << "Response: ";
        user_input = get_int();
    }
    cout << "\n";
    if (user_input == 1) {
        user_input = -1;
        cout << "Gregg implores you, \"Make an assessment..\"\n";
        cout << "\n";
        while (user_input < 1 || user_input > 2) {
            cout << "+-----------------------------------------+\n";
            cout << "|---------How do you respond?-------------|\n";
            cout << "|-----------------------------------------|\n";
            cout << "|1. I think you're a nice modern gentleman|\n";
            cout << "|-----------------------------------------|\n";
            cout << "|2. I think you're a scaly man fish-------|\n";
            cout << "+-----------------------------------------+\n";
            cout << "Response: ";
            user_input = get_int();
            cout << "\n";
        }
        if (user_input == 1) {
            cout << "Gregg, suspicious of your response, accuses you of lying to him\n";
            cout << "However, he reconsiders his position and uses his powers to render\n";
            cout << "you unconscious, you awaken in his lair, sitting at a table\n";
            cout << "Gregg places a succulent fish dinner on the table in front of you.\n";
            cout << "\"I got an A in home economics\", Gregg offers.\n";
            cout << "\n*~~*~* You win *~*~~*\n";
        } else {
            cout << "Gregg begrudgingly admits that you've confirmed his suspicions\n";
            cout << "that he had about what you were already thinking about him. He sighs\n";
            cout << "heavily before using his powers to strap you to a plaque\n";
            cout << "which he then hangs in his lair\n";
            cout << "\nGame Over\n";
        }
    } else {
        cout << "Gregg has taken grave offense to your answer to his question\n";
        cout << "and uses his mix-up powers to sink your boat causing you to\n";
        cout << "be lost to his waters forevermore\n";
        cout << "\nGame Over\n";
    }
}


/**
* Generates two single digit numbers at random,
* prints the numbers as an addition problem.
* asks user to solve and prints correct/incorrect
*/
void math_practice() {
    // i feel like this is bad practice putting all the generation
    // inside the function
    random_device r;
    uniform_int_distribution<int> dist(0, 9);
    int num1 = dist(r);
    int num2 = dist(r);
    int answer;
    cout << "\nQuestion 4: Math Practice\n";
    cout << "-------------------------\n";
    cout << "What is " << num1 << " + " << num2 << "?";
    cout << "\n";
    answer = get_int();
    if (answer == num1 + num2) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
    }
}
