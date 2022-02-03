#include "symboltable.h"

symboltable::symboltable() {
    st.emplace_back("root");
}

symboltable *symboltable::get() {
    if (!instance)
        instance = new symboltable();
    return instance;
}

void symboltable::pushscope(const string &name) {
    st.emplace_back(name);
}

void symboltable::popscope() {
    st.pop_back();
}

void symboltable::addentry(const string &name, const string &type) {
    descriptor d(type);
    st.back().table.emplace(name, d);
    st.back().count += sizeofdtype(dtypefromstr(type));
}

descriptor symboltable::getentry(const string &name, const string &type) {
    for (auto ri = st.rbegin(); ri != st.rend(); ++ri)
        for (const auto &p: ri->table)
            if (p.first == name && p.second.getType() == dtypefromstr(type))
                return p.second;
    throw runtime_error("symbol not found");
}



