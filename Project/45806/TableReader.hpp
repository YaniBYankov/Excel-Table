#ifndef TableReader_hpp
#define TableReader_hpp
#include "Table.hpp"
#include <fstream>
/**
 @brief TableReader- Class that validates the file and the reads it into a table
 */
class TableReader
{
public:
    /**
     @brief Method that reads the file to the table if it is valid
     @param table table to read to
     @param filePath file to read from
     @return bool
     */
    bool ReadTable(Table& table,const string& filePath);
private:
    /**
     @brief Method that checks if a file is valid and prints all the errors if there are any
     @param file file to check
     @return bool
     */
    bool isValid(ifstream& file) const;
    /**
     @brief Method that validates a single row of a file and stores the errors in vector
     @param row string with the row
     @param errors vector with errors
     @param index which row to check
     */
    void validate(const string& row,vector<string>& errors,size_t index) const;
    /**
     @brief Method that checks for missing commas in a single row and stores the errors in vector
     @param str string with the row
     @param errors vector with errors
     @param index which row to check
     */
    void checkCommas(const string& str,vector<string>& errors,size_t index) const;
};

#endif /* TableReader_hpp */
