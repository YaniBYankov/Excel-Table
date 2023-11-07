#ifndef DoubleCell_hpp
#define DoubleCell_hpp

#include "CellAbstraction.hpp"
/**
 @brief DoubleCell- class that inherits publicly CellAbstraction and  represents a cell containing a double value
 */
class DoubleCell:public CellAbstraction
{
public:
    /**
     @brief Constructor the sets the value of the cell
     @param number string that contains the double to set
     */
    DoubleCell(const string& number);
    /**
     @brief Copy constructor
     @param other another DoubleCell to copy from
     */
    DoubleCell(const DoubleCell& other);
    /**
     @brief operator =
     @param other other DoubleCell to copy from
     @return DoubleCell&
     */
    DoubleCell& operator=(const DoubleCell& other);
    /**
     @brief virtual destructor
     */
    virtual ~DoubleCell();
    
    /**
     @brief Method that clones the cell
     @return CellAbstraction&
     */
    virtual CellAbstraction* clone() const override;
    /**
     @brief function that converts the value of a cell into a string
     @return string
     */
    virtual string convertToString() const override;
    /**
     @brief function that converts the value of a cell into double
     @return double
     */
    virtual double convertToDouble() const override;
    /**
     @brief operator + that calculates the values of two cells and adds them
     @param other cell to add with
     @return double
     */
    virtual double operator+(const CellAbstraction& other) const override;
    /**
     @brief operator - that calculates the values of two cells and subtract them
     @param other cell to subtract with
     @return double
     */
    virtual double operator-(const CellAbstraction& other) const override;
    /**
     @brief operator * that calculates the values of two cells and multiplies them
     @param other cell to multiply with
     @return double
     */
    virtual double operator*(const CellAbstraction& other) const override;
    /**
     @brief operator / that calculates the values of two cells and devides them
     @param other cell to devide with
     @return double
     */
    virtual double operator/(const CellAbstraction& other) const override;
    /**
     @brief operator == that calculates the values of two cells and checks if they are equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator==(const CellAbstraction& other) const override;
    /**
     @brief operator != that calculates the values of two cells and checks if they are different
     @param other cell to compare with
     @return bool
     */
    virtual bool operator!=(const CellAbstraction& other) const override;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is less
     @param other cell to compare with
     @return bool
     */
    virtual bool operator<(const CellAbstraction& other) const override;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is less or equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator<=(const CellAbstraction& other) const override;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is greater
     @param other cell to compare with
     @return bool
     */
    virtual bool operator>(const CellAbstraction& other) const override;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is greater or equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator>=(const CellAbstraction& other) const override;
    /**
     @brief virtual method that prints the value of a cell after it has been calculated
     @param out ostream
     @param forFile  print it to a file or just cout
     */
    virtual void print(ostream& out,bool forFile) const override;
    /**
     @brief virtual method that gets the length of the string containing the cell value
     @return size_t
     */
    virtual size_t getSize() const override;
private:
    /**
     @brief Class member that stores the double value
     */
    double value;
    
};

#endif /* DoubleCell_hpp */
