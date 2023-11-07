//
//  StringFunctions.hpp
//  Project
//
//  Created by Yani Yankov on 5.06.23.
//

#ifndef StringFunctions_hpp
#define StringFunctions_hpp
#include <iostream>
using namespace std;
#include <string>
#include <cmath>

namespace StringFunctions
{
bool checkIfInt(const string& str);
bool checkIfDouble(const string& str);
bool checkIfString(const string& str);
bool checkIfFormula(const string& str);
bool checkIfHasSign(const string& str);
bool checkIfOperation(const string& str);
bool checkIfArguments(const string& str);
void removeSpacesFront(string& string);
void removeSpacesIn(string& string);
void removeSpacesBack(string& string);
void removeSpaces(string& string);
void reduceSpaces(string& str);
bool isCharOperation(char c);
bool isCell(const string& str);
bool isStringSpacesOnly(const string& str);
vector<string> extractBy(const string& str,char symbol);
string toUpper(const string& str);
vector<size_t> getCellCoordinates(const string& str);
vector<string> getArguments(const string& str);
string getOperation(const string& str);
string addQuoatations(const string& str);
string removeQuoatations(const string& str);
string removeSlash(const string& str);

bool compareDouble(double x,double y);
void removeZeroesDouble(string& str);
size_t countDots(const string& str);
}

#endif /* StringFunctions_hpp */
