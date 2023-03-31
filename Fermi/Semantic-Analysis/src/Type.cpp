#include "Type.hpp"

namespace Fermi::SemanticAnalysis 
{
    bool isIntegerType(const FermiType& type) noexcept 
    {
        return type == Fermi_int8_t ||
               type == Fermi_int16_t ||
               type == Fermi_int32_t ||
               type == Fermi_int64_t;
    }

    bool isFloatingPointType(const FermiType& type) noexcept 
    {
        return type == Fermi_float32_t || type == Fermi_float64_t;
    }
}