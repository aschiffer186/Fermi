/**
 * @file FermiSourceFile.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef FERMI_SOURCE_FILE_HPP
#define FERMI_SOURCE_FILE_HPP

#include <istream>
#include <memory>
#include <string>

#include "FermiLexer.hpp"

#include "StatementNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class SyntaxNode;

    /**
     * @brief Manages parsing
     * 
     * class FermiSourceFile is responsible for managing the first stages of translation, 
     * lexing and parsing for each Fermi source file. It also manages the memory of the 
     * syntax tree representing that source file.
     */
    class FermiSourceFile
    {
    public:
        explicit FermiSourceFile(std::string_view name);

        FermiSourceFile(const FermiSourceFile&) = delete;
        FermiSourceFile(FermiSourceFile&&) = default;

        FermiSourceFile& operator=(const FermiSourceFile&) = delete;
        FermiSourceFile& operator=(FermiSourceFile&&) = delete; 

        void setSyntaxTree(std::unique_ptr<FermiStatementNode> syntaxTree);

        void addDiagnostic(std::string_view diagnostic);

        const FermiStatementNode& getTree() const;

        bool parsedSuccessfully() const;

        const std::vector<std::string>& getDiagnostics() const;

        std::string_view getName() const;
    private:
        std::string name_;
        std::vector<std::string> diagnostics_;
        std::unique_ptr<FermiStatementNode> syntaxTree_;
    };
} // namespace Fermi::SyntaxAnalysis


#endif