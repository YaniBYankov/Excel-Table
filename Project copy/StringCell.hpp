//
//  StringCell.hpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#ifndef StringCell_hpp
#define StringCell_hpp

#include "CellAbstraction.hpp"

class StringCell: public CellAbstraction
{
public:
    StringCell(const string& number);
    StringCell(const StringCell& other);
    StringCell& operator=(const StringCell& other);
    bool operator==(const StringCell& other) const;
    virtual ~StringCell();
    
    
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
    string value;
};

#endif /* StringCell_hpp */
