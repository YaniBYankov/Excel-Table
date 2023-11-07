//
//  FormulaCell.cpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

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

//vector<string> FormulaCell::getArguments() const
//{
//    vector<string> res;
//    string f=this->value;
//    if(f[0]=='=')
//    {
//        f.erase(f.begin());
//    }
//    string arg;
//    while (!f.empty())
//    {
//        if(StringFunctions::isCharOperation(f[0]))
//        {
//            if (!arg.empty())
//            {
//                res.push_back(arg);
//                arg.clear();
//            }
//            f.erase(f.begin());
//            continue;
//        }
//        arg.push_back(f[0]);
//        f.erase(f.begin());
//    }
//    res.push_back(arg);
//    return res;
//}
//
//string FormulaCell::getOperation() const
//{
//    string res;
//    size_t sz=this->value.size();
//    for (size_t i=0;i<sz;i++)
//    {
//        if(StringFunctions::isCharOperation(this->value[i]))
//        {
//            res.push_back(this->value[i]);
//        }
//    }
//    return res;
//}



double FormulaCell::calculateFormula() const
{
    double res=0;
    vector<string> args=StringFunctions::getArguments(this->value);
    string operation=StringFunctions::getOperation(this->value);
    double a;
    double b;
    if(StringFunctions::isCell(args[0]))
    {
        vector<size_t> argsA=StringFunctions::getCellCoordinates(args[0]);
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
        if(StringFunctions::checkIfInt(args[0])||StringFunctions::checkIfDouble(args[0]))
        {
            a=stod(args[0]);
        }
        else
        {
            a=0;
        }
    }
    
    if(StringFunctions::isCell(args[1]))
    {
        vector<size_t> argsB=StringFunctions::getCellCoordinates(args[1]);
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
        if(StringFunctions::checkIfInt(args[1])||StringFunctions::checkIfDouble(args[1]))
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
        if(StringFunctions::compareDouble(0, b))
        {
            throw invalid_argument("Can't devide by ZERO!");
        }
        res=a/b;
    }
    if (operation=="==")
    {
        res=StringFunctions::compareDouble(a, b);
    }
    if (operation=="!=")
    {
        res=!StringFunctions::compareDouble(a, b);
    }
    if (operation=="<=")
    {
        res=(StringFunctions::compareDouble(a, b)||a<b);
    }
    if (operation=="<")
    {
        res=a<b;
    }
    if (operation==">=")
    {
        res=(StringFunctions::compareDouble(a, b)||a>b);
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
            StringFunctions::removeZeroesDouble(output);
            out<<output;
            //out<<to_string(res);
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
        StringFunctions::removeZeroesDouble(str);
        return str.size();
        //size_t sz=to_string(res).size();
        //return sz;
    } catch (const invalid_argument& e) {
        string err="ERROR";
        return err.size();
    }
    
}
