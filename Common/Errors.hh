#ifndef ERRORS_HH
#define ERRORS_HH 

#include <string_view>

namespace Fermi 
{
    void report(std::size_t line, std::string_view where, std::string_view message);
}

#endif