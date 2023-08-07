#include "FermiLexerTypes.hpp"

#include <array>
#include <ostream>
#include <type_traits>


namespace Fermi::LexicalAnalysis
{
    constexpr std::array tokenKindNames {
        "Character Literal",
        "Complex Literal",
        "Float Ltieral",
        "Integer Literal",
        "String Literal",
    };

    std::ostream& operator<<(std::ostream& os, FermiTokenKind kind)
    {
        auto idx = static_cast<std::underlying_type_t<FermiTokenKind>>(kind);
        os << tokenKindNames[idx];
        return os;
    }
}
