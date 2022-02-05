//
// Created by Parsa Noori on 2/3/2022 AD.
//

#include <iostream>
#include <cstdarg>
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

    st->pushscope(name, true);

    for (const auto &p: formals)
        st->addentry(p.second, p.first);

    w->appendText(name + ":\n");
}

void codegen::endfunction() {
    string scopename = st->currentscopename();

    if (scopename == "main")
        w->appendText(string("    # exit\n")
                      + "    li $v0, 10\n"
                      + "    syscall\n"
        );
    else
        w->appendText(string("    # return from " + scopename + "\n")
                      + "    jr $ra\n"
        );

    st->popscope(); // for formals

}

void codegen::printexpr(const exprtype &expr) {
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
    else if (expr.second == "bool") {
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

exprtype codegen::addconstant(const pair<string, string> &constant) {
    string id = idgen::nextid();
    if (constant.second == "string")
        w->appendData("    " + id + ": .asciiz " + constant.first + "\n");
    else if (constant.second == "double")
        w->appendData("    " + id + ": .word " +
                      to_string(floatToInt(stof(constant.first))) + "\n");
    else if (constant.second == "bool") {
        if (constant.first == "true")
            w->appendData("    " + id + ": .word 1\n");
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

exprtype codegen::assignexpr(const string &lefside, const exprtype &expr) {
    auto d = st->getentry(lefside);
    if (d.getType() != dtypefromstr(expr.second))
        throw runtime_error("semantic error: invalid assignment: " + d.getTypeString() + "=" + expr.second);
    w->appendText("    #assigning " + expr.first + " to " + d.getID() + "\n");
    if (expr.second == "int" || expr.second == "bool")
        w->appendText(
                "    lw $t0, " + expr.first + "\n"
                + "    la $t1, " + d.getID() + "\n"
                + "    sw $t0, 0($t1) \n"
        );
    else if (expr.second == "double")
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

exprtype codegen::findid(const string &id) {
    auto d = st->getentry(id);
    return {d.getID(), d.getTypeString()};
}

exprtype
codegen::assignexproperation(const string &lefside, const exprtype &expr, const string &operation) {
    auto d = st->getentry(lefside);
    if (d.getType() != dtypefromstr(expr.second))
        throw runtime_error("semantic error: invalid assignment: " + d.getTypeString() + operation + expr.second);
    w->appendText(
            "    # doing the " + operation + "\n"
            + "    lw $t0, " + expr.first + "\n"
            + "    lw $t1, " + d.getID() + "\n"
    );
    switch (operation[0]) {
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
    return {d.getID(), expr.second};
}

void codegen::openstmtblock() {
    string id = idgen::nextid() + "_simple_block_open";
    st->pushscope(id);
}

void codegen::closestmtblock() {
    st->popscope();
}

void codegen::ifstmt(const exprtype &expr) {
    w->appendText("    #begin ifsmtm\n");
    if (expr.second != "bool")
        throw runtime_error("invalid type for if statement");
    string endlabel = "ENDIFLABEL_" + idgen::nextid();
    w->appendText(
            "    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + endlabel + "\n"
    );
    ss.push(endlabel);
}

void codegen::endiflabel() {
    try {
        w->appendText(
                any_cast<string>(ss.top()) + ":\n"
        );
        ss.pop();
    } catch (const std::bad_any_cast &e) {
        std::cerr << "bad any cast on end if:\n\t" << e.what() << '\n';
    }
}

void codegen::elseifstmt(const exprtype &expr) {
    if (expr.second != "bool")
        throw runtime_error("invalid type for if statement");
    string elselabel = "ENDIFLABEL_" + idgen::nextid();
    w->appendText(
            "    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + elselabel + "\n"
    );
    ss.push(elselabel);
}

void codegen::elselabel() {
    string endelselabel = "ENDELSELABEL" + idgen::nextid();
    w->appendText(
        "    j " + endelselabel + "\n"
    );
    try {
        w->appendText(
                any_cast<string>(ss.top()) + ":\n"
        );
        ss.pop();
        ss.push(endelselabel);
    } catch (const std::bad_any_cast &e) {
        std::cerr << "bad any cast on else:\n\t" << e.what() << '\n';
    }
}

void codegen::endelse() {
    try {
        w->appendText(
                any_cast<string>(ss.top()) + ":\n"
        );
        ss.pop();
    } catch (const std::bad_any_cast &e) {
        std::cerr << "bad any cast on end else:\n\t" << e.what() << '\n';
    }
}

exprtype codegen::exproperation(const exprtype &lefside, const exprtype &expr, const string &operation) {
    if (lefside.second != expr.second)
        throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
    string temp_id = idgen::nextid();
    string type_of_output;
    w->appendData("    " + temp_id + ": .word 0\n");
    w->appendText(
            "    # doing the " + operation + "\n"
            + "    lw $t0, " + expr.first + "\n"
            + "    lw $t1, " + lefside.first + "\n"
    );
    if(operation == "+"){
        w->appendText("    add $t0, $t0, $t1\n");
        type_of_output = expr.second;
    }
    else if (operation == "-"){
        w->appendText("    sub $t0, $t1, $t0\n");
        type_of_output = expr.second;
    }
    else if (operation == "*"){
        w->appendText("    mult $t0, $t1\n");
        w->appendText("    mflo $t0\n");
        type_of_output = expr.second;
    }
    else if (operation == "/"){
        w->appendText("    div $t1, $t0\n");
        w->appendText("    mflo $t0\n");
        type_of_output = expr.second;
    }
    else if (operation == "%"){
        w->appendText("    div $t1, $t0\n");
        w->appendText("    mfhi $t0\n");
        type_of_output = expr.second;
    }
    else if (operation == "<"){
        w->appendText("    slt $t0, $t1 , $t0\n");
        type_of_output = "bool";
    }
    else if (operation == ">"){
        w->appendText("    slt $t0, $t0 , $t1\n");
        type_of_output = "bool";
    }
    else if (operation == "<"){
        w->appendText("    slt $t0, $t1 , $t0\n");
        type_of_output = "bool";
    }
    else if (operation == "<="){
        w->appendText("    slt $t7, $t1 , $t0\n");
        string ltequallabel = idgen::nextid() + "_op_lteq";
        w->appendText("    bne $t7, $zero , " + ltequallabel + "_ok\n");
        w->appendText("    beq $t0, $zero , " + ltequallabel + "_ok\n");
        w->appendText("    add $t0, $zero , $zero\n");
        w->appendText(ltequallabel + "_ok:\n");
        type_of_output = "bool";
    }
    else if (operation == ">="){
        w->appendText("    slt $t7, $t0 , $t1\n");
        string gtequallabel = idgen::nextid() + "_op_gteq";
        w->appendText("    bne $t7, $zero , " + gtequallabel + "_ok\n");
        w->appendText("    beq $t0, $zero , " + gtequallabel + "_ok\n");
        w->appendText("    add $t0, $zero , $zero\n");
        w->appendText(gtequallabel + "_ok:\n");
        type_of_output = "bool";
    }
    else{
        throw runtime_error("my error: the operation is not implemented yet: " + operation);
    }
    w->appendText("    sw $t0, " + temp_id + "\n\n");
    return {temp_id, type_of_output};
}

exprtype codegen::unaryminus(const exprtype &expr) {
    if (expr.second != "int")
        throw runtime_error("semantic error: invalid operation: -" + expr.second);
    string temp_id = idgen::nextid();
    w->appendData("    " + temp_id + ": .word 0\n");
    w->appendText("    # doing the u-\n");
    w->appendText(
            "    lw $t0, " + expr.first + "\n"
            + "    sub $t0, $zero, $t0\n"
            + "    sw $t0, " + temp_id + "\n\n"
    );
    return {temp_id, expr.second};
}

void codegen::whilestmt1() {
    cout << "I am here . where are Uuuuuuuuuuuuu ?" << endl;
    string whilename = idgen::nextid() + "_while_loop";
    st->pushscope(whilename);
    w->appendText("    " + whilename + "_before:");
}

void codegen::whilestmt2(const pair<string, string> &expr) {
    cout << "I am here . where are Uuuuuuuuuuuuu ?" << endl;
    if (expr.second != "bool")
        throw runtime_error("invalid type for while expression");
    string laftername = st->currentscopename() + "_after";
    w->appendText("    lw $t0, " + expr.first + "\n"
                + "    beqz $t0, " + laftername + ":\n"
    );
}

void codegen::whilestmt3() {
    cout << "I am here . where are Uuuuuuuuuuuuu ?" << endl;
    string whilename = st->currentscopename();
    w->appendText("    j " + whilename + "_before\n"
                + whilename + "_after:\n"
    );
}

