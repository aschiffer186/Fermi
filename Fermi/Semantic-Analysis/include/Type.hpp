/**
 * @file Type.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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

    FermiType commonType(const FermiType& t1, const FermiType& t2);
}

#endif