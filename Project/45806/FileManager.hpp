#ifndef FileManager_hpp
#define FileManager_hpp
#include "Table.hpp"
#include "TableReader.hpp"
#include "TableWriter.hpp"

/**
 @brief FileManager- Singleton class that manages the file and the operations with it
 */
class FileManager
{
public:
    /**
     @brief Method that prints a Menu with all the commands
     */
    void Menu() const;
    /**
     @brief Method that opens a given file checks if it is valid and then reads the information from it
     @param fileName path or a name to a file to open
     */
    void open(const string& fileName);
    /**
     @brief Method that closes the current opened file
     */
    void close();
    /**
     @brief Method that saves the current table to the current opened file
     */
    void save();
    /**
     @brief Method that saves the current table to another file
     @param fileName file name to save to
     */
    void saveas(const string& fileName);
    /**
     @brief Method that prints the table
     */
    void print() const;
    /**
     @brief Method that edits that cell in the table
     @param row row of the cell to edit
     @param col col of the cell to edit
     @param value string with the value to edit
     */
    void edit(size_t row,size_t col,const string& value);
    /**
     @brief Method that prints the Menu and is handling the commands from the user
     */
    void run();
    
    FileManager(const FileManager& other)=delete;
    FileManager& operator=(const FileManager& other)=delete;
    /**
     @brief Static method that gets the Instance of a FileManager
     @return static FileManager&
     */
    static FileManager& getInstance();
private:
    /**
     @brief Default constructor that is private so that there can be only one instance of this class
     */
    FileManager(){}
    /**
     @brief Class member that stores the file path to the current opened file
     */
    string filePath;
    /**
     @brief Class member that is the table
     */
    Table table;
    /**
     @brief Class member that is boolean and tells if the FileManager has opened a table at the moment or not
     */
    bool hasTable=false;
    /**
     @brief Class member that is boolean and tells if the current file has been saved or not
     */
    bool saved=true;
    /**
     @brief Method that gets file path from the user input
     @return string
     */
    string getFilePath();
    /**
     @brief Method that gets the arguments needed for editing a cell and stores them in a vector
     */
    void getEditArgs(vector<string>& args);
};

#endif /* FileManager_hpp */
