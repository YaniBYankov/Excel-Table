//
//  Table.cpp
//  Project
//
//  Created by Yani Yankov on 6.06.23.
//

#include "Table.hpp"

Table::Table():rows(0),cols(0){};

const Cell& Table::getCell(size_t row, size_t col) const
{
    return this->cells[row].at(col);
}

size_t Table::getColWidth(size_t col) const
{
    size_t res=0;
    for (size_t i=0;i<this->rows;i++)
    {
        if (this->cells[i][col].size()>res)
        {
            res=this->cells[i][col].size();
        }
    }
    return res;
}

void Table::printCell(size_t row, size_t col,ostream& out,bool forFile) const
{
    if(forFile)
    {
        this->cells[row][col].print(out,true);
    }
    else
    {
        size_t spaces=this->getColWidth(col)-this->cells[row][col].size();
        for (size_t i=0;i<spaces;i++)
        {
            out<<' ';
        }
        this->cells[row][col].print(out,false);
    }
    
}

void Table::print(ostream& out,bool forFile) const
{
    if (forFile)
    {
        for (size_t i=0;i<this->rows;i++)
        {
            for (size_t j=0;j<this->cols;j++)
            {
                this->printCell(i,j,out,true);
                if(j<this->cols-1)
                {
                    out<<",";
                }
            }
            out<<endl;
        }
    }
    else
    {
        for (size_t i=0;i<this->rows;i++)
        {
            for (size_t j=0;j<this->cols;j++)
            {
                this->printCell(i,j,out,false);
                out<<" | ";
            }
            out<<endl;
        }
    }
}

void Table::addCell(const Cell& cell, size_t row, size_t col)
{
    this->resizeTable(row, col);
    this->cells[row-1][col-1]=cell;
}

void Table::resizeCols(size_t c)
{
    size_t amount=c-this->cols;
    
    for (size_t i=0;i<this->rows;i++)
    {
        for(size_t j=0;j<amount;j++)
        {
            Cell toFill;
            this->cells[i].push_back(toFill);
        }
    }
    
    this->cols=c;
}

void Table::resizeRows(size_t r)
{
    size_t amount=r-this->rows;
    
    for (size_t i=0;i<amount;i++)
    {
        vector<Cell> toAdd;
        for(size_t j=0;j<this->cols;j++)
        {
            Cell toFill;
            toAdd.push_back(toFill);
        }
        this->cells.push_back(toAdd);
    }
    
    this->rows=r;
}

void Table::resizeTable(size_t r, size_t c)
{
    if(this->rows<r)
    {
        this->resizeRows(r);
    }
    if(this->cols<c)
    {
        this->resizeCols(c);
    }
}

void Table::edit(size_t row, size_t col,const string &value)
{
    if(row<=0||col<=0)
    {
        throw invalid_argument("Invalid cell position!");
    }
    this->resizeTable(row, col);
    try
    {
        this->cells[row-1][col-1].editCell(value, *this);
    }
    catch (const invalid_argument& e)
    {
        throw e;
    }
    
}

void Table::clear()
{
    this->cells.clear();
    this->rows=0;
    this->cols=0;
}

bool Table::isEmpty()const
{
    if(this->rows==0&&this->cols==0&&this->cells.empty())
    {
        return true;
    }
    return false;
}

bool Table::isOutOfTable(size_t r, size_t c)const
{
    if(this->rows+1<r||this->cols+1<c)
    {
        return true;
    }
    return false;
}
