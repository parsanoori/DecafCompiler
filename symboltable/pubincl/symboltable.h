#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <iostream>
#include <list>
#include <unordered_map>
#include "descriptor.h"
#include "scope.h"

using namespace std;

class symboltable {
    list<scope> st;

    static symboltable *instance;

    symboltable();

    string funcName = "root";

public:
    static symboltable *get();

    void pushscope(const string& name,bool isFuncName = false);

    void popscope();

    string currentFuncName();

    descriptor addentry(const string& name,const string& type);

    descriptor getentry(const string& name/*, const string& type*/);

    symboltable(symboltable&) = delete;

    void operator=(const symboltable&) = delete;
};

#endif
