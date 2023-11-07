#include "Cell.hpp"
#include "DoubleCell.hpp"
#include "IntCell.hpp"
#include "StringCell.hpp"
#include "FormulaCell.hpp"
#include "Table.hpp"
#include "FileManager.hpp"
void exe()
{
    FileManager& m=FileManager::getInstance();
    m.run();
}

int main() {
    exe();
    return 0;
}
