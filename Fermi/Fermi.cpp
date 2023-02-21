#include <fstream>
#include <iostream>
#include <string_view>

#include "FermiCommandArguments.hpp"
#include "FermiSourceFile.hpp"
#include "FermiParser.hpp"

int main(int argc, const char** argv)
{
    if (argc < 2)
    {
        std::cout << "Must provide at least one command line argument";
        return 0;
    }
    
    Fermi::Setup::CommandLineArguments args = Fermi::Setup::getOpts(argc, argv);

    if (static_cast<Fermi::Setup::CLT>(args.options & Fermi::Setup::CommandLineOptions::ShowHelp))
    {
        std::cout << "Fermi compiler usage:\n";
        std::cout << "fermi [options] source-file\n";
        std::cout << "Options:\n";
        std::cout << "\t--help, -h: Display this message\n";
        std::cout << "\t--version, -v: Display Fermi compiler version information\n";
        std::cout << "\t-o [file]: Specify output executable name\n";
        std::cout << "\t--show-tree,-st: Print parse tree to terminal\n";
        return 0;
    }

    if (static_cast<Fermi::Setup::CLT>(args.options & Fermi::Setup::CommandLineOptions::ShowVersion))
    {
        std::cout << "Fermi Compiler Version " << FERMI_MAJOR_VERSION << "." << FERMI_MINOR_VERSION << ".";
        std::cout << FERMI_PATCH_VERSION << "\n";
        return 0;
    }

    std::string fileName = args.sourceFiles[0];
    std::ifstream fin{fileName};

    Fermi::SyntaxAnalysis::FermiSourceFile srcFile{fileName, fin};
    Fermi::SyntaxAnalysis::FermiParser parser{srcFile};
    int res = parser.parse();
    if (res != 0)
    {
        for(std::string_view msg : srcFile.errors)
            std::cerr << msg << "\n";
        std::cerr << "Compilation failed\n";
        return 0;
    }

    if (static_cast<Fermi::Setup::CLT>(args.options & Fermi::Setup::CommandLineOptions::ShowSyntaxTree))
        std::cout << *srcFile.syntaxTree << "\n";
    return 0;
}