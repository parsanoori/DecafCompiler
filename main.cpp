#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "scanner.hpp"
#include "preprocessor.hpp"
#include <sstream>
using namespace std ;

string stream_to_string(istream& i){
    i.seekg(0, std::ios::end);
    size_t size = i.tellg();
    std::string buffer(size, ' ');
    i.seekg(0);
    i.read(&buffer[0], size); 
    return buffer;
}

int main(int argc, char* argv[]){
    if (argc < 5 ){
        cerr<< "Usage: " << argv[0] << " -i <input> -o <output>" << endl ;
        return 1;
    }

    ofstream output_file(argv[4]);
    ifstream input_file(argv[2]);
        
    string i = stream_to_string(input_file);
    string preprocessed = preprocess(i);
    istringstream ss(preprocessed);
    scan(ss,output_file);

    return 0;
}
