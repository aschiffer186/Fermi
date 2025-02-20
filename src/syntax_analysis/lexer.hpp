#ifndef LEXER_HPP
#define LEXER_HPP

#include <ostream>
#include <string_view>

#include "parser.hpp"

namespace fermi {
class lexer {
public:
  explicit lexer(std::string_view source);

  parser::symbol_type next_token();

  void reset();
  // token lookahead();
  void set_as_typename(bool enabled);

private:
  void skip_to_token();

private:
  static constexpr std::string_view eof_lexeme{"$"};

private:
  bool lex_as_typename_{false};
  parser::location_type loc_{};
  std::string_view source_;
  std::string_view::const_iterator curr_;
};

std::ostream& operator<<(std::ostream& os, const parser::symbol_type& symbol);
} // namespace fermi

#endif