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





#include "parser.hh"


// Unqualified %code blocks.
#line 25 "parser.yy"

# include "driver.hh"
#include <iostream>
using namespace std;

#line 52 "src/parser.cc"


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

namespace yy {
#line 144 "src/parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.move< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.copy< std::string > (that.value);
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.move< std::string > (that.value);
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
        switch (yykind)
    {
      case symbol_kind::S_id: // id
#line 49 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 316 "src/parser.cc"
        break;

      case symbol_kind::S_string: // string
#line 49 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 322 "src/parser.cc"
        break;

      default:
        break;
    }
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
            symbol_type yylookahead (yylex (drv));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        yylhs.value.emplace< std::string > ();
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
  case 2: // program: macro program
#line 54 "parser.yy"
                       { }
#line 590 "src/parser.cc"
    break;

  case 3: // program: declerations
#line 55 "parser.yy"
                      {  }
#line 596 "src/parser.cc"
    break;

  case 4: // macro: import string
#line 57 "parser.yy"
                     { }
#line 602 "src/parser.cc"
    break;

  case 5: // macro: define id id
#line 58 "parser.yy"
                    { }
#line 608 "src/parser.cc"
    break;

  case 6: // declerations: declaration declerations
#line 60 "parser.yy"
                                       { }
#line 614 "src/parser.cc"
    break;

  case 7: // declerations: declaration
#line 61 "parser.yy"
                          {  }
#line 620 "src/parser.cc"
    break;

  case 8: // declaration: variabledecl
#line 63 "parser.yy"
                          { }
#line 626 "src/parser.cc"
    break;

  case 9: // declaration: functiondecl
#line 64 "parser.yy"
                          { }
#line 632 "src/parser.cc"
    break;

  case 10: // declaration: classdecl
#line 65 "parser.yy"
                       { }
#line 638 "src/parser.cc"
    break;

  case 11: // variabledecl: variable semicolon
#line 67 "parser.yy"
                                 { }
#line 644 "src/parser.cc"
    break;

  case 12: // variable: type id
#line 69 "parser.yy"
                  { }
#line 650 "src/parser.cc"
    break;

  case 13: // type: int
#line 71 "parser.yy"
          { }
#line 656 "src/parser.cc"
    break;

  case 14: // type: double
#line 72 "parser.yy"
             { }
#line 662 "src/parser.cc"
    break;

  case 15: // type: bool
#line 73 "parser.yy"
           { }
#line 668 "src/parser.cc"
    break;

  case 16: // type: string_kw
#line 74 "parser.yy"
                { }
#line 674 "src/parser.cc"
    break;

  case 17: // type: id
#line 75 "parser.yy"
         { }
#line 680 "src/parser.cc"
    break;

  case 18: // type: type openclosebracket
#line 76 "parser.yy"
                            { }
#line 686 "src/parser.cc"
    break;

  case 19: // functiondecl: type id openparantheses formals closeparantheses stmtblock
#line 78 "parser.yy"
                                                                         { }
#line 692 "src/parser.cc"
    break;

  case 20: // functiondecl: void id openparantheses formals closeparantheses stmtblock
#line 79 "parser.yy"
                                                                         { }
#line 698 "src/parser.cc"
    break;

  case 21: // formals: formalsp
#line 81 "parser.yy"
                  { }
#line 704 "src/parser.cc"
    break;

  case 22: // formals: %empty
#line 82 "parser.yy"
                {  }
#line 710 "src/parser.cc"
    break;

  case 23: // formalsp: variable comma formalsp
#line 84 "parser.yy"
                                  { }
#line 716 "src/parser.cc"
    break;

  case 24: // formalsp: variable
#line 85 "parser.yy"
                   { }
#line 722 "src/parser.cc"
    break;

  case 25: // classdecl: class id openbrace fields closebrace
#line 87 "parser.yy"
                                                {  }
#line 728 "src/parser.cc"
    break;

  case 26: // fields: field fields
#line 89 "parser.yy"
                     { }
#line 734 "src/parser.cc"
    break;

  case 28: // field: accessmode variabledecl
#line 92 "parser.yy"
                               { }
#line 740 "src/parser.cc"
    break;

  case 29: // field: accessmode functiondecl
#line 93 "parser.yy"
                               { }
#line 746 "src/parser.cc"
    break;

  case 30: // accessmode: private
#line 95 "parser.yy"
                    { }
#line 752 "src/parser.cc"
    break;

  case 31: // accessmode: public
#line 96 "parser.yy"
                   { }
#line 758 "src/parser.cc"
    break;

