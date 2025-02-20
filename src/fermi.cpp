#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <optional>

#include "environment.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "source_file.hpp"

int main(int argc, const char** argv) {
  const std::optional<fermi::compiler_arguments> arguments =
      fermi::process_command_line_arguments(argc, argv);
  if (!arguments.has_value()) {
    return EXIT_FAILURE;
  }

  const std::filesystem::path& input_file_path(arguments->file_name);

  if (!std::filesystem::exists(input_file_path)) {
    fermi::set_console_color(std::cerr, fermi::console_color::red);
    std::cerr << "Error";
    fermi::set_console_color(std::cerr, fermi::console_color::reset);
    std::cerr << ": could not open input file " << input_file_path << "\n";
    return EXIT_FAILURE;
  }

  fermi::source_file source_file{input_file_path};

  // fermi::lexer lexer{src_code};

  // if (arguments->options & fermi::compiler_options::display_tokens) {
  //   // Display tokens
  //   lexer.reset();
  // }

  fermi::lexer lexer{source_file.view_source_code()};

  if (arguments->options & fermi::compiler_options::display_tokens) {
    std::cout << "Display tokens from lexer for input file: "
              << source_file.view_filename() << '\n';
    fermi::set_console_color(std::cout, fermi::console_color::yellow);
    std::cout << "Warning";
    fermi::set_console_color(std::cout, fermi::console_color::reset);
    std::cout << ": tokens shown below come from context insensitive lexing\n";
    while (true) {
      const auto tok(lexer.next_token());
      std::cout << tok << "\n";
      if (tok.kind() == fermi::parser::symbol_kind_type::S_YYEOF) {
        break;
      }
    }
    lexer.reset();
  }

  fermi::parser parser{lexer, source_file.view_syntax_tree()};
  // [[maybe_unused]] auto ok = parser.parse();
}