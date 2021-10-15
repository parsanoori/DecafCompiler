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
    if (begin > 0 && i[begin - 1] == '"' && end < i_length - 1 && i[end] == '"')
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
    string tmp = i;
    size_t before_tmp;
    smatch m;
    const regex& re = regex("([^_a-zA-Z]+\\d*)(" + r + ")(\\d*[^_a-zA-Z]+)");
    while(regex_search(tmp,m,re)){
        before_tmp = i.length() - tmp.length();
        size_t start = m.position() + m[1].length();
        size_t length = m[2].length();
        if(should_be_changed(tmp,start,length)) {
            i.replace(before_tmp + start,  length, s);
            tmp = i.substr(before_tmp + start + s.length(), i.length() - before_tmp - start - s.length());
        } else{
            tmp = i.substr(before_tmp + length,length);
        }
    }
}

string preprocess(string i){

    string_change_newlines(i);

    smatch m;
    regex e("define[^\\S\\n]+([A-Za-z_]\\w*)[^\\S\\n]+(.*)\n"); // find all defines
    while(regex_search(i,m,e)) { // search for pattern
        string r = m[1].str(),s=m[2].str(); // store before it messes up
        i.erase(m.position(),m[0].length()); // erase the shit
        replace_if_it_should_be(i,r,s); // replace thos bastards
    }
    return i;
}