  case 32: // accessmode: %empty
#line 97 "parser.yy"
                   { }
#line 764 "src/parser.cc"
    break;

  case 33: // stmtblock: openbrace stmtblockcontent closebrace
#line 99 "parser.yy"
                                                 { }
#line 770 "src/parser.cc"
    break;

  case 34: // stmtblockcontent: variabledecl stmtblockcontent
#line 101 "parser.yy"
                                                { }
#line 776 "src/parser.cc"
    break;

  case 35: // stmtblockcontent: statements
#line 102 "parser.yy"
                             { }
#line 782 "src/parser.cc"
    break;

  case 36: // statements: %empty
#line 104 "parser.yy"
                   { }
#line 788 "src/parser.cc"
    break;

  case 37: // statements: stmt statements
#line 105 "parser.yy"
                            { }
#line 794 "src/parser.cc"
    break;

  case 38: // stmt: expr semicolon
#line 107 "parser.yy"
                     { }
#line 800 "src/parser.cc"
    break;

  case 39: // stmt: semicolon
#line 108 "parser.yy"
                     { }
#line 806 "src/parser.cc"
    break;

  case 40: // stmt: ifstmt
#line 109 "parser.yy"
                  { }
#line 812 "src/parser.cc"
    break;

  case 41: // stmt: whilestmt
#line 110 "parser.yy"
                     { }
#line 818 "src/parser.cc"
    break;

  case 42: // stmt: forstmt
#line 111 "parser.yy"
                   { }
#line 824 "src/parser.cc"
    break;

  case 43: // stmt: breakstmt
#line 112 "parser.yy"
                     { }
#line 830 "src/parser.cc"
    break;

  case 44: // stmt: continuestmt
#line 113 "parser.yy"
                        { }
#line 836 "src/parser.cc"
    break;

  case 45: // stmt: returnstmt
#line 114 "parser.yy"
                      { }
#line 842 "src/parser.cc"
    break;

  case 46: // stmt: printstmt
#line 115 "parser.yy"
                     { }
#line 848 "src/parser.cc"
    break;

  case 47: // stmt: stmtblock
#line 116 "parser.yy"
                     { }
#line 854 "src/parser.cc"
    break;

  case 48: // ifstmt: if openparantheses expr closeparantheses stmt
#line 119 "parser.yy"
                                                      { }
#line 860 "src/parser.cc"
    break;

  case 49: // ifstmt: if openparantheses expr closeparantheses stmt elsestmt
#line 120 "parser.yy"
                                                              { }
#line 866 "src/parser.cc"
    break;

  case 50: // elsestmt: else stmt
#line 122 "parser.yy"
                    { }
#line 872 "src/parser.cc"
    break;

  case 51: // whilestmt: while openparantheses expr closeparantheses stmt
#line 124 "parser.yy"
                                                            { }
#line 878 "src/parser.cc"
    break;

  case 52: // forstmt: for openparantheses nexpr semicolon expr semicolon nexpr closeparantheses stmt
#line 126 "parser.yy"
                                                                                        { }
#line 884 "src/parser.cc"
    break;

  case 53: // returnstmt: return nexpr semicolon
#line 128 "parser.yy"
                                   { }
#line 890 "src/parser.cc"
    break;

  case 54: // breakstmt: break semicolon
#line 130 "parser.yy"
                           { }
#line 896 "src/parser.cc"
    break;

  case 55: // nexpr: expr
#line 132 "parser.yy"
            { }
#line 902 "src/parser.cc"
    break;

  case 56: // nexpr: %empty
#line 133 "parser.yy"
             { }
#line 908 "src/parser.cc"
    break;

  case 57: // continuestmt: continue semicolon
#line 135 "parser.yy"
                                 { }
#line 914 "src/parser.cc"
    break;

  case 58: // printstmt: print openparantheses printcontent closeparantheses semicolon
#line 139 "parser.yy"
                                                                             {}
#line 920 "src/parser.cc"
    break;

  case 59: // printcontent: printcontent comma expr
#line 143 "parser.yy"
                                      {}
#line 926 "src/parser.cc"
    break;

  case 60: // printcontent: expr
#line 144 "parser.yy"
                   {}
#line 932 "src/parser.cc"
    break;

  case 61: // expr: lvalue assign expr
#line 154 "parser.yy"
                                         {}
#line 938 "src/parser.cc"
    break;

  case 62: // expr: lvalue plusequal expr
#line 155 "parser.yy"
                                          {}
#line 944 "src/parser.cc"
    break;

