#include "writer.h"
#include "iostream"

using namespace std;

writer *writer::instance;

void writer::appendData(const string &d) {
    if (to_stack) {
        string tmp = datastack.top().append(d);
        datastack.pop();
        datastack.push(tmp);
    } else
        data.append(d);
}

void writer::appendText(string t) {
    if (to_stack) {
        string tmp = textstack.top().append(t);
        textstack.pop();
        textstack.push(tmp);
    } else
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

void writer::appendFromStacks() {
    data.append(datastack.top());
    datastack.pop();
    text.append(textstack.top());
    textstack.pop();
}


void writer::new_tops() {
    textstack.push("");
    datastack.push("");
}



