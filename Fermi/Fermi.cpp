#include <fstream>
#include <iostream>

#include "FermiLexer.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: fermi [File Name]";
        return 0;
    }

    std::ifstream fin{argv[1]};

    Fermi::SyntaxAnalysis::FermiLexer lexer{fin};

    while (true) { const auto token = lexer.nextToken(); }
}