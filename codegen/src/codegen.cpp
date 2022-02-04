//
// Created by Parsa Noori on 2/3/2022 AD.
//

#include "codegen.h"
#include "idgen.h"

codegen *codegen::instance;


codegen *codegen::get() {
    if (!instance)
        instance = new codegen();
    return instance;
}

void codegen::printconstliteral(const string &id) {
    w->appendText("    # print " + id + "...\n"
                  + "    li $v0, 4\n"
                  + "    la $a0, " + id + "\n"
                  + "    syscall\n\n"
    );
}

codegen::codegen() {
    w = writer::get();
    st = symboltable::get();
    ft = functiontable::get();
}

void codegen::printnewline() {
    w->appendText(
            string("    # Printing new line\n") +
            "    li $a0, 0xA\n" +
            "    li $v0, 0xB\n" +
            "    syscall\n\n"
    );

}

void codegen::writestuff() {
    w->writestuff();
}

void codegen::variable(const string &type, const string &id) {
    auto d = st->addentry(id, type);
    w->appendData("    " + d.getID() + ": .word " + "0\n");
}

void codegen::addfunction(const string &name, const std::vector<std::pair<std::string, std::string>> &formals) {
    vector<dtype> types;
    types.reserve(formals.size());
    for (const auto& p: formals)
        types.push_back(dtypefromstr(p.first));
    ft->add_function(name, types);

    st->pushscope(name);

    for (const auto& p: formals)
        st->addentry(p.second, p.first);

    st->pushscope(name + "_stmtblock");

    w->appendText(name + ":\n");
}

void codegen::endfunction() {
    string scopename = st->currentscopename();
    cout << scopename << endl;
    if (scopename == "main_stmtblock")
        w->appendText(string("    # exit\n")
                      + "    li $v0, 10\n"
                      + "    syscall\n"
        );
    else
        w->appendText(string("    # return from " + scopename + "\n")
                      + "    jr $ra\n"
        );

    st->popscope(); // for stmtblock
    st->popscope(); // for formals

}

void codegen::printexpr(const pair<string, string> &expr) {
    //instance->printconstliteral(expr.first);
    if(expr.second == "string") {
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 4\n"
                      + "    la $a0, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
    }
    else if(expr.second == "int"){
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 1\n"
                      + "    lw $a0, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
    }
}

pair<string,string> codegen::addconstant(const pair<string,string> &constant) {
    string id = idgen::nextid();
    if(constant.second == "string"){
        w->appendData("    " + id + ": .asciiz " + constant.first + "\n");
    }
    else if(constant.second == "int"){
        w->appendData("    " + id + ": .word " + constant.first + "\n");
    }
    else{
        w->appendData("    " + id + ": .asciiz \"" + constant.first + "\"\n");
    }
    return {id,constant.second};
}

pair<string, string> codegen::assignexpr(const string &lefside,const pair<string,string> &expr) {
    auto d = st->getentry(lefside);
    w->appendText(
            "    lw $t0, " + expr.first +"\n"
            + "    sw $t0, " + d.getID() + "\n"
            );
    return {d.getID(),expr.second};
}

pair<string, string> codegen::findid(const string &id) {
    auto d = st->getentry(id);
    string type;
    switch(d.getType()){
        case dtype::INT:
            type = "int";
            break;
        case dtype::DOUBLE:
            type = "double";
            break;
        case dtype::BOOL:
            type = "bool";
            break;
        case dtype::STRING:
            type = "string";
            break;
        case dtype::VOID:
            type = "void";
            break;
        case dtype::OBJECT:
            type = "object";
            break;
        case dtype::DUMMY:
            type = "dummy";
            break;
    }
    return pair<string, string>(d.getID(),type);
}





