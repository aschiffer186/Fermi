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





#include "FermiParser.hpp"


// Unqualified %code blocks.
#line 29 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"

    #include "FermiLexer.hpp"

    #define yylex lexer.nextToken

#line 52 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"


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

#line 6 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
namespace Fermi { namespace SyntaxAnalysis {
#line 145 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"

  /// Build a parser object.
  FermiParser::FermiParser (Fermi::SyntaxAnalysis::FermiLexer& lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      lexer (lexer_yyarg)
  {}

  FermiParser::~FermiParser ()
  {}

  FermiParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  FermiParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  FermiParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  FermiParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  FermiParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  FermiParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  FermiParser::symbol_kind_type
  FermiParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  FermiParser::stack_symbol_type::stack_symbol_type ()
  {}

  FermiParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_creation_expression: // creation_expression
      case symbol_kind::S_identity_expression: // identity_expression
      case symbol_kind::S_literal: // literal
        value.YY_MOVE_OR_COPY< std::shared_ptr<ExpressionNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_31_variable_declaration: // variable-declaration
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_35_assignment_statement: // assignment-statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<StatementNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_34_expression_list: // expression-list
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ExpressionNode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_start: // start
      case symbol_kind::S_statements: // statements
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<StatementNode>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  FermiParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
        value.move< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_creation_expression: // creation_expression
      case symbol_kind::S_identity_expression: // identity_expression
      case symbol_kind::S_literal: // literal
        value.move< std::shared_ptr<ExpressionNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_31_variable_declaration: // variable-declaration
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_35_assignment_statement: // assignment-statement
        value.move< std::shared_ptr<StatementNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_34_expression_list: // expression-list
        value.move< std::vector<std::shared_ptr<ExpressionNode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_start: // start
      case symbol_kind::S_statements: // statements
        value.move< std::vector<std::shared_ptr<StatementNode>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  FermiParser::stack_symbol_type&
  FermiParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
        value.copy< Type > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_creation_expression: // creation_expression
      case symbol_kind::S_identity_expression: // identity_expression
      case symbol_kind::S_literal: // literal
        value.copy< std::shared_ptr<ExpressionNode> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_31_variable_declaration: // variable-declaration
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_35_assignment_statement: // assignment-statement
        value.copy< std::shared_ptr<StatementNode> > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_34_expression_list: // expression-list
        value.copy< std::vector<std::shared_ptr<ExpressionNode>> > (that.value);
        break;

      case symbol_kind::S_start: // start
      case symbol_kind::S_statements: // statements
        value.copy< std::vector<std::shared_ptr<StatementNode>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  FermiParser::stack_symbol_type&
  FermiParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
        value.move< Type > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_creation_expression: // creation_expression
      case symbol_kind::S_identity_expression: // identity_expression
      case symbol_kind::S_literal: // literal
        value.move< std::shared_ptr<ExpressionNode> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_31_variable_declaration: // variable-declaration
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_35_assignment_statement: // assignment-statement
        value.move< std::shared_ptr<StatementNode> > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_34_expression_list: // expression-list
        value.move< std::vector<std::shared_ptr<ExpressionNode>> > (that.value);
        break;

      case symbol_kind::S_start: // start
      case symbol_kind::S_statements: // statements
        value.move< std::vector<std::shared_ptr<StatementNode>> > (that.value);
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
  FermiParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  FermiParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  FermiParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  FermiParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  FermiParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  FermiParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  FermiParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  FermiParser::debug_level_type
  FermiParser::debug_level () const
  {
    return yydebug_;
  }

  void
  FermiParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  FermiParser::state_type
  FermiParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  FermiParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  FermiParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  FermiParser::operator() ()
  {
    return parse ();
  }

  int
  FermiParser::parse ()
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
      case symbol_kind::S_type: // type
        yylhs.value.emplace< Type > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_creation_expression: // creation_expression
      case symbol_kind::S_identity_expression: // identity_expression
      case symbol_kind::S_literal: // literal
        yylhs.value.emplace< std::shared_ptr<ExpressionNode> > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_31_variable_declaration: // variable-declaration
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_35_assignment_statement: // assignment-statement
        yylhs.value.emplace< std::shared_ptr<StatementNode> > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_34_expression_list: // expression-list
        yylhs.value.emplace< std::vector<std::shared_ptr<ExpressionNode>> > ();
        break;

      case symbol_kind::S_start: // start
      case symbol_kind::S_statements: // statements
        yylhs.value.emplace< std::vector<std::shared_ptr<StatementNode>> > ();
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
  case 2: // start: statements
#line 67 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                  {yylhs.value.as < std::vector<std::shared_ptr<StatementNode>> > () = std::move(yystack_[0].value.as < std::vector<std::shared_ptr<StatementNode>> > ());}
#line 715 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 3: // statements: statements statement
#line 68 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                 {yystack_[1].value.as < std::vector<std::shared_ptr<StatementNode>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<StatementNode> > ())); yylhs.value.as < std::vector<std::shared_ptr<StatementNode>> > () = std::move(yystack_[1].value.as < std::vector<std::shared_ptr<StatementNode>> > ());}
#line 721 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 4: // statements: %empty
#line 69 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
             {yylhs.value.as < std::vector<std::shared_ptr<StatementNode>> > () = std::vector<std::shared_ptr<StatementNode>>{};}
#line 727 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 5: // statement: variable-declaration
#line 72 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                         {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<StatementNode> > ());}
#line 733 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 6: // statement: print_statement
#line 73 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                      {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<StatementNode> > ());}
#line 739 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 7: // statement: assignment-statement
#line 74 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                           {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<StatementNode> > ());}
#line 745 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 8: // variable-declaration: "let" IDENTIFIER "=" expression
#line 77 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                    {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::make_shared<VariableDeclarationNode>(Type::deduced, yystack_[2].value.as < std::string > (), std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 751 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 9: // variable-declaration: "let" IDENTIFIER ":" type "=" expression ";"
#line 78 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                                   {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::make_shared<VariableDeclarationNode>(yystack_[3].value.as < Type > (), yystack_[5].value.as < std::string > (), std::move(yystack_[1].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 757 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 10: // type: "int8_t"
#line 81 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
             {yylhs.value.as < Type > () = Type::int8_t;}
#line 763 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 11: // type: "int16_t"
#line 82 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                {yylhs.value.as < Type > () = Type::int16_t;}
#line 769 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 12: // type: "int32_t"
#line 83 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                {yylhs.value.as < Type > () = Type::int32_t;}
#line 775 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 13: // type: "int64_t"
#line 84 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                {yylhs.value.as < Type > () = Type::int64_t;}
#line 781 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 14: // type: "float32_t"
#line 85 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                  {yylhs.value.as < Type > () = Type::float32_t;}
#line 787 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 15: // type: "float64_t"
#line 86 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                  {yylhs.value.as < Type > () = Type::float64_t;}
#line 793 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 16: // print_statement: "print" "(" expression-list ")" ";"
#line 88 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                                     {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::make_shared<PrintNode>(std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ExpressionNode>> > ()));}
#line 799 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 17: // expression-list: expression-list "," expression
#line 89 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                                {yystack_[2].value.as < std::vector<std::shared_ptr<ExpressionNode>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ())); yylhs.value.as < std::vector<std::shared_ptr<ExpressionNode>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ExpressionNode>> > ());}
#line 805 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 18: // expression-list: expression
#line 90 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                 {std::vector<std::shared_ptr<ExpressionNode>> v; v.push_back(std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ())); yylhs.value.as < std::vector<std::shared_ptr<ExpressionNode>> > () = std::move(v);}
#line 811 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 19: // assignment-statement: IDENTIFIER "=" expression ";"
#line 92 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                                    {yylhs.value.as < std::shared_ptr<StatementNode> > () = std::make_shared<AssignmentStatementNode>(yystack_[3].value.as < std::string > (), std::move(yystack_[1].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 817 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 20: // expression: identity_expression
#line 94 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                        {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ());}
#line 823 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 21: // expression: creation_expression
#line 95 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                          {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ());}
#line 829 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 22: // creation_expression: expression "+" expression
#line 98 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                              {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Addition, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 835 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 23: // creation_expression: expression "-" expression
#line 99 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Subtraction, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 841 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 24: // creation_expression: expression "*" expression
#line 100 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Multiplication, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 847 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 25: // creation_expression: expression "/" expression
#line 101 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Division, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 853 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 26: // creation_expression: expression "//" expression
#line 102 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                 {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::IntegerDivision, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 859 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 27: // creation_expression: expression "^" expression
#line 103 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Exponentiation, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 865 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 28: // creation_expression: expression "%" expression
#line 104 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                                {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<BinaryExpressionNode>(std::move(yystack_[2].value.as < std::shared_ptr<ExpressionNode> > ()), BinaryExpressionTypes::Modulo, std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ()));}
#line 871 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 29: // identity_expression: literal
#line 107 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
            {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::move(yystack_[0].value.as < std::shared_ptr<ExpressionNode> > ());}
#line 877 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 30: // identity_expression: IDENTIFIER
#line 108 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                 {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<LiteralNode>(yystack_[0].value.as < std::string > (), LiteralType::Identifier);}
#line 883 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 31: // identity_expression: "(" expression ")"
#line 109 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                         {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::move(yystack_[1].value.as < std::shared_ptr<ExpressionNode> > ());}
#line 889 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 32: // literal: INTEGER_LITERAL
#line 112 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                    {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<LiteralNode>(yystack_[0].value.as < std::string > (), LiteralType::Integer);}
#line 895 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;

  case 33: // literal: FLOAT_LITERAL
#line 113 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
                    {yylhs.value.as < std::shared_ptr<ExpressionNode> > () = std::make_shared<LiteralNode>(yystack_[0].value.as < std::string > (), LiteralType::Float);}
#line 901 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"
    break;


#line 905 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"

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
  FermiParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  FermiParser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "IDENTIFIER", "+", "-", "*", "/", "//", "^", "%", "=",
  ";", "(", ")", ",", ":", "let", "print", "int8_t", "int16_t", "int32_t",
  "int64_t", "float32_t", "float64_t", "$accept", "start", "statements",
  "statement", "variable-declaration", "type", "print_statement",
  "expression-list", "assignment-statement", "expression",
  "creation_expression", "identity_expression", "literal", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // FermiParser::context.
  FermiParser::context::context (const FermiParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  FermiParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  FermiParser::yy_lac_check_ (symbol_kind_type yytoken) const
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
  FermiParser::yy_lac_establish_ (symbol_kind_type yytoken)
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
  FermiParser::yy_lac_discard_ (const char* event)
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
  FermiParser::yy_syntax_error_arguments_ (const context& yyctx,
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
  FermiParser::yysyntax_error_ (const context& yyctx) const
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


  const signed char FermiParser::yypact_ninf_ = -14;

  const signed char FermiParser::yytable_ninf_ = -1;

  const signed char
  FermiParser::yypact_[] =
  {
     -14,     6,     2,   -14,    19,     3,    15,   -14,   -14,   -14,
     -14,    -2,    -8,    -2,   -14,   -14,   -14,    -2,    35,   -14,
     -14,   -14,    -2,    13,    -5,    53,    17,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,   -14,    53,   -14,   -14,   -14,   -14,
     -14,   -14,    59,    34,    -2,   -14,    58,    58,    46,    46,
      46,    46,    46,    -2,   -14,    53,    44,   -14
  };

  const signed char
  FermiParser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     0,     0,     3,     5,     6,
       7,     0,     0,     0,    32,    33,    30,     0,     0,    21,
      20,    29,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     8,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    31,    22,    23,    24,    25,
      26,    27,    28,     0,    16,    17,     0,     9
  };

  const signed char
  FermiParser::yypgoto_[] =
  {
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -13,
     -14,   -14,   -14
  };

  const signed char
  FermiParser::yydefgoto_[] =
  {
       0,     1,     2,     7,     8,    42,     9,    24,    10,    18,
      19,    20,    21
  };

  const signed char
  FermiParser::yytable_[] =
  {
      25,    14,    15,    16,    26,    22,     3,     4,    12,    35,
      23,    43,    44,    17,    46,    47,    48,    49,    50,    51,
      52,     5,     6,    27,    28,    29,    30,    31,    32,    33,
      13,    55,    11,    45,    36,    37,    38,    39,    40,    41,
      56,    27,    28,    29,    30,    31,    32,    33,    54,    34,
      27,    28,    29,    30,    31,    32,    33,    32,    57,    27,
      28,    29,    30,    31,    32,    33,    29,    30,    31,    32,
      33,     0,    53
  };

  const signed char
  FermiParser::yycheck_[] =
  {
      13,     3,     4,     5,    17,    13,     0,     5,     5,    22,
      18,    16,    17,    15,    27,    28,    29,    30,    31,    32,
      33,    19,    20,     6,     7,     8,     9,    10,    11,    12,
      15,    44,    13,    16,    21,    22,    23,    24,    25,    26,
      53,     6,     7,     8,     9,    10,    11,    12,    14,    14,
       6,     7,     8,     9,    10,    11,    12,    11,    14,     6,
       7,     8,     9,    10,    11,    12,     8,     9,    10,    11,
      12,    -1,    13
  };

  const signed char
  FermiParser::yystos_[] =
  {
       0,    28,    29,     0,     5,    19,    20,    30,    31,    33,
      35,    13,     5,    15,     3,     4,     5,    15,    36,    37,
      38,    39,    13,    18,    34,    36,    36,     6,     7,     8,
       9,    10,    11,    12,    14,    36,    21,    22,    23,    24,
      25,    26,    32,    16,    17,    16,    36,    36,    36,    36,
      36,    36,    36,    13,    14,    36,    36,    14
  };

  const signed char
  FermiParser::yyr1_[] =
  {
       0,    27,    28,    29,    29,    30,    30,    30,    31,    31,
      32,    32,    32,    32,    32,    32,    33,    34,    34,    35,
      36,    36,    37,    37,    37,    37,    37,    37,    37,    38,
      38,    38,    39,    39
  };

  const signed char
  FermiParser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     4,     7,
       1,     1,     1,     1,     1,     1,     5,     3,     1,     4,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     1,     1
  };




#if YYDEBUG
  const signed char
  FermiParser::yyrline_[] =
  {
       0,    67,    67,    68,    69,    72,    73,    74,    77,    78,
      81,    82,    83,    84,    85,    86,    88,    89,    90,    92,
      94,    95,    98,    99,   100,   101,   102,   103,   104,   107,
     108,   109,   112,   113
  };

  void
  FermiParser::yy_stack_print_ () const
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
  FermiParser::yy_reduce_print_ (int yyrule) const
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


#line 6 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"
} } // Fermi::SyntaxAnalysis
#line 1502 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/src/FermiParser.cpp"

#line 115 "/home/aschiffe/Dev/Fermi/Fermi/Syntax-Analysis/include/FermiParser.yy"

namespace Fermi::SyntaxAnalysis
{
    void FermiParser::error(const location&, const std::string&)
    {
        
    }
}
