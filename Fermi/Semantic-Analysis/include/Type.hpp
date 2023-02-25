#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

namespace Fermi::SemanticAnalysis
{
    struct Type 
    {
        std::size_t size; 
        std::string name;
    };
} // namespace Fermi::SemanticAnalysis
#endif