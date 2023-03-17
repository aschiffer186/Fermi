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

    // Built-in types 
    inline const Type Fermi_int8_t{1, "int8_t"};
    inline const Type Fermi_int16_t{2, "int16_t"};
    inline const Type Fermi_int32_t{4, "int32_t"};
    inline const Type Fermi_int64_t{8, "int64_t"};
    inline const Type Fermi_float32_t{4, "float32_t"};
    inline const Type Fermi_float64_t{5, "float64_t"};

    bool isIntegerType(const Type& type);

    bool isFloatingPointType(const Type& type);

    Type getCommonType(const Type& t1, const Type& t2);
} // namespace Fermi::SemanticAnalysis
#endif