#include "StringCell.hpp"

StringCell::StringCell(const string& str)
{
    
    this->value=Utilities::removeQuoatations(str);
    this->value=Utilities::removeSlash(this->value);
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
    if (Utilities::checkIfDouble(this->value)||
        Utilities::checkIfInt(this->value))
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
        out<<Utilities::addQuoatations(this->value);
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
