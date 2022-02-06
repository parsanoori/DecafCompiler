#ifndef __IDGEN__
#define __IDGEN__
#include <iostream>
using namespace std;

class idgen{

    public:
    static string nextid(){
        static int current = 28; // first one is aa
        SAM:
        string r = "_";
        int tmp = current;
        while(tmp > 0){
            char c = (char) ('a' + tmp % 27 - 1);
            if (c == '`') {
                current++;
                goto SAM;
            }
            r = c + r;
            tmp /= 27;
        }
        current++;
        return r;
    }

    static string nextlabel(){
        static int current = 28; // first one is _label_aa
        string r;
        int tmp = current;
        while(tmp > 0){
            r = (char) ('a' + tmp % 27 - 1) + r;
            tmp /= 27;
        }
        r = "_label_" + r;
        current++;
        if (current % 27 == 0)
            current++;
        return r;
    }
};

#endif
