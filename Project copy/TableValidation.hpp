//
//  TableValidation.hpp
//  Project
//
//  Created by Yani Yankov on 11.06.23.
//

#ifndef TableValidation_hpp
#define TableValidation_hpp

#include "Table.hpp"

namespace TableValidation
{
void validate(const string& row,vector<string>& errors,size_t index);
void checkCommas(const string& str,vector<string>& errors,size_t index);
}

#endif /* TableValidation_hpp */
