//
//  IntCell.hpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#ifndef IntCell_hpp
#define IntCell_hpp
#include "CellAbstraction.hpp"

class IntCell: public CellAbstraction
{
public:
    IntCell(const string& number);
    IntCell(const IntCell& other);
    IntCell& operator=(const IntCell& other);
    bool operator==(const IntCell& other) const;
    virtual ~IntCell();
    
    
    virtual CellAbstraction* clone() const override;
    virtual string convertToString() const override;
    virtual double convertToDouble() const override;
    
    virtual double operator+(const CellAbstraction& other) const override;
    virtual double operator-(const CellAbstraction& other) const override;
    virtual double operator*(const CellAbstraction& other) const override;
    virtual double operator/(const CellAbstraction& other) const override;
    
    virtual bool operator==(const CellAbstraction& other) const override;
    virtual bool operator!=(const CellAbstraction& other) const override;
    virtual bool operator<(const CellAbstraction& other) const override;
    virtual bool operator<=(const CellAbstraction& other) const override;
    virtual bool operator>(const CellAbstraction& other) const override;
    virtual bool operator>=(const CellAbstraction& other) const override;
    
    virtual void print(ostream& out,bool forFile) const override;
    
    virtual size_t getSize() const override;
private:
    long long value;
};

#endif /* IntCell_hpp */
