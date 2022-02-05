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
    w->appendData("    " + d.getID() + ": .word " + "0\n\n");
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
    else if (expr.second == "double")
        w->appendText("    # print " + expr.first + "...\n"
                      + "    li $v0, 2\n"
                      + "    l.s $f12, " + expr.first + "\n"
                      + "    syscall\n\n"
        );
}

exprtype codegen::addconstant(const pair<string, string> &constant) {
    w->appendData("    #" + constant.first + "\n");
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
    if(expr.second == "int") {
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
    }
    else if(expr.second == "double"){
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
        throw e;
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
        throw e;
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
        throw e;
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
    if (operation == "+") {
        w->appendText("    addu $t0, $t0, $t1\n");
        type_of_output = expr.second;
    } else if (operation == "-") {
        w->appendText("    subu $t0, $t1, $t0\n");
        type_of_output = expr.second;
    } else if (operation == "*") {
        w->appendText("    mult $t0, $t1\n");
        w->appendText("    mflo $t0\n");
        type_of_output = expr.second;
    } else if (operation == "/") {
        w->appendText("    div $t1, $t0\n");
        w->appendText("    mflo $t0\n");
        type_of_output = expr.second;
    } else if (operation == "%") {
        w->appendText("    div $t1, $t0\n");
        w->appendText("    mfhi $t0\n");
        type_of_output = expr.second;
    } else if (operation == "||") {
        if (lefside.second != "bool") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        w->appendText("    or $t0, $t0, $t1\n");
    } else if (operation == "&&") {
        if (lefside.second != "bool") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
        w->appendText("    and $t0, $t0, $t1\n");
    } else if (operation == "==") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else if (operation == "!=") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else if (operation == "<") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else if (operation == "<=") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else if (operation == ">") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else if (operation == ">=") {
        if (lefside.second != "int") {
            throw runtime_error("semantic error: invalid operation: " + lefside.second + operation + expr.second);
        }
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
        type_of_output = "bool";
    } else {
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
            + "    subu $t0, $zero, $t0\n"
            + "    sw $t0, " + temp_id + "\n\n"
    );
    return {temp_id, expr.second};
}

exprtype codegen::unarynot(const exprtype &expr) {
    if (expr.second != "bool")
        throw runtime_error("semantic error: invalid operation: !" + expr.second);
    string temp_id = idgen::nextid();
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
    string whilename = "while_loop_" + idgen::nextid();
    w->appendText(whilename + ":");
    ss.push(whilename);
}

void codegen::whilestmt2(const pair<string, string> &expr) {
    if (expr.second != "bool")
        throw runtime_error("invalid type for while expression");
    string endwhile = "endwhile_" + idgen::nextid();
    w->appendText("    lw $t0, " + expr.first + "\n"
                  + "    beqz $t0, " + endwhile + "\n"
    );
    ss.push(endwhile);
}

void codegen::whilestmt3() {
    string startname,endname;
    try{
        endname = any_cast<string>(ss.top());
        ss.pop();
        startname = any_cast<string>(ss.top());
        ss.pop();
    } catch (const bad_any_cast &e) {
        cerr << "bad any cast in whilestmt3" << endl;
        throw e;
    }
    w->appendText("    j " + startname + "\n"
                  + endname + ":\n\n"
    );
}

void codegen::forloopcond(const exprtype &expr) {
    if (!(expr.second == "bool"))
        throw runtime_error("value for condition of loop must be bool");
    string endforlabel = "ENDFOR_" + idgen::nextid();
    w->appendText(
            +"    lw $t0, " + expr.first + "\n"
            + "    beqz $t0, " + endforlabel + "\n"
    );
    w->to_buffer = true;
    ss.push(endforlabel);
}

void codegen::endsecnexpr() {
    w->to_buffer = false;
}

void codegen::endforstmt() {
    // for second nexpr
    w->flushbuffers();

    string endforlabel;
    string beginforlabel;
    try {
        endforlabel = any_cast<string>(ss.top());
        ss.pop();
        beginforlabel = any_cast<string>(ss.top());
        ss.pop();
    } catch (const bad_any_cast &e) {
        cerr << "bad any cast in endforstmt" << endl;
        throw e;
    }
    w->appendText(
            "    j " + beginforlabel + "\n"
            + endforlabel + ":\n\n"
    );


}

void codegen::beginfor() {
    string beginforlabel = "BEGINFOR_" + idgen::nextid();
    w->appendText(
            "    # begin for loop of " + beginforlabel + "\n"
            + beginforlabel + ":\n"
    );
    ss.push(beginforlabel);
}
