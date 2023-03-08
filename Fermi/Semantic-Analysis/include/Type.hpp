#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

namespace Fermi::SemanticAnalysis
{
    struct Type 
    {
        std::size_t size; 
        std::string name;

        bool operator==(const Type& lhs) const = default;
    };

    bool isIntegerType(const Type& type);

    bool isFloatingPointType(const Type& type);
} // namespace Fermi::SemanticAnalysis
#endif