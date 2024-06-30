#include <filesystem>
#include <fstream>
#include <iostream>

#include "FermiParser.hpp"
#include "FermiSourceFile.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: fermi [File Name]";
        return 0;
    }

    const std::filesystem::path path{argv[1]};

    Fermi::SyntaxAnalysis::FermiSourceFile srcFile{path};

    using enum Fermi::SyntaxAnalysis::FermiParser::symbol_kind_type;

    for (const auto& token = srcFile.getLexer().nextToken();
         token.kind() !=
         Fermi::SyntaxAnalysis::FermiParser::symbol_kind_type::S_YYEOF;)
    {
        std::cout << token << "\n";
    }
}