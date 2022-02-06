#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "driver.hh"
#include "preprocessor.hpp"
#include <sstream>
#include "writer.h"

using namespace std;

string stream_to_string(istream &i) {
    i.seekg(0, std::ios::end);
    size_t size = i.tellg();
    std::string buffer(size, ' ');
    i.seekg(0);
    i.read(&buffer[0], size);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << " -i <input> -o <output>" << endl;
        return 1;
    }

    ofstream output_file(argv[4]);
    ifstream input_file(argv[2]);

    string i = stream_to_string(input_file);
    string preprocessed = preprocess(i);

    ofstream tmp("tmp.txt");
    tmp << preprocessed;
    tmp.flush();
    tmp.close();

    writer::set(&output_file);

    driver drv;
    int result;
    try {
        result = drv.parse("tmp.txt");
    } catch (const runtime_error& e){
        cout << "Semantic Error" << endl;
        cerr << e.what() << endl;
        return 2;
    }
    if (!result) {
        cout << "OK" << endl;
    } else {
        cout << "Syntax Error" << endl;
        return 1;
    }

    return 0;
}
