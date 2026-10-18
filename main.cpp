/** Course: CSC2210
Instructor: Dr. Ukegbu 
Last Modifier: Liam Salas, Aditya Miriyala
Last Modified: 2026-10-18
**/

#include <iostream>
#include <limits>
#include <string>
#include "Table.h"
using namespace std;

const int MAX_TABLES{10};

// Keeps asking until the user enters a number. Returns false if input ends.
bool readInt(int& value) {
    while (!(cin >> value)) {
        if (cin.eof()) {
            return false;
        }
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Reset the input error.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip the bad input.
    }
    return true;
}

Table* findTable(Table* tables[], int count, const string& name) {
    for (int i = 0; i < count; i++) {
        if (tables[i]->getName() == name) {
            return tables[i];
        }
    }
    return nullptr;
}

// Asks for a table name and returns that table, or nullptr if it is not found.
Table* askForTable(Table* tables[], int count) {
    string name;
    cout << "Table name: ";
    cin >> name;
    Table* table{findTable(tables, count, name)};
    if (table == nullptr) {
        cout << "No table named " << name << ".\n";
    }
    return table;
}

// Asks for one value per column. 
string* askForRow(Table* table) {
    string* values{new string[table->getColumnCount()]};
    for (int i = 0; i < table->getColumnCount(); i++) {
        cout << table->getColumnName(i) << ": ";
        cin >> values[i];
    }
    return values;
}

int main() {
    Table* tables[MAX_TABLES]{};
    int tableCount{0};

    // Keep showing the menu until the user picks 0.
    int choice{-1};
    while (choice != 0) {
        cout << "\n====================\n";
        cout << "    IRONDB v0.3\n";
        cout << "====================\n";
        cout << "1. Create Table\n";
        cout << "2. Insert Row\n";
        cout << "3. Show Table\n";
        cout << "4. List Tables\n";
        cout << "5. Update Row\n";
        cout << "0. Exit" << endl; // force buffer flush

        cout << "Enter your choice: ";
        if (!readInt(choice)) {
            break;
        }

        switch (choice) {
            case 1: {
                if (tableCount == MAX_TABLES) {
                    cout << "Table limit reached.\n";
                    break;
                }
                string name;
                cout << "Table name: ";
                cin >> name;
                if (findTable(tables, tableCount, name) != nullptr) {
                    cout << "A table named " << name << " already exists.\n";
                    break;
                }

                int numColumns{0};
                cout << "Number of columns: ";
                if (!readInt(numColumns) || numColumns < 1) {
                    cout << "A table needs at least one column.\n";
                    break;
                }

                string* columnNames{new string[numColumns]};
                for (int i = 0; i < numColumns; i++) {
                    cout << "Column " << i + 1 << " name: ";
                    cin >> columnNames[i];
                }
                tables[tableCount] = new Table(name, columnNames, numColumns);
                tableCount++;
                delete[] columnNames;
                cout << "Created table " << name << ".\n";
                break;
            }

            case 2: {
                Table* table{askForTable(tables, tableCount)};
                if (table == nullptr) {
                    break;
                }
                string* values{askForRow(table)};
                table->insertRow(values);
                delete[] values;
                cout << "Row added.\n";
                break;
            }

            case 3: {
                Table* table{askForTable(tables, tableCount)};
                if (table != nullptr) {
                    table->print();
                }
                break;
            }

            case 4:
                if (tableCount == 0) {
                    cout << "No tables yet.\n";
                }
                for (int i = 0; i < tableCount; i++) {
                    cout << tables[i]->getName() << " (" << tables[i]->getColumnCount()
                         << " columns, " << tables[i]->getRowCount() << " rows)\n";
                }
                break;

            case 5: {
                Table* table{askForTable(tables, tableCount)};
                if (table == nullptr) {
                    break;
                }
                int row{0};
                cout << "Row number: ";
                if (!readInt(row) || row < 0 || row >= table->getRowCount()) {
                    cout << "Invalid row.\n";
                    break;
                }
                string* values{askForRow(table)};
                table->updateRow(row, values);
                delete[] values;
                cout << "Row updated.\n";
                break;
            }

            case 0:
                cout << "Exiting IronDB.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    for (int i = 0; i < tableCount; i++) {
        delete tables[i];
    }
    return 0;
}
