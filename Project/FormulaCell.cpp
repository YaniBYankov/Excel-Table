#include "FormulaCell.hpp"

FormulaCell::FormulaCell(const string& formula, const Table& table):table(table)
{
    this->value=formula;
}

FormulaCell::FormulaCell(const FormulaCell& other):table(other.table)
{
    this->value=other.value;
}

FormulaCell& FormulaCell::operator=(const FormulaCell &other)
{
    if (this!=&other)
    {
        this->value=other.value;
    }
    return *this;
}

FormulaCell::~FormulaCell(){}

CellAbstraction* FormulaCell::clone() const
{
    return new FormulaCell(*this);
}

string FormulaCell::convertToString() const
{
    return this->value;
}

double FormulaCell::calculateFormula() const
{
    double res=0;
    vector<string> args=Utilities::getArguments(this->value);
    string operation=Utilities::getOperation(this->value);
    double a;
    double b;
    if(Utilities::isCell(args[0]))
    {
        vector<size_t> argsA=Utilities::getCellCoordinates(args[0]);
        if(this->table.isOutOfTable(argsA[0], argsA[1]))
        {
            a=0;
        }
        else
        {
            a=this->table.getCell(argsA[0]-1, argsA[1]-1).getValueDouble();
        }
    }
    else
    {
        if(Utilities::checkIfInt(args[0])||Utilities::checkIfDouble(args[0]))
        {
            a=stod(args[0]);
        }
        else
        {
            a=0;
        }
    }
    
    if(Utilities::isCell(args[1]))
    {
        vector<size_t> argsB=Utilities::getCellCoordinates(args[1]);
        if(this->table.isOutOfTable(argsB[0], argsB[1]))
        {
            b=0;
        }
        else
        {
            b=this->table.getCell(argsB[0]-1, argsB[1]-1).getValueDouble();
        }
    }
    else
    {
        if(Utilities::checkIfInt(args[1])||Utilities::checkIfDouble(args[1]))
        {
            b=stod(args[1]);
        }
        else
        {
            b=0;
        }
        
    }
    
    if (operation=="+")
    {
        res=a+b;
    }
    if (operation=="-")
    {
        res=a-b;
    }
    if (operation=="*")
    {
        res=a*b;
    }
    if (operation=="/")
    {
        if(Utilities::compareDouble(0, b))
        {
            throw invalid_argument("Can't devide by ZERO!");
        }
        res=a/b;
    }
    if (operation=="==")
    {
        res=Utilities::compareDouble(a, b);
    }
    if (operation=="!=")
    {
        res=!Utilities::compareDouble(a, b);
    }
    if (operation=="<=")
    {
        res=(Utilities::compareDouble(a, b)||a<b);
    }
    if (operation=="<")
    {
        res=a<b;
    }
    if (operation==">=")
    {
        res=(Utilities::compareDouble(a, b)||a>b);
    }
    if (operation==">")
    {
        res=a>b;
    }
    
    return res;
}

double FormulaCell::convertToDouble() const
{
    return this->calculateFormula();
}

double FormulaCell::operator+(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()+other.convertToDouble();
    return res;
}

double FormulaCell::operator-(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()-other.convertToDouble();
    return res;
}

double FormulaCell::operator*(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()*other.convertToDouble();
    return res;
}

double FormulaCell::operator/(const CellAbstraction& other) const
{
    double res=0;
    res=this->convertToDouble()/other.convertToDouble();
    return res;
}

bool FormulaCell::operator==(const CellAbstraction& other) const
{
    return (!(*this<other)&&!(*this>other));
}

bool FormulaCell::operator!=(const CellAbstraction& other) const
{
    return !(*this==other);
}
bool FormulaCell::operator<(const CellAbstraction& other) const
{
    return this->convertToDouble()<other.convertToDouble();
}
bool FormulaCell::operator<=(const CellAbstraction& other) const
{
    return !(this->convertToDouble()>other.convertToDouble());
}
bool FormulaCell::operator>(const CellAbstraction& other) const
{
    return this->convertToDouble()>other.convertToDouble();
}
bool FormulaCell::operator>=(const CellAbstraction& other) const
{
    return !(this->convertToDouble()<other.convertToDouble());
}

void FormulaCell::print(ostream& out,bool forFile) const
{
    if(forFile)
    {
        out<<this->value;
    }
    else
    {
        double res;
        try {
            res=this->calculateFormula();
            string output=to_string(res);
            Utilities::removeZeroesDouble(output);
            out<<output;
        } catch (const invalid_argument& e) {
            out<<"ERROR";
        }
    }
}

size_t FormulaCell::getSize() const
{
    double res;
    try {
        res=this->calculateFormula();
        string str=to_string(res);
        Utilities::removeZeroesDouble(str);
        return str.size();
    } catch (const invalid_argument& e) {
        string err="ERROR";
        return err.size();
    }
    
}
