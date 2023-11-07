//
//  TableReader.cpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#include "TableReader.hpp"


void TableReader::ReadTable(Table &table,const string& filePath)
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
            vector<string> cells=StringFunctions::extractBy(line,',');
            for(size_t i=0;i<cells.size();i++)
            {
                StringFunctions::removeSpacesFront(cells[i]);
                StringFunctions::removeSpacesBack(cells[i]);
                Cell toAddCell(cells[i],table);
                table.addCell(toAddCell, row, i+1);
            }
            row++;
        }
    }
}

bool TableReader::isValid(ifstream& file) const
{
    vector<string> errors;
    string row;
    size_t index=1;
    while (getline(file,row))
    {
        TableValidation::validate(row,errors,index);
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
