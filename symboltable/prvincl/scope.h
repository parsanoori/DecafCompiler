//
// Created by Parsa Noori on 2/2/2022 AD.
//

#ifndef COMPILER_SCOPE_H
#define COMPILER_SCOPE_H

#include <string>
#include <unordered_map>
#include <utility>
#include "descriptor.h"

using namespace std;

struct scope {
    const string name;
    int count = 0;
    unordered_map<string, descriptor> table;

    scope(string name) : name(std::move(name)), count(0) {}
};


#endif //COMPILER_SCOPE_H