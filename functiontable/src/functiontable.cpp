//
// Created by Parsa Noori on 2/4/2022 AD.
//
#include "functiontable.h"

functiontable *functiontable::instance;

void functiontable::add_function(const string &name, const vector<dtype> &types,const dtype rtype) {
    table.emplace(name, types);
    return_type.emplace(name, rtype);
}

bool functiontable::function_matches(const string &name, const vector<dtype> &types) {
    return types == table[name];
}

const vector<dtype> & functiontable::get_formals(const string &name) {
    return table[name];
}

functiontable *functiontable::get() {
    if (!instance)
        instance = new functiontable();
    return instance;
}

dtype functiontable::get_return_type(const string &name) {
    return return_type[name];
}

void functiontable::set_return_expr(const string &name,const string &id) {
    return_expr.emplace(name, id);
}

string functiontable::get_return_expr(const string &name) {
    return return_expr[name];
}

const vector<pair<string, string>> &functiontable::get_formals_with_name(const string &name) {
    return formals_with_name[name];
}

void functiontable::set_formals_with_name(const string &name, const vector<pair<string, string>> &formals) {
    formals_with_name.emplace(name,formals);
}
