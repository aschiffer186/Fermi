#ifndef TYPE_HPP
#define TYPE_HPP

#include <ostream>
#include <string>

namespace Fermi::SemanticAnalysis
{
    struct FermiType 
    {
        std::size_t size;
        std::string name;

        friend bool operator==(const FermiType& lhs, const FermiType& rhs) noexcept = default;
    };

    std::ostream& operator<<(std::ostream& os, const FermiType& type);

    inline const FermiType Fermi_int8_t{1, "int8_t"};
    inline const FermiType Fermi_int16_t{2, "int16_t"};
    inline const FermiType Fermi_int32_t{4, "int32_t"};
    inline const FermiType Fermi_int64_t{8, "int64_t"};
    inline const FermiType Fermi_float32_t{4, "float32_t"};
    inline const FermiType Fermi_float64_t{4, "float64_t"};

    bool isIntegerType(const FermiType& type) noexcept;
    bool isFloatingPointType(const FermiType& type) noexcept;
}

#endif