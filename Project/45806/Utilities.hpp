#ifndef Utilities_hpp
#define Utilities_hpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/**
 @brief Namespace with helper functions
 */
namespace Utilities
{
/**
 @brief checks if a string is an integer
 @param str string to check
 @return bool
 */
bool checkIfInt(const string& str);
/**
 @brief checks if a string is a double
 @param str string to check
 @return bool
 */
bool checkIfDouble(const string& str);
/**
 @brief checks if a string is a string
 @param str string to check
 @return bool
 */
bool checkIfString(const string& str);
/**
 @brief checks if a string is a formula
 @param str string to check
 @return bool
 */
bool checkIfFormula(const string& str);
/**
 @brief checks if a string is a number and has sign
 @param str string to check
 @return bool
 */
bool checkIfHasSign(const string& str);
/**
 @brief checks if a string is an operation
 @param str string to check
 @return bool
 */
bool checkIfOperation(const string& str);
/**
 @brief checks if a string is a valid argument for cell value
 @param str string to check
 @return bool
 */
bool checkIfArguments(const string& str);
/**
 @brief remove spaces before the first symbol of a string
 @param string string to remove spaces
 */
void removeSpacesFront(string& string);
/**
 @brief remove spaces  in a string
 @param string string to remove spaces
 */
void removeSpacesIn(string& string);
/**
 @brief remove spaces after the last symbol of a string
 @param string string to remove spaces
 */
void removeSpacesBack(string& string);
/**
 @brief remove all spaces of a string
 @param string string to remove spaces
 */
void removeSpaces(string& string);
/**
 @brief reduce spaces of a string to one
 @param str string to remove spaces
 */
void reduceSpaces(string& str);
/**
 @brief checks if a character is an operation
 @param c character to check
 @return bool
 */
bool isCharOperation(char c);
/**
 @brief checks if a string is a cell
 @param str string to check
 @return bool
 */
bool isCell(const string& str);
/**
 @brief checks if a string contains only spaces
 @param str string to check
 @return bool
 */
bool isStringSpacesOnly(const string& str);
/**
 @brief extract strings from a string by a given symbol
 @param str string to extract from
 @param symbol symbol to separety by
 @return vector<string>
 */
vector<string> extractBy(const string& str,char symbol);
/**
 @brief returns a copy of a string but with all caps
 @param str string from which to get all caps copy
 @return string
 */
string toUpper(const string& str);
/**
 @brief extract cell coordinates from a string
 @param str string to extract from
 @return vector<size_t>
 */
vector<size_t> getCellCoordinates(const string& str);
/**
 @brief extract arguments from a string
 @param str string to extract from
 @return vector<size_t>
 */
vector<string> getArguments(const string& str);
/**
 @brief get operation from a string
 @param str string to get from
 @return string
 */
string getOperation(const string& str);
/**
 @brief get copy of a string with quoatations
 @param str string to copy from
 @return string
 */
string addQuoatations(const string& str);
/**
 @brief get copy of a string but without quoatations
 @param str string to copy from
 @return string
 */
string removeQuoatations(const string& str);
/**
 @brief get copy from a string but without slash
 @param str string to remove from
 @return string
 */
string removeSlash(const string& str);
/**
 @brief compares if two doubles are equal
 @param x number one
 @param y number two
 @return bool
 */
bool compareDouble(double x,double y);
/**
 @brief removes all trailing zeroes
 @param str string to remove trailing zeroes
 */
void removeZeroesDouble(string& str);
/**
 @brief counts dot in a string
 @param str string to count from
 @return size_t
 */
size_t countDots(const string& str);
}

#endif /* Utilities_hpp */
