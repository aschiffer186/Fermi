#ifndef FERMI_MODULE_HPP
#define FERMI_MODULE_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "Type.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiNode;
}

namespace Fermi::SemanticAnalysis
{
    class FermiASTNode;

    /**
     * @brief Represents a Fermi compilation unit
     * 
     */
    class FermiModule
    {
    public:
        FermiModule(std::string_view moduleName, const SyntaxAnalysis::FermiNode& syntaxTree);

        std::string_view getModuleName();
    private:
        void createAST(const SyntaxAnalysis::FermiNode& syntaxTree);
    private:
        std::unique_ptr<FermiASTNode> ASTRoot_;
        std::string moduleName_;
        std::unordered_map<std::string, Type> symbolTable_;
        std::vector<std::string> diagnostics_;
    };
}

#endif
