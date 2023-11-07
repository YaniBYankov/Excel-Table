//
//  main.cpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#include "Cell.hpp"
#include "DoubleCell.hpp"
#include "IntCell.hpp"
#include "StringCell.hpp"
#include "FormulaCell.hpp"
#include "Table.hpp"
#include "FileManager.hpp"
void call()
{
    FileManager& m=FileManager::getInstance();
    m.run();
}

int main() {
//    Table table;
//    Cell p("5",table);
//    Cell t("6",table);
//    Cell y("\"Yanidskfjhnsakhjds\"",table);
//    Cell x("=123+67",table);
//    table.addCell(p, 1, 1);
//    table.addCell(t, 1, 3);
//    table.addCell(x, 4, 6);
//    table.addCell(y, 2, 6);
//    table.edit(11, 2, "\"edited\"");
//    table.print();
    call();
   // cout<<5;
//    m.open("T.txt");
//    m.print();
//    m.edit(7, 10, "44");
//    cout<<endl;
//    //m.print();
//    m.saveas("Test.txt");
//    FileManager k;
//    k.open("Test.txt");
//    k.print();
//    k.edit(6, 6, "100");
//    k.print();
//    k.close();
    return 0;
}
