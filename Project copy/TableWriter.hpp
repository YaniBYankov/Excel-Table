//
//  TableWriter.hpp
//  Project
//
//  Created by Yani Yankov on 14.06.23.
//

#ifndef TableWriter_hpp
#define TableWriter_hpp

#include "Table.hpp"
#include <fstream>

class TableWriter
{
public:
    void writeTable(const Table& table,const string& fileName);
    
    
};

#endif /* TableWriter_hpp */
