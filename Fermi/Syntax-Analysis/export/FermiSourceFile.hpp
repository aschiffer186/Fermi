#ifndef FERMI_SOURCE_FILE_HPP
#define FERMI_SOURCE_FILE_HPP

#include <filesystem>
#include <fstream>
#include <memory>
#include <utility>
#include <vector>

#include "FermiLexer.hpp"
#include "SyntaxNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiSourceFile
    {
      public:
        explicit FermiSourceFile(const std::filesystem::path& path);

        auto getLexer() -> FermiLexer&;

        template <typename NodeType, typename... Args>
        auto emplaceNode(Args&&... args) -> void
        {
            syntaxTree_.emplace_back(
                std::in_place_type<NodeType>, std::forward<Args>(args)...);
        }

        auto syntaxTreeSize() const -> std::size_t
        {
            return syntaxTree_.size();
        }

      private:
        std::string             sourceFileName_;
        std::ifstream           input_;
        FermiLexer              lexer_;
        std::vector<SyntaxNode> syntaxTree_;
    };
} // namespace Fermi::SyntaxAnalysis

#endif