#include <fstream>
#include <string_view>

#include "FermiSourceFile.hpp"
#include "FermiParser.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;
    
    std::string filename = argv[1];
    std::ifstream fin{filename};

    Fermi::SyntaxAnalysis::FermiSourceFile srcFile{filename, fin};
    Fermi::SyntaxAnalysis::FermiParser parser{srcFile};
    parser.parse();
    std::cout << *srcFile.syntaxTree << "\n";
    return 0;
}