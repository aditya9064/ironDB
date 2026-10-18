/** Course: CSC2210
Instructor: Dr. Ukegbu **/

#include "Column.h"
using namespace std;

Column::Column() {}

Column::~Column() {
    delete[] values;
}

void Column::setName(const string& newName) {
    name = newName;
}

string Column::getName() const {
    return name;
}

void Column::addValue(const string& value) {
    if (size == capacity) {
        grow();
    }
    values[size] = value;
    size++;
}

bool Column::setValue(int index, const string& value) {
    if (index < 0 || index >= size) {
        return false;
    }
    values[index] = value;
    return true;
}

string Column::getValue(int index) const {
    if (index < 0 || index >= size) {
        return "";
    }
    return values[index];
}

int Column::getSize() const {
    return size;
}

void Column::grow() {
    int newCapacity{capacity == 0 ? 4 : capacity * 2};
    string* newValues{new string[newCapacity]};
    for (int i = 0; i < size; i++) {
        newValues[i] = values[i];
    }
    delete[] values; // Free the old array before using the new one.
    values = newValues;
    capacity = newCapacity;
}
