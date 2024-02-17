#include "Errors.hh"

#include <iostream>

#include "ConsoleColors.hh"

namespace Fermi 
{
    void report(std::size_t line, std::string_view where, std::string_view message)
    {
        std::cerr << "[line: " << line << "] " << Red << "Error " << Black << where << ": " << message << "\n";
    }
}