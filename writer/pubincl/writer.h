//
// Created by Parsa Noori on 2/3/2022 AD.
//

#ifndef COMPILER_WRITER_H
#define COMPILER_WRITER_H

#include <string>

using namespace std;

class writer {
    string data = ".data\n";
    string text = ".text\n";
    static writer *instance;

    writer() = default;

public:
    static writer *get();

    writer(writer &) = delete;

    void operator=(const writer &) = delete;

    void appendData(const string& d);

    void appendText(string t);

};


#endif //COMPILER_WRITER_H
