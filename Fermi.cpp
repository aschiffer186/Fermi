#include <algorithm>
#include <iostream>
#include <ranges>

#include "Common/Errors.hh"
#include "Scanner.hh"

void run(std::string text)
{
    Fermi::Lexer lexer{std::move(text)};
    auto tokens = lexer.scanTokens();

    if (std::ranges::any_of(tokens, [](const auto& tok) { return tok.type == Fermi::TokenType::Error; }))
    {
        auto it = std::ranges::filter_view(tokens, [](const auto& tok){ return tok.type == Fermi::TokenType::Error; });
        for(const auto& tok : it)
        {
            std::string msg = "Unexpected token: " + tok.lexeme;
            Fermi::report(tok.line, "", msg);
        }
        return;
    }   

    for(const auto& token : tokens)
    {
        std::cout << token << "\n";
    }
}

void runPrompt()
{
    std::string line;
    for(;;)
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "quit") { break; }
        run(std::move(line));
    }
}

int main(int argc, char** argv)
{
    runPrompt();
    return 0;
}