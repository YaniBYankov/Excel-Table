#ifndef CellAbstraction_hpp
#define CellAbstraction_hpp

#include <vector>
#include "Utilities.hpp"
/**
 @brief CellAbstraction- Interface with pure virtual methods that all sub classes must implement. It contains all the operators, as well as print function and other methods.
 */
class CellAbstraction{
public:
    /**
     @brief Clone function that is used for copying
     @return pointer to CellAbstraction
     */
    virtual CellAbstraction* clone() const=0;
    /**
     @brief function that converts the value of a cell into a string
     @return string
     */
    virtual string convertToString() const=0;
    /**
     @brief function that converts the value of a cell into double
     @return double
     */
    virtual double convertToDouble() const=0;
    /**
     @brief operator + that calculates the values of two cells and adds them
     @param other cell to add with
     @return double
     */
    virtual double operator+(const CellAbstraction& other) const=0;
    /**
     @brief operator - that calculates the values of two cells and subtract them
     @param other cell to subtract with
     @return double
     */
    virtual double operator-(const CellAbstraction& other) const=0;
    /**
     @brief operator * that calculates the values of two cells and multiplies them
     @param other cell to multiply with
     @return double
     */
    virtual double operator*(const CellAbstraction& other) const=0;
    /**
     @brief operator / that calculates the values of two cells and devides them
     @param other cell to devide with
     @return double
     */
    virtual double operator/(const CellAbstraction& other) const=0;
    /**
     @brief operator == that calculates the values of two cells and checks if they are equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator==(const CellAbstraction& other) const=0;
    /**
     @brief operator != that calculates the values of two cells and checks if they are different
     @param other cell to compare with
     @return bool
     */
    virtual bool operator!=(const CellAbstraction& other) const=0;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is less
     @param other cell to compare with
     @return bool
     */
    virtual bool operator<(const CellAbstraction& other) const=0;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is less or equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator<=(const CellAbstraction& other) const=0;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is greater
     @param other cell to compare with
     @return bool
     */
    virtual bool operator>(const CellAbstraction& other) const=0;
    /**
     @brief operator  that calculates the values of two cells and checks if the first is greater or equal
     @param other cell to compare with
     @return bool
     */
    virtual bool operator>=(const CellAbstraction& other) const=0;
    /**
     @brief virtual destructor
     */
    virtual ~CellAbstraction();
    /**
     @brief virtual method that prints the value of a cell after it has been calculated
     @param out ostream
     @param forFile  print it to a file or just cout
     */
    virtual void print(ostream& out,bool forFile) const=0;
    /**
     @brief virtual method that gets the length of the string containing the cell value
     @return size_t 
     */
    virtual size_t getSize() const=0;
};

#endif /* CellAbstraction_hpp */
