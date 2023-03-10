#ifndef IR_GENERATOR_HPP
#define IR_GENERATOR_HPP

#include <unordered_map>

#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "Visitor.hpp"

namespace Fermi::SemanticAnalysis
{
    class AssignNode;
    class ASTNode;
    class LiteralNode;
    class TypeConversionNode;

    class IRGenerator
    {
    private:
        llvm::AllocaInst* codegen(const AssignNode* node);
        llvm::AllocaInst* codegen(const BinaryExpressionNode* node);
        llvm::AllocaInst* codegen(const LiteralNode* node);
        llvm::AllocaInst* codegen(const TypeConversionNode* node);
    private:
        std::unique_ptr<ASTNode> AST_;
        llvm::LLVMContext context_;
        llvm::Module module_;
    };
} // namespace Fermi::SemanticAnalysis


#endif