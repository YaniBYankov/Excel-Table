//
//  DoubleCell.hpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#ifndef DoubleCell_hpp
#define DoubleCell_hpp

#include "CellAbstraction.hpp"

class DoubleCell:public CellAbstraction
{
public:
    DoubleCell(const string& number);
    DoubleCell(const DoubleCell& other);
    DoubleCell& operator=(const DoubleCell& other);
    bool operator==(const DoubleCell& other) const;
    virtual ~DoubleCell();
    
    
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
    double value;
    
};

#endif /* DoubleCell_hpp */
