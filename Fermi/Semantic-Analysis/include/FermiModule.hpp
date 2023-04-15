/**
 * @file FermiModule.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FERMI_MODULE_HPP
#define FERMI_MODULE_HPP

#include <string>
#include <unordered_map>

#include "ASTNodes/StatementASTNode.hpp"
#include "Type.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiStatementNode;
}

namespace Fermi::SemanticAnalysis
{
    class FermiModule
    {
    public: 
        explicit FermiModule(const SyntaxAnalysis::FermiStatementNode& syntaxTree);
    private: 
        FermiASTNode ast_;
        std::unordered_map<std::string, FermiType> symbolTable_;
    };
}

#endif