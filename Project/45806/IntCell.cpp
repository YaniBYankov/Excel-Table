#include "IntCell.hpp"

IntCell::IntCell(const string& number)
{
    this->value=stoll(number);
}

IntCell::IntCell(const IntCell& other)
{
    this->value=other.value;
}

IntCell& IntCell::operator=(const IntCell &other)
{
    if (this!=&other)
    {
        this->value=other.value;
    }
    return *this;
}

IntCell::~IntCell(){}

CellAbstraction* IntCell::clone() const
{
    return new IntCell(*this);
}

string IntCell::convertToString() const
{
    return to_string(this->value);
}

double IntCell::convertToDouble() const
{
    return this->value;
}

double IntCell::operator+(const CellAbstraction& other) const
{
    double res=0;
    res=this->value+other.convertToDouble();
    return res;
}

double IntCell::operator-(const CellAbstraction& other) const
{
    double res=0;
    res=this->value-other.convertToDouble();
    return res;
}

double IntCell::operator*(const CellAbstraction& other) const
{
    double res=0;
    res=this->value*other.convertToDouble();
    return res;
}

double IntCell::operator/(const CellAbstraction& other) const
{
    double res=0;
    res=this->value/other.convertToDouble();
    return res;
}

bool IntCell::operator==(const CellAbstraction& other) const
{
    return (!(*this<other)&&!(*this>other));
}

bool IntCell::operator!=(const CellAbstraction& other) const
{
    return !(*this==other);
}
bool IntCell::operator<(const CellAbstraction& other) const
{
    return this->value<other.convertToDouble();
}
bool IntCell::operator<=(const CellAbstraction& other) const
{
    return !(this->value>other.convertToDouble());
}
bool IntCell::operator>(const CellAbstraction& other) const
{
    return this->value>other.convertToDouble();
}
bool IntCell::operator>=(const CellAbstraction& other) const
{
    return !(this->value<other.convertToDouble());
}

void IntCell::print(ostream& out,bool forFile) const
{
    out<<this->convertToString();
}

size_t IntCell::getSize() const
{
    return this->convertToString().size();
}
