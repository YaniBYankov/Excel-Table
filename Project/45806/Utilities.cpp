#include "Utilities.hpp"

bool Utilities::checkIfHasSign(const string &str)
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

bool Utilities::checkIfInt(const string &str)
{
    if (str.empty())
    {
        return false;
    }
    size_t sz=str.size();
    
    if(!Utilities::checkIfHasSign(str))
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

bool Utilities::checkIfDouble(const string &str)
{
    if (str.empty())
    {
        return false;
    }
    
    if(Utilities::countDots(str)!=1)
    {
        return false;
    }
    
    if(!Utilities::checkIfHasSign(str))
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

size_t Utilities::countDots(const string &str)
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

void Utilities::removeSpacesFront(string &string)
{
    if(string.empty())
    {
        return;
    }
    while (string[0]==' ')
    {
        string.erase(string.begin());
    }
}

void Utilities::removeSpacesBack(string &string)
{
    if(string.empty())
    {
        return;
    }
    size_t lenght=string.size()-1;
    while (string[lenght]==' ')
    {
        string.erase(string.begin()+lenght);
        lenght--;
    }
}

void Utilities::removeSpacesIn(string &string)
{
    if(string.empty())
    {
        return;
    }
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

void Utilities::removeSpaces(string &string)
{
    Utilities::removeSpacesFront(string);
    Utilities::removeSpacesBack(string);
    Utilities::removeSpacesIn(string);
}

bool Utilities::isCharOperation(char c)
{
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='<'||c=='>'||c=='='||c=='!')
    {
        return true;
    }
    return false;
}

bool Utilities::isCell(const string &str)
{
    string temp=Utilities::toUpper(str);
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

string Utilities::toUpper(const string &str)
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

vector<size_t> Utilities::getCellCoordinates(const string &str)
{
    vector<size_t> res;
    string cell=Utilities::toUpper(str);
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

bool Utilities::compareDouble(double x, double y)
{
    double epsilon = 0.00000001;
    if(abs(x - y) < epsilon)
    {
       return true;
    }
    return false;
}

bool Utilities::checkIfString(const string& str)
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

bool Utilities::checkIfOperation(const string& str)
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

bool Utilities::checkIfArguments(const string& str)
{
    if(!(Utilities::checkIfInt(str)||
         Utilities::checkIfDouble(str)||
         Utilities::checkIfString(str)||
         Utilities::isCell(str)))
    {
        return false;
    }
    return true;
}

bool Utilities::checkIfFormula(const string& str)
{
    if (str.empty())
    {
        return false;
    }
    string temp=str;
    Utilities::removeSpaces(temp);
    if (temp.size()<4||temp[0]!='=')
    {
        return false;
    }
    
    temp.erase(temp.begin());
    vector<string> args=Utilities::getArguments(temp);
    string operation=Utilities::getOperation(temp);
    
    if(args.size()!=2||!(operation.size()==2||operation.size()==1))
    {
        return false;
    }
    
    if(!Utilities::checkIfOperation(operation))
    {
        return false;
    }
    
    for(size_t i=0;i<args.size();i++)
    {
        if(!Utilities::checkIfArguments(args[i]))
        {
            return false;
        }
    }
    return true;
}

vector<string> Utilities::getArguments(const string& str)
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
        if(Utilities::isCharOperation(f[0]))
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

string Utilities::getOperation(const string& str)
{
    string res;
    
    size_t sz=str.size();
    for (size_t i=1;i<sz;i++)
    {
        if(Utilities::isCharOperation(str[i]))
        {
            res.push_back(str[i]);
        }
    }
    return res;
}

string Utilities::removeQuoatations(const string &str)
{
    string res=str;
    if(!str.empty())
    {
        res.erase(res.begin());
        res.erase(res.end()-1);
    }
    return res;
}

void Utilities::reduceSpaces(string &str)
{
    if (str.empty())
    {
        return;
    }
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

bool Utilities::isStringSpacesOnly(const string &str)
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

vector<string> Utilities::extractBy(const string &str,char symbol)
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

string Utilities::removeSlash(const string &str)
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

string Utilities::addQuoatations(const string &str)
{
    string res;
    res.push_back('"');
    res=res+str;
    res.push_back('"');
    return res;
}

void Utilities::removeZeroesDouble(string &str)
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
