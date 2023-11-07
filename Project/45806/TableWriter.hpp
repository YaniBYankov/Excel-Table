#ifndef TableWriter_hpp
#define TableWriter_hpp

#include "Table.hpp"
#include <fstream>
/**
 @brief TableWriter- Class that writes a table to a file with given file name
 */
class TableWriter
{
public:
    /**
     @brief Method that writes a table
     @param table table to write
     @param fileName file to write in
     */
    void writeTable(const Table& table,const string& fileName);
};

#endif /* TableWriter_hpp */
