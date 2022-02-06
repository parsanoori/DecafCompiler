//
// Created by Parsa Noori on 2/3/2022 AD.
//

#include <iostream>
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
    w->appendData("    #" + id + "\n");
    if (d.getTypeString() == "string") {
        w->appendData("    .align 2\n");
        w->appendData("    " + d.getID() + ": .space 1024\n\n");
    } else {
        w->appendData("    .align 2\n");
        w->appendData("    " + d.getID() + ": .word 0\n\n");
    }
}

void codegen::addfunction(const string &name, const std::vector<std::pair<std::string, std::string>> &formals,
                          const string &rtype) {
    vector<dtype> types;
    types.reserve(formals.size());
    for (const auto &p: formals)
        types.push_back(dtypefromstr(p.first));
    ft->add_function(name, types, dtypefromstr(rtype));

    st->pushscope(name, true);

    for (const auto &p: formals)
        st->addentry(p.second, p.first);

    w->appendText(name + ":\n");
}

exprtype codegen::functioncall(const string &name, const std::vector<std::pair<std::string, std::string>> &formals) {
    vector<dtype> types;
    types.reserve(formals.size());
    for (const auto &p: formals)
        types.push_back(dtypefromstr(p.second));
    if (!ft->function_matches(name, types)) {
        throw runtime_error("function " + name + " not found");
    }
    w->appendText("    #calling " + name + "\n");
    for (const auto &p: formals) {
        if (p.second == "string") {
            w->appendText("    addi $sp, $sp, -4\n");
            w->appendText(
                    "    la $t0, " + p.first + "\n"
                    + "    sw $t0, 0($sp)\n"
            );
        } else {
            w->appendText("    addi $sp, $sp, -4\n");
            w->appendText(
                    "    lw $t0, " + p.first + "\n"
                    + "    sw $t0, 0($sp)\n"
            );
        }
    }

    string id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word 0\n");
    w->appendText(
            "    jal " + name + "\n"
            + "    sw $v0, " + id + "\n\n"
    );
    for (const auto &p: formals) {
        w->appendText("    addi $sp, $sp, 4\n");
    }
    return {id, strfromdtype(ft->get_return_type(name))};
}

void codegen::endfunction() {
    string scopename = st->currentFuncName();

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
    } else if (expr.second == "double")
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 2\n"
                      + "    l.s $f12, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
}

