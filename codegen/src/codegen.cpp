//
// Created by Parsa Noori on 2/3/2022 AD.
//

#include "codegen.h"
#include "idgen.h"
#include "floatutils.h"

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
    for (const auto &p: formals)
        types.push_back(dtypefromstr(p.first));
    ft->add_function(name, types);

    st->pushscope(name);

    for (const auto &p: formals)
        st->addentry(p.second, p.first);

    st->pushscope(name + "_stmtblock");

    w->appendText(name + ":\n");
}

void codegen::endfunction() {
    string scopename = st->currentscopename();

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
    if (expr.second == "string")
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 4\n"
                      + "    la $a0, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
    else if (expr.second == "int")
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 1\n"
                      + "    lw $a0, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
    else if (expr.second == "bool"){
        string label = idgen::nextlabel();
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 4\n"
                      + "    la $a0, _false_str\n"
                      + "    lw $t0, " + expr.first + "\n"
                      + "    beq $t0, 0, " + label + "\n"
                      + "    la $a0, _true_str\n"
                      + label + ":\n"
                      + "    syscall\n\n"
        );
    }
}

pair<string, string> codegen::addconstant(const pair<string, string> &constant) {
    string id = idgen::nextid();
    if (constant.second == "string")
        w->appendData("    " + id + ": .asciiz " + constant.first + "\n");
    else if (constant.second == "float")
        w->appendData("    " + id + ": .word " +
                      to_string(floatToInt(stof(constant.first))) + "\n");
    else if (constant.second == "bool") {
        if (constant.first == "true")
            w->appendText("    " + id + ": .word 1\n");
        else if (constant.first == "false")
            w->appendText("    " + id + ": .word 0\n");
        else
            throw runtime_error("something went wrogn"); // shouldn't be reached
    } else if (constant.second == "int")
        w->appendData("    " + id + ": .word " + constant.first + "\n");
    else
        throw runtime_error("some thing went wrong"); // shouldn't be reached

    return {id, constant.second};
}

pair<string, string> codegen::assignexpr(const string &lefside, const pair<string, string> &expr) {
    auto d = st->getentry(lefside);
    if (d.getType() != dtypefromstr(expr.second))
        throw runtime_error("semantic error: invalid assignment");
    w->appendText("    #assigning " + expr.first + " to " + d.getID() + "\n");
    if (expr.second == "int" || expr.second == "bool")
        w->appendText(
                "    lw $t0, " + expr.first + "\n"
                + "    la $t1, " + d.getID() + "\n"
                + "    sw $t0, 0($t1) \n"
        );
    else if (expr.second == "float")
        w->appendText("    lw $a0, " + expr.first + "\n"
                      + "    mtc1 $a0, $f0\n"
                      + "    la $a0, " + d.getID() + "\n"
                      + "    swc1 $f0, 0($a0)\n"
        );
    else if (expr.second == "string")
        w->appendText("    la $a0, " + expr.first + "\n"
                      + "    la $a1, " + d.getID() + "\n"
                      + "    sw $a0, 0($a1)\n"
        );
    else
        throw runtime_error("something went wrong internally");

    return {d.getID(), expr.second};
}

pair<string, string> codegen::findid(const string &id) {
    auto d = st->getentry(id);
    string type;
    switch (d.getType()) {
        case dtype::INT:
            type = "int";
            break;
        case dtype::DOUBLE:
            type = "float";
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
    return {d.getID(), type};
}

pair<string, string>
codegen::assignexproperation(const string &lefside, const pair<string, string> &expr, const string &operation) {
    auto d = st->getentry(lefside);
    w->appendText(
            "    # doing the " + operation +"\n"
            + "    lw $t0, " + expr.first +"\n"
            + "    lw $t1, " + d.getID() + "\n"
    );
    switch (operation[0]){
        case '+':
            w->appendText("    add $t0, $t0, $t1\n");
            break;
        case '-':
            w->appendText("    sub $t0, $t1, $t0\n");
            break;
        case '*':
            w->appendText("    mult $t0, $t1\n");
            w->appendText("    mflo $t0\n");
            break;
        case '/':
            w->appendText("    div $t1, $t0\n");
            w->appendText("    mflo $t0\n");
            break;
    }
    w->appendText("    sw $t0, " + d.getID() + "\n\n");
    return {d.getID(),expr.second};
}





