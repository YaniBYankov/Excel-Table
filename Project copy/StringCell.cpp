//
//  StringCell.cpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#include "StringCell.hpp"

StringCell::StringCell(const string& str)
{
    
    this->value=StringFunctions::removeQuoatations(str);
    this->value=StringFunctions::removeSlash(this->value);
}

StringCell::StringCell(const StringCell& other)
{
    this->value=other.value;
}

StringCell& StringCell::operator=(const StringCell &other)
{
    if (this!=&other)
    {
        
        this->value=other.value;
    }
    return *this;
}

StringCell::~StringCell(){}

CellAbstraction* StringCell::clone() const
{
    return new StringCell(*this);
}

string StringCell::convertToString() const
{
    return this->value;
}

double StringCell::convertToDouble() const
{
    if (StringFunctions::checkIfDouble(this->value)||
        StringFunctions::checkIfInt(this->value))
    {
        return stod(this->value);
    }
    return 0;
}

double StringCell::operator+(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()+other.convertToDouble();
    return res;
}

double StringCell::operator-(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()-other.convertToDouble();
    return res;
}

double StringCell::operator*(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()*other.convertToDouble();
    return res;
}

double StringCell::operator/(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()/other.convertToDouble();
    return res;
}

bool StringCell::operator==(const CellAbstraction& other) const
{
    return (!(*this<other)&&!(*this>other));
}

bool StringCell::operator!=(const CellAbstraction& other) const
{
    return !(*this==other);
}
bool StringCell::operator<(const CellAbstraction& other) const
{
    return this->convertToDouble()<other.convertToDouble();
}
bool StringCell::operator<=(const CellAbstraction& other) const
{
    return !(this->convertToDouble()>other.convertToDouble());
}
bool StringCell::operator>(const CellAbstraction& other) const
{
    return this->convertToDouble()>other.convertToDouble();
}
bool StringCell::operator>=(const CellAbstraction& other) const
{
    return !(this->convertToDouble()<other.convertToDouble());
}

void StringCell::print(ostream& out,bool forFile) const
{
    if(forFile)
    {
        out<<StringFunctions::addQuoatations(this->value);
    }
    else
    {
        out<<this->convertToString();
    }
}

size_t StringCell::getSize() const
{
    return this->value.size();
}
