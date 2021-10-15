#include <iostream>
#include <regex>
#include <string>
using namespace std;

void string_change_newlines(string& i){ // shitty windows new lines
    i = regex_replace(i,regex("\r\n"),"\n");
    i = regex_replace(i,regex("\r"),"\n");
}

bool should_be_changed(const string& i,size_t begin,size_t length){ // is it bastard
    size_t i_length = i.length();

    size_t end = begin + length;
    if (begin > 0 && i[begin - 1] == '"' && end < i_length - 1 && i[end + 1] == '"')
        return true;

    while(end < i_length && i[end] != '\n')
        if (i[++end] == '"')
            return false;

    while(begin >= 0 && i[begin] != '\n')
        if (i[--begin] == '"')
            return false;

    return true;
}

void replace_if_it_should_be(string& i,const string& r,const string& s){ // replace it it is bastard
    smatch m;
    const regex& re = regex("([^_a-zA-Z]+\\d*)(" + r + ")(\\d*[^_a-zA-Z]+)");
    while(regex_search(i,m,re)){
        if(should_be_changed(i,m.position() + m[1].length(),m[2].length()))
            i.replace(m.position() + m[1].length(),m[2].length(),s);
    }
}

string preprocess(string i){

    string_change_newlines(i);

    smatch m;
    regex e("define\\s+([A-Za-z_]\\w*)\\s+(.*)\n"); // find all defines
    while(regex_search(i,m,e)) { // search for pattern
        string r = m[1].str(),s=m[2].str(); // store before it messes up
        i.erase(m.position(),m[0].length()); // erase the shit
        replace_if_it_should_be(i,r,s); // replace thos bastards
    }
    return i;
}
