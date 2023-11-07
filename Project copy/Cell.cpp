//
//  Cell.cpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#include "Cell.hpp"

Cell::Cell():value(nullptr){}

Cell::Cell(const string& value,const Table& table):value(nullptr)
{
    if (!value.empty())
    {
        if (!this->isValid(value))
        {
            string error="Invalid cell value "+value;
            throw invalid_argument(error);
        }
        this->setCell(value, table);
    }
}

Cell::Cell(const Cell& other)
{
    this->copy(other);
}

Cell& Cell::operator=(const Cell &other)
{
    if(this!=&other)
    {
        this->copy(other);
    }
    return *this;
}

CellAbstraction* Cell::getCell() const
{
    return this->value;
}

void Cell::copy(const Cell &other)
{
    if(other.value)
    {
        this->value=other.value->clone();
    }
    else
    {
        this->value=nullptr;
    }
}

void Cell::print(ostream& out,bool forFile) const
{
    if (this->value)
    {
        this->value->print(out,forFile);
    }
    else
    {
        out<<"";
    }
}

double Cell::getValueDouble() const
{
    if(this->value)
    {
        return this->value->convertToDouble();
    }
    return 0;
}

bool Cell::isValid(const string &value)
{
    if(!(StringFunctions::checkIfInt(value)||
         StringFunctions::checkIfDouble(value)||
         StringFunctions::checkIfString(value)||
         StringFunctions::checkIfFormula(value)
         ))
    {
        return false;
    }
    return true;
}

size_t Cell::size() const
{
    if(this->value)
    {
        return this->value->getSize();
    }
    return 0;
}

Cell::~Cell()
{
    delete this->value;
}

void Cell::setCell(const string &value, const Table &table)
{
    if(StringFunctions::checkIfInt(value))
    {
        this->value=new IntCell(value);
    }
    else if(StringFunctions::checkIfDouble(value))
    {
        this->value=new DoubleCell(value);
    }
    else if(StringFunctions::checkIfString(value))
    {
        this->value=new StringCell(value);
    }
    else if(StringFunctions::checkIfDouble(value))
    {
        this->value=new DoubleCell(value);
    }
    else if(StringFunctions::checkIfFormula(value))
    {
        this->value=new FormulaCell(value,table);
    }
}

void Cell::editCell(const string &value, const Table &table)
{
    if(!value.empty())
    {
        if (!this->isValid(value))
        {
            string error="Invalid cell value "+value;
            throw invalid_argument(error);
        }
        if(this->value)
        {
            delete this->value;
        }
        this->setCell(value, table);
    }
}
