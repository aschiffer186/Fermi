/**
 * @file StatementASTNode.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>
#include <bits/ranges_algo.h>
#include <iterator>

#include "ASTNodes/StatementASTNode.hpp"
#include "ASTNodes/ASTNode.hpp"

namespace Fermi::SemanticAnalysis 
{
    ASTNodeType FermiASTNode::getNodeType() const 
    {
        return ASTNodeType::FermiStatement;
    }

    std::vector<const ASTNode*> FermiASTNode::getChildren() const 
    {
        std::vector<const ASTNode*> children;
        std::ranges::transform(children_, std::back_inserter(children), [](const auto& ptr){
            return ptr.get();
        });
        return children;
    }

    void FermiASTNode::addChild(std::unique_ptr<StatementASTNode> child) 
    {
        children_.push_back(std::move(child));
    }
}