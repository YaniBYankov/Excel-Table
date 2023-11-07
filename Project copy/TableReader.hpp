//
//  TableReader.hpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#ifndef TableReader_hpp
#define TableReader_hpp
#include "Table.hpp"
#include "TableValidation.hpp"
#include <fstream>
class TableReader
{
public:
    void ReadTable(Table& table,const string& filePath);
private:
    bool isValid(ifstream& file) const;
};

#endif /* TableReader_hpp */
