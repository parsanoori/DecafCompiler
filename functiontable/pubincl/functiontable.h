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
    unordered_map<string,vector<pair<string,string>>> formals_with_name;
    unordered_map<string,dtype> return_type;
    unordered_map<string,string> return_expr;
    functiontable() = default;
    static functiontable* instance;
public:
    void operator =(const functiontable&) = delete;
    functiontable(const functiontable&) = delete;

    static functiontable *get();

    void add_function(const string& name,const vector<dtype>& types,const dtype rtype);
    bool function_matches(const string&name,const vector<dtype>& types);
    dtype get_return_type(const string &name);
    void set_return_expr(const string &name,const string &id);
    string get_return_expr(const string &name);
    const vector<dtype> & get_formals(const string &name);
    const vector<pair<string,string>> & get_formals_with_name(const string &name);
    void set_formals_with_name(const string &name,const vector<pair<string,string>> &formals);
};

#endif //COMPILER_FUNCTIONTABLE_H