exprtype codegen::addconstant(const pair<string, string> &constant) {
    w->appendData("    #" + constant.first + "\n");
    string id = idgen::nextid();
    if (constant.second == "string") {
        w->appendData("    .align 2\n");
        w->appendData("    " + id + ": .asciiz " + constant.first + "\n");
    } else if (constant.second == "double") {
        w->appendData("    .align 2\n");
        w->appendData("    " + id + ": .word " +
                      to_string(floatToInt(stof(constant.first))) + "\n");
    } else if (constant.second == "bool") {
        if (constant.first == "true") {
            w->appendData("    .align 2\n");
            w->appendData("    " + id + ": .word 1\n");
        } else if (constant.first == "false") {
            w->appendData("    .align 2\n");
            w->appendText("    " + id + ": .word 0\n");
        } else
            throw runtime_error("something went wrogn"); // shouldn't be reached
    } else if (constant.second == "int") {
        w->appendData("    .align 2\n");
        w->appendData("    " + id + ": .word " + constant.first + "\n");
    } else
        throw runtime_error("some thing went wrong"); // shouldn't be reached

    w->appendText("\n");

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
    else if (expr.second == "string") {
        w->appendText("    la $a0, " + expr.first + "\n"
                      + "    sw $a0, " + d.getID() + "\n"
        );
        string label = idgen::nextlabel();
        w->appendText(
                "    la $t0, " + expr.first + "\n"
                + "    la $t1, " + d.getID() + "\n"
                + label + ":\n"
                + "    lb $t2, ($t0)\n"
                + "    sb $t2, ($t1)\n"
                + "    addi $t0, $t0, 1\n"
                + "    addi $t1, $t1, 1\n"
                + "    bne $t2, $zero, " + label + "\n\n"
        );
    } else
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
    if (expr.second == "int") {
        w->appendText(
                "    # doing the " + operation + "\n"
                + "    lw $t0, " + expr.first + "\n"
                + "    lw $t1, " + d.getID() + "\n"
        );
        switch (operation[0]) {
            case '+':
                w->appendText("    addu $t0, $t0, $t1\n");
                break;
            case '-':
                w->appendText("    subu $t0, $t1, $t0\n");
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
    } else if (expr.second == "double") {
        w->appendText(
                "    # doing the " + operation + "\n"
                + "    l.s $f0, " + expr.first + "\n"
                + "    l.s $f1, " + d.getID() + "\n"
        );
        switch (operation[0]) {
            case '+':
                w->appendText("    add.s $f0, $f0, $f1\n");
                break;
            case '-':
                w->appendText("    sub.s $f0, $f1, $f0\n");
                break;
            case '*':
                w->appendText("    mul.s $f0, $f0, $f1\n");
                break;
            case '/':
                w->appendText("    div.s $f0, $f1, $f0\n");
                break;
        }
        w->appendText("    s.s $f0, " + d.getID() + "\n\n");
    } else if (expr.second == "string" && operation[0] == '+') {
        string temp_id = idgen::nextid();
        w->appendData("    .align 2\n");
        w->appendData("    " + temp_id + ": .space 1024\n");
        w->appendText(
                "    # doing the " + operation + "\n"
                + "    la $t2, " + expr.first + "\n"
                + "    la $t1, " + d.getID() + "\n"
                + "    la $t3, " + temp_id + "\n"
                + "copyfirst" + temp_id + ":\n"
                + "    lb $t0, ($t1)\n"
                + "    beqz $t0, copysecond" + temp_id + "\n"
                + "    sb $t0, ($t3)\n"
                + "    addi $t1, $t1, 1\n"
                + "    addi $t3, $t3, 1\n"
                + "    j copyfirst" + temp_id + "\n"
                + "copysecond" + temp_id + ":\n"
                + "    lb $t0, ($t2)\n"
                + "    beqz $t0, copyend" + temp_id + "\n"
                + "    sb $t0, ($t3)\n"
                + "    addi $t2, $t2, 1\n"
                + "    addi $t3, $t3, 1\n"
                + "    j copysecond" + temp_id + "\n"
                + "copyend" + temp_id + ":\n"
                + "    sb $t0, ($t3)\n\n"
        );
        d.setID(temp_id);
        return {temp_id, "string"};
    } else {
        throw runtime_error("semantic error: invalid assignment: " + d.getTypeString() + operation + expr.second);
    }
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
    condstack.push(endlabel);
}

void codegen::endiflabel() {
    w->appendText(
            condstack.top() + ":\n"
    );
    condstack.pop();

}

void codegen::elseifstmt(const exprtype &expr) {
    if (expr.second != "bool")
        throw runtime_error("invalid type for if statement");
    string elselabel = "ENDIFLABEL_" + idgen::nextid();
    w->appendText(
            "    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + elselabel + "\n"
    );
    condstack.push(elselabel);
}

void codegen::elselabel() {
    string endelselabel = "ENDELSELABEL" + idgen::nextid();
    w->appendText(
            "    j " + endelselabel + "\n"
            + condstack.top() + ":\n"
    );
    condstack.pop();
    condstack.push(endelselabel);
}

void codegen::endelse() {
    w->appendText(
            condstack.top() + ":\n"
    );
    condstack.pop();
}

exprtype codegen::exproperation(const exprtype &lefside, const exprtype &expr, const string &operation) {
    if (lefside.second != expr.second)
        throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
    string temp_id = idgen::nextid();
    string type_of_output;
    if (expr.second == "string") {
        if (operation == "+") {
            w->appendData("    .align 2\n");
            w->appendData("    " + temp_id + ": .space 1024\n");
            w->appendText(
                    "    # doing the " + operation + "\n"
                    + "    la $t2, " + expr.first + "\n"
                    + "    la $t1, " + lefside.first + "\n"
                    + "    la $t3, " + temp_id + "\n"
                    + "copyfirst" + temp_id + ":\n"
                    + "    lb $t0, ($t1)\n"
                    + "    beqz $t0, copysecond" + temp_id + "\n"
                    + "    sb $t0, ($t3)\n"
                    + "    addi $t1, $t1, 1\n"
                    + "    addi $t3, $t3, 1\n"
                    + "    j copyfirst" + temp_id + "\n"
                    + "copysecond" + temp_id + ":\n"
                    + "    lb $t0, ($t2)\n"
                    + "    beqz $t0, copyend" + temp_id + "\n"
                    + "    sb $t0, ($t3)\n"
                    + "    addi $t2, $t2, 1\n"
                    + "    addi $t3, $t3, 1\n"
                    + "    j copysecond" + temp_id + "\n"
                    + "copyend" + temp_id + ":\n"
                    + "    sb $t0, ($t3)\n\n"
            );
            return {temp_id, "string"};
        } else if (operation == "==") {
            w->appendData("    .align 2\n");
            w->appendData("    " + temp_id + ": .word 0\n");
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    # doing the " + operation + "\n"
                    + "    la $t0, " + expr.first + "\n"
                    + "    la $t1, " + lefside.first + "\n"
                    + "compare" + temp_id + ":\n"
                    + "    lb $t2, ($t0)\n"
                    + "    lb $t3, ($t1)\n"
                    + "    bne $t2, $t3, " + label1 + "\n"
                    + "    addi $t0, $t0, 1\n"
                    + "    addi $t1, $t1, 1\n"
                    + "    bne $t2, $zero, compare" + temp_id + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n\n"
            );
            w->appendText("    sw $t0, " + temp_id + "\n\n");
            return {temp_id, "bool"};
        } else if (operation == "!=") {
            w->appendData("    .align 2\n");
            w->appendData("    " + temp_id + ": .word 0\n");
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    # doing the " + operation + "\n"
                    + "    la $t0, " + expr.first + "\n"
                    + "    la $t1, " + lefside.first + "\n"
                    + "compare" + temp_id + ":\n"
                    + "    lb $t2, ($t0)\n"
                    + "    lb $t3, ($t1)\n"
                    + "    bne $t2, $t3, " + label1 + "\n"
                    + "    addi $t0, $t0, 1\n"
                    + "    addi $t1, $t1, 1\n"
                    + "    bne $t2, $zero, compare" + temp_id + "\n"
                    + "    li $t0, 0\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 1\n"
                    + label2 + ":\n\n"
            );
            w->appendText("    sw $t0, " + temp_id + "\n\n");
            return {temp_id, "bool"};
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
    }
    w->appendData("    .align 2\n");
    w->appendData("    " + temp_id + ": .word 0\n");
    if (expr.second == "int" || expr.second == "bool") {
        w->appendText(
                "    # doing the " + operation + "\n"
                + "    lw $t0, " + expr.first + "\n"
                + "    lw $t1, " + lefside.first + "\n"
        );
    } else if (expr.second == "double") {
        w->appendText(
                "    # doing the " + operation + "\n"
                + "    l.s $f0, " + expr.first + "\n"
                + "    l.s $f1, " + lefside.first + "\n"
        );
    } else {
        throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
    }
    if (operation == "+") {
        if (expr.second == "int") {
            w->appendText("    addu $t0, $t0, $t1\n");
        } else if (expr.second == "double") {
            w->appendText("    add.s $f0, $f0, $f1\n");
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = expr.second;
    } else if (operation == "-") {
        if (expr.second == "int") {
            w->appendText("    subu $t0, $t1, $t0\n");
        } else if (expr.second == "double") {
            w->appendText("    sub.s $f0, $f1, $f0\n");
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = expr.second;
    } else if (operation == "*") {
        if (expr.second == "int") {
            w->appendText("    mult $t0, $t1\n");
            w->appendText("    mflo $t0\n");
        } else if (expr.second == "double") {
            w->appendText("    mul.s $f0, $f1, $f0\n");
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = expr.second;
    } else if (operation == "/") {
        if (expr.second == "int") {
            w->appendText("    div $t1, $t0\n");
            w->appendText("    mflo $t0\n");
        } else if (expr.second == "double") {
            w->appendText("    div.s $f0, $f1, $f0\n");
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = expr.second;
    } else if (operation == "%") {
        if (expr.second == "int") {
            w->appendText("    div $t1, $t0\n");
            w->appendText("    mfhi $t0\n");
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = expr.second;
    } else if (operation == "||") {
        if (lefside.second != "bool") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        w->appendText("    or $t0, $t0, $t1\n");
        type_of_output = expr.second;
    } else if (operation == "&&") {
        if (lefside.second != "bool") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        w->appendText("    and $t0, $t0, $t1\n");
        type_of_output = expr.second;
    } else if (operation == "==") {
        if (expr.second == "int" || expr.second == "bool") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    bne $t0, $t1, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.eq.s $f0, $f1\n");
            w->appendText(
                    "    bc1f " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else if (operation == "!=") {
        if (expr.second == "int" || expr.second == "bool") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    beq $t0, $t1, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.eq.s $f0, $f1\n");
            w->appendText(
                    "    bc1t " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else if (operation == "<") {
        if (expr.second == "int") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    bge $t1, $t0, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.le.s $f0, $f1\n");
            w->appendText(
                    "    bc1t " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else if (operation == "<=") {
        if (expr.second == "int") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    bgt $t1, $t0, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.lt.s $f0, $f1\n");
            w->appendText(
                    "    bc1t " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else if (operation == ">") {
        if (expr.second == "int") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    ble $t1, $t0, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.le.s $f1, $f0\n");
            w->appendText(
                    "    bc1t " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else if (operation == ">=") {
        if (expr.second == "int") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText(
                    "    blt $t1, $t0, " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else if (expr.second == "double") {
            string label1 = idgen::nextlabel();
            string label2 = idgen::nextlabel();
            w->appendText("    c.lt.s $f1, $f0\n");
            w->appendText(
                    "    bc1t " + label1 + "\n"
                    + "    li $t0, 1\n"
                    + "    b " + label2 + "\n"
                    + label1 + ":\n"
                    + "    li $t0, 0\n"
                    + label2 + ":\n"
            );
        } else {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        type_of_output = "bool";
    } else {
        throw runtime_error("my error: the operation is not implemented yet: " + operation);
    }
    if (type_of_output == "int" || type_of_output == "bool") {
        w->appendText("    sw $t0, " + temp_id + "\n\n");
    } else if (type_of_output == "double") {
        w->appendText("    s.s $f0, " + temp_id + "\n\n");
    } else {
        throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
    }
    return {temp_id, type_of_output};
}

exprtype codegen::unaryminus(const exprtype &expr) {
    if (expr.second == "int") {
        string temp_id = idgen::nextid();
        w->appendData("    .align 2\n");
        w->appendData("    " + temp_id + ": .word 0\n");
        w->appendText("    # doing the u-\n");
        w->appendText(
                "    lw $t0, " + expr.first + "\n"
                + "    subu $t0, $zero, $t0\n"
                + "    sw $t0, " + temp_id + "\n\n"
        );
        return {temp_id, expr.second};
    } else if (expr.second == "double") {
        string temp_id = idgen::nextid();
        w->appendData("    .align 2\n");
        w->appendData("    " + temp_id + ": .word 0\n");
        w->appendText("    # doing the u-\n");
        w->appendText(
                "    l.s $f0, " + expr.first + "\n"
                + "    sub.s $f1, $f0, $f0 #making zero\n"
                + "    sub.s $f0, $f1, $f0\n"
                + "    s.s $f0, " + temp_id + "\n\n"
        );
        return {temp_id, expr.second};
    } else {
        throw runtime_error("semantic error: invalid operation: -" + expr.second);
    }
}

exprtype codegen::unarynot(const exprtype &expr) {
    if (expr.second != "bool")
        throw runtime_error("semantic error: invalid operation: !" + expr.second);
    string temp_id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + temp_id + ": .word 0\n");
    w->appendText("    # doing the u!\n");
    w->appendText(
            "    lw $t0, " + expr.first + "\n"
            + "    li $t1, 1\n"
            + "    subu $t0, $t1, $t0\n"
            + "    sw $t0, " + temp_id + "\n\n"
    );
    return {temp_id, expr.second};
}

void codegen::whilestmt1() {
    string beginwhile = "while_loop_" + idgen::nextid();
    w->appendText(beginwhile + ":\n");
    loopstack.push({beginwhile, beginwhile, ""});
}

void codegen::whilestmt2(const pair<string, string> &expr) {
    if (expr.second != "bool")
        throw runtime_error("invalid type for while expression");
    string endwhile = "endwhile_" + idgen::nextid();
    w->appendText("    lw $t0, " + expr.first + "\n"
                  + "    beqz $t0, " + endwhile + "\n"
    );
    loopstack.top().end = endwhile;
}

void codegen::whilestmt3() {

    w->appendText(
            "    j " + loopstack.top().begin + "\n"
            + loopstack.top().end + ":\n\n"
    );

    loopstack.pop();
}


void codegen::beginfor() {
    string beginforlabel = "BEGINFOR_" + idgen::nextid();
    w->appendText(
            "    # begin for loop of " + beginforlabel + "\n"
            + beginforlabel + ":\n"
    );
    loopstack.push({beginforlabel, "", ""});
}

void codegen::forloopcond(const exprtype &expr) {
    if (!(expr.second == "bool"))
        throw runtime_error("value for condition of loop must be bool");
    string endforlabel = "ENDFOR_" + idgen::nextid();
    w->appendText(
            +"    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + endforlabel + "\n"
    );
    w->to_stack = true;
    w->new_tops();
    string snlabel = "SN_LABEL_" + idgen::nextid();
    w->appendText(snlabel + ":\n");
    loopstack.top().end = endforlabel;
    loopstack.top().snlabel = snlabel;
}

void codegen::endsecnexpr() {
    w->to_stack = false;
}

void codegen::endforstmt() {
    // for second nexpr
    w->appendFromStacks();

    string end = loopstack.top().end;
    string begin = loopstack.top().begin;

    w->appendText(
            "    j " + begin + "\n"
            + end + ":\n\n"
    );

    loopstack.pop();
}


void codegen::breakstmt() {
    w->appendText(
            "    #break\n"
            "    j " + loopstack.top().end + "\n\n"
    );
}

exprtype codegen::readinteger() {
    string id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word " + "0\n");
    w->appendText(
            string("    li $v0, 5\n")
            + "    syscall\n"
            + "    sw $v0, " + id + "\n"
    );
    return {id, "int"};
}

exprtype codegen::itob(const exprtype &expr) {
    if (expr.second != "int")
        throw runtime_error("semantic error: itob's input should be integer");
    string id = idgen::nextid();
    string itoblabel = "ITOB_" + idgen::nextid();
    string zero = itoblabel + "_z";
    string not_zero = itoblabel + "_nz";
    string end = itoblabel + "_e";
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word " + "0\n");
    w->appendText(
            string("    #itob" + id + "\n")
            + "    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + zero + "\n"
            + "    li $t0, 1\n"
            + "    sw $t0, " + id + "\n"
            + "    j " + end + "\n"
            + "    " + zero + ":\n"
            + "    sw $zero, " + id + "\n"
            + "    " + end + ":\n\n"
    );
    return {id, "bool"};
}

exprtype codegen::btoi(const exprtype &expr) {
    if (expr.second != "bool")
        throw runtime_error("semantic error: btoi's input should be bool");
    string id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word " + "0\n");
    w->appendText(
            string("    #btoi" + id + "\n")
            + "    lw $t0, " + expr.first + "\n"
            + "    sw $t0, " + id + "\n\n"
    );
    return {id, "int"};
}

exprtype codegen::itod(const exprtype &expr) {
    if (expr.second != "int")
        throw runtime_error("semantic error: itod's input should be integer");
    string id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word " + "0\n");
    w->appendText(
            string("    #itod" + id + "\n")
            + "    l.s $f0, " + expr.first + "\n"
            + "    cvt.s.w $f1, $f0\n"
            + "    s.s $f1, " + id + "\n\n"
    );
    return {id, "double"};
}

exprtype codegen::dtoi(const exprtype &expr) {
    if (expr.second != "double")
        throw runtime_error("semantic error: dtoi's input should be integer");
    string id = idgen::nextid();
    w->appendData("    .align 2\n");
    w->appendData("    " + id + ": .word " + "0\n");
    w->appendText(
            string("    #dtoi" + id + "\n")
            + "    l.s $f0, " + expr.first + "\n"
            + "    cvt.w.s $f1, $f0\n"
            + "    s.s $f1, " + id + "\n\n"
    );
    return {id, "int"};
}

void codegen::continuestmt() {
    w->appendText(
            "    j " + loopstack.top().snlabel + "\n"
    );
}

void codegen::funcreturn(const exprtype &expr) {
    w->appendText(
            "    # return " + expr.first + "\n"
            + "    lw $v0, " + expr.first + "\n\n"
    );
}

exprtype codegen::getline(size_t l) {
    string id = idgen::nextid();
    w->appendData(
            string("    # for __line__\n") +
            "    " + id + ": .word " + to_string(l) + "\n\n"
    );
    return {id, "int"};
}

exprtype codegen::getfunc() {
    return addconstant(
            {'"' + st->currentFuncName() + '"', "string"}
    );
}
