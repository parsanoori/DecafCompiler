#include "writer.h"


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
