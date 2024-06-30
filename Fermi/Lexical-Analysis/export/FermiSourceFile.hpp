#ifndef FERMI_SOURCE_FILE_HPP
#define FERMI_SOURCE_FILE_HPP

#include <filesystem>
#include <fstream>
#include <memory>

#include "FermiLexer.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiSourceFile
    {
      public:
        explicit FermiSourceFile(const std::filesystem::path& path);

        auto getLexer() -> FermiLexer&;

      private:
        std::string   sourceFileName_;
        std::ifstream input_;
        FermiLexer    lexer_;
    };
} // namespace Fermi::SyntaxAnalysis

#endif