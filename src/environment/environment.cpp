#include "environment.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>

std::optional<fermi::compiler_arguments>
fermi::process_command_line_arguments(int argc, const char** argv) {
  if (argc < 2) {
    std::cerr << "Must specify at least file name";
    return std::nullopt;
  }

  compiler_arguments arguments;

  for (int i = 1; i < argc; ++i) {
    const std::string_view arg(argv[i]);
    if (arg == "--tokens" || arg == "-T") {
      arguments.options |= compiler_options::display_tokens;
    } else if (arg == "--parse-tree" || arg == "-P") {
      arguments.options |= compiler_options::display_parse_tree;
    } else {
      arguments.file_name = arg;
    }
  }

  return arguments;
}

std::string fermi::read_file(const std::filesystem::path& input_file_path) {
  assert(std::filesystem::exists(input_file_path) &&
         "Internal error: couldn't open input_file_path");

  std::ifstream fin(input_file_path);
  assert(fin.is_open() && "Internal error: could not open input file stream");

  std::ostringstream ss;
  ss << fin.rdbuf();
  return ss.str();
}