//
// Created by Parsa Noori on 2/3/2022 AD.
//

#ifndef COMPILER_CODEGEN_H
#define COMPILER_CODEGEN_H

#include <iostream>
#include "writer.h"
#include "semanticstack.h"
#include "symboltable.h"
#include "functiontable.h"

using namespace std;

class codegen {
    writer *w;
    semanticstack ss;
    symboltable *st;
    functiontable *ft;

    codegen();

    static codegen *instance;

public:

    void printnewline();

    static codegen *get();

    void operator=(codegen &) = delete;

    codegen(const codegen &) = delete;

    void writestuff();

    void printstrliteral(const string &exp);

    void variable(const string &type, const string &id);

    void addfunction(const string &name, const std::vector<std::pair<std::string,std::string>> &t);

    void endfunction();

    void printexpr(const pair<string,string> &expr);

};


#endif //COMPILER_CODEGEN_H
