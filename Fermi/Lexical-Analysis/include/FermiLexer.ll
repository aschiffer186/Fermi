%{
    #include "FermiLexer.hpp"

    #include <charconv>
    #include <cmath>
    #include <istream>
    #include <ostream>

    #undef YY_DECL 
    #define YY_DECL auto Fermi::SyntaxAnalysis::FermiLexer::nextToken() -> FermiParser::symbol_type

    using FermiParser = Fermi::SyntaxAnalysis::FermiParser;

    #undef YY_NULL
    #define YY_NULL FermiParser::make_YYEOF(loc_)

    #define YY_USER_ACTION loc_.columns(yyleng);
%}

%option c++
%option yyclass="Fermi::SyntaxAnalysis::FermiLexer"
%option noyywrap
%option nodefault
%option debug

digit [0-9]
based_digit {digit}|[a-zA-Z]

decimal_integer_literal {digit}+([eE][+]?{digit}+)?
based_integer_literal {digit}{1,2}#{based_digit}+#([+]?{based_digit}+)? 
integer_literal {decimal_integer_literal}|{based_integer_literal}

decimal_float_literal {digit}*\.{digit}+([eE][+-]?{digit}+)?
based_float_literal {digit}{1,2}#{based_digit}*\.{based_digit}+#([+-]?{based_digit}+)?
float_literal {decimal_float_literal}|{based_float_literal}
simple_character [^[:cntrl:]\'\\]
%%

{integer_literal} { return makeIntegerLiteral(yytext); }
{float_literal} { return makeFloatLiteral(yytext); }
({integer_literal}|{float_literal})i { return makeComplexLiteral(yytext); }
\'{simple_character}\' { return FermiParser::make_CHARACTER_LITERAL (loc_); }
[_[:alpha:]][_[:alpha:][:digit:]]* { return FermiParser::make_IDENTIFIER(yytext, loc_); }

"=" { return FermiParser::make_ASSIGN(loc_);}
"+" { return FermiParser::make_PLUS(loc_);}
"-" { return FermiParser::make_MINUS(loc_);}
"*" { return FermiParser::make_STAR(loc_);}
"/" { return FermiParser::make_SLASH(loc_);}
"%" { return FermiParser::make_PERCENT(loc_);}
"^" { return FermiParser::make_CARET(loc_);}

";" { return FermiParser::make_SEMICOLON(loc_); }
"(" { return FermiParser::make_LPAREN(loc_); }
")" { return FermiParser::make_RPAREN(loc_); }

. { return FermiParser::make_YYerror(loc_);}

%%

namespace Fermi::SyntaxAnalysis 
{
    FermiLexer::FermiLexer(std::istream& in)
    : yyFlexLexer{&in}
    {

    }

    auto makeIntegerLiteralExponent(std::string_view text, location loc) -> FermiParser::symbol_type
    {
        double value; 
        auto res = std::from_chars(text.cbegin(), text.cend(), value);
        return FermiParser::make_INTEGER_LITERAL(static_cast<std::uint64_t>(value), loc);
    }

    auto FermiLexer::makeIntegerLiteral(const char* ptr) const -> FermiParser::symbol_type
    {
        const std::string_view text(ptr, yyleng);
        std::uint64_t value{};

        if (auto idx = text.find('e'); idx != std::string_view::npos)
        {
            return makeIntegerLiteralExponent(text, loc_);
        }

        if (auto idx = text.find('E'); idx != std::string_view::npos)
        {
            return makeIntegerLiteralExponent(text, loc_);
        }

        if (auto idx = text.find('#'); idx == std::string_view::npos)
        {
            auto [ptr, ec] = std::from_chars(text.cbegin(), text.cend(), value);
            if (ec == std::errc::result_out_of_range)
            {
                std::string message = "integer literal: ";
                message.append(text);
                message.append(" cannot be represented by any fundamental integral type.");
                throw FermiParser::syntax_error(loc_, message);
            }
        }
        else 
        {
            int base{};
            auto [ptr, ec] = std::from_chars(text.cbegin(), text.cend(), base);
            auto [ptr2, ec2] = std::from_chars(ptr + 1, text.cend(), value, base);

            if (ec2 == std::errc::result_out_of_range)
            {
                std::string message = "integer literal: ";
                message.append(text);
                message.append(" cannot be represented by any fundamental integral type.");
                throw FermiParser::syntax_error(loc_, message);
            }

            if (ptr2 != text.cend())
            {
                std::uint64_t exp{}; 
                auto [ptr3, ec3] = std::from_chars(ptr2 + 1, text.cend(), exp, base);
                value = value * std::pow(10, exp);
            }
        }
        return FermiParser::make_INTEGER_LITERAL(value, loc_);
    }

    auto FermiLexer::makeFloatLiteral(const char* p) const -> FermiParser::symbol_type
    {
        std::string_view text(p, yyleng);

        double value{};
        [[maybe_unused]] auto res = std::from_chars(text.begin(), text.cend(), value); 

        return FermiParser::make_FLOAT_LITERAL(value, loc_);
    }

    auto FermiLexer::makeComplexLiteral(const char* p) const -> FermiParser::symbol_type
    {
        std::string_view text(p, yyleng);

        double value{};
        [[maybe_unused]] auto res = std::from_chars(text.begin(), text.cend(), value); 

        return FermiParser::make_COMPLEX_LITERAL(value, loc_);
    }

    auto operator<<(std::ostream& os, const FermiParser::symbol_type&) -> std::ostream& 
    {
        return os;
    }
}