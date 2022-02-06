#include "dtype.h"

dtype dtypefromstr(const string& s){
    // handle type
    if (s == "int")
        return dtype::INT;
    else if (s == "double")
        return dtype::DOUBLE;
    else if (s == "bool")
        return dtype::BOOL;
    else if (s == "string")
        return dtype::STRING;
    else if (s == "void")
        return dtype::VOID;
    else return dtype::OBJECT;
}

string strfromdtype(dtype s){
    if (s == dtype::INT)
        return "int";
    else if (s == dtype::DOUBLE)
        return "double";
    else if (s == dtype::BOOL)
        return "bool";
    else if (s == dtype::STRING)
        return "string";
    else if (s == dtype::VOID)
        return "void";
    else return "object";
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"
int sizeofdtype(dtype t) {
    // handle type
    if (t == dtype::INT)
        return 4;
    else if (t == dtype::DOUBLE)
        return 4;
    else if (t == dtype::BOOL)
        return 4;
    else if (t == dtype::STRING)
        return 4;
    else if (t == dtype::VOID)
        return -1;
    else return 4;
}
#pragma clang diagnostic pop

