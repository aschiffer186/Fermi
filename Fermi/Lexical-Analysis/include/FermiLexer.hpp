/**
 * @file FermiLexer.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FERMI_LEXER_HPP
#define FERMI_LEXER_HPP

#include <iosfwd>
#include <vector>

#ifndef yyFlexLever
#include <FlexLexer.h>
#endif

#include "FermiLexerTypes.hpp"

namespace Fermi::LexicalAnalysis
{
    class FermiLexer : yyFlexLexer
    {
    public:
        using FlexLexer::yylex; 

        FermiLexer(std::istream&);
    
        std::vector<FermiToken> lex();
    private:
        FermiToken nextToken();

        static FermiToken makeToken();
    private: 
        Location _currLoc;
    };
}

#endif