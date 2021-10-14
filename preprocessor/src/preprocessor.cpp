#include <iostream>
#include <regex>
#include <string>
using namespace std;

void string_change_newlines(string& i){ // shitty windows new lines
    i = regex_replace(i,regex("\r\n"),"\n");
    i = regex_replace(i,regex("\r"),"\n");
}

bool should_be_changed(const string& i,size_t begin,size_t length){ // is it bastard
    size_t end = begin + length;
    if (i[begin - 1] == '"' && i[end + 1] == '"')
        return true;

    while(i[end] != '\n')
        if (i[++end] == '"')
            return false;

    while(i[begin] != '\n')
        if (i[--begin] == '"')
            return false;

    return true;
}

void replace_if_it_should_be(string& i,const regex& r,const string& s){ // replace it it is bastard
    smatch m;
    while(regex_search(i,m,regex(r))){
        if(should_be_changed(i,m.position(),m[0].length()))
                i.replace(m.position(),m[0].length(),s);
    }
}

string preprocess(string i){

    string_change_newlines(i);

    smatch m;
    regex e("define\\s+([A-Za-z_]\\w*)\\s+(.*)\n"); // find all defines
    while(regex_search(i,m,e)) { // search for pattern
        string r = m[1].str(),s=m[2].str(); // store before it messes up
        i.erase(m.position(),m.position()+m[0].length()); // erase the shit
        replace_if_it_should_be(i,regex(r),s); // replace thos bastards
    }
    return i;
} 
