//
//  TableValidation.cpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#include "TableValidation.hpp"

void TableValidation::checkCommas(const string &str,vector<string>& errors,size_t index)
{
    vector<string> values=StringFunctions::extractBy(str, ' ');
    if(values.size()>1)
    {
        for(size_t i=0;i<values.size()-1;i++)
        {
            string err="At row "+to_string(index)+" after |"+values[i]+"| is missing \",\"";
            errors.push_back(err);
        }
    }
}

void TableValidation::validate(const string &row, vector<string> &errors,size_t index)
{
    string temp=row;
    StringFunctions::reduceSpaces(temp);
    vector<string> cells;
    cells=StringFunctions::extractBy(row, ',');
    for(size_t i=0;i<cells.size();i++)
    {
        StringFunctions::removeSpacesFront(cells[i]);
        StringFunctions::removeSpacesBack(cells[i]);
    }
    
    for(size_t i=0;i<cells.size();i++)
    {
        TableValidation::checkCommas(cells[i], errors, index);
    }
    
    for (size_t i=0;i<cells.size();i++)
    {
        if(!StringFunctions::isStringSpacesOnly(cells[i]))
        {
            if (!StringFunctions::checkIfInt(cells[i])&&
                !StringFunctions::checkIfDouble(cells[i])&&
                !StringFunctions::checkIfString(cells[i])&&
                !StringFunctions::checkIfFormula(cells[i]))
            {
                string err="At row "+to_string(index)+" and col "+to_string(i)+" cell: |"+cells[i]+"| contains unknown data type";
                errors.push_back(err);
            }
        }
    }
}
