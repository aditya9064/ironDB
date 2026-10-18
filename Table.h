/** Course: CSC2210
Instructor: Dr. Ukegbu 
Last Modifier: Liam Salas 
Last Modified: 2026-10-18
**/

#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "Column.h"

class Table {
public:
    Table(const std::string& tableName, const std::string* columnNames, int numColumns);
    ~Table();
    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;

    std::string getName() const;
    int getColumnCount() const;
    int getRowCount() const;
    std::string getColumnName(int index) const;
    void insertRow(const std::string* rowValues);
    bool updateRow(int row, const std::string* rowValues);
    void print() const;

private:
    std::string name;
    Column* columns{nullptr};
    int columnCount{0};
    int rowCount{0};
};

#endif