  case 63: // expr: lvalue minusequal expr
#line 156 "parser.yy"
                                           {}
#line 950 "src/parser.cc"
    break;

  case 64: // expr: lvalue starequal expr
#line 157 "parser.yy"
                                          {}
#line 956 "src/parser.cc"
    break;

  case 65: // expr: lvalue slashequal expr
#line 158 "parser.yy"
                                           {}
#line 962 "src/parser.cc"
    break;

  case 66: // expr: constant
#line 159 "parser.yy"
                                    {}
#line 968 "src/parser.cc"
    break;

  case 67: // expr: lvalue
#line 160 "parser.yy"
                                    {}
#line 974 "src/parser.cc"
    break;

  case 68: // expr: this
#line 161 "parser.yy"
                                    {}
#line 980 "src/parser.cc"
    break;

  case 69: // expr: call
#line 162 "parser.yy"
                                    {}
#line 986 "src/parser.cc"
    break;

  case 70: // expr: openparantheses expr closeparantheses
#line 163 "parser.yy"
                                                                   {}
#line 992 "src/parser.cc"
    break;

  case 71: // expr: expr plus expr
#line 164 "parser.yy"
                                       {}
#line 998 "src/parser.cc"
    break;

  case 72: // expr: expr minus expr
#line 165 "parser.yy"
                                        {}
#line 1004 "src/parser.cc"
    break;

  case 73: // expr: expr star expr
#line 166 "parser.yy"
                                       {}
#line 1010 "src/parser.cc"
    break;

  case 74: // expr: expr slash expr
#line 167 "parser.yy"
                                        {}
#line 1016 "src/parser.cc"
    break;

  case 75: // expr: expr percent expr
#line 168 "parser.yy"
                                          {}
#line 1022 "src/parser.cc"
    break;

  case 76: // expr: minus expr
#line 169 "parser.yy"
                                        {}
#line 1028 "src/parser.cc"
    break;

  case 77: // expr: expr lessthan expr
#line 170 "parser.yy"
                                           {}
#line 1034 "src/parser.cc"
    break;

  case 78: // expr: expr lessthanequal expr
#line 171 "parser.yy"
                                               {}
#line 1040 "src/parser.cc"
    break;

  case 79: // expr: expr greaterthan expr
#line 172 "parser.yy"
                                              {}
#line 1046 "src/parser.cc"
    break;

  case 80: // expr: expr greaterthanequal expr
#line 173 "parser.yy"
                                                  {}
#line 1052 "src/parser.cc"
    break;

  case 81: // expr: expr equal expr
#line 174 "parser.yy"
                                       {}
#line 1058 "src/parser.cc"
    break;

  case 82: // expr: expr notequal expr
#line 175 "parser.yy"
                                          {}
#line 1064 "src/parser.cc"
    break;

  case 83: // expr: expr and expr
#line 176 "parser.yy"
                                     {}
#line 1070 "src/parser.cc"
    break;

  case 84: // expr: expr or expr
#line 177 "parser.yy"
                                    {}
#line 1076 "src/parser.cc"
    break;

  case 85: // expr: not expr
#line 178 "parser.yy"
                                      {}
#line 1082 "src/parser.cc"
    break;

  case 86: // expr: readinteger openparantheses closeparantheses
#line 179 "parser.yy"
                                                                  {}
#line 1088 "src/parser.cc"
    break;

  case 87: // expr: readline openparantheses closeparantheses
#line 180 "parser.yy"
                                                                   {}
#line 1094 "src/parser.cc"
    break;

  case 88: // expr: new id
#line 181 "parser.yy"
                                 {}
#line 1100 "src/parser.cc"
    break;

  case 89: // expr: newarray openparantheses expr comma type closeparantheses
#line 182 "parser.yy"
                                                                      {}
#line 1106 "src/parser.cc"
    break;

  case 90: // expr: itod openparantheses expr closeparantheses
#line 183 "parser.yy"
                                                            {}
#line 1112 "src/parser.cc"
    break;

  case 91: // expr: dtoi openparantheses expr closeparantheses
#line 184 "parser.yy"
                                                            {}
#line 1118 "src/parser.cc"
    break;

  case 92: // expr: itob openparantheses expr closeparantheses
#line 185 "parser.yy"
                                                            {}
#line 1124 "src/parser.cc"
    break;

  case 93: // expr: btoi openparantheses expr closeparantheses
#line 186 "parser.yy"
                                                            {}
#line 1130 "src/parser.cc"
    break;

