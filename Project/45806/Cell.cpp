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
    if(!(Utilities::checkIfInt(value)||
         Utilities::checkIfDouble(value)||
         Utilities::checkIfString(value)||
         Utilities::checkIfFormula(value)
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
    if(Utilities::checkIfInt(value))
    {
        this->value=new IntCell(value);
    }
    else if(Utilities::checkIfDouble(value))
    {
        this->value=new DoubleCell(value);
    }
    else if(Utilities::checkIfString(value))
    {
        this->value=new StringCell(value);
    }
    else if(Utilities::checkIfDouble(value))
    {
        this->value=new DoubleCell(value);
    }
    else if(Utilities::checkIfFormula(value))
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

bool Cell::checkForSelfArgument(const string &cell,const Table& table) const
{
    if(Utilities::checkIfFormula(this->value->convertToString()))
    {
        vector<string> args=Utilities::getArguments(value->convertToString());
        
        string args0=Utilities::toUpper(args[0]);
        string args1=Utilities::toUpper(args[1]);
        
        if(cell==args0||cell==args1)
        {
            return true;
        }
        if(Utilities::isCell(args0))
        {
            vector<size_t> coords=Utilities::getCellCoordinates(args0);
            if(!table.isOutOfTable(coords[0], coords[1]))
            {
                return table.getCell(coords[0]-1, coords[1]-1).checkForSelfArgument(cell, table);
            }
        }
        if(Utilities::isCell(args1))
        {
            vector<size_t> coords=Utilities::getCellCoordinates(args1);
            if(!table.isOutOfTable(coords[0], coords[1]))
            {
                return table.getCell(coords[0]-1, coords[1]-1).checkForSelfArgument(cell, table);
            }
        }
    }
    return false;
}
