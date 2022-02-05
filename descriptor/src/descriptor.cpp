#include "descriptor.h"

#include <utility>
#include "dtype.h"
#include "idgen.h"

//dtype descriptor::typefromstr(const string& s){
//     // handle type
//    if (s == "int")
//        return dtype::INT;
//    else if (s == "double")
//        return dtype::DOUBLE;
//    else if (s == "bool")
//        return dtype::BOOL;
//    else if (s == "string")
//        return dtype::STRING;
//    else if (s == "void")
//        return dtype::VOID;
//    else return dtype::OBJECT;
//}

descriptor::descriptor(const string& typestr){
    //handle type
    this->t = dtypefromstr(typestr);

    // handle id
    id = idgen::nextid();
}

dtype descriptor::getType() const{
    return t;
}

string descriptor::getTypeString() const{
    string type;
    switch (t) {
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
    return type;
}

string descriptor::getID() const{
    return id;
}
