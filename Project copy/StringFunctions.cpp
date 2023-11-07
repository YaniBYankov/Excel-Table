//
//  StringFunctions.cpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#include "StringFunctions.hpp"

bool StringFunctions::checkIfHasSign(const string &str)
{
    if (str.empty())
    {
        return false;
    }
    
    if(str[0]=='+'||str[0]=='-'||isdigit(str[0]))
    {
        return true;
    }
    return false;
}

bool StringFunctions::checkIfInt(const string &str)
{
    if (str.empty())
    {
        return false;
    }
    size_t sz=str.size();
    
    if(!StringFunctions::checkIfHasSign(str))
    {
        return false;
    }
    
    for (size_t i=1;i<sz;i++)
    {
        if(!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool StringFunctions::checkIfDouble(const string &str)
{
    if (str.empty())
    {
        return false;
    }
    
    if(StringFunctions::countDots(str)!=1)
    {
        return false;
    }
    
    if(!StringFunctions::checkIfHasSign(str))
    {
        return false;
    }
    
    
    size_t sz=str.size();
    for (size_t i=1;i<sz;i++)
    {
        if(!isdigit(str[i]))
        {
            if (str[i]=='.')
            {
                continue;
            }
            return false;
        }
    }
    return true;
}

size_t StringFunctions::countDots(const string &str)
{
    size_t cnt=0;
    size_t sz=str.size();
    for (size_t i=0;i<sz;i++)
    {
        if (str[i]=='.')
        {
            cnt++;
        }
    }
    return cnt;
}

void StringFunctions::removeSpacesFront(string &string)
{
    while (string[0]==' ')
    {
        string.erase(string.begin());
    }
}

void StringFunctions::removeSpacesBack(string &string)
{
    size_t lenght=string.size()-1;
    while (string[lenght]==' ')
    {
        string.erase(string.begin()+lenght);
        lenght--;
    }
}

void StringFunctions::removeSpacesIn(string &string)
{
    
    size_t lenght=string.size();
    
    for (size_t i=0;i<lenght;i++)
    {
        if (string[i]=='"')
        {
            ++i;
            while(string[i]!='"'&& i<lenght-1)
            {
                ++i;
                if(string[i]=='\\'&&string[i+1]=='\"')
                {
                    i+=2;
                }
            }
        }
        
        if (string[i]==' ')
        {
            string.erase(i,1);
            --i;
            --lenght;
        }
    }
}

void StringFunctions::removeSpaces(string &string)
{
    StringFunctions::removeSpacesFront(string);
    StringFunctions::removeSpacesBack(string);
    StringFunctions::removeSpacesIn(string);
}

bool StringFunctions::isCharOperation(char c)
{
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='<'||c=='>'||c=='='||c=='!')
    {
        return true;
    }
    return false;
}

bool StringFunctions::isCell(const string &str)
{
    string temp=StringFunctions::toUpper(str);
    if(temp=="R0C0")
    {
        return false;
    }
    if(temp[0]!='R')
    {
        return false;
    }
    temp.erase(temp.begin());
    bool col=false;
    while (!temp.empty()) {
        if (temp[0]>='0'&&temp[0]<='9')
        {
            temp.erase(temp.begin());
        }
        else if(temp[0]=='C'&&!col)
        {
            temp.erase(temp.begin());
            col=true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string StringFunctions::toUpper(const string &str)
{
    string res=str;
    size_t sz=str.size();
    for (size_t i=0;i<sz;i++)
    {
        if (res[i]>='a'&&res[i]<='z')
        {
            res[i]-='a'-'A';
        }
    }
    return res;
}

vector<size_t> StringFunctions::getCellCoordinates(const string &str)
{
    vector<size_t> res;
    string cell=StringFunctions::toUpper(str);
    string x;
    string y;
    
    cell.erase(cell.begin());
    bool second=false;
    while(!cell.empty())
    {
        if(cell[0]=='C')
        {
            second=true;
            cell.erase(cell.begin());
            continue;
        }
        if (!second)
        {
            x.push_back(cell[0]);
            cell.erase(cell.begin());
        }
        else
        {
            y.push_back(cell[0]);
            cell.erase(cell.begin());
        }
    }
    res.push_back(stoi(x));
    res.push_back(stoi(y));
    return res;
}

bool StringFunctions::compareDouble(double x, double y)
{
    double epsilon = 0.00000001;
    if(abs(x - y) < epsilon)
    {
       return true;
    }
    return false;
}

bool StringFunctions::checkIfString(const string& str)
{
    if (str.empty())
    {
        return false;
    }
    if (str.size()<2)
    {
        return false;
    }
    if(str[0]!='"'||str[str.size()-1]!='"')
    {
        return false;
    }
    return true;
}

bool StringFunctions::checkIfOperation(const string& str)
{
    if(!
       (str=="+"||
       str=="-"||
       str=="*"||
       str=="/"||
       str=="<"||
       str==">"||
       str=="=="||
       str=="!="||
       str=="<="||
       str==">="))
    {
        return false;
    }
    return true;
}

bool StringFunctions::checkIfArguments(const string& str)
{
    if(!(StringFunctions::checkIfInt(str)||
         StringFunctions::checkIfDouble(str)||
         StringFunctions::checkIfString(str)||
         StringFunctions::isCell(str)))
    {
        return false;
    }
    return true;
}

bool StringFunctions::checkIfFormula(const string& str)
{
    if (str.empty())
    {
        return false;
    }
    string temp=str;
    StringFunctions::removeSpaces(temp);
    if (temp.size()<4||temp[0]!='=')
    {
        return false;
    }
    
    temp.erase(temp.begin());
    vector<string> args=StringFunctions::getArguments(temp);
    string operation=StringFunctions::getOperation(temp);
    
    if(args.size()!=2||!(operation.size()==2||operation.size()==1))
    {
        return false;
    }
    
    if(!StringFunctions::checkIfOperation(operation))
    {
        return false;
    }
    
    for(size_t i=0;i<args.size();i++)
    {
        if(!StringFunctions::checkIfArguments(args[i]))
        {
            return false;
        }
    }
    return true;
}

vector<string> StringFunctions::getArguments(const string& str)
{
    vector<string> res;
    string f=str;
    if(f[0]=='=')
    {
        f.erase(f.begin());
    }
    string arg;
    while (!f.empty())
    {
        if(StringFunctions::isCharOperation(f[0]))
        {
            if (!arg.empty())
            {
                res.push_back(arg);
                arg.clear();
            }
            f.erase(f.begin());
            continue;
        }
        arg.push_back(f[0]);
        f.erase(f.begin());
    }
    res.push_back(arg);
    return res;
}

string StringFunctions::getOperation(const string& str)
{
    string res;
    
    size_t sz=str.size();
    for (size_t i=1;i<sz;i++)
    {
        if(StringFunctions::isCharOperation(str[i]))
        {
            res.push_back(str[i]);
        }
    }
    return res;
}

string StringFunctions::removeQuoatations(const string &str)
{
    string res=str;
    res.erase(res.begin());
    res.erase(res.end()-1);
    return res;
}

void StringFunctions::reduceSpaces(string &str)
{
    size_t len=str.size();
    string res;
    for(size_t i=0;i<len;i++)
    {
        if (str[i]!=' ')
        {
            res.push_back(str[i]);
        }
        else
        {
            res.push_back(' ');
            while (str[i+1]==' ')
            {
                i++;
            }
        }
    }
    str=res;
}

bool StringFunctions::isStringSpacesOnly(const string &str)
{
    if(str.empty())
    {
        return true;
    }
    size_t len=str.size();
    for(size_t i=0;i<len;i++)
    {
        if(str[i]!=' ')
        {
            return false;
        }
    }
    return true;
}

vector<string> StringFunctions::extractBy(const string &str,char symbol)
{
    string temp=str;
    vector<string> res;
    size_t len=temp.size();
    bool inQuotes=false;
    string curr;
    for (size_t i=0;i<len;i++)
    {
        if(temp[i]=='"')
        {
            inQuotes=!inQuotes;
        }
        if(!inQuotes)
        {
           if(temp[i]!=symbol)
           {
               curr.push_back(temp[i]);
           }
            else
            {
                res.push_back(curr);
                curr.erase();
            }
        }
        else
        {
            curr.push_back(temp[i]);
        }
    }
    if(!curr.empty())
    {
        res.push_back(curr);
    }
    return res;
}

string StringFunctions::removeSlash(const string &str)
{
    string res=str;
    for(size_t i=0;i<res.size();i++)
    {
        if(res[i]=='\\')
        {
            if(res[i+1]=='\"'||res[i+1]=='\\')
            {
                res.erase(res.begin()+i);
            }
        }
    }
    return res;
}

string StringFunctions::addQuoatations(const string &str)
{
    string res;
    res.push_back('"');
    res=res+str;
    res.push_back('"');
    return res;
}

void StringFunctions::removeZeroesDouble(string &str)
{
    while(true)
    {
        if(str[str.size()-1]=='0')
        {
            str.pop_back();
        }
        else if(str[str.size()-1]=='.')
        {
            str.pop_back();
            break;
        }
        else
        {
            break;
        }
    }
}
