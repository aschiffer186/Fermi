#ifndef FERMI_COMMAND_ARGUMENTS_HPP
#define FERMI_COMMAND_ARGUMENTS_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace Fermi::Setup
{
    //fermi [source file] [args] 
    //fermi txt.frm -h/--help -v/--version -st/--show-tree
    enum class CommandLineOptions : std::uint16_t
    {
        None = 0,
        ShowHelp = 1,
        ShowVersion = 1 << 1,
        ShowSyntaxTree = 1 << 2
    };

    CommandLineOptions& operator&=(CommandLineOptions& lhs, CommandLineOptions rhs);
    CommandLineOptions operator&(CommandLineOptions lhs, CommandLineOptions rhs);

    CommandLineOptions& operator|=(CommandLineOptions& lhs, CommandLineOptions rhs);
    CommandLineOptions operator|(CommandLineOptions lhs, CommandLineOptions rhs);

    CommandLineOptions operator~(CommandLineOptions opts);

    using CLT = std::underlying_type_t<CommandLineOptions>;

    struct CommandLineArguments
    {
        CommandLineOptions options;
        std::string executableName;
        std::vector<std::string> sourceFiles;
    };

    CommandLineArguments getOpts(int argc, const char** argv);
}

#endif