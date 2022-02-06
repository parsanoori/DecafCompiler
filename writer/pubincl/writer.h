//
// Created by Parsa Noori on 2/3/2022 AD.
//

#ifndef COMPILER_WRITER_H
#define COMPILER_WRITER_H

#include <string>
#include <fstream>

using namespace std;

class writer {
    string data = "    .data\n    _false_str: .asciiz \"false\"\n    _true_str: .asciiz \"true\"\n";
    string text = "    .text\n    .globl main\n";
    static writer *instance;
    ofstream* of;
    writer() = default;

    stack<string> datastack;
    stack<string> textstack;


public:

    bool to_stack = false;

    static void set(ofstream*);

    static writer *get();

    writer(writer &) = delete;

    void operator=(const writer &) = delete;

    void appendData(const string& d);

    void appendText(string t);

    void writestuff();

    void new_tops();

    void appendFromStacks();

};


#endif //COMPILER_WRITER_H
