#include <iostream>
#include <regex>
#include <string>

using namespace std;

void remove_comments(string &i) {
    i = regex_replace(i, regex("/\\*(.|\n)*?\\*/"), " ");
    i = regex_replace(i, regex("//.*"), "");
}

void string_change_newlines(string &i) { // shitty windows new lines
    i = regex_replace(i, regex("\r\n"), "\n");
    i = regex_replace(i, regex("\r"), "\n");
}

bool should_be_changed(const string &i, size_t begin, size_t length) { // is it bastard
    size_t i_length = i.length();

    size_t end = begin + length;
    if (begin > 0 && i[begin - 1] == '"' && end < i_length - 1 && i[end] == '"')
        return true;

    while (end < i_length && i[end] != '\n')
        if (i[++end] == '"')
            return false;

    while (begin >= 0 && i[begin] != '\n')
        if (i[--begin] == '"')
            return false;

    return true;
}

void replace_if_it_should_be(string &i, const string &r, const string &s) { // replace it it is bastard
    string result;
    string tmp = i;
    size_t before_tmp;
    smatch m;
    const regex &re = regex("([^_a-zA-Z]+\\d*)(" + r + ")(\\d*[^_a-zA-Z]+)");
    while (regex_search(tmp, m, re)) {
        size_t start = m.position() + m[1].length();
        size_t length = m[2].length();
        if (should_be_changed(tmp, start, length)) {
            result += tmp.substr(0, start) + s;
            tmp = tmp.substr(start + length, tmp.length() - start - length);
        } else {
            result += tmp.substr(0,start+length);
            tmp = tmp.substr(start+length, tmp.size()-start-length);
        }
    }
    i = result + tmp;
}

string preprocess(string i) {

    string_change_newlines(i);
    remove_comments(i);

    smatch m;
    regex e("define[^\\S\\n]+([A-Za-z_]\\w*)[^\\S\\n]+(.*)\n"); // find all defines
    while (regex_search(i, m, e)) { // search for pattern
        string r = m[1].str(), s = m[2].str(); // store before it messes up
        i.replace(m.position(), m[0].length(), "\n"); // erase the shit
        replace_if_it_should_be(i, r, s); // replace thos bastards
    }
    return i;
}
