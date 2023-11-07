//
//  DoubleCell.cpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#include "DoubleCell.hpp"

DoubleCell::DoubleCell(const string& number)
{
    this->value=stod(number);
}

DoubleCell::DoubleCell(const DoubleCell& other)
{
    this->value=other.value;
}

DoubleCell& DoubleCell::operator=(const DoubleCell &other)
{
    if (this!=&other)
    {
        this->value=other.value;
    }
    return *this;
}

DoubleCell::~DoubleCell(){}

CellAbstraction* DoubleCell::clone() const
{
    return new DoubleCell(*this);
}

string DoubleCell::convertToString() const
{
    return to_string(this->value);
}

double DoubleCell::convertToDouble() const
{
    return this->value;
}

double DoubleCell::operator+(const CellAbstraction& other) const
{
    double res=0;
    res=this->value+other.convertToDouble();
    return res;
}

double DoubleCell::operator-(const CellAbstraction& other) const
{
    double res=0;
    res=this->value-other.convertToDouble();
    return res;
}

double DoubleCell::operator*(const CellAbstraction& other) const
{
    double res=0;
    res=this->value*other.convertToDouble();
    return res;
}

double DoubleCell::operator/(const CellAbstraction& other) const
{
    double res=0;
    res=this->value/other.convertToDouble();
    return res;
}

bool DoubleCell::operator==(const CellAbstraction& other) const
{
    return (!(*this<other)&&!(*this>other));
}

bool DoubleCell::operator!=(const CellAbstraction& other) const
{
    return !(*this==other);
}
bool DoubleCell::operator<(const CellAbstraction& other) const
{
    return this->value<other.convertToDouble();
}
bool DoubleCell::operator<=(const CellAbstraction& other) const
{
    return !(this->value>other.convertToDouble());
}
bool DoubleCell::operator>(const CellAbstraction& other) const
{
    return this->value>other.convertToDouble();
}
bool DoubleCell::operator>=(const CellAbstraction& other) const
{
    return !(this->value<other.convertToDouble());
}

void DoubleCell::print(ostream& out,bool forFile) const
{
    string output=this->convertToString();
    StringFunctions::removeZeroesDouble(output);
    out<<output;
    //out<<this->convertToString();
}

size_t DoubleCell::getSize() const
{
    string toString=this->convertToString();
    StringFunctions::removeZeroesDouble(toString);
    return toString.size();
}
