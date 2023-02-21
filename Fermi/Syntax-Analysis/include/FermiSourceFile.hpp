#ifndef FERMI_SOURCE_FILE_HPP
#define FERMI_SOURCE_FILE_HPP

#include <istream>
#include <memory>
#include <string>

#include "FermiLexer.hpp"

#include "StatementNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    class SyntaxNode;

    class FermiSourceFile
    {
    public:
        std::string name;
        FermiLexer lexer;
        std::shared_ptr<FermiNode> syntaxTree;
        std::vector<std::string> errors;

        FermiSourceFile(std::string_view nameIn, std::istream& istreamIn)
        : name{nameIn}, lexer{istreamIn}, syntaxTree{nullptr}, errors{}
        {

        }
    };
} // namespace Fermi::SyntaxAnalysis


#endif