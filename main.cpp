#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std ;

int main(int argc, char* argv[]){
    if (argc < 5 ){
        cerr<< "Usage: " << argv[0] << " -i <input> -o <output>" << endl ;
        return 1;
    }

    string input_file_name = argv[2];
    string output_file_name = argv[4];

    ofstream output_file("out/" + output_file_name);
    ifstream input_file("test/" + input_file_name);

}
