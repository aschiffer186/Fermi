/**
 * @file FermiLexer.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FERMI_LEXER_HPP
#define FERMI_LEXER_HPP

#include <iosfwd>

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

#include "Location.hpp"
#include "FermiParser.hpp"

/// @namespace Namespace containing all types and functions related to syntax analysis
namespace Fermi::SyntaxAnalysis
{
    /**
     * @brief Class defining FermiLexer
     * 
     * The FermiLexer class defines the lexer used to lex Fermi source files. 
     * The FermiLexer consumes characters in a Fermi source file one at a time 
     * and groups them into tokens according to regular expressions defined in 
     * FermiLexer.ll. The FermiLexer will produce the longest tokens possible, 
     * even if this causes the program to be ill-formed. 
     * 
     * The FermiLexer will consume characters until either the end of the file 
     * is reached, in which case it will emit the end of file token, or 
     * until an invalid token is formed. 
     * 
     * FermiLexers ignore whitespce and comments.
     */
    class FermiLexer : public yyFlexLexer
    {
    public:
        /**
         * @brief Construct a new FermiLexer object
         * 
         * Constructs a new FermiLexer that will lex the characters 
         * found in the specified input stream.
         * 
         * @pre the input stream is in a valid state for reading
         * @param in the input stream to lex
         */
        explicit FermiLexer(std::istream& in);

        using FlexLexer::yylex;

        /**
         * @brief Forms the next token
         * 
         * This function consumes characters, advancing the lexer for each character consumed, 
         * and groups the characters into tokens until the longest possible token is formed 
         * or no valid token is formed. If no valid token is formed, the YYError token is returned, 
         * otherwise the appropriate token is returned. If this function is at the end of a file, 
         * YYEOF is returned to indicate the end of file.
         * 
         * @return the next token in the source file
         */
        FermiParser::symbol_type nextToken();
    private:
        location loc_;
    };
} // namespace Fermi::SyntaxAnalysis


#endif