  case 94: // expr: line
#line 187 "parser.yy"
                                {}
#line 1136 "src/parser.cc"
    break;

  case 95: // expr: func
#line 188 "parser.yy"
                                {}
#line 1142 "src/parser.cc"
    break;

  case 96: // lvalue: id
#line 191 "parser.yy"
                                 {}
#line 1148 "src/parser.cc"
    break;

  case 97: // lvalue: expr dot id
#line 192 "parser.yy"
                                     {}
#line 1154 "src/parser.cc"
    break;

  case 98: // lvalue: expr openbracket expr closebracket
#line 193 "parser.yy"
                                                         {}
#line 1160 "src/parser.cc"
    break;

  case 99: // call: id openparantheses actuals closeparantheses
#line 196 "parser.yy"
                                                               {}
#line 1166 "src/parser.cc"
    break;

  case 100: // call: expr dot id openparantheses actuals closeparantheses
#line 197 "parser.yy"
                                                                   {}
#line 1172 "src/parser.cc"
    break;

  case 101: // actuals: actualscontent
#line 200 "parser.yy"
                                          {}
#line 1178 "src/parser.cc"
    break;

  case 102: // actuals: %empty
#line 201 "parser.yy"
                                    {}
#line 1184 "src/parser.cc"
    break;

  case 103: // actualscontent: expr comma actualscontent
#line 204 "parser.yy"
                                  {}
#line 1190 "src/parser.cc"
    break;

  case 104: // actualscontent: expr
#line 205 "parser.yy"
               { }
#line 1196 "src/parser.cc"
    break;

  case 105: // constant: integer
#line 208 "parser.yy"
                                {}
#line 1202 "src/parser.cc"
    break;

  case 106: // constant: float
#line 209 "parser.yy"
                           {}
#line 1208 "src/parser.cc"
    break;

  case 107: // constant: boolean
#line 210 "parser.yy"
                               {}
#line 1214 "src/parser.cc"
    break;

  case 108: // constant: string
#line 211 "parser.yy"
                            {}
#line 1220 "src/parser.cc"
    break;

  case 109: // constant: nullkw
#line 212 "parser.yy"
                                      {}
#line 1226 "src/parser.cc"
    break;


#line 1230 "src/parser.cc"

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
    "end of file", "error", "invalid token", "id", "string", "define",
  "import", "semicolon", "integer", "double", "bool", "string_kw",
  "openclosebracket", "openbracket", "closebracket", "private", "public",
  "if", "else", "while", "for", "boolean", "void", "int", "class",
  "nullkw", "slash", "percent", "return", "break", "new", "this",
  "newarray", "print", "readinteger", "readline", "line", "func", "btoi",
  "continue", "dtoi", "itob", "itod", "float", "plus", "minus", "star",
  "div", "lessthanequal", "greaterthanequal", "lessthan", "greaterthan",
  "equal", "notequal", "and", "or", "closebrace", "openparantheses",
  "closeparantheses", "comma", "assign", "openbrace", "plusequal",
  "minusequal", "starequal", "slashequal", "not", "dot", "$accept",
  "program", "macro", "declerations", "declaration", "variabledecl",
  "variable", "type", "functiondecl", "formals", "formalsp", "classdecl",
  "fields", "field", "accessmode", "stmtblock", "stmtblockcontent",
  "statements", "stmt", "ifstmt", "elsestmt", "whilestmt", "forstmt",
  "returnstmt", "breakstmt", "nexpr", "continuestmt", "printstmt",
  "printcontent", "expr", "lvalue", "call", "actuals", "actualscontent",
  "constant", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -176;

  const signed char parser::yytable_ninf_ = -28;

