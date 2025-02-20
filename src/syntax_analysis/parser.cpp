// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 27 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"

    #include "lexer.hpp"
#line 34 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"

    #define yylex lexer_.next_token

    using namespace fermi::syntax_nodes;

#line 55 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
namespace fermi {
#line 148 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"

  /// Build a parser object.
  parser::parser (fermi::lexer& lexer__yyarg, std::vector<syntax_nodes::syntax_node>& syntax_tree__yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      lexer_ (lexer__yyarg),
      syntax_tree_ (syntax_tree__yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_93_variable_declaration: // variable-declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_95_simple_type: // simple-type
      case symbol_kind::S_96_function_declaration: // function-declaration
      case symbol_kind::S_99_function_parameter: // function-parameter
      case symbol_kind::S_101_return_type_opt: // return-type-opt
      case symbol_kind::S_102_return_type: // return-type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_105_assignment_statement: // assignment-statement
      case symbol_kind::S_106_compound_statement: // compound-statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_108_primary_exression: // primary-exression
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_110_binary_expression: // binary-expression
      case symbol_kind::S_111_unary_expression: // unary-expression
      case symbol_kind::S_112_absolute_value_expression: // absolute-value-expression
      case symbol_kind::S_113_function_call_expression: // function-call-expression
      case symbol_kind::S_114_array_index_expression: // array-index-expression
        value.YY_MOVE_OR_COPY< std::size_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_CHARACTER: // CHARACTER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
        value.YY_MOVE_OR_COPY< std::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_97_function_parameter_list_opt: // function-parameter-list-opt
      case symbol_kind::S_98_function_parameter_list: // function-parameter-list
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_115_expression_list_opt: // expression-list-opt
      case symbol_kind::S_116_expression_list: // expression-list
        value.YY_MOVE_OR_COPY< std::vector<std::size_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mode: // mode
        value.YY_MOVE_OR_COPY< syntax_nodes::function_parameter_attributes::attribute > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_93_variable_declaration: // variable-declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_95_simple_type: // simple-type
      case symbol_kind::S_96_function_declaration: // function-declaration
      case symbol_kind::S_99_function_parameter: // function-parameter
      case symbol_kind::S_101_return_type_opt: // return-type-opt
      case symbol_kind::S_102_return_type: // return-type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_105_assignment_statement: // assignment-statement
      case symbol_kind::S_106_compound_statement: // compound-statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_108_primary_exression: // primary-exression
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_110_binary_expression: // binary-expression
      case symbol_kind::S_111_unary_expression: // unary-expression
      case symbol_kind::S_112_absolute_value_expression: // absolute-value-expression
      case symbol_kind::S_113_function_call_expression: // function-call-expression
      case symbol_kind::S_114_array_index_expression: // array-index-expression
        value.move< std::size_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_CHARACTER: // CHARACTER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
        value.move< std::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_97_function_parameter_list_opt: // function-parameter-list-opt
      case symbol_kind::S_98_function_parameter_list: // function-parameter-list
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_115_expression_list_opt: // expression-list-opt
      case symbol_kind::S_116_expression_list: // expression-list
        value.move< std::vector<std::size_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mode: // mode
        value.move< syntax_nodes::function_parameter_attributes::attribute > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_93_variable_declaration: // variable-declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_95_simple_type: // simple-type
      case symbol_kind::S_96_function_declaration: // function-declaration
      case symbol_kind::S_99_function_parameter: // function-parameter
      case symbol_kind::S_101_return_type_opt: // return-type-opt
      case symbol_kind::S_102_return_type: // return-type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_105_assignment_statement: // assignment-statement
      case symbol_kind::S_106_compound_statement: // compound-statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_108_primary_exression: // primary-exression
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_110_binary_expression: // binary-expression
      case symbol_kind::S_111_unary_expression: // unary-expression
      case symbol_kind::S_112_absolute_value_expression: // absolute-value-expression
      case symbol_kind::S_113_function_call_expression: // function-call-expression
      case symbol_kind::S_114_array_index_expression: // array-index-expression
        value.copy< std::size_t > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_CHARACTER: // CHARACTER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
        value.copy< std::string_view > (that.value);
        break;

      case symbol_kind::S_97_function_parameter_list_opt: // function-parameter-list-opt
      case symbol_kind::S_98_function_parameter_list: // function-parameter-list
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_115_expression_list_opt: // expression-list-opt
      case symbol_kind::S_116_expression_list: // expression-list
        value.copy< std::vector<std::size_t> > (that.value);
        break;

      case symbol_kind::S_mode: // mode
        value.copy< syntax_nodes::function_parameter_attributes::attribute > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_93_variable_declaration: // variable-declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_95_simple_type: // simple-type
      case symbol_kind::S_96_function_declaration: // function-declaration
      case symbol_kind::S_99_function_parameter: // function-parameter
      case symbol_kind::S_101_return_type_opt: // return-type-opt
      case symbol_kind::S_102_return_type: // return-type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_105_assignment_statement: // assignment-statement
      case symbol_kind::S_106_compound_statement: // compound-statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_108_primary_exression: // primary-exression
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_110_binary_expression: // binary-expression
      case symbol_kind::S_111_unary_expression: // unary-expression
      case symbol_kind::S_112_absolute_value_expression: // absolute-value-expression
      case symbol_kind::S_113_function_call_expression: // function-call-expression
      case symbol_kind::S_114_array_index_expression: // array-index-expression
        value.move< std::size_t > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_CHARACTER: // CHARACTER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
        value.move< std::string_view > (that.value);
        break;

      case symbol_kind::S_97_function_parameter_list_opt: // function-parameter-list-opt
      case symbol_kind::S_98_function_parameter_list: // function-parameter-list
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_115_expression_list_opt: // expression-list-opt
      case symbol_kind::S_116_expression_list: // expression-list
        value.move< std::vector<std::size_t> > (that.value);
        break;

      case symbol_kind::S_mode: // mode
        value.move< syntax_nodes::function_parameter_attributes::attribute > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_93_variable_declaration: // variable-declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_95_simple_type: // simple-type
      case symbol_kind::S_96_function_declaration: // function-declaration
      case symbol_kind::S_99_function_parameter: // function-parameter
      case symbol_kind::S_101_return_type_opt: // return-type-opt
      case symbol_kind::S_102_return_type: // return-type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_105_assignment_statement: // assignment-statement
      case symbol_kind::S_106_compound_statement: // compound-statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_108_primary_exression: // primary-exression
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_110_binary_expression: // binary-expression
      case symbol_kind::S_111_unary_expression: // unary-expression
      case symbol_kind::S_112_absolute_value_expression: // absolute-value-expression
      case symbol_kind::S_113_function_call_expression: // function-call-expression
      case symbol_kind::S_114_array_index_expression: // array-index-expression
        yylhs.value.emplace< std::size_t > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_COMPLEX: // COMPLEX
      case symbol_kind::S_CHARACTER: // CHARACTER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
        yylhs.value.emplace< std::string_view > ();
        break;

      case symbol_kind::S_97_function_parameter_list_opt: // function-parameter-list-opt
      case symbol_kind::S_98_function_parameter_list: // function-parameter-list
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_115_expression_list_opt: // expression-list-opt
      case symbol_kind::S_116_expression_list: // expression-list
        yylhs.value.emplace< std::vector<std::size_t> > ();
        break;

      case symbol_kind::S_mode: // mode
        yylhs.value.emplace< syntax_nodes::function_parameter_attributes::attribute > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 5: // declaration: variable-declaration
#line 128 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                           { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > ();}
#line 774 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 6: // declaration: function-declaration
#line 129 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                           { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > (); }
#line 780 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 7: // variable-declaration: "let" IDENTIFIER ";"
#line 132 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                         {
        syntax_tree_.push_back(variable_declaration_node{.name = yystack_[1].value.as < std::string_view > (), .type = missing_expression, .initializer = missing_expression});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 789 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 8: // variable-declaration: "let" IDENTIFIER ":" type ";"
#line 136 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                    {
        variable_declaration_node node {
            .name = yystack_[3].value.as < std::string_view > (), 
            .type = yystack_[1].value.as < std::size_t > (),
            .initializer = missing_expression
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 803 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 9: // variable-declaration: "let" IDENTIFIER "=" expression ";"
#line 145 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                          {
        variable_declaration_node node {
            .name = yystack_[3].value.as < std::string_view > (), 
            .type = missing_expression,
            .initializer = yystack_[1].value.as < std::size_t > ()
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 817 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 10: // variable-declaration: "let" IDENTIFIER ":" type "=" expression ";"
#line 154 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                   {
         variable_declaration_node node {
            .name = yystack_[5].value.as < std::string_view > (), 
            .type = yystack_[3].value.as < std::size_t > (),
            .initializer = yystack_[1].value.as < std::size_t > ()
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 831 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 11: // type: simple-type
#line 165 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                  {yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > ();}
#line 837 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 12: // type: type "&"
#line 166 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                               {
        type_node type {
            .inner_type = yystack_[1].value.as < std::size_t > (), 
            .attribute = type_attributes::reference
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 850 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 13: // type: type "*"
#line 174 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                             {
        type_node type {
            .inner_type = yystack_[1].value.as < std::size_t > (), 
            .attribute = type_attributes::pointer
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 863 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 14: // type: type "[" "]"
#line 182 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                               {
        type_node type {
            .inner_type = yystack_[2].value.as < std::size_t > (), 
            .attribute = type_attributes::array
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 876 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 15: // type: type "*" "mutable"
#line 190 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                               {
        type_node type {
            .inner_type = yystack_[2].value.as < std::size_t > (), 
            .attribute = (type_attributes::pointer | type_attributes::mutable_type)
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 889 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 16: // type: type "[" "]" "mutable"
#line 198 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                 {
        type_node type {
            .inner_type = yystack_[3].value.as < std::size_t > (), 
            .attribute = (type_attributes::array | type_attributes::mutable_type)
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 902 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 17: // simple-type: TYPE_NAME
#line 208 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                {
        literal_expression_node inner_type{
            .type = literal_type::identifier, 
            .literal = yystack_[0].value.as < std::string_view > ()
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 919 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 18: // simple-type: TYPE_NAME "mutable"
#line 220 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                          {
        literal_expression_node inner_type{
            .type = literal_type::identifier, 
            .literal = yystack_[1].value.as < std::string_view > ()
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1,
            .attribute = type_attributes::mutable_type
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 937 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 19: // simple-type: "typeof" "(" expression ")"
#line 233 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                  {
        unary_expression_node inner_type {
            .op = unary_operator::typeof_operator, 
            .child = yystack_[1].value.as < std::size_t > ()
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 954 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 20: // simple-type: "typeof" "(" expression ")" "mutable"
#line 245 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                             {
        unary_expression_node inner_type {
            .op = unary_operator::typeof_operator, 
            .child = yystack_[2].value.as < std::size_t > ()
        };
         syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1,
            .attribute = type_attributes::mutable_type
        };
        syntax_tree_.push_back(type);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 972 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 21: // function-declaration: "let" IDENTIFIER "(" function-parameter-list-opt ")" return-type-opt "=" compound-statement
#line 260 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                                                                {
        function_declaration_node node {
            .name = yystack_[6].value.as < std::string_view > (), 
            .parameters = std::move(yystack_[4].value.as < std::vector<std::size_t> > ()), 
            .return_type = yystack_[2].value.as < std::size_t > (), 
            .definition = yystack_[0].value.as < std::size_t > ()
        };
        syntax_tree_.push_back(std::move(node));
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 987 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 22: // function-parameter-list-opt: function-parameter-list
#line 272 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                              {yylhs.value.as < std::vector<std::size_t> > () = std::move(yystack_[0].value.as < std::vector<std::size_t> > ()); }
#line 993 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 23: // function-parameter-list-opt: %empty
#line 273 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             { yylhs.value.as < std::vector<std::size_t> > () = {}; }
#line 999 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 24: // function-parameter-list: function-parameter
#line 276 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                         {yylhs.value.as < std::vector<std::size_t> > () = std::vector{yystack_[0].value.as < std::size_t > ()}; }
#line 1005 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 25: // function-parameter-list: function-parameter-list "," function-parameter
#line 277 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                     { yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ()); }
#line 1011 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 26: // function-parameter: IDENTIFIER
#line 280 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                 {
        function_parameter_node node {
            .name = yystack_[0].value.as < std::string_view > (), 
            .type = missing_expression, 
            .mode = function_parameter_attributes::in
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
      }
#line 1025 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 27: // function-parameter: IDENTIFIER ":" mode
#line 289 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                          {
         function_parameter_node node {
            .name = yystack_[2].value.as < std::string_view > (), 
            .type = missing_expression, 
            .mode = yystack_[0].value.as < syntax_nodes::function_parameter_attributes::attribute > ()
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1039 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 28: // function-parameter: IDENTIFIER ":" type
#line 298 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                          {
         function_parameter_node node {
            .name = yystack_[2].value.as < std::string_view > (), 
            .type = yystack_[0].value.as < std::size_t > (),
            .mode = function_parameter_attributes::in
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1053 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 29: // function-parameter: IDENTIFIER ":" mode type
#line 307 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                               {
         function_parameter_node node {
            .name = yystack_[3].value.as < std::string_view > (), 
            .type = yystack_[0].value.as < std::size_t > (),
            .mode = yystack_[1].value.as < syntax_nodes::function_parameter_attributes::attribute > ()
        };
        syntax_tree_.push_back(node);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1067 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 30: // mode: "in"
#line 318 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
           {yylhs.value.as < syntax_nodes::function_parameter_attributes::attribute > () = function_parameter_attributes::in;}
#line 1073 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 31: // mode: "out"
#line 319 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {yylhs.value.as < syntax_nodes::function_parameter_attributes::attribute > () = function_parameter_attributes::out;}
#line 1079 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 32: // mode: "in" "out"
#line 320 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                 { yylhs.value.as < syntax_nodes::function_parameter_attributes::attribute > () = function_parameter_attributes::in | function_parameter_attributes::out; }
#line 1085 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 33: // mode: "move"
#line 321 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {yylhs.value.as < syntax_nodes::function_parameter_attributes::attribute > () = function_parameter_attributes::move; }
#line 1091 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 34: // return-type-opt: return-type
#line 324 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                  { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > (); }
#line 1097 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 35: // return-type-opt: %empty
#line 325 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             { yylhs.value.as < std::size_t > () = missing_expression; }
#line 1103 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 36: // return-type: "->" type
#line 327 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                        {
    yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > ();
}
#line 1111 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 37: // statements: statements statement
#line 332 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                           { yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ()); }
#line 1117 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 38: // statements: %empty
#line 333 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {yylhs.value.as < std::vector<std::size_t> > () = {}; }
#line 1123 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 39: // statement: expression ";"
#line 336 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                     { yylhs.value.as < std::size_t > () = yystack_[1].value.as < std::size_t > (); }
#line 1129 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 40: // statement: assignment-statement
#line 337 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                           { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > (); }
#line 1135 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 41: // statement: compound-statement
#line 338 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                         { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > (); }
#line 1141 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 42: // statement: declaration
#line 339 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                  { yylhs.value.as < std::size_t > () = yystack_[0].value.as < std::size_t > () ; }
#line 1147 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 43: // assignment-statement: expression "=" expression ";"
#line 342 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                    {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::copy, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1156 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 44: // assignment-statement: expression "<-" expression ";"
#line 346 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::move, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1165 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 45: // assignment-statement: expression "+=" expression ";"
#line 350 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::add, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1174 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 46: // assignment-statement: expression "-=" expression ";"
#line 354 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::subtract, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1183 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 47: // assignment-statement: expression "*=" expression ";"
#line 358 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::multiply, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1192 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 48: // assignment-statement: expression "%=" expression ";"
#line 362 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::modulo, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1201 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 49: // assignment-statement: expression "/=" expression ";"
#line 366 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::divide, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1210 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 50: // assignment-statement: expression "//=" expression ";"
#line 370 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                      {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::int_divide, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1219 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 51: // assignment-statement: expression "^=" expression ";"
#line 374 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     {
        syntax_tree_.push_back(assignment_statement_node{.lhs=yystack_[3].value.as < std::size_t > (), .type=assignment_type::exponent, .rhs=yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1228 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 52: // compound-statement: "{" statements "}"
#line 380 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                       { 
        syntax_tree_.push_back(compound_statement_node{.statements = std::move(yystack_[1].value.as < std::vector<std::size_t> > ())});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1237 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 53: // expression: primary-exression
#line 387 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                        {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1243 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 54: // expression: binary-expression
#line 388 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                        {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1249 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 55: // expression: unary-expression
#line 389 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                       {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1255 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 56: // expression: absolute-value-expression
#line 390 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1261 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 57: // expression: function-call-expression
#line 391 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                               {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1267 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 58: // expression: array-index-expression
#line 392 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                             {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1273 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 59: // primary-exression: literal
#line 395 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
              {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1279 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 60: // primary-exression: "(" expression ")"
#line 396 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                         {yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;}
#line 1285 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 61: // literal: CHARACTER
#line 399 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
               {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::character, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1294 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 62: // literal: COMPLEX
#line 403 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::complex, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1303 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 63: // literal: FLOAT
#line 407 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
           {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::floating_point, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1312 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 64: // literal: IDENTIFIER
#line 411 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::identifier, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1321 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 65: // literal: INTEGER
#line 415 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::integer, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1330 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 66: // literal: STRING
#line 419 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::string, .literal = yystack_[0].value.as < std::string_view > ()}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1339 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 67: // literal: "true"
#line 423 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
            {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::boolean, .literal = "true"}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1348 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 68: // literal: "false"
#line 427 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::boolean, .literal = "false"}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1357 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 69: // literal: "this"
#line 431 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
            {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::this_literal, .literal = "this"}); 
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1366 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 70: // binary-expression: expression "or" expression
#line 437 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::binary_or, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1375 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 71: // binary-expression: expression "and" expression
#line 441 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                  {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::binary_and, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1384 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 72: // binary-expression: expression "==" expression
#line 445 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::equals, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1393 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 73: // binary-expression: expression "!=" expression
#line 449 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::not_equals, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1402 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 74: // binary-expression: expression "<" expression
#line 453 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::less, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1411 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 75: // binary-expression: expression "<=" expression
#line 457 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::less_equal, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1420 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 76: // binary-expression: expression ">" expression
#line 461 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::greater, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1429 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 77: // binary-expression: expression ">=" expression
#line 465 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::greater_equal, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1438 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 78: // binary-expression: expression "<=>" expression
#line 469 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                  {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::spaceship, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1447 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 79: // binary-expression: expression "+" expression
#line 473 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::add, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1456 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 80: // binary-expression: expression "-" expression
#line 477 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::subtract, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1465 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 81: // binary-expression: expression "*" expression
#line 481 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::multiply, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1474 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 82: // binary-expression: expression "/" expression
#line 485 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::divide, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1483 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 83: // binary-expression: expression "//" expression
#line 489 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                 {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::int_divide, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1492 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 84: // binary-expression: expression "%" expression
#line 493 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::modulo, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1501 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 85: // binary-expression: expression "^" expression
#line 497 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::exponent, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1510 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 86: // binary-expression: expression "." expression
#line 501 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                {
        syntax_tree_.push_back(binary_expression_node{.left_child = yystack_[2].value.as < std::size_t > (), .op = binary_operator::member, .right_child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1519 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 87: // unary-expression: expression "!"
#line 507 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                     {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::factorial, .child = yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1528 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 88: // unary-expression: "not" expression
#line 511 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                       {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::unary_not, .child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1537 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 89: // unary-expression: "-" expression
#line 515 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                     {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::negate, .child = yystack_[0].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1546 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 90: // absolute-value-expression: "|" expression "|"
#line 521 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                       {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::absolute_value, .child = yystack_[1].value.as < std::size_t > ()});
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1555 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 91: // function-call-expression: IDENTIFIER "(" expression-list-opt ")"
#line 527 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                             {
        literal_expression_node function_expression{.type = literal_type::identifier, .literal = yystack_[3].value.as < std::string_view > ()};
        syntax_tree_.push_back(function_expression);
        function_call_expression_node function_call{.function_expression = syntax_tree_.size() - 1, .parameter_keys = std::move(yystack_[1].value.as < std::vector<std::size_t> > ())};
        syntax_tree_.push_back(std::move(function_call));
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
      }
#line 1567 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 92: // function-call-expression: function-call-expression "(" expression-list-opt ")"
#line 534 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                           {
        function_call_expression_node function_call{.function_expression = yystack_[3].value.as < std::size_t > (), .parameter_keys = std::move(yystack_[1].value.as < std::vector<std::size_t> > ())};
        syntax_tree_.push_back(std::move(function_call));
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1577 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 93: // array-index-expression: IDENTIFIER "[" expression "]"
#line 541 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                    {
        literal_expression_node function_expression{.type = literal_type::identifier, .literal = yystack_[3].value.as < std::string_view > ()};
        syntax_tree_.push_back(function_expression);
        array_index_expression_node array_index{.array_expression = syntax_tree_.size() - 1, .index_expression = yystack_[1].value.as < std::size_t > ()};
        syntax_tree_.push_back(array_index);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1589 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 94: // array-index-expression: function-call-expression "[" expression "]"
#line 548 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                  {
        array_index_expression_node array_index{.array_expression = yystack_[3].value.as < std::size_t > (), .index_expression = yystack_[1].value.as < std::size_t > ()};
        syntax_tree_.push_back(array_index);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1599 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 95: // array-index-expression: array-index-expression "[" expression "]"
#line 553 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                                {
        array_index_expression_node array_index{.array_expression = yystack_[3].value.as < std::size_t > (), .index_expression = yystack_[1].value.as < std::size_t > ()};
        syntax_tree_.push_back(array_index);
        yylhs.value.as < std::size_t > () = syntax_tree_.size() - 1;
    }
#line 1609 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 96: // expression-list-opt: expression-list
#line 565 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                      { yylhs.value.as < std::vector<std::size_t> > () = std::move(yystack_[0].value.as < std::vector<std::size_t> > ());}
#line 1615 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 97: // expression-list-opt: %empty
#line 566 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
             { yylhs.value.as < std::vector<std::size_t> > () = {}; }
#line 1621 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 98: // expression-list: expression
#line 569 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                 { yylhs.value.as < std::vector<std::size_t> > () = std::vector{yystack_[0].value.as < std::size_t > ()}; }
#line 1627 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;

  case 99: // expression-list: expression-list "," expression
#line 570 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
                                     { yylhs.value.as < std::vector<std::size_t> > ().push_back(yystack_[0].value.as < std::size_t > ()); }
#line 1633 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"
    break;


#line 1637 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "INTEGER", "FLOAT", "COMPLEX",
  "CHARACTER", "STRING", "IDENTIFIER", "TYPE_NAME", "as", "&", "and",
  "bool", "compeval", "define", "else", "elsif", "export", "false", "for",
  "if", "import", "in", "int", "let", "match", "module", "move", "mutable",
  "new", "not", "operator", "or", "out", "public", "pure", "range",
  "requires", "return", "static", "struct", "this", "true", "type",
  "typeof", "typeset", "where", "while", "with", ":", "::", "{", "[", "(",
  "}", "]", ")", ";", "=", "!", "!=", "^", "^=", ",", ".", "==", ">", ">=",
  "<-", "<", "<=", "->", "-", "-=", "--", "%", "%=", "|", "+", "+=", "++",
  "/", "/=", "//", "//=", "<=>", "*", "*=", "$accept", "start",
  "declarations", "declaration", "variable-declaration", "type",
  "simple-type", "function-declaration", "function-parameter-list-opt",
  "function-parameter-list", "function-parameter", "mode",
  "return-type-opt", "return-type", "statements", "statement",
  "assignment-statement", "compound-statement", "expression",
  "primary-exression", "literal", "binary-expression", "unary-expression",
  "absolute-value-expression", "function-call-expression",
  "array-index-expression", "expression-list-opt", "expression-list", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -56;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -56,     3,   -14,   -56,     9,   -56,   -56,   -56,   -46,    -8,
      19,   -56,   752,   -11,   -24,    55,   -56,   -18,   -21,   -31,
     -56,   -56,   -56,   -56,   -56,   -56,   -39,   -56,   752,   -56,
     -56,   752,   752,   752,    87,   -56,   -56,   -56,   -56,   -56,
     -28,   -15,   -56,   752,   -56,   -17,   -56,   752,    15,     0,
     -23,    19,   752,   752,   -36,   118,    41,   149,   752,   752,
     -56,   -56,   752,   752,   752,   752,   752,   752,   752,   752,
     752,   752,   752,   752,   752,   752,   752,   752,   752,   752,
     180,    45,   211,   -56,    51,   -56,   -56,    -5,    -8,    -8,
      29,   -56,   -56,   253,   630,    34,    36,   -56,   -56,   766,
     660,   789,   -55,   -56,   789,   801,   801,   801,   801,    41,
     -55,    41,   -55,   -55,   223,   -55,   289,    47,   330,    73,
     -56,   -56,   -56,    -5,    -5,    53,   -56,   -56,   752,   -56,
     -56,   -56,   -56,   -56,   -56,   630,   745,   -56,   -56,   -56,
     -56,   -56,    10,   -56,   752,   752,   752,   752,   752,   752,
     752,   752,   752,   360,   390,   420,   450,   480,   510,   540,
     570,   600,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     3,     5,     6,     0,     0,
      23,     7,     0,    17,     0,     0,    11,    26,     0,    22,
      24,    65,    63,    62,    61,    66,    64,    68,     0,    69,
      67,     0,     0,     0,     0,    53,    59,    54,    55,    56,
      57,    58,    18,     0,    12,     0,     8,     0,    13,     0,
      35,     0,     0,    97,    88,     0,    89,     0,     0,     0,
       9,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,    14,     0,    15,    30,    33,    31,    28,    27,     0,
       0,    34,    25,     0,    98,     0,    96,    60,    90,    71,
      70,    73,    85,    86,    72,    76,    77,    74,    75,    80,
      84,    79,    82,    83,    78,    81,     0,     0,     0,    19,
      16,    10,    32,    29,    36,     0,    93,    91,     0,    94,
      92,    95,    20,    38,    21,    99,     0,    52,    42,    37,
      40,    41,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    51,    44,    46,    48,    45,    49,    50,
      47
  };

  const signed char
  parser::yypgoto_[] =
  {
     -56,   -56,   -56,   -29,   -56,   -47,   -56,   -56,   -56,   -56,
      58,   -56,   -56,   -56,   -56,   -56,   -56,   -26,   -12,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,    33,   -56
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     5,     6,    15,    16,     7,    18,    19,
      20,    88,    90,    91,   136,   139,   140,   134,    94,    35,
      36,    37,    38,    39,    40,    41,    95,    96
  };

  const unsigned char
  parser::yytable_[] =
  {
      34,    13,    87,     3,     9,    61,    44,    63,    10,    13,
      64,     4,    11,    12,    52,    53,    54,     8,    42,    55,
      56,    57,    58,    84,    61,    77,    78,    17,    85,    64,
      43,    80,    49,    51,    86,    82,    50,    14,    79,    81,
      93,   123,   124,    59,    83,    14,    99,   100,    45,    89,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    44,   118,   143,   144,
      61,    62,    63,   145,   120,    64,    65,    66,    67,   146,
      68,    69,    48,    70,   147,   122,    71,   148,   125,    72,
     149,   127,    73,   150,    74,   151,    75,    76,   152,    58,
     128,    61,   132,    63,   130,   133,    64,   138,    45,    92,
     141,   117,     0,    46,    47,     0,   135,    71,     0,     0,
      59,     0,     0,    73,   142,    74,     0,     0,    76,     0,
      58,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,    48,     0,     0,    60,     0,    61,    62,    63,
       0,    59,    64,    65,    66,    67,     0,    68,    69,     0,
      70,    58,     0,    71,     0,     0,    72,     0,     0,    73,
       0,    74,     0,    75,    76,    97,     0,     0,    61,    62,
      63,     0,    59,    64,    65,    66,    67,     0,    68,    69,
       0,    70,    58,     0,    71,     0,     0,    72,     0,     0,
      73,     0,    74,     0,    75,    76,     0,     0,     0,    61,
      62,    63,     0,    59,    64,    65,    66,    67,     0,    68,
      69,     0,    70,    58,     0,    71,     0,    98,    72,     0,
       0,    73,     0,    74,     0,    75,    76,   119,     0,     0,
      61,    62,    63,     0,    59,    64,    65,    66,    67,     0,
      68,    69,     0,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,    58,    75,    76,     0,   121,
       0,    61,    62,    63,     0,     0,    64,    65,    66,    67,
       0,    68,    69,    61,    70,    63,    59,    71,    64,     0,
      72,     0,     0,    73,     0,    74,    70,    75,    76,    71,
       0,    58,    72,     0,     0,    73,     0,    74,     0,   126,
      76,     0,     0,    61,    62,    63,     0,     0,    64,    65,
      66,    67,    59,    68,    69,     0,    70,     0,     0,    71,
       0,     0,    72,     0,     0,    73,     0,    74,     0,    75,
      76,     0,    58,     0,     0,   129,     0,     0,     0,    61,
      62,    63,     0,     0,    64,    65,    66,    67,     0,    68,
      69,     0,    70,    59,     0,    71,     0,     0,    72,     0,
       0,    73,    58,    74,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   162,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   163,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   164,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   165,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   166,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   167,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   168,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   169,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,   170,     0,
      61,    62,    63,    59,     0,    64,    65,    66,    67,     0,
      68,    69,    58,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,     0,     0,
      61,    62,    63,     0,     0,    64,    65,    66,    67,     0,
      68,    69,     0,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,     0,     0,
      61,    62,    63,     0,     0,    64,    65,    66,    67,     0,
      68,    69,     0,    70,     0,     0,    71,     0,     0,    72,
       0,     0,    73,     0,    74,     0,    75,    76,    21,    22,
      23,    24,    25,    26,     0,    21,    22,    23,    24,    25,
      26,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       4,    27,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,    29,    30,     0,
       0,     0,     0,     0,    29,    30,     0,   133,     0,    31,
     137,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,     0,    32,    61,    62,    63,     0,
      33,    64,    65,    66,    67,     0,    68,    69,     0,    70,
       0,     0,    71,     0,     0,    72,     0,     0,    73,    61,
      74,    63,    75,    76,    64,     0,    66,    67,     0,    68,
      69,    61,    70,    63,     0,    71,    64,     0,    72,     0,
       0,    73,     0,    74,    70,    75,    76,    71,     0,     0,
      72,     0,     0,    73,     0,    74,     0,    75,    76
  };

  const short
  parser::yycheck_[] =
  {
      12,     9,    49,     0,    50,    60,    11,    62,    54,     9,
      65,    25,    58,    59,    53,    54,    28,     8,    29,    31,
      32,    33,    12,    23,    60,    53,    54,     8,    28,    65,
      54,    43,    50,    64,    34,    47,    57,    45,    53,    56,
      52,    88,    89,    33,    29,    45,    58,    59,    53,    72,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    11,    79,    58,    59,
      60,    61,    62,    63,    29,    65,    66,    67,    68,    69,
      70,    71,    87,    73,    74,    34,    76,    77,    59,    79,
      80,    57,    82,    83,    84,    85,    86,    87,    88,    12,
      64,    60,    29,    62,    57,    52,    65,   136,    53,    51,
     136,    78,    -1,    58,    59,    -1,   128,    76,    -1,    -1,
      33,    -1,    -1,    82,   136,    84,    -1,    -1,    87,    -1,
      12,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    87,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    33,    65,    66,    67,    68,    -1,    70,    71,    -1,
      73,    12,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    86,    87,    57,    -1,    -1,    60,    61,
      62,    -1,    33,    65,    66,    67,    68,    -1,    70,    71,
      -1,    73,    12,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    -1,    -1,    -1,    60,
      61,    62,    -1,    33,    65,    66,    67,    68,    -1,    70,
      71,    -1,    73,    12,    -1,    76,    -1,    78,    79,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    57,    -1,    -1,
      60,    61,    62,    -1,    33,    65,    66,    67,    68,    -1,
      70,    71,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    12,    86,    87,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    70,    71,    60,    73,    62,    33,    76,    65,    -1,
      79,    -1,    -1,    82,    -1,    84,    73,    86,    87,    76,
      -1,    12,    79,    -1,    -1,    82,    -1,    84,    -1,    56,
      87,    -1,    -1,    60,    61,    62,    -1,    -1,    65,    66,
      67,    68,    33,    70,    71,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    86,
      87,    -1,    12,    -1,    -1,    56,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    65,    66,    67,    68,    -1,    70,
      71,    -1,    73,    33,    -1,    76,    -1,    -1,    79,    -1,
      -1,    82,    12,    84,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    58,    -1,
      60,    61,    62,    33,    -1,    65,    66,    67,    68,    -1,
      70,    71,    12,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    -1,    -1,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      70,    71,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    -1,    -1,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      70,    71,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,     3,     4,
       5,     6,     7,     8,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    19,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    73,    60,    61,    62,    -1,
      78,    65,    66,    67,    68,    -1,    70,    71,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    60,
      84,    62,    86,    87,    65,    -1,    67,    68,    -1,    70,
      71,    60,    73,    62,    -1,    76,    65,    -1,    79,    -1,
      -1,    82,    -1,    84,    73,    86,    87,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    86,    87
  };

  const signed char
  parser::yystos_[] =
  {
       0,    90,    91,     0,    25,    92,    93,    96,     8,    50,
      54,    58,    59,     9,    45,    94,    95,     8,    97,    98,
      99,     3,     4,     5,     6,     7,     8,    19,    31,    42,
      43,    54,    73,    78,   107,   108,   109,   110,   111,   112,
     113,   114,    29,    54,    11,    53,    58,    59,    87,    50,
      57,    64,    53,    54,   107,   107,   107,   107,    12,    33,
      58,    60,    61,    62,    65,    66,    67,    68,    70,    71,
      73,    76,    79,    82,    84,    86,    87,    53,    54,    53,
     107,    56,   107,    29,    23,    28,    34,    94,   100,    72,
     101,   102,    99,   107,   107,   115,   116,    57,    78,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   115,   107,    57,
      29,    58,    34,    94,    94,    59,    56,    57,    64,    56,
      57,    56,    29,    52,   106,   107,   103,    55,    92,   104,
     105,   106,   107,    58,    59,    63,    69,    74,    77,    80,
      83,    85,    88,   107,   107,   107,   107,   107,   107,   107,
     107,   107,    58,    58,    58,    58,    58,    58,    58,    58,
      58
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    89,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    95,    95,    95,
      95,    96,    97,    97,    98,    98,    99,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   102,   103,   103,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   107,   107,   107,   107,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     112,   113,   113,   114,   114,   114,   115,   115,   116,   116
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     3,     5,     5,
       7,     1,     2,     2,     3,     3,     4,     1,     2,     4,
       5,     8,     1,     0,     1,     3,     1,     3,     3,     4,
       1,     1,     2,     1,     1,     0,     2,     2,     0,     2,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     4,     4,     4,     4,     4,     1,     0,     1,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   121,   121,   124,   125,   128,   129,   132,   136,   145,
     154,   165,   166,   174,   182,   190,   198,   208,   220,   233,
     245,   260,   272,   273,   276,   277,   280,   289,   298,   307,
     318,   319,   320,   321,   324,   325,   327,   332,   333,   336,
     337,   338,   339,   342,   346,   350,   354,   358,   362,   366,
     370,   374,   380,   387,   388,   389,   390,   391,   392,   395,
     396,   399,   403,   407,   411,   415,   419,   423,   427,   431,
     437,   441,   445,   449,   453,   457,   461,   465,   469,   473,
     477,   481,   485,   489,   493,   497,   501,   507,   511,   515,
     521,   527,   534,   541,   548,   553,   565,   566,   569,   570
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 6 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"
} // fermi
#line 2463 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.cpp"

#line 572 "/home/aschiffer/Fermi-Redux/src/syntax_analysis/parser.yy"


void fermi::parser::error(const location_type& l, const std::string& m)
{
    std::cerr << (l.begin.filename ? l.begin.filename->c_str() : "(undefined)");
    std::cerr << ':' << l.begin.line << ':' << l.begin.column << '-' << l.end.column << ": " << m << '\n';
}
