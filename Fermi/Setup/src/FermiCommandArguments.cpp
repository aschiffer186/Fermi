#include <type_traits>

#include "FermiCommandArguments.hpp"

namespace Fermi::Setup
{
    CommandLineOptions& operator&=(CommandLineOptions& lhs, CommandLineOptions rhs)
    {
        lhs = static_cast<CommandLineOptions>(static_cast<CLT>(lhs) & static_cast<CLT>(rhs));
        return lhs;
    }

    CommandLineOptions operator&(CommandLineOptions lhs, CommandLineOptions rhs)
    {
        lhs &= rhs;
        return lhs;
    }

    CommandLineOptions& operator|=(CommandLineOptions& lhs, CommandLineOptions rhs)
    {
        lhs = static_cast<CommandLineOptions>(static_cast<CLT>(lhs) | static_cast<CLT>(rhs));
        return lhs;
    }

    CommandLineOptions operator|(CommandLineOptions lhs, CommandLineOptions rhs)
    {
        lhs |= rhs;
        return lhs;
    }

    CommandLineOptions operator~(CommandLineOptions opts)
    {
        return static_cast<CommandLineOptions>(~static_cast<CLT>(opts));
    }

    bool isShortArg(std::string_view arg)
    {
        return arg.starts_with("-") && !arg.starts_with("--");
    }

    bool isLongArg(std::string_view arg)
    {
        return arg.starts_with("--");
    }

    CommandLineOptions processShortArg(std::string_view arg)
    {
        if (arg == "-h")
        {
            return CommandLineOptions::ShowHelp;
        } 
        else if (arg == "-v")
        {
            return CommandLineOptions::ShowVersion;
        }
        else if (arg == "-st")
        {
            return CommandLineOptions::ShowSyntaxTree;
        }
        throw 1;
    }

    CommandLineOptions processLongArg(std::string_view arg)
    {
        if (arg == "--help")
        {
            return CommandLineOptions::ShowHelp;
        }
        else if (arg == "--version")
        {
            return CommandLineOptions::ShowVersion;
        }
        else if (arg == "--show-tree")
        {
            return CommandLineOptions::ShowSyntaxTree;
        }
        throw 1;
    }

    CommandLineArguments getOpts(int argc, const char** argv)
    {
        if (argc < 2)
        {
            //Show help message
            //Throw
        }

        auto opts = CommandLineOptions::None;
        CommandLineArguments args;

        for(int i = 1; i < argc; ++i)
        {
            std::string_view currArg = argv[i];

            if (isShortArg(currArg))
            {
                opts |= processShortArg(currArg);
            }
            else if(isLongArg(currArg))
            {
                opts |= processLongArg(currArg);
            }
            else 
            {
                if(currArg.ends_with(".frm"))
                {
                    args.sourceFiles.emplace_back(currArg);
                }
            }
        }
        args.options = opts;
        return args;
    }
}