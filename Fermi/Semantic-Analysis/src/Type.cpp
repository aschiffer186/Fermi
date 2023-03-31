/**
 * @file Type.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>

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

    FermiType commonType(const FermiType& t1, const FermiType& t2)
    {
        std::size_t maxSize = std::max(t1.size, t2.size);
        if (isIntegerType(t1) && isIntegerType(t2))
        {
            if (maxSize == 1)
                return Fermi_int8_t;
            else if (maxSize == 2)
                return Fermi_int16_t; 
            else if (maxSize == 4)
                return Fermi_int32_t; 
            else
                return Fermi_int64_t;
        }
        else  
        {
            if (maxSize == 4)
                return Fermi_float32_t; 
            else 
                return Fermi_float64_t;
        }
    }
}