#ifndef __PUBINCL__
#define __PUBINCL__

#include <iostream>
using namespace std;

enum class dtype {
    INT, DOUBLE, BOOL, STRING, VOID, OBJECT, DUMMY
};

int sizeofdtype(dtype);

dtype dtypefromstr(const string&);



#endif
