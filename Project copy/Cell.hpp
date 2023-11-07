//
//  Cell.hpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#ifndef Cell_hpp
#define Cell_hpp

#include "CellAbstraction.hpp"

#include "DoubleCell.hpp"
#include "IntCell.hpp"
#include "StringCell.hpp"
#include "FormulaCell.hpp"

using namespace std;

class Table;

class Cell{
public:
    Cell();
    Cell(const string& value,const Table& table);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    CellAbstraction* getCell() const;
    ~Cell();
    
    double getValueDouble() const;
    void print(ostream& out,bool forFile) const;
    void editCell(const string& value,const Table& table);
    size_t size() const;
private:
    CellAbstraction* value;
    
    bool isValid(const string& value);
    void copy(const Cell& other);
    void setCell(const string& value,const Table& table);
};

#endif /* Cell_hpp */
