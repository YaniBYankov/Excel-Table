#ifndef IntCell_hpp
#define IntCell_hpp
#include "CellAbstraction.hpp"
/**
 @brief IntCell- class that inherits publicly CellAbstraction and  represents a cell containing an integer value
 */
class IntCell: public CellAbstraction
{
public:
    /**
     @brief Constructor the sets the value of the cell
     @param number string that contains the integer to set
     */
    IntCell(const string& number);
    /**
     @brief Copy constructor
     @param other another IntCell to copy from
     */
    IntCell(const IntCell& other);
    /**
     @brief operator =
     @param other other IntCell to copy from
     @return IntCell&
     */
    IntCell& operator=(const IntCell& other);
    /**
     @brief virtual destructor
     */
    virtual ~IntCell();
    
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
     @brief Class member that stores the integer value
     */
    long long value;
};

#endif /* IntCell_hpp */
