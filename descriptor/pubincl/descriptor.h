#ifndef __DSCP__
#define __DSCP__

#include <iostream>
#include "dtype.h"

using namespace std;

class descriptor{
    string id;
    dtype t;
    
    dtype typefromstr(string s);
    public:
    descriptor(string type);
    dtype getType() const;
    string getID() const;

};

#endif
