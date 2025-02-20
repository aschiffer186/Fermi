#include <filesystem>
#include <string>
#include <string_view>

#include "syntax_node.hpp"

namespace fermi {
class source_file {
public:
  explicit source_file(std::filesystem::path file_path);

  std::string_view view_source_code() const noexcept;

  std::vector<syntax_nodes::syntax_node>& view_syntax_tree() noexcept;

  std::string_view view_filename() const noexcept;

  void add_syntax_error(std::string error);

  bool parse_ok() const noexcept;

private:
  std::vector<syntax_nodes::syntax_node> syntax_tree_;
  std::vector<std::string> syntax_errors_;
  std::string source_code_;
  std::filesystem::path file_path_;
};
} // namespace fermi