  const short
  parser::yypact_[] =
  {
      78,  -176,    18,    -1,  -176,  -176,  -176,    26,  -176,    37,
      42,    78,  -176,    87,  -176,    41,    22,  -176,  -176,    57,
    -176,    -2,    14,  -176,  -176,  -176,  -176,    28,  -176,  -176,
      83,    -9,    83,    36,    79,    45,  -176,  -176,  -176,    43,
      -9,    21,    46,    83,  -176,    47,  -176,  -176,  -176,  -176,
      47,  -176,   126,  -176,  -176,     2,  -176,  -176,  -176,    50,
      56,    62,  -176,  -176,   217,   113,   118,  -176,    66,    67,
      69,    70,  -176,  -176,    71,   125,    81,    82,    84,  -176,
     217,   217,   217,   126,  -176,    88,  -176,   174,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,   243,    52,  -176,  -176,   217,
     217,   217,   217,    91,   133,   616,  -176,  -176,   217,   217,
      92,    94,   217,  -176,   217,   217,   217,     3,   303,     3,
    -176,  -176,  -176,  -176,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   150,   217,
     217,   217,   217,   217,   333,   112,  -176,   363,   393,   165,
    -176,   423,   -32,   616,  -176,  -176,   453,   483,   513,   543,
    -176,   586,     3,     3,     3,     3,     3,   632,     3,   632,
     632,     3,   160,   160,   160,   117,   632,   632,     3,     3,
     632,   217,  -176,   174,   174,   217,    83,   168,   217,  -176,
    -176,  -176,  -176,  -176,   217,  -176,   158,  -176,   273,    -8,
    -176,   616,   121,   174,  -176,   217,  -176,  -176,  -176,   122,
     174,  -176
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    17,     0,     0,    14,    15,    16,     0,    13,     0,
       0,     0,     3,     7,     8,     0,     0,     9,    10,     0,
       4,     0,     0,     1,     2,     6,    11,    12,    18,     5,
      22,    32,    22,    24,     0,     0,    21,    30,    31,     0,
      32,     0,     0,     0,    12,     0,    25,    26,    28,    29,
       0,    23,    36,    20,    19,    96,   108,    39,   105,     0,
       0,     0,   107,   109,    56,     0,     0,    68,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,   106,
       0,     0,     0,    36,    47,     0,    35,    36,    40,    41,
      42,    45,    43,    44,    46,     0,    67,    69,    66,   102,
       0,     0,    56,    96,     0,    55,    54,    88,     0,     0,
       0,     0,     0,    57,     0,     0,     0,    76,     0,    85,
      34,    33,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,   101,     0,     0,     0,
      53,     0,     0,    60,    86,    87,     0,     0,     0,     0,
      70,     0,    74,    75,    71,    72,    73,    78,    80,    77,
      79,    81,    82,    83,    84,    97,    61,    62,    63,    64,
      65,     0,    99,     0,     0,     0,     0,     0,     0,    93,
      91,    92,    90,    98,   102,   103,    48,    51,     0,     0,
      58,    59,     0,     0,    49,    56,    89,   100,    50,     0,
       0,    52
  };

  const short
  parser::yypgoto_[] =
  {
    -176,   173,  -176,   172,  -176,   -29,   -10,     0,   147,   157,
     153,  -176,   161,  -176,  -176,   -35,   107,   110,  -175,  -176,
    -176,  -176,  -176,  -176,  -176,  -100,  -176,  -176,  -176,   -63,
    -176,  -176,     4,    19,  -176
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    10,    11,    12,    13,    14,    15,    34,    17,    35,
      36,    18,    39,    40,    41,    84,    85,    86,    87,    88,
     204,    89,    90,    91,    92,   104,    93,    94,   152,    95,
      96,    97,   145,   146,    98
  };

  const short
  parser::yytable_[] =
  {
      16,   105,   149,    20,    28,   -17,    37,    38,   196,   197,
      53,    16,    48,    16,   -17,    54,   124,   117,   118,   119,
      33,    19,    33,    83,     1,    27,   187,   188,   208,    21,
       4,     5,     6,    33,    28,   211,   144,   147,   148,   105,
      22,    16,    23,     7,     8,   151,   153,   -27,    26,   156,
     206,   157,   158,   159,    83,    30,   135,   136,   137,    99,
      29,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    31,   176,   177,   178,   179,
     180,     1,    44,     2,     3,    32,     1,     4,     5,     6,
       1,    28,     4,     5,     6,    43,     4,     5,     6,    46,
       7,     8,     9,    45,    50,   209,     8,   100,    52,     7,
       8,     9,   139,   101,   140,   141,   142,   143,   144,   102,
     106,   107,   198,   108,   109,   201,   110,   111,   112,    55,
      56,   144,   113,    57,    58,     4,     5,     6,   114,   115,
     150,   116,   105,    59,   121,    60,    61,    62,    99,     8,
     154,    63,   155,   175,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
     182,    80,   185,   124,   194,   200,   203,   103,    56,   207,
     210,    57,    58,    81,    24,    25,   199,    52,    49,    42,
     120,    59,    82,    60,    61,    62,    51,   122,   202,    63,
     195,    47,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    80,
     103,    56,     0,     0,     0,    58,     0,     0,     0,     0,
       0,    81,     0,     0,     0,    52,     0,     0,    62,     0,
      82,     0,    63,     0,     0,     0,     0,    66,    67,    68,
     123,    70,    71,    72,    73,    74,   124,    76,    77,    78,
      79,     0,    80,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,     0,    81,     0,     0,     0,     0,     0,
     205,     0,     0,    82,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   160,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,     0,   181,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   183,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   184,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,     0,   186,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   190,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   124,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   125,
     126,   191,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   124,
     193,   192,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   125,   126,     0,   124,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,   127,   128,   129,     0,
       0,   131,     0,   138,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138
  };

