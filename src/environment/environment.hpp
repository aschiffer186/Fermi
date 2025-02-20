#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <array>
#include <cstdint>
#include <filesystem>
#include <optional>
#include <string>
#include <utility>

namespace fermi {
// General config stuff
#ifndef NDEBUG
constexpr bool in_debug_mode = true;
#else
constexpr bool in_debug_mode = false;
#endif

enum class platform { platform_unix, platform_windows };

constexpr platform fermi_platform = platform::platform_unix;

namespace compiler_options {
enum options : std::uint64_t {
  none = 0,
  display_tokens = 1 << 0,
  display_parse_tree = 1 << 1
};

constexpr options& operator&=(options& lhs, options rhs) noexcept {
  lhs = static_cast<options>(std::to_underlying(lhs) & std::to_underlying(rhs));
  return lhs;
}

constexpr options& operator|=(options& lhs, options rhs) noexcept {
  lhs = static_cast<options>(std::to_underlying(lhs) | std::to_underlying(rhs));
  return lhs;
}

constexpr options operator&(options lhs, options rhs) noexcept {
  lhs = static_cast<options>(std::to_underlying(lhs) & std::to_underlying(rhs));
  return lhs;
}

constexpr options operator|(options lhs, options rhs) noexcept {
  lhs = static_cast<options>(std::to_underlying(lhs) | std::to_underlying(rhs));
  return lhs;
}
} // namespace compiler_options

struct compiler_arguments {
  compiler_options::options options = compiler_options::none;
  std::string file_name;
};

std::optional<compiler_arguments>
process_command_line_arguments(int argc, const char** argv);

std::string read_file(const std::filesystem::path& input_file_path);

enum class console_color { reset, red, yellow };

// template <platform p> void func() {}

template <platform p = fermi_platform>
std::ostream& set_console_color(std::ostream& os, console_color color) {
  constexpr std::array unix_escape_code{"\033[0m", "\033[31m", "\033[33m"};
  if constexpr (p == platform::platform_unix) {
    os << unix_escape_code[static_cast<int>(color)];
  } else {
    func<p>();
  }
  return os;
}
} // namespace fermi

#endif