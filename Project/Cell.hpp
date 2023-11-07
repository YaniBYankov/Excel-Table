#ifndef Cell_hpp
#define Cell_hpp

#include "CellAbstraction.hpp"

#include "DoubleCell.hpp"
#include "IntCell.hpp"
#include "StringCell.hpp"
#include "FormulaCell.hpp"

using namespace std;

class Table;
/**
 @brief Cell- class that represents a cell containing a pointer to a CellAbstraction that holds the value of the cell
 */
class Cell{
public:
    /**
     @brief Default constructor that sets the value pointer to nullptr
     */
    Cell();
    /**
     @brief Constructor that sets the value of a cell with a given string
     @param value value to set
     @param table it is used for cells from FormulaCell that contains a refrence to a table
     */
    Cell(const string& value,const Table& table);
    /**
     @brief Copy constructor
     @param other other cell to copy from
     */
    Cell(const Cell& other);
    /**
     @brief operator =
     @param other other cell to copy from
     @return Cell&
     */
    Cell& operator=(const Cell& other);
    /**
     @brief Method that returns the value of the cell (getter)
     @return CellAbstraction*
     */
    CellAbstraction* getCell() const;
    /**
     @brief Destructor that deletes the value of a cell
     */
    ~Cell();
    /**
     @brief Method that gets the value of the cell in double number
     @return double
     */
    double getValueDouble() const;
    /**
     @brief Method that prints the value of the cell
     @param out ostream to print to. It can be cout or ofstream
     @param forFile boolean that tells if the printing is to a file
     */
    void print(ostream& out,bool forFile) const;
    /**
     @brief Methot that checks if the given value is valid Cell value and then edits the cell by changing its value to the new one
     @param value new value
     @param table it is used for cells from FormulaCell that contains a refrence to a table
     */
    void editCell(const string& value,const Table& table);
    /**
     @brief Methot that checks if the cell has a value and then calls (<CellAbstraction>"::")n<getSize> that returns the length of the string containing the cell value
     @return size_t 
     */
    size_t size() const;
    /**
     @brief Methot that checks if the given Cell is an argument of a formula of another cell
     @param cell Cell argument to check
     @param table table in which to check
     @return bool
     */
    bool checkForSelfArgument(const string& cell,const Table& table) const;
private:
    /**
     @brief Class member that holds a pointer to a cell value of type CellAbstraction
     */
    CellAbstraction* value;
    /**
     @brief Methot that checks if the given string is valid cell value
     @param value string to check
     @return bool
     */
    bool isValid(const string& value);
    /**
     @brief Methot that copies the value from another cell
     @param other another cell to copy from
     */
    void copy(const Cell& other);
    /**
     @brief Methot that sets the value of the cell from a given string
     @param value string with the value
     @param table it is used for cells from FormulaCell that contains a refrence to a tabletable
     */
    void setCell(const string& value,const Table& table);
};

#endif /* Cell_hpp */
