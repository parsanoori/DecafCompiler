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
    stack<string> loopstack;
    stack<string> condstack;
    symboltable *st;
    functiontable *ft;

    string beginloopname;
    string endloopname;

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

    void addfunction(const string &name, const std::vector<std::pair<std::string, std::string>> &t,const string& rtype);

    exprtype functioncall(const string &name, const std::vector<std::pair<std::string, std::string>> &t);

    void funcreturn(const exprtype &expr);

    void endfunction();

    void printexpr(const exprtype &expr);

    exprtype addconstant(const pair<string, string> &constant);

    exprtype findid(const string &id);

    exprtype assignexpr(const string &lefside, const exprtype &expr);

    exprtype assignexproperation(const string &lefside, const exprtype &expr, const string &operation);

    exprtype exproperation(const exprtype &lefside, const exprtype &expr, const string &operation);

    exprtype unaryminus(const exprtype &expr);

    exprtype unarynot(const exprtype &expr);

    void openstmtblock();

    void closestmtblock();

    void ifstmt(const exprtype &);

    void endiflabel();

    void elseifstmt(const exprtype &);

    void elselabel();

    void endelse();

    void beginfor();

    void forloopcond(const exprtype &);

    void endsecnexpr();

    void endforstmt();

    void whilestmt1();

    void whilestmt2(const exprtype &);

    void whilestmt3();

    void breakstmt();

    exprtype readinteger();

    exprtype itob(const exprtype&);

    exprtype btoi(const exprtype&);

    exprtype itod(const exprtype&);

    exprtype dtoi(const exprtype&);

};


#endif //COMPILER_CODEGEN_H
