#include <fstream>
#include <string_view>

#include "FermiCommandArguments.hpp"
#include "FermiSourceFile.hpp"
#include "FermiParser.hpp"

int main(int argc, const char** argv)
{
    if (argc < 2)
        return 1;
    
    Fermi::Setup::CommandLineArguments args = Fermi::Setup::getOpts(argc, argv);

    std::string fileName = args.sourceFiles[0];
    std::ifstream fin{fileName};

    Fermi::SyntaxAnalysis::FermiSourceFile srcFile{fileName, fin};
    Fermi::SyntaxAnalysis::FermiParser parser{srcFile};
    parser.parse();
    std::cout << *srcFile.syntaxTree << "\n";
    return 0;
}