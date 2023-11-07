//
//  Table.hpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#ifndef Table_hpp
#define Table_hpp

#include "Cell.hpp"

class Cell;

class Table
{
public:
    Table();
    void addCell(const Cell& cell,size_t row,size_t col);
    const Cell& getCell(size_t row,size_t col) const;
    
    void print(ostream& out,bool forFile) const;
    void edit(size_t row,size_t col,const string& value);
    void clear();
    bool isEmpty() const;
    bool isOutOfTable(size_t r,size_t c) const;
private:
    vector< vector <Cell> > cells;
    size_t rows;
    size_t cols;
    
    size_t getColWidth(size_t col) const;
    void printCell(size_t row,size_t col,ostream& out,bool forFile) const;
    
    void resizeTable(size_t r,size_t c);
    void resizeRows(size_t r);
    void resizeCols(size_t c);
    
};

#endif /* Table_hpp */
