#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "preprocessor.hpp"
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

    string input_file_name = argv[2];
    string output_file_name = argv[4];

    ofstream output_file(output_file_name);
    ifstream input_file(input_file_name);
    
    string i = stream_to_string(input_file);
    cout << preprocess(i) << endl;

    return 0;
}
