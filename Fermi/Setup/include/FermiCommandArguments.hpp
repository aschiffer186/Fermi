#ifndef FERMI_COMMAND_ARGUMENTS_HPP
#define FERMI_COMMAND_ARGUMENTS_HPP

#include <string>
#include <vector>

namespace Fermi::Setup
{
    //fermi [source file] [args] 
    //fermi txt.frm -h/--help -v/--version -st/--show-tree
    enum class CommandLineOptions
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

    struct CommandLineArguments
    {
        CommandLineOptions options;
        std::string executableName;
        std::vector<std::string> sourceFiles;
    };

    CommandLineArguments getOpts(int argc, const char** argv);
}

#endif