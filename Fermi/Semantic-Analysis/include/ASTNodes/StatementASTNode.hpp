/**
 * @file StatementASTNodes.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef STATEMENT_AST_NODE_HPP
#define STATEMENT_AST_NODE_HPP

#include <memory>
#include <vector>

#include "ASTNode.hpp"

namespace Fermi::SemanticAnalysis
{
    class StatementASTNode : public ASTNode 
    {
    public: 
        virtual ~StatementASTNode() = default;
    };

    class FermiASTNode : public StatementASTNode 
    {
    public:
        std::vector<const ASTNode*> getChildren() const override;

        ASTNodeType getNodeType() const override;

        void addChild(std::unique_ptr<StatementASTNode> child);
    private:
        std::vector<std::unique_ptr<StatementASTNode>> children_;
    };
}

#endif