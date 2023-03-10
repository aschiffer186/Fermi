#include "FermiSourceFile.hpp"

namespace Fermi::SyntaxAnalysis
{
    FermiSourceFile::FermiSourceFile(std::string_view name)
    : name_{name}, diagnostics_{}, syntaxTree_{}
    {

    }

    void FermiSourceFile::setSyntaxTree(std::unique_ptr<FermiNode> syntaxTree)
    {
        syntaxTree_ = std::move(syntaxTree);
    }

    void FermiSourceFile::addDiagnostic(std::string_view diagnostic)
    {
        diagnostics_.emplace_back(diagnostic);
    }

    const FermiNode& FermiSourceFile::getTree() const 
    {
        return *syntaxTree_;
    }

    bool FermiSourceFile::parsedSuccessfully() const 
    {
        return diagnostics_.empty();
    }

    const std::vector<std::string>& FermiSourceFile::getDiagnostics() const 
    {
        return diagnostics_;
    }

    std::string_view FermiSourceFile::getName() const 
    {
        return name_;
    }
}