#include "TableReader.hpp"


bool TableReader::ReadTable(Table& table,const string& filePath)
{
    ifstream read;
    read.open(filePath);
    if(!read.is_open())
    {
        read.close();
        throw invalid_argument("Couldn't open file to read!");
    }
    if(this->isValid(read))
    {
        table.clear();
        read.clear();
        read.seekg(0);
        size_t row=1;
        string line;
        while(getline(read,line))
        {
            vector<string> cells=Utilities::extractBy(line,',');
            for(size_t i=0;i<cells.size();i++)
            {
                Utilities::removeSpacesFront(cells[i]);
                Utilities::removeSpacesBack(cells[i]);
                Cell toAddCell(cells[i],table);
                table.addCell(toAddCell, row, i+1);
            }
            row++;
        }
        return true;
    }
    return false;
}

bool TableReader::isValid(ifstream& file) const
{
    vector<string> errors;
    string row;
    size_t index=1;
    while (getline(file,row))
    {
        this->validate(row,errors,index);
        index++;
    }
    if(!errors.empty())
    {
        cout<<"Invalid input!"<<endl;
        cout<<"ERRORS: "<<endl;
        for (size_t i=0;i<errors.size();i++)
        {
            cout<<errors[i]<<endl;
        }
        return false;
    }
    return true;
}

void TableReader::checkCommas(const string &str,vector<string>& errors,size_t index) const
{
    vector<string> values=Utilities::extractBy(str, ' ');
    if(values.size()>1)
    {
        for(size_t i=0;i<values.size()-1;i++)
        {
            string err="At row "+to_string(index)+" after |"+values[i]+"| is missing \",\"";
            errors.push_back(err);
        }
    }
}

void TableReader::validate(const string &row, vector<string> &errors,size_t index) const
{
    string temp=row;
    Utilities::reduceSpaces(temp);
    vector<string> cells;
    cells=Utilities::extractBy(row, ',');
    for(size_t i=0;i<cells.size();i++)
    {
        Utilities::removeSpacesFront(cells[i]);
        Utilities::removeSpacesBack(cells[i]);
    }
    
    for(size_t i=0;i<cells.size();i++)
    {
        this->checkCommas(cells[i], errors, index);
    }
    
    for (size_t i=0;i<cells.size();i++)
    {
        if(!Utilities::isStringSpacesOnly(cells[i]))
        {
            if (!Utilities::checkIfInt(cells[i])&&
                !Utilities::checkIfDouble(cells[i])&&
                !Utilities::checkIfString(cells[i])&&
                !Utilities::checkIfFormula(cells[i]))
            {
                string err="At row "+to_string(index)+" and col "+to_string(i)+" cell: |"+cells[i]+"| contains unknown data type";
                errors.push_back(err);
            }
        }
    }
}
