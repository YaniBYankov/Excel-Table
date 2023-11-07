//
//  FormulaCell.hpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#ifndef FormulaCell_hpp
#define FormulaCell_hpp

#include "CellAbstraction.hpp"
#include "Table.hpp"

class Table;

class FormulaCell:public CellAbstraction
{
public:
    FormulaCell(const string& formula,const Table& table);
    FormulaCell(const FormulaCell& other);
    FormulaCell& operator=(const FormulaCell& other);
    bool operator==(const FormulaCell& other) const;
    virtual ~FormulaCell();
    
    
    virtual CellAbstraction* clone() const override;
    virtual string convertToString() const override;
    virtual double convertToDouble() const override;
    
    virtual double operator+(const CellAbstraction& other) const override;
    virtual double operator-(const CellAbstraction& other) const override;
    virtual double operator*(const CellAbstraction& other) const override;
    virtual double operator/(const CellAbstraction& other) const override;  //TODO: Deviding by zero
    
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
    const Table& table;
    
    double calculateFormula() const;
};

#endif /* FormulaCell_hpp */
