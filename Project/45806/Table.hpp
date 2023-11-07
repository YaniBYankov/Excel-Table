#ifndef Table_hpp
#define Table_hpp

#include "Cell.hpp"

class Cell;
/**
 @brief Table- class that represents a table with cells
 */
class Table
{
public:
    /**
     @brief default constructor that sets the rows and cols to zero
     */
    Table();
    /**
     @brief Method that adds cell in the table and resizes the table if needed
     @param cell cell to add
     @param row row of the cell to add
     @param col col of the cell to add
     */
    void addCell(const Cell& cell,size_t row,size_t col);
    /**
     @brief Method that returns a cell from the table
     @param row row of the cell
     @param col col of the cell
     @return const Cell&
     */
    const Cell& getCell(size_t row,size_t col) const;
    /**
     @brief Method that prints the value of the table
     @param out ostream to print to. It can be cout or ofstream
     @param forFile boolean that tells if the printing is to a file
     */
    void print(ostream& out,bool forFile) const;
    /**
     @brief Method that checks if the position and the value of the cell is valid and then edits that cell in the table
     @param row row of the cell to edit
     @param col col of the cell to edit
     @param value string with the value to edit
     */
    void edit(size_t row,size_t col,const string& value);
    /**
     @brief Method that clears the table and sets rows and cols to zero
     */
    void clear();
    /**
     @brief Method that checks if the table is empty
     @return bool
     */
    bool isEmpty() const;
    /**
     @brief Method that checks if a given cell coordinates is out of the table
     @param r row
     @param c col
     @return bool
     */
    bool isOutOfTable(size_t r,size_t c) const;
private:
    /**
     @brief Class member containing all the cells
     */
    vector<vector<Cell>> cells;
    /**
     @brief Class member that contains the number of rows in the table
     */
    size_t rows;
    /**
     @brief Class member that contains the number of cols in the table
     */
    size_t cols;
    /**
     @brief Method that returns the width ot the biggest cell in a column
     @param col column
     @return size_t
     */
    size_t getColWidth(size_t col) const;
    /**
     @brief Method that prints a cell at given position
     @param row row of the cell
     @param col col of the cell
     @param out ostream
     @param forFile  print it to a file or just cout
     */
    void printCell(size_t row,size_t col,ostream& out,bool forFile) const;
    /**
     @brief Method that resizes the cols and rows of the table if needed
     @param r rows to resize to
     @param c cols to resize to
     */
    void resizeTable(size_t r,size_t c);
    /**
     @brief Method that resizes the rows of the table if needed
     @param r rows to resize to
     */
    void resizeRows(size_t r);
    /**
     @brief Method that resizes the cols of the table if needed
     @param c cols to resize to
     */
    void resizeCols(size_t c);
    
};

#endif /* Table_hpp */
