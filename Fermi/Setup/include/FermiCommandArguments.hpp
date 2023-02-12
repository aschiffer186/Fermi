#ifndef FERMI_COMMAND_ARGUMENTS_HPP
#define FERMI_COMMAND_ARGUMENTS_HPP

#include <string>
#include <vector>

namespace Fermi::Setup
{
    enum class CommandLineOptions
    {
        ShowHelp,
        ShowVersion,
        ShowSyntaxTree
    };

    CommandLineOptions& operator&=(CommandLineOptions& lhs, CommandLineOptions rhs);
    CommandLineOptions operator&(CommandLineOptions lhs, CommandLineOptions rhs);

    CommandLineOptions& operator|=(CommandLineOptions& lhs, CommandLineOptions rhs);
    CommandLineOptions operator|(CommandLineOptions lhs, CommandLineOptions rhs);

    struct CommandLineArguments
    {
        CommandLineOptions options;
        std::string executableName;
        std::vector<std::string> sourceFiles;
    };

    CommandLineArguments getOpts(int argc, const char* argv);
}

#endif