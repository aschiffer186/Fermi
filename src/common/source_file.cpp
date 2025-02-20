#include "source_file.hpp"
#include "environment.hpp"

#include <cassert>
#include <filesystem>
#include <string_view>

fermi::source_file::source_file(std::filesystem::path file_path)
    : file_path_(std::move(file_path)) {
  assert(std::filesystem::exists(file_path_) &&
         "Internal error: couldn't open path");
  source_code_ = read_file(file_path_);
}

std::string_view fermi::source_file::view_source_code() const noexcept {
  return source_code_;
}

auto fermi::source_file::view_syntax_tree() noexcept
    -> std::vector<syntax_nodes::syntax_node>& {
  return syntax_tree_;
}

std::string_view fermi::source_file::view_filename() const noexcept {
  return file_path_.native();
}

void fermi::source_file::add_syntax_error(std::string error) {
  syntax_errors_.push_back(std::move(error));
}

bool fermi::source_file::parse_ok() const noexcept {
  return syntax_errors_.empty();
}