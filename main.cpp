/** Course: CSC2210
Instructor: Dr. Ukegbu **/

#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Keep showing the menu until the user picks 0.
    int choice{-1};
    while (choice != 0) {
        cout << "\n====================\n";
        cout << "    IRONDB v0.2\n";
        cout << "====================\n";
        cout << "1. Create Table\n";
        cout << "2. Insert Row\n";
        cout << "3. Show Table\n";
        cout << "4. List Tables\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";

        // Check that the user entered a number.
        if (!(cin >> choice)) {
            // Stop if the input stream has ended.
            if (cin.eof()) {
                break;
            }
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Reset the input error.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip the bad input.
            continue;
        }
        // These options are just placeholders for now.
        switch (choice) {
            case 1:
                cout << "Create Table selected.\n";
                break;

            case 2:
                cout << "Insert Row selected.\n";
                break;

            case 3:
                cout << "Show Table selected.\n";
                break;

            case 4:
                cout << "List Tables selected.\n";
                break;

            case 0:
                cout << "Exiting IronDB.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }
    return 0;
}