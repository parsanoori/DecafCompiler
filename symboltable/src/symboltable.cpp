#include "symboltable.h"

symboltable* symboltable::instance;

symboltable::symboltable() {
    st.emplace_back("root");
}

symboltable *symboltable::get() {
    if (!instance)
        instance = new symboltable();
    return instance;
}

void symboltable::pushscope(const string &name,bool isFuncName) {
    st.emplace_back(name);
    if (isFuncName)
        funcName = name;
}

void symboltable::popscope() {
    st.pop_back();
}

descriptor symboltable::addentry(const string &name, const string &type) {
    try {
        auto d = getentry(name);
        throw runtime_error("redefining " + name);
    }
    catch (runtime_error &error) {
        if(error.what()[0] == 'r'){ // redefining
            throw error;
        }
    }
    descriptor d(type);
    st.back().table.emplace(name, d);
    st.back().count += sizeofdtype(dtypefromstr(type));
    return d;
}

descriptor symboltable::getentry(const string &name/*, const string &type*/) {
    for (auto ri = st.rbegin(); ri != st.rend(); ++ri)
        for (const auto &p: ri->table)
            if (p.first == name /*&& p.second.getType() == dtypefromstr(type)*/)
                return p.second;
    throw runtime_error("symbol " + name + " not found");
}

string symboltable::currentscopename() {
    return funcName;
}



