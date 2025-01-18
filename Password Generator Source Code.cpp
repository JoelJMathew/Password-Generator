#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length) {
    // Individual characters to create password
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    string pass = "";
    for (int i = 0; i < length; i++) {
        pass += chars[rand() % chars.size()];
    }
    return pass;
}
int main() {
    // Random seed so passwords are not the same each time
    srand(time(0));
    while (true) {
        int p_length = 0;
        cout << "Enter Desired Password Length (greater than 0): ";
        // Check for valid length input
        while (!(cin >> p_length) || p_length <= 0) {
            // Clear buffer incase of invalid entry by user
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid length. Please enter a positive number." << endl;
            cout << "Enter Desired Password Length (greater than 0): ";
        }
        string password = generatePassword(p_length);
        cout << "Generated Password: " << password << endl;
        string user_input;
        // Option to generate a new password
        cout << "Would you like to generate another password? (yes/no): ";
        while (true) {
            cin >> user_input;
            if (user_input == "yes" || user_input == "no") {
                break;
            }
            cout << "Invalid entry. Please enter 'yes' or 'no'." << endl;
            cout << "Would you like to generate another password? (yes/no): ";
        }
        if (user_input == "no") {
            break;
        }
    }
    return 0;
}
