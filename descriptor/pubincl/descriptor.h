#ifndef __DSCP__
#define __DSCP__

#include <iostream>
#include "dtype.h"

using namespace std;

class descriptor {
    string id;
    dtype t;

//    dtype typefromstr(const string &s);

public:
    explicit descriptor(const string &type);

    [[nodiscard]] dtype getType() const;

    [[nodiscard]] string getID() const;

    [[nodiscard]] string getTypeString() const;

    void setID(const string basicString);
};

#endif
