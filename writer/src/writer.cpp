#include "writer.h"
#include "iostream"

using namespace std;

writer *writer::instance;

void writer::appendData(const string &d) {
    data.append(d);
}

void writer::appendText(string t) {
    text.append(t);
}

writer *writer::get() {
    if (!instance)
        instance = new writer();
    return instance;
}


void writer::set(ofstream *of) {
    if (instance->of)
        throw runtime_error("what the fuck bro?");
    instance->of = of;
}

void writer::writestuff() {
    *of << data << endl << text << endl;
    of->flush();
    of->close();
}
