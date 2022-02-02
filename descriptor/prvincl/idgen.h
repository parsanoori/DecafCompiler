#ifndef __IDGEN__
#define __IDGEN__
#include <iostream>
using namespace std;

class idgen{

    public:
    static string nextid(){
        static int current = 28; // first one is aa
        string r;
        int tmp = current;
        while(tmp > 0){
            r = (char) ('a' + tmp % 27 - 1) + r; 
            tmp /= 27;
        }
        current++;
        if (current % 27 == 0)
            current++;
        return r;
    }
};

#endif
