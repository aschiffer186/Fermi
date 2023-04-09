#ifndef AST_ERRORS_HPP
#define AST_ERRORS_HPP

#include <stdexcept>

namespace Fermi::SemanticAnalysis
{
    class InvalidLiteralException : public std::runtime_error 
    {
        explicit InvalidLiteralException(const std::string& whatArg)
        : std::runtime_error{whatArg}
        {
            
        }
    };
}

#endif