#include "descriptor.h"
#include "dtype.h"
#include "idgen.h"

dtype descriptor::typefromstr(string s){
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

descriptor::descriptor(string typestr){
    //handle type
    this->t = typefromstr(typestr);

    // handle id
    id = idgen::nextid();
}

dtype descriptor::getType() const{
    return t;
}

string descriptor::getID() const{
    return id;
}