  const short
  parser::yycheck_[] =
  {
       0,    64,   102,     4,    12,     3,    15,    16,   183,   184,
      45,    11,    41,    13,    12,    50,    13,    80,    81,    82,
      30,     3,    32,    52,     3,     3,    58,    59,   203,     3,
       9,    10,    11,    43,    12,   210,    99,   100,   101,   102,
       3,    41,     0,    22,    23,   108,   109,    56,     7,   112,
      58,   114,   115,   116,    83,    57,    53,    54,    55,    57,
       3,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    61,   139,   140,   141,   142,
     143,     3,     3,     5,     6,    57,     3,     9,    10,    11,
       3,    12,     9,    10,    11,    59,     9,    10,    11,    56,
      22,    23,    24,    58,    58,   205,    23,    57,    61,    22,
      23,    24,    60,    57,    62,    63,    64,    65,   181,    57,
       7,     3,   185,    57,    57,   188,    57,    57,    57,     3,
       4,   194,     7,     7,     8,     9,    10,    11,    57,    57,
       7,    57,   205,    17,    56,    19,    20,    21,    57,    23,
      58,    25,    58,     3,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      58,    45,     7,    13,    57,     7,    18,     3,     4,    58,
      58,     7,     8,    57,    11,    13,   186,    61,    41,    32,
      83,    17,    66,    19,    20,    21,    43,    87,   194,    25,
     181,    40,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
       3,     4,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    61,    -1,    -1,    21,    -1,
      66,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
       7,    34,    35,    36,    37,    38,    13,    40,    41,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    66,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    13,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    26,
      27,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    13,
      14,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    26,    27,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    67,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     5,     6,     9,    10,    11,    22,    23,    24,
      69,    70,    71,    72,    73,    74,    75,    76,    79,     3,
       4,     3,     3,     0,    69,    71,     7,     3,    12,     3,
      57,    61,    57,    74,    75,    77,    78,    15,    16,    80,
      81,    82,    77,    59,     3,    58,    56,    80,    73,    76,
      58,    78,    61,    83,    83,     3,     4,     7,     8,    17,
      19,    20,    21,    25,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      45,    57,    66,    73,    83,    84,    85,    86,    87,    89,
      90,    91,    92,    94,    95,    97,    98,    99,   102,    57,
      57,    57,    57,     3,    93,    97,     7,     3,    57,    57,
      57,    57,    57,     7,    57,    57,    57,    97,    97,    97,
      84,    56,    85,     7,    13,    26,    27,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    54,    55,    67,    60,
      62,    63,    64,    65,    97,   100,   101,    97,    97,    93,
       7,    97,    96,    97,    58,    58,    97,    97,    97,    97,
      58,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,     3,    97,    97,    97,    97,
      97,    59,    58,    58,    58,     7,    59,    58,    59,    58,
      58,    58,    58,    14,    57,   101,    86,    86,    97,    75,
       7,    97,   100,    18,    88,     7,    58,    58,    86,    93,
      58,    86
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    74,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    89,    90,    91,    92,    93,    93,    94,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   102
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     6,
       6,     1,     0,     3,     1,     5,     2,     0,     2,     2,
       1,     1,     0,     3,     2,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       2,     5,     9,     3,     2,     1,     0,     2,     5,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     2,     6,
       4,     4,     4,     4,     1,     1,     1,     3,     4,     4,
       6,     1,     0,     3,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    54,    54,    55,    57,    58,    60,    61,    63,    64,
      65,    67,    69,    71,    72,    73,    74,    75,    76,    78,
      79,    81,    82,    84,    85,    87,    89,    90,    92,    93,
      95,    96,    97,    99,   101,   102,   104,   105,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   119,   120,
     122,   124,   126,   128,   130,   132,   133,   135,   139,   143,
     144,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   191,   192,   193,   196,
     197,   200,   201,   204,   205,   208,   209,   210,   211,   212
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


} // yy
#line 2034 "src/parser.cc"

#line 217 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
