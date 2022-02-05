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

using exprtype = pair<string, string>;
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

    void printconstliteral(const string &exp);

    void variable(const string &type, const string &id);

    void addfunction(const string &name, const std::vector<std::pair<std::string, std::string>> &t);

    void endfunction();

    void printexpr(const exprtype &expr);

    exprtype addconstant(const pair<string, string> &constant);

    exprtype findid(const string &id);

    exprtype assignexpr(const string &lefside, const exprtype &expr);

    exprtype assignexproperation(const string &lefside, const exprtype &expr, const string &operation);

    exprtype exproperation(const exprtype &lefside, const exprtype &expr, const string &operation);

    exprtype unaryminus(const exprtype &expr);

    void openstmtblock();

    void closestmtblock();

    void ifstmt(const exprtype &);

    void endiflabel();

    void elseifstmt(const exprtype &);

    void elselabel();

    void endelse();

};


#endif //COMPILER_CODEGEN_H
