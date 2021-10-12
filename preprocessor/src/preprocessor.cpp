#include <iostream>
#include <regex>
#include <string>
using namespace std;

string preprocess(string i){

    i = regex_replace(i,regex("\r\n"),"\n");
    i = regex_replace(i,regex("\r"),"\n");

    smatch m;
    regex e("define\\s+([A-Za-z_]\\w*)\\s+(.*)\n"); // find all defines
    while(regex_search(i,m,e)) { // search for pattern
        string r = m[1].str(),t=m[2].str(); // store before it messes up
        i.erase(m.position(),m.position()+m[0].length()); // erase the shit
        i = regex_replace(i,regex(r),t); // replace those bastards
    }
    return i;
} 
