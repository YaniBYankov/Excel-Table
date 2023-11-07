//
//  FileManager.cpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#include "FileManager.hpp"

FileManager& FileManager::getInstance()
{
    static FileManager fileManager;
    return fileManager;
}

void FileManager::Menu() const
{
    cout<<"\t\t*************MENU*************"<<endl;
    cout<<endl;
    cout<<"[OPEN] <file path> ----------------->opens the file (file path)!"<<endl;
    cout<<"[PRINT] ---------------------------->prints the table!"<<endl;
    cout<<"[EDIT] <row> <column> <new value> --> edits the content of the cell!"<<endl;
    cout<<"[SAVE] ----------------------------->saves the current document in the current file!"<<endl;
    cout<<"[SAVE AS] <file path> -------------->saves the current document at (file path)!"<<endl;
    cout<<"[CLOSE] ----------------------------> closes the current file!"<<endl;
    cout<<"[EXIT] -----------------------------> closes the program!"<<endl;
    
}

void FileManager::open(const string &fileName)
{
    try
    {
        TableReader reader;
        reader.ReadTable(this->table,fileName);
        this->filePath=fileName;
        this->hasTable=true;
        cout<<"\nFile has been opened successfully!"<<endl;
    }
    catch (const invalid_argument& e)
    {
        cout<<e.what()<<endl;
    }
}

void FileManager::print() const
{
    if(!this->hasTable)
    {
        cout<<"There is no document opened!"<<endl;
        return;
    }
    this->table.print(cout,false);
    cout<<endl;
}

void FileManager::edit(size_t row, size_t col, const string &value)
{
    if(!this->hasTable)
    {
        cout<<"There is no document opened!"<<endl;
        return;
    }
    try
    {
        this->table.edit(row, col, value);
        this->saved=false;
    } catch (const invalid_argument& e)
    {
        cout<<e.what()<<endl;
    }
}

void FileManager::save()
{
    if(!this->hasTable)
    {
        cout<<"There is no document opened!"<<endl;
        return;
    }
    try
    {
        TableWriter writer;
        writer.writeTable(this->table, this->filePath);
        cout<<"\nFile has been saved successfully!"<<endl;
        this->saved=true;
    }
    catch (const invalid_argument& e)
    {
        cout<<e.what()<<endl;
    }
    
}

void FileManager::saveas(const string &fileName)
{
    if(!this->hasTable)
    {
        cout<<"There is no document opened!"<<endl;
        return;
    }
    try
    {
        TableWriter writer;
        writer.writeTable(this->table, fileName);
        cout<<"\nFile has been saved successfully as "+fileName+"!"<<endl;
        this->saved=true;
    }
    catch (const invalid_argument& e)
    {
        cout<<e.what()<<endl;
    }
}

void FileManager::close()
{
    if(!this->hasTable)
    {
        cout<<"Can't close empty document!"<<endl;
    }
    else
    {
        if (!this->saved)
        {
            cout<<"There have been unsaved changes!"<<endl;
            cout<<"Do you want to save the file?"<<endl;
            cout<<"y/n or c (to cance)"<<endl;
            while(true)
            {
                char c;
                cin>>c;
                if(c=='y')
                {
                    this->save();
                    break;
                }
                else if(c=='n')
                {
                    break;
                }
                else if(c=='c')
                {
                    return;
                }
                else
                {
                    cout<<"Please enter valid command!"<<endl;
                }
            }
        }
        this->table.clear();
        this->hasTable=false;
        this->saved=false;
        this->filePath.clear();
    }
}

string FileManager::getFilePath()
{
    string filePath;
    cout<<"Please enter file path!"<<endl;
    getline(cin,filePath);
    return filePath;
}

void FileManager::getEditArgs(vector<string> &args)
{
    string argsInput;
    while(true)
    {
        cout<<"Please enter <row> <column> <new value>!"<<endl;
        getline(cin,argsInput);
        StringFunctions::removeSpacesFront(argsInput);
        StringFunctions::removeSpacesBack(argsInput);
        vector<string> arguments=StringFunctions::extractBy(argsInput, ' ');
        if(arguments.size()!=3)
        {
            cout<<"Please enter <row> <column> <new value>!"<<endl;
        }
        else if(StringFunctions::checkIfInt(arguments[0])&&
                StringFunctions::checkIfInt(arguments[1]))
//                (StringFunctions::checkIfInt(arguments[2])||
//                StringFunctions::checkIfDouble(arguments[2])||
//                StringFunctions::checkIfString(arguments[2])||
//                StringFunctions::checkIfFormula(arguments[2])))
        {
            for (size_t i=0;i<arguments.size();i++)
            {
                args.push_back(arguments[i]);
            }
            break;
        }
        else
        {
            cout<<"Please enter valid <row> <column> <new value>!"<<endl;
        }
    }
}

void FileManager::run()
{
    this->Menu();
    
    string input;
    string command;
    while(true)
    {
        getline(cin, input);
        StringFunctions::removeSpacesFront(input);
        StringFunctions::removeSpacesBack(input);
        vector<string> args=StringFunctions::extractBy(input,' ');
        if(args.size()>=1)
        {
            command=StringFunctions::toUpper(args[0]);
            
            if(command=="OPEN")
            {
                if(args.size()==1)
                {
                    args.push_back(this->getFilePath());
                }
                this->open(args[1]);
            }
            else if (command=="PRINT")
            {
                this->print();
            }
            else if(command=="EDIT")
            {
                if (args.size()==1)
                {
                    this->getEditArgs(args);
                }
                if(args.size()!=4)
                {
                    args.clear();
                    args.push_back("EDIT");
                    this->getEditArgs(args);
                }
                this->edit(stol(args[1]), stol(args[2]), args[3]);
            }
            else if(command=="SAVE")
            {
                this->save();
            }
            else if(command=="SAVEAS")
            {
                if(args.size()==1)
                {
                    args.push_back(this->getFilePath());
                }
                this->saveas(args[1]);
            }
            else if (command=="CLOSE")
            {
                this->close();
            }
            else if(command=="EXIT")
            {
                break;
            }
            else
            {
                cout<<"Please enter valid command!"<<endl;
            }
        }
        
    }
    
}
