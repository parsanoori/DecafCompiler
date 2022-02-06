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

functiontable *functiontable::get() {
    if (!instance)
        instance = new functiontable();
    return instance;
}

dtype functiontable::get_return_type(const string &name) {
    return return_type[name];
}
