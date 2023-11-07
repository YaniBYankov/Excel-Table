//
//  FileManager.hpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#ifndef FileManager_hpp
#define FileManager_hpp
#include "Table.hpp"
#include "TableReader.hpp"
#include "TableWriter.hpp"


class FileManager
{
public:
    void Menu() const;
    void open(const string& fileName);
    void close();
    void save();
    void saveas(const string& fileName);
    void print() const;
    void edit(size_t row,size_t col,const string& value);
    void run();
    
    FileManager(const FileManager& other)=delete;
    FileManager& operator=(const FileManager& other)=delete;
    static FileManager& getInstance();
private:
    FileManager(){}
    string filePath;
    Table table;
    bool hasTable=false;
    bool saved=true;
    
    string getFilePath();
    void getEditArgs(vector<string>& args);
};

#endif /* FileManager_hpp */
