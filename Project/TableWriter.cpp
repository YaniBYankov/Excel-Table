#include "TableWriter.hpp"

void TableWriter::writeTable(const Table &table, const string &fileName)
{
    ofstream write(fileName);
    if(!write.is_open())
    {
        write.close();
        throw invalid_argument("Couldn't open file to write!");
    }
    
    table.print(write, true);
}
