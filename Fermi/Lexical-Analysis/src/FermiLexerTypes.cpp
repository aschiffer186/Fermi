#include "FermiLexerTypes.hpp"

#include <array>
#include <ostream>
#include <type_traits>


namespace Fermi::LexicalAnalysis
{
    template<typename Enum>
    constexpr auto toUnderlying(Enum e) noexcept
    {
        return static_cast<std::underlying_type_t<FermiTokenKind>>(e);
    }

    constexpr std::array tokenKindNames {
        "Character Literal",
        "Complex Literal",
        "Float Ltieral",
        "Integer Literal",
        "String Literal",
        "Identifier",
        "Amp",
        "Colon",
        "Comma",
        "LeftBrace",
        "LeftBracket",
        "LeftParenthesis",
        "RightBrace",
        "RightBracket",
        "RightParenthesis",
        "SemiColon",
        "Plus",
        "Minus",
        "Star",
        "Slash",
        "Double Slash",
        "Carent",
        "Percent",
        "Double Amp",
        "Double Pipe",
        "Bang",
        "Equal",
        "Not Equal",
        "Greater",
        "Less",
        "Greater Equal",
        "Less Equal",
        "Spaceship",
        "Dot",
        "Assign",
        "As",
        "Define",
        "Export",
        "Let",
        "Module",
        "Nothrow",
        "Operator",
        "Public",
        "Pure",
        "Struct",
        "Template",
        "Typeset",
        "Error",
        "EOF"
    };
    static_assert(tokenKindNames.size() == toUnderlying(FermiTokenKind::END));


    std::ostream& operator<<(std::ostream& os, FermiTokenKind kind)
    {
        auto idx = toUnderlying(kind);
        os << tokenKindNames[idx];
        return os;
    }

    std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const FermiToken& tok)
    {
        return os;
    }
}
