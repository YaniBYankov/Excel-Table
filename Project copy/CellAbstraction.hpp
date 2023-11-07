//
//  CellAbstraction.hpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#ifndef CellAbstraction_hpp
#define CellAbstraction_hpp

#include <iostream>
#include <vector>
#include <string>
#include "StringFunctions.hpp"
using namespace std;

class CellAbstraction{
public:
    virtual CellAbstraction* clone() const=0;
    virtual string convertToString() const=0;
    virtual double convertToDouble() const=0;
    
    virtual double operator+(const CellAbstraction& other) const=0;
    virtual double operator-(const CellAbstraction& other) const=0;
    virtual double operator*(const CellAbstraction& other) const=0;
    virtual double operator/(const CellAbstraction& other) const=0;
    
    virtual bool operator==(const CellAbstraction& other) const=0;
    virtual bool operator!=(const CellAbstraction& other) const=0;
    virtual bool operator<(const CellAbstraction& other) const=0;
    virtual bool operator<=(const CellAbstraction& other) const=0;
    virtual bool operator>(const CellAbstraction& other) const=0;
    virtual bool operator>=(const CellAbstraction& other) const=0;
    virtual ~CellAbstraction();
    
    virtual void print(ostream& out,bool forFile) const=0;
    
    virtual size_t getSize() const=0;
};

#endif /* CellAbstraction_hpp */
