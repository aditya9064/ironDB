/** Course: CSC2210
Instructor: Dr. Ukegbu 
Last Modifier: Liam Salas 
Last Modified: 2026-10-18
**/

#ifndef COLUMN_H
#define COLUMN_H

#include <string>

class Column {
public:
    Column();
    ~Column();
    // Copying is turned off so two columns never delete the same array.
    Column(const Column&) = delete;
    Column& operator=(const Column&) = delete;

    void setName(const std::string& newName);
    std::string getName() const;
    void addValue(const std::string& value);
    bool setValue(int index, const std::string& value);
    std::string getValue(int index) const;
    int getSize() const;

private:
    std::string name;
    std::string* values{nullptr};
    int size{0};
    int capacity{0};
    void grow();
};

#endif
