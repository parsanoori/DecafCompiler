#include <iostream>
#include <regex>
#include <string>
using namespace std;

string preprocess(string i){
    smatch m;
    regex e("define\\s([A-Za-z]\\w*)\\s(.*)\n"); // find all defines
    regex d;
    while(regex_search(i,m,e)) { // search for pattern
        int start = m.position();
        int end = start + m.size();
        i.erase(start,end);
        d  = m[1].str();
        i = regex_replace(i,d,m[2].str());
    }
    return i;
} 
