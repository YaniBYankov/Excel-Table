#ifndef StringCell_hpp
#define StringCell_hpp

#include "CellAbstraction.hpp"
/**
 @brief StringClass- class that inherits publicly CellAbstraction and  represents a cell containing a string value
 */
class StringCell: public CellAbstraction
{
public:
    /**
     @brief Constructor the sets the value of the cell
     @param str string that contains the string to set
     */
    StringCell(const string& str);
    /**
     @brief Copy constructor
     @param other another StringCell to copy from
     */
    StringCell(const StringCell& other);
    /**
     @brief operator =
     @param other other StringCell to copy from
     @return StringCell&
     */
    StringCell& operator=(const StringCell& other);
    /**
     @brief virtual destructor
     */
    virtual ~StringCell();
    
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
     @brief Class member that stores the string value
     */
    string value;
};

#endif /* StringCell_hpp */
