/** Course: CSC2210
Instructor: Dr. Ukegbu **/

#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(const string& tableName, const string* columnNames, int numColumns) {
    name = tableName;
    columnCount = numColumns;
    columns = new Column[columnCount];
    for (int i = 0; i < columnCount; i++) {
        columns[i].setName(columnNames[i]);
    }
}

Table::~Table() {
    delete[] columns;
}

string Table::getName() const {
    return name;
}

int Table::getColumnCount() const {
    return columnCount;
}

int Table::getRowCount() const {
    return rowCount;
}

string Table::getColumnName(int index) const {
    if (index < 0 || index >= columnCount) {
        return "";
    }
    return columns[index].getName();
}

void Table::insertRow(const string* rowValues) {
    // Every column gets a value so they all stay the same length.
    for (int i = 0; i < columnCount; i++) {
        columns[i].addValue(rowValues[i]);
    }
    rowCount++;
}

bool Table::updateRow(int row, const string* rowValues) {
    if (row < 0 || row >= rowCount) {
        return false;
    }
    for (int i = 0; i < columnCount; i++) {
        columns[i].setValue(row, rowValues[i]);
    }
    return true;
}

void Table::print() const {
    cout << "Table: " << name << "\n";
    cout << "row";
    for (int i = 0; i < columnCount; i++) {
        cout << " | " << columns[i].getName();
    }
    cout << "\n";

    for (int row = 0; row < rowCount; row++) {
        cout << row;
        for (int i = 0; i < columnCount; i++) {
            cout << " | " << columns[i].getValue(row);
        }
        cout << "\n";
    }

    if (rowCount == 0) {
        cout << "(no rows)\n";
    }
}
