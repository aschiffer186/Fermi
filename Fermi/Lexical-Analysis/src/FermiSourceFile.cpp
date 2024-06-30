#include "FermiSourceFile.hpp"
#include "FermiLexer.hpp"
#include <filesystem>
#include <stdexcept>

namespace Fermi::SyntaxAnalysis
{
    FermiSourceFile::FermiSourceFile(const std::filesystem::path& path)
        : input_{path},
          lexer_{input_}
    {
        if (std::filesystem::exists(path))
        {
            std::string message = "Input file: ";
            message.append(path.c_str());
            message.append(", does not exist");
            throw std::invalid_argument{message};
        }
    }

    auto FermiSourceFile::getLexer() -> FermiLexer& { return lexer_; }
} // namespace Fermi::SyntaxAnalysis