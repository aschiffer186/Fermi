#include "FermiParser.hpp"
#include "FermiLexerTypes.hpp"

namespace Fermi::SyntaxAnalysis
{
    FermiParser::FermiParser(std::vector<LexicalAnalysis::FermiToken> tokens)
    : tokens_(std::move(tokens))
    {

    }

    void FermiParser::parse()
    {
        
    }

    const std::vector<SyntaxNode>& FermiParser::getSyntaxTree() const 
    {
        return syntaxTree_;
    }

    std::size_t FermiParser::parseExpression() 
    {
        return 0;
    }

    auto FermiParser::getPrecedence(LexicalAnalysis::FermiTokenKind kind) 
    {
        return tokPrec_.find(kind);
    }

    bool FermiParser::accept(LexicalAnalysis::FermiTokenKind expected)
    {
        const LexicalAnalysis::FermiToken& tok = tokens_[currTokenIdex_];
        if(tok.kind == expected)
        {
            ++currTokenIdex_;
            return true;
        }
        return false;
    }

    bool FermiParser::expect(LexicalAnalysis::FermiTokenKind expected)
    {
        const LexicalAnalysis::FermiToken& tok = tokens_[currTokenIdex_];
        if(tok.kind == expected)
        {
            ++currTokenIdex_;
            return true;
        }
        //Error 
        return false;
    }

    const std::unordered_map<LexicalAnalysis::FermiTokenKind, int> FermiParser::tokPrec_{
        {LexicalAnalysis::FermiTokenKind::Assign, -5},
        {LexicalAnalysis::FermiTokenKind::PipePipe, -4},
        {LexicalAnalysis::FermiTokenKind::AmpAmp, -3},
        {LexicalAnalysis::FermiTokenKind::Equal, -2},
        {LexicalAnalysis::FermiTokenKind::NotEqual, -2},
        {LexicalAnalysis::FermiTokenKind::Less, -1},
        {LexicalAnalysis::FermiTokenKind::LessEqual, -1},
        {LexicalAnalysis::FermiTokenKind::GreaterEqual, -1},
        {LexicalAnalysis::FermiTokenKind::Greater, -1},
        {LexicalAnalysis::FermiTokenKind::Spaceship, 0},
        {LexicalAnalysis::FermiTokenKind::Plus, 1},
        {LexicalAnalysis::FermiTokenKind::Minus, 1},
        {LexicalAnalysis::FermiTokenKind::Star, 2},
        {LexicalAnalysis::FermiTokenKind::Slash, 2},
        {LexicalAnalysis::FermiTokenKind::SlashSlash, 2},
        {LexicalAnalysis::FermiTokenKind::Percent, 2},
        {LexicalAnalysis::FermiTokenKind::Caret, 3},
    };
}