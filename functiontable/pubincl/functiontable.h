//
// Created by Parsa Noori on 2/4/2022 AD.
//

#ifndef COMPILER_FUNCTIONTABLE_H
#define COMPILER_FUNCTIONTABLE_H
#include <unordered_map>
#include <vector>
#include "dtype.h"
using namespace std;

class functiontable{
    unordered_map<string,vector<dtype>> table;
    functiontable() = default;
    static functiontable* instance;
public:
    void operator =(const functiontable&) = delete;
    functiontable(const functiontable&) = delete;

    static functiontable *get();

    void add_function(const string& name,const vector<dtype>& types);
    bool function_matches(const string&name,const vector<dtype>& types);
};

#endif //COMPILER_FUNCTIONTABLE_H
