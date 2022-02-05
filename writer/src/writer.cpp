#include "writer.h"
#include "iostream"

using namespace std;

writer *writer::instance;

void writer::appendData(const string &d) {
    if (!to_buffer)
        data.append(d);
    else
        databuffer.append(d);
}

void writer::appendText(string t) {
    if (!to_buffer)
        text.append(t);
    else
        textbuffer.append(t);
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

void writer::flushbuffers() {
    text.append(textbuffer);
    data.append(databuffer);
    textbuffer.clear();
    databuffer.clear();
}
