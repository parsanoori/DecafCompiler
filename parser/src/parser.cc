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
#include "codegen.h"
#include "dtype.h"
#include <vector>
using namespace std;

codegen &cg = *(codegen::get());

#line 57 "src/parser.cc"


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
#line 149 "src/parser.cc"

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
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
      case symbol_kind::S_define: // define
      case symbol_kind::S_import: // import
      case symbol_kind::S_semicolon: // semicolon
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_double: // double
      case symbol_kind::S_bool: // bool
      case symbol_kind::S_string_kw: // string_kw
      case symbol_kind::S_openclosebracket: // openclosebracket
      case symbol_kind::S_openbracket: // openbracket
      case symbol_kind::S_closebracket: // closebracket
      case symbol_kind::S_private: // private
      case symbol_kind::S_public: // public
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_for: // for
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_void: // void
      case symbol_kind::S_int: // int
      case symbol_kind::S_class: // class
      case symbol_kind::S_nullkw: // nullkw
      case symbol_kind::S_slash: // slash
      case symbol_kind::S_percent: // percent
      case symbol_kind::S_return: // return
      case symbol_kind::S_break: // break
      case symbol_kind::S_new: // new
      case symbol_kind::S_this: // this
      case symbol_kind::S_newarray: // newarray
      case symbol_kind::S_print: // print
      case symbol_kind::S_readinteger: // readinteger
      case symbol_kind::S_readline: // readline
      case symbol_kind::S_line: // line
      case symbol_kind::S_func: // func
      case symbol_kind::S_btoi: // btoi
      case symbol_kind::S_continue: // continue
      case symbol_kind::S_dtoi: // dtoi
      case symbol_kind::S_itob: // itob
      case symbol_kind::S_itod: // itod
      case symbol_kind::S_float: // float
      case symbol_kind::S_plus: // plus
      case symbol_kind::S_minus: // minus
      case symbol_kind::S_star: // star
      case symbol_kind::S_div: // div
      case symbol_kind::S_lessthanequal: // lessthanequal
      case symbol_kind::S_greaterthanequal: // greaterthanequal
      case symbol_kind::S_lessthan: // lessthan
      case symbol_kind::S_greaterthan: // greaterthan
      case symbol_kind::S_equal: // equal
      case symbol_kind::S_notequal: // notequal
      case symbol_kind::S_and: // and
      case symbol_kind::S_or: // or
      case symbol_kind::S_closebrace: // closebrace
      case symbol_kind::S_openparantheses: // openparantheses
      case symbol_kind::S_closeparantheses: // closeparantheses
      case symbol_kind::S_comma: // comma
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_openbrace: // openbrace
      case symbol_kind::S_plusequal: // plusequal
      case symbol_kind::S_minusequal: // minusequal
      case symbol_kind::S_starequal: // starequal
      case symbol_kind::S_slashequal: // slashequal
      case symbol_kind::S_not: // not
      case symbol_kind::S_dot: // dot
      case symbol_kind::S_program: // program
      case symbol_kind::S_macro: // macro
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_variabledecl: // variabledecl
      case symbol_kind::S_type: // type
      case symbol_kind::S_functiondecl: // functiondecl
      case symbol_kind::S_classdecl: // classdecl
      case symbol_kind::S_fields: // fields
      case symbol_kind::S_field: // field
      case symbol_kind::S_accessmode: // accessmode
      case symbol_kind::S_stmtblock: // stmtblock
      case symbol_kind::S_stmtblockcontent: // stmtblockcontent
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_ifstmt: // ifstmt
      case symbol_kind::S_elsestmt: // elsestmt
      case symbol_kind::S_whilestmt: // whilestmt
      case symbol_kind::S_forstmt: // forstmt
      case symbol_kind::S_returnstmt: // returnstmt
      case symbol_kind::S_breakstmt: // breakstmt
      case symbol_kind::S_nexpr: // nexpr
      case symbol_kind::S_continuestmt: // continuestmt
      case symbol_kind::S_printstmt: // printstmt
      case symbol_kind::S_printcontent: // printcontent
      case symbol_kind::S_lvalue: // lvalue
      case symbol_kind::S_call: // call
      case symbol_kind::S_actuals: // actuals
      case symbol_kind::S_actualscontent: // actualscontent
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.move< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
      case symbol_kind::S_define: // define
      case symbol_kind::S_import: // import
      case symbol_kind::S_semicolon: // semicolon
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_double: // double
      case symbol_kind::S_bool: // bool
      case symbol_kind::S_string_kw: // string_kw
      case symbol_kind::S_openclosebracket: // openclosebracket
      case symbol_kind::S_openbracket: // openbracket
      case symbol_kind::S_closebracket: // closebracket
      case symbol_kind::S_private: // private
      case symbol_kind::S_public: // public
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_for: // for
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_void: // void
      case symbol_kind::S_int: // int
      case symbol_kind::S_class: // class
      case symbol_kind::S_nullkw: // nullkw
      case symbol_kind::S_slash: // slash
      case symbol_kind::S_percent: // percent
      case symbol_kind::S_return: // return
      case symbol_kind::S_break: // break
      case symbol_kind::S_new: // new
      case symbol_kind::S_this: // this
      case symbol_kind::S_newarray: // newarray
      case symbol_kind::S_print: // print
      case symbol_kind::S_readinteger: // readinteger
      case symbol_kind::S_readline: // readline
      case symbol_kind::S_line: // line
      case symbol_kind::S_func: // func
      case symbol_kind::S_btoi: // btoi
      case symbol_kind::S_continue: // continue
      case symbol_kind::S_dtoi: // dtoi
      case symbol_kind::S_itob: // itob
      case symbol_kind::S_itod: // itod
      case symbol_kind::S_float: // float
      case symbol_kind::S_plus: // plus
      case symbol_kind::S_minus: // minus
      case symbol_kind::S_star: // star
      case symbol_kind::S_div: // div
      case symbol_kind::S_lessthanequal: // lessthanequal
      case symbol_kind::S_greaterthanequal: // greaterthanequal
      case symbol_kind::S_lessthan: // lessthan
      case symbol_kind::S_greaterthan: // greaterthan
      case symbol_kind::S_equal: // equal
      case symbol_kind::S_notequal: // notequal
      case symbol_kind::S_and: // and
      case symbol_kind::S_or: // or
      case symbol_kind::S_closebrace: // closebrace
      case symbol_kind::S_openparantheses: // openparantheses
      case symbol_kind::S_closeparantheses: // closeparantheses
      case symbol_kind::S_comma: // comma
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_openbrace: // openbrace
      case symbol_kind::S_plusequal: // plusequal
      case symbol_kind::S_minusequal: // minusequal
      case symbol_kind::S_starequal: // starequal
      case symbol_kind::S_slashequal: // slashequal
      case symbol_kind::S_not: // not
      case symbol_kind::S_dot: // dot
      case symbol_kind::S_program: // program
      case symbol_kind::S_macro: // macro
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_variabledecl: // variabledecl
      case symbol_kind::S_type: // type
      case symbol_kind::S_functiondecl: // functiondecl
      case symbol_kind::S_classdecl: // classdecl
      case symbol_kind::S_fields: // fields
      case symbol_kind::S_field: // field
      case symbol_kind::S_accessmode: // accessmode
      case symbol_kind::S_stmtblock: // stmtblock
      case symbol_kind::S_stmtblockcontent: // stmtblockcontent
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_ifstmt: // ifstmt
      case symbol_kind::S_elsestmt: // elsestmt
      case symbol_kind::S_whilestmt: // whilestmt
      case symbol_kind::S_forstmt: // forstmt
      case symbol_kind::S_returnstmt: // returnstmt
      case symbol_kind::S_breakstmt: // breakstmt
      case symbol_kind::S_nexpr: // nexpr
      case symbol_kind::S_continuestmt: // continuestmt
      case symbol_kind::S_printstmt: // printstmt
      case symbol_kind::S_printcontent: // printcontent
      case symbol_kind::S_lvalue: // lvalue
      case symbol_kind::S_call: // call
      case symbol_kind::S_actuals: // actuals
      case symbol_kind::S_actualscontent: // actualscontent
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.move< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.copy< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
      case symbol_kind::S_define: // define
      case symbol_kind::S_import: // import
      case symbol_kind::S_semicolon: // semicolon
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_double: // double
      case symbol_kind::S_bool: // bool
      case symbol_kind::S_string_kw: // string_kw
      case symbol_kind::S_openclosebracket: // openclosebracket
      case symbol_kind::S_openbracket: // openbracket
      case symbol_kind::S_closebracket: // closebracket
      case symbol_kind::S_private: // private
      case symbol_kind::S_public: // public
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_for: // for
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_void: // void
      case symbol_kind::S_int: // int
      case symbol_kind::S_class: // class
      case symbol_kind::S_nullkw: // nullkw
      case symbol_kind::S_slash: // slash
      case symbol_kind::S_percent: // percent
      case symbol_kind::S_return: // return
      case symbol_kind::S_break: // break
      case symbol_kind::S_new: // new
      case symbol_kind::S_this: // this
      case symbol_kind::S_newarray: // newarray
      case symbol_kind::S_print: // print
      case symbol_kind::S_readinteger: // readinteger
      case symbol_kind::S_readline: // readline
      case symbol_kind::S_line: // line
      case symbol_kind::S_func: // func
      case symbol_kind::S_btoi: // btoi
      case symbol_kind::S_continue: // continue
      case symbol_kind::S_dtoi: // dtoi
      case symbol_kind::S_itob: // itob
      case symbol_kind::S_itod: // itod
      case symbol_kind::S_float: // float
      case symbol_kind::S_plus: // plus
      case symbol_kind::S_minus: // minus
      case symbol_kind::S_star: // star
      case symbol_kind::S_div: // div
      case symbol_kind::S_lessthanequal: // lessthanequal
      case symbol_kind::S_greaterthanequal: // greaterthanequal
      case symbol_kind::S_lessthan: // lessthan
      case symbol_kind::S_greaterthan: // greaterthan
      case symbol_kind::S_equal: // equal
      case symbol_kind::S_notequal: // notequal
      case symbol_kind::S_and: // and
      case symbol_kind::S_or: // or
      case symbol_kind::S_closebrace: // closebrace
      case symbol_kind::S_openparantheses: // openparantheses
      case symbol_kind::S_closeparantheses: // closeparantheses
      case symbol_kind::S_comma: // comma
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_openbrace: // openbrace
      case symbol_kind::S_plusequal: // plusequal
      case symbol_kind::S_minusequal: // minusequal
      case symbol_kind::S_starequal: // starequal
      case symbol_kind::S_slashequal: // slashequal
      case symbol_kind::S_not: // not
      case symbol_kind::S_dot: // dot
      case symbol_kind::S_program: // program
      case symbol_kind::S_macro: // macro
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_variabledecl: // variabledecl
      case symbol_kind::S_type: // type
      case symbol_kind::S_functiondecl: // functiondecl
      case symbol_kind::S_classdecl: // classdecl
      case symbol_kind::S_fields: // fields
      case symbol_kind::S_field: // field
      case symbol_kind::S_accessmode: // accessmode
      case symbol_kind::S_stmtblock: // stmtblock
      case symbol_kind::S_stmtblockcontent: // stmtblockcontent
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_ifstmt: // ifstmt
      case symbol_kind::S_elsestmt: // elsestmt
      case symbol_kind::S_whilestmt: // whilestmt
      case symbol_kind::S_forstmt: // forstmt
      case symbol_kind::S_returnstmt: // returnstmt
      case symbol_kind::S_breakstmt: // breakstmt
      case symbol_kind::S_nexpr: // nexpr
      case symbol_kind::S_continuestmt: // continuestmt
      case symbol_kind::S_printstmt: // printstmt
      case symbol_kind::S_printcontent: // printcontent
      case symbol_kind::S_lvalue: // lvalue
      case symbol_kind::S_call: // call
      case symbol_kind::S_actuals: // actuals
      case symbol_kind::S_actualscontent: // actualscontent
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.copy< std::vector<std::pair<std::string,std::string>> > (that.value);
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
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.move< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
      case symbol_kind::S_define: // define
      case symbol_kind::S_import: // import
      case symbol_kind::S_semicolon: // semicolon
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_double: // double
      case symbol_kind::S_bool: // bool
      case symbol_kind::S_string_kw: // string_kw
      case symbol_kind::S_openclosebracket: // openclosebracket
      case symbol_kind::S_openbracket: // openbracket
      case symbol_kind::S_closebracket: // closebracket
      case symbol_kind::S_private: // private
      case symbol_kind::S_public: // public
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_for: // for
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_void: // void
      case symbol_kind::S_int: // int
      case symbol_kind::S_class: // class
      case symbol_kind::S_nullkw: // nullkw
      case symbol_kind::S_slash: // slash
      case symbol_kind::S_percent: // percent
      case symbol_kind::S_return: // return
      case symbol_kind::S_break: // break
      case symbol_kind::S_new: // new
      case symbol_kind::S_this: // this
      case symbol_kind::S_newarray: // newarray
      case symbol_kind::S_print: // print
      case symbol_kind::S_readinteger: // readinteger
      case symbol_kind::S_readline: // readline
      case symbol_kind::S_line: // line
      case symbol_kind::S_func: // func
      case symbol_kind::S_btoi: // btoi
      case symbol_kind::S_continue: // continue
      case symbol_kind::S_dtoi: // dtoi
      case symbol_kind::S_itob: // itob
      case symbol_kind::S_itod: // itod
      case symbol_kind::S_float: // float
      case symbol_kind::S_plus: // plus
      case symbol_kind::S_minus: // minus
      case symbol_kind::S_star: // star
      case symbol_kind::S_div: // div
      case symbol_kind::S_lessthanequal: // lessthanequal
      case symbol_kind::S_greaterthanequal: // greaterthanequal
      case symbol_kind::S_lessthan: // lessthan
      case symbol_kind::S_greaterthan: // greaterthan
      case symbol_kind::S_equal: // equal
      case symbol_kind::S_notequal: // notequal
      case symbol_kind::S_and: // and
      case symbol_kind::S_or: // or
      case symbol_kind::S_closebrace: // closebrace
      case symbol_kind::S_openparantheses: // openparantheses
      case symbol_kind::S_closeparantheses: // closeparantheses
      case symbol_kind::S_comma: // comma
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_openbrace: // openbrace
      case symbol_kind::S_plusequal: // plusequal
      case symbol_kind::S_minusequal: // minusequal
      case symbol_kind::S_starequal: // starequal
      case symbol_kind::S_slashequal: // slashequal
      case symbol_kind::S_not: // not
      case symbol_kind::S_dot: // dot
      case symbol_kind::S_program: // program
      case symbol_kind::S_macro: // macro
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_variabledecl: // variabledecl
      case symbol_kind::S_type: // type
      case symbol_kind::S_functiondecl: // functiondecl
      case symbol_kind::S_classdecl: // classdecl
      case symbol_kind::S_fields: // fields
      case symbol_kind::S_field: // field
      case symbol_kind::S_accessmode: // accessmode
      case symbol_kind::S_stmtblock: // stmtblock
      case symbol_kind::S_stmtblockcontent: // stmtblockcontent
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_ifstmt: // ifstmt
      case symbol_kind::S_elsestmt: // elsestmt
      case symbol_kind::S_whilestmt: // whilestmt
      case symbol_kind::S_forstmt: // forstmt
      case symbol_kind::S_returnstmt: // returnstmt
      case symbol_kind::S_breakstmt: // breakstmt
      case symbol_kind::S_nexpr: // nexpr
      case symbol_kind::S_continuestmt: // continuestmt
      case symbol_kind::S_printstmt: // printstmt
      case symbol_kind::S_printcontent: // printcontent
      case symbol_kind::S_lvalue: // lvalue
      case symbol_kind::S_call: // call
      case symbol_kind::S_actuals: // actuals
      case symbol_kind::S_actualscontent: // actualscontent
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.move< std::vector<std::pair<std::string,std::string>> > (that.value);
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
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< std::pair<std::string,std::string> > ();
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
      case symbol_kind::S_define: // define
      case symbol_kind::S_import: // import
      case symbol_kind::S_semicolon: // semicolon
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_double: // double
      case symbol_kind::S_bool: // bool
      case symbol_kind::S_string_kw: // string_kw
      case symbol_kind::S_openclosebracket: // openclosebracket
      case symbol_kind::S_openbracket: // openbracket
      case symbol_kind::S_closebracket: // closebracket
      case symbol_kind::S_private: // private
      case symbol_kind::S_public: // public
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_for: // for
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_void: // void
      case symbol_kind::S_int: // int
      case symbol_kind::S_class: // class
      case symbol_kind::S_nullkw: // nullkw
      case symbol_kind::S_slash: // slash
      case symbol_kind::S_percent: // percent
      case symbol_kind::S_return: // return
      case symbol_kind::S_break: // break
      case symbol_kind::S_new: // new
      case symbol_kind::S_this: // this
      case symbol_kind::S_newarray: // newarray
      case symbol_kind::S_print: // print
      case symbol_kind::S_readinteger: // readinteger
      case symbol_kind::S_readline: // readline
      case symbol_kind::S_line: // line
      case symbol_kind::S_func: // func
      case symbol_kind::S_btoi: // btoi
      case symbol_kind::S_continue: // continue
      case symbol_kind::S_dtoi: // dtoi
      case symbol_kind::S_itob: // itob
      case symbol_kind::S_itod: // itod
      case symbol_kind::S_float: // float
      case symbol_kind::S_plus: // plus
      case symbol_kind::S_minus: // minus
      case symbol_kind::S_star: // star
      case symbol_kind::S_div: // div
      case symbol_kind::S_lessthanequal: // lessthanequal
      case symbol_kind::S_greaterthanequal: // greaterthanequal
      case symbol_kind::S_lessthan: // lessthan
      case symbol_kind::S_greaterthan: // greaterthan
      case symbol_kind::S_equal: // equal
      case symbol_kind::S_notequal: // notequal
      case symbol_kind::S_and: // and
      case symbol_kind::S_or: // or
      case symbol_kind::S_closebrace: // closebrace
      case symbol_kind::S_openparantheses: // openparantheses
      case symbol_kind::S_closeparantheses: // closeparantheses
      case symbol_kind::S_comma: // comma
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_openbrace: // openbrace
      case symbol_kind::S_plusequal: // plusequal
      case symbol_kind::S_minusequal: // minusequal
      case symbol_kind::S_starequal: // starequal
      case symbol_kind::S_slashequal: // slashequal
      case symbol_kind::S_not: // not
      case symbol_kind::S_dot: // dot
      case symbol_kind::S_program: // program
      case symbol_kind::S_macro: // macro
      case symbol_kind::S_declarations: // declarations
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_variabledecl: // variabledecl
      case symbol_kind::S_type: // type
      case symbol_kind::S_functiondecl: // functiondecl
      case symbol_kind::S_classdecl: // classdecl
      case symbol_kind::S_fields: // fields
      case symbol_kind::S_field: // field
      case symbol_kind::S_accessmode: // accessmode
      case symbol_kind::S_stmtblock: // stmtblock
      case symbol_kind::S_stmtblockcontent: // stmtblockcontent
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_ifstmt: // ifstmt
      case symbol_kind::S_elsestmt: // elsestmt
      case symbol_kind::S_whilestmt: // whilestmt
      case symbol_kind::S_forstmt: // forstmt
      case symbol_kind::S_returnstmt: // returnstmt
      case symbol_kind::S_breakstmt: // breakstmt
      case symbol_kind::S_nexpr: // nexpr
      case symbol_kind::S_continuestmt: // continuestmt
      case symbol_kind::S_printstmt: // printstmt
      case symbol_kind::S_printcontent: // printcontent
      case symbol_kind::S_lvalue: // lvalue
      case symbol_kind::S_call: // call
      case symbol_kind::S_actuals: // actuals
      case symbol_kind::S_actualscontent: // actualscontent
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        yylhs.value.emplace< std::vector<std::pair<std::string,std::string>> > ();
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
  case 2: // sp: program
#line 64 "parser.yy"
            { cg.writestuff(); }
#line 1094 "src/parser.cc"
    break;

  case 3: // program: macro program
#line 66 "parser.yy"
                       { }
#line 1100 "src/parser.cc"
    break;

  case 4: // program: declarations
#line 67 "parser.yy"
                      { }
#line 1106 "src/parser.cc"
    break;

  case 5: // macro: import string
#line 69 "parser.yy"
                     { }
#line 1112 "src/parser.cc"
    break;

  case 6: // macro: define id id
#line 70 "parser.yy"
                    { }
#line 1118 "src/parser.cc"
    break;

  case 7: // declarations: declaration declarations
#line 72 "parser.yy"
                                       { }
#line 1124 "src/parser.cc"
    break;

  case 8: // declarations: declaration
#line 73 "parser.yy"
                          {  }
#line 1130 "src/parser.cc"
    break;

  case 9: // declaration: variabledecl
#line 75 "parser.yy"
                          { }
#line 1136 "src/parser.cc"
    break;

  case 10: // declaration: functiondecl
#line 76 "parser.yy"
                          { }
#line 1142 "src/parser.cc"
    break;

  case 11: // declaration: classdecl
#line 77 "parser.yy"
                       { }
#line 1148 "src/parser.cc"
    break;

  case 12: // variabledecl: variable semicolon
#line 79 "parser.yy"
                                 { }
#line 1154 "src/parser.cc"
    break;

  case 13: // variable: type id
#line 81 "parser.yy"
                  { cg.variable(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()}; }
#line 1160 "src/parser.cc"
    break;

  case 14: // type: int
#line 83 "parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1166 "src/parser.cc"
    break;

  case 15: // type: double
#line 84 "parser.yy"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1172 "src/parser.cc"
    break;

  case 16: // type: bool
#line 85 "parser.yy"
           { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1178 "src/parser.cc"
    break;

  case 17: // type: string_kw
#line 86 "parser.yy"
                {  yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1184 "src/parser.cc"
    break;

  case 18: // type: id
#line 87 "parser.yy"
         {  yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1190 "src/parser.cc"
    break;

  case 19: // type: type openclosebracket
#line 88 "parser.yy"
                            {  yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 1196 "src/parser.cc"
    break;

  case 20: // $@1: %empty
#line 90 "parser.yy"
                                                               { cg.addfunction(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::pair<std::string,std::string>> > ()); }
#line 1202 "src/parser.cc"
    break;

  case 21: // functiondecl: type id openparantheses formals closeparantheses $@1 stmtblock
#line 90 "parser.yy"
                                                                                                    { cg.endfunction(); }
#line 1208 "src/parser.cc"
    break;

  case 22: // $@2: %empty
#line 91 "parser.yy"
                                                               { cg.addfunction(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::pair<std::string,std::string>> > ()); }
#line 1214 "src/parser.cc"
    break;

  case 23: // functiondecl: void id openparantheses formals closeparantheses $@2 stmtblock
#line 91 "parser.yy"
                                                                                                    { cg.endfunction(); }
#line 1220 "src/parser.cc"
    break;

  case 24: // formals: formalsp
#line 93 "parser.yy"
                  {  yylhs.value.as < std::vector<std::pair<std::string,std::string>> > () = yystack_[0].value.as < std::vector<std::pair<std::string,std::string>> > (); }
#line 1226 "src/parser.cc"
    break;

  case 25: // formals: %empty
#line 94 "parser.yy"
                {  }
#line 1232 "src/parser.cc"
    break;

  case 26: // formalsp: variable comma formalsp
#line 96 "parser.yy"
                                  { yystack_[0].value.as < std::vector<std::pair<std::string,std::string>> > ().push_back(yystack_[2].value.as < std::pair<std::string,std::string> > ()); yylhs.value.as < std::vector<std::pair<std::string,std::string>> > () = yystack_[0].value.as < std::vector<std::pair<std::string,std::string>> > (); }
#line 1238 "src/parser.cc"
    break;

  case 27: // formalsp: variable
#line 97 "parser.yy"
                   { yylhs.value.as < std::vector<std::pair<std::string,std::string>> > () = {yystack_[0].value.as < std::pair<std::string,std::string> > ()}; }
#line 1244 "src/parser.cc"
    break;

  case 28: // classdecl: class id openbrace fields closebrace
#line 99 "parser.yy"
                                                {  }
#line 1250 "src/parser.cc"
    break;

  case 29: // fields: field fields
#line 101 "parser.yy"
                     { }
#line 1256 "src/parser.cc"
    break;

  case 30: // fields: %empty
#line 102 "parser.yy"
               { }
#line 1262 "src/parser.cc"
    break;

  case 31: // field: accessmode variabledecl
#line 104 "parser.yy"
                               { }
#line 1268 "src/parser.cc"
    break;

  case 32: // field: accessmode functiondecl
#line 105 "parser.yy"
                               { }
#line 1274 "src/parser.cc"
    break;

  case 33: // accessmode: private
#line 107 "parser.yy"
                    { }
#line 1280 "src/parser.cc"
    break;

  case 34: // accessmode: public
#line 108 "parser.yy"
                   { }
#line 1286 "src/parser.cc"
    break;

  case 35: // accessmode: %empty
#line 109 "parser.yy"
                   { }
#line 1292 "src/parser.cc"
    break;

  case 36: // $@3: %empty
#line 111 "parser.yy"
                     { cg.openstmtblock(); }
#line 1298 "src/parser.cc"
    break;

  case 37: // stmtblock: openbrace $@3 stmtblockcontent closebrace
#line 111 "parser.yy"
                                                                         { cg.closestmtblock(); }
#line 1304 "src/parser.cc"
    break;

  case 38: // stmtblockcontent: variabledecl stmtblockcontent
#line 113 "parser.yy"
                                                { }
#line 1310 "src/parser.cc"
    break;

  case 39: // stmtblockcontent: statements
#line 114 "parser.yy"
                             { }
#line 1316 "src/parser.cc"
    break;

  case 40: // statements: %empty
#line 116 "parser.yy"
                   { }
#line 1322 "src/parser.cc"
    break;

  case 41: // statements: stmt statements
#line 117 "parser.yy"
                            { }
#line 1328 "src/parser.cc"
    break;

  case 42: // stmt: expr semicolon
#line 119 "parser.yy"
                     { }
#line 1334 "src/parser.cc"
    break;

  case 43: // stmt: semicolon
#line 120 "parser.yy"
                     { }
#line 1340 "src/parser.cc"
    break;

  case 44: // stmt: ifstmt
#line 121 "parser.yy"
                  { }
#line 1346 "src/parser.cc"
    break;

  case 45: // stmt: whilestmt
#line 122 "parser.yy"
                     { }
#line 1352 "src/parser.cc"
    break;

  case 46: // stmt: forstmt
#line 123 "parser.yy"
                   { }
#line 1358 "src/parser.cc"
    break;

  case 47: // stmt: breakstmt
#line 124 "parser.yy"
                     { }
#line 1364 "src/parser.cc"
    break;

  case 48: // stmt: continuestmt
#line 125 "parser.yy"
                        { }
#line 1370 "src/parser.cc"
    break;

  case 49: // stmt: returnstmt
#line 126 "parser.yy"
                      { }
#line 1376 "src/parser.cc"
    break;

  case 50: // stmt: printstmt
#line 127 "parser.yy"
                     { }
#line 1382 "src/parser.cc"
    break;

  case 51: // stmt: stmtblock
#line 128 "parser.yy"
                     { }
#line 1388 "src/parser.cc"
    break;

  case 52: // $@4: %empty
#line 132 "parser.yy"
                                                { cg.ifstmt(yystack_[1].value.as < std::pair<std::string,std::string> > ()); }
#line 1394 "src/parser.cc"
    break;

  case 53: // ifstmt: if openparantheses expr closeparantheses $@4 stmt elsestmt
#line 132 "parser.yy"
                                                                                 { }
#line 1400 "src/parser.cc"
    break;

  case 54: // $@5: %empty
#line 134 "parser.yy"
               { cg.elselabel(); }
#line 1406 "src/parser.cc"
    break;

  case 55: // elsestmt: else $@5 stmt
#line 134 "parser.yy"
                                        { cg.endelse(); }
#line 1412 "src/parser.cc"
    break;

  case 56: // elsestmt: %empty
#line 135 "parser.yy"
                 { cg.endiflabel(); }
#line 1418 "src/parser.cc"
    break;

  case 57: // $@6: %empty
#line 137 "parser.yy"
                                 { cg.whilestmt1(); }
#line 1424 "src/parser.cc"
    break;

  case 58: // $@7: %empty
#line 137 "parser.yy"
                                                                            { cg.whilestmt2(yystack_[1].value.as < std::pair<std::string,std::string> > ()); }
#line 1430 "src/parser.cc"
    break;

  case 59: // whilestmt: while openparantheses $@6 expr closeparantheses $@7 stmt
#line 137 "parser.yy"
                                                                                                        { cg.whilestmt3(); }
#line 1436 "src/parser.cc"
    break;

  case 60: // $@8: %empty
#line 139 "parser.yy"
                                    { cg.beginfor(); }
#line 1442 "src/parser.cc"
    break;

  case 61: // $@9: %empty
#line 139 "parser.yy"
                                                                      { cg.forloopcond(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1448 "src/parser.cc"
    break;

  case 62: // $@10: %empty
#line 139 "parser.yy"
                                                                                                              { cg.endsecnexpr(); }
#line 1454 "src/parser.cc"
    break;

  case 63: // forstmt: for openparantheses nexpr $@8 semicolon expr $@9 semicolon nexpr $@10 closeparantheses stmt
#line 139 "parser.yy"
                                                                                                                                                          { cg.endforstmt(); }
#line 1460 "src/parser.cc"
    break;

  case 64: // returnstmt: return nexpr semicolon
#line 141 "parser.yy"
                                   { }
#line 1466 "src/parser.cc"
    break;

  case 65: // breakstmt: break semicolon
#line 143 "parser.yy"
                           { cg.breakstmt(); }
#line 1472 "src/parser.cc"
    break;

  case 66: // nexpr: expr
#line 145 "parser.yy"
            { }
#line 1478 "src/parser.cc"
    break;

  case 67: // nexpr: %empty
#line 146 "parser.yy"
             { }
#line 1484 "src/parser.cc"
    break;

  case 68: // continuestmt: continue semicolon
#line 148 "parser.yy"
                                 {  }
#line 1490 "src/parser.cc"
    break;

  case 69: // printstmt: print openparantheses printcontent closeparantheses semicolon
#line 152 "parser.yy"
                                                                       { cg.printnewline(); }
#line 1496 "src/parser.cc"
    break;

  case 70: // printcontent: printcontent comma expr
#line 155 "parser.yy"
                                      { cg.printexpr(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1502 "src/parser.cc"
    break;

  case 71: // printcontent: expr
#line 156 "parser.yy"
                   { cg.printexpr(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1508 "src/parser.cc"
    break;

  case 72: // expr: constant
#line 171 "parser.yy"
                                    { yylhs.value.as < std::pair<std::string,std::string> > () = cg.addconstant(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1514 "src/parser.cc"
    break;

  case 73: // expr: lvalue
#line 172 "parser.yy"
                                    { yylhs.value.as < std::pair<std::string,std::string> > () = cg.findid(yystack_[0].value.as < std::string > ()); }
#line 1520 "src/parser.cc"
    break;

  case 74: // expr: this
#line 173 "parser.yy"
                                    {}
#line 1526 "src/parser.cc"
    break;

  case 75: // expr: call
#line 174 "parser.yy"
                                    {}
#line 1532 "src/parser.cc"
    break;

  case 76: // expr: readinteger openparantheses closeparantheses
#line 175 "parser.yy"
                                                                  { yylhs.value.as < std::pair<std::string,std::string> > () = cg.readinteger(); }
#line 1538 "src/parser.cc"
    break;

  case 77: // expr: readline openparantheses closeparantheses
#line 176 "parser.yy"
                                                                   {}
#line 1544 "src/parser.cc"
    break;

  case 78: // expr: new id
#line 177 "parser.yy"
                                 {}
#line 1550 "src/parser.cc"
    break;

  case 79: // expr: newarray openparantheses expr comma type closeparantheses
#line 178 "parser.yy"
                                                                      {}
#line 1556 "src/parser.cc"
    break;

  case 80: // expr: itod openparantheses expr closeparantheses
#line 179 "parser.yy"
                                                            {}
#line 1562 "src/parser.cc"
    break;

  case 81: // expr: dtoi openparantheses expr closeparantheses
#line 180 "parser.yy"
                                                            {}
#line 1568 "src/parser.cc"
    break;

  case 82: // expr: itob openparantheses expr closeparantheses
#line 181 "parser.yy"
                                                            { yylhs.value.as < std::pair<std::string,std::string> > () = cg.itob(yystack_[1].value.as < std::pair<std::string,std::string> > ()); }
#line 1574 "src/parser.cc"
    break;

  case 83: // expr: btoi openparantheses expr closeparantheses
#line 182 "parser.yy"
                                                            {}
#line 1580 "src/parser.cc"
    break;

  case 84: // expr: line
#line 183 "parser.yy"
                                {}
#line 1586 "src/parser.cc"
    break;

  case 85: // expr: func
#line 184 "parser.yy"
                                {}
#line 1592 "src/parser.cc"
    break;

  case 86: // expr: lvalue assign expr
#line 185 "parser.yy"
                                         { yylhs.value.as < std::pair<std::string,std::string> > () = cg.assignexpr(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1598 "src/parser.cc"
    break;

  case 87: // expr: lvalue plusequal expr
#line 186 "parser.yy"
                                          { yylhs.value.as < std::pair<std::string,std::string> > () = cg.assignexproperation(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1604 "src/parser.cc"
    break;

  case 88: // expr: lvalue minusequal expr
#line 187 "parser.yy"
                                           { yylhs.value.as < std::pair<std::string,std::string> > () = cg.assignexproperation(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1610 "src/parser.cc"
    break;

  case 89: // expr: lvalue starequal expr
#line 188 "parser.yy"
                                          { yylhs.value.as < std::pair<std::string,std::string> > () = cg.assignexproperation(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1616 "src/parser.cc"
    break;

  case 90: // expr: lvalue slashequal expr
#line 189 "parser.yy"
                                           { yylhs.value.as < std::pair<std::string,std::string> > () = cg.assignexproperation(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1622 "src/parser.cc"
    break;

  case 91: // expr: expr or expr
#line 190 "parser.yy"
                                    { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1628 "src/parser.cc"
    break;

  case 92: // expr: expr and expr
#line 191 "parser.yy"
                                     { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1634 "src/parser.cc"
    break;

  case 93: // expr: expr equal expr
#line 192 "parser.yy"
                                       { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1640 "src/parser.cc"
    break;

  case 94: // expr: expr notequal expr
#line 193 "parser.yy"
                                          { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1646 "src/parser.cc"
    break;

  case 95: // expr: expr lessthan expr
#line 194 "parser.yy"
                                           { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1652 "src/parser.cc"
    break;

  case 96: // expr: expr lessthanequal expr
#line 195 "parser.yy"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1658 "src/parser.cc"
    break;

  case 97: // expr: expr greaterthan expr
#line 196 "parser.yy"
                                              { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1664 "src/parser.cc"
    break;

  case 98: // expr: expr greaterthanequal expr
#line 197 "parser.yy"
                                                  { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1670 "src/parser.cc"
    break;

  case 99: // expr: expr plus expr
#line 198 "parser.yy"
                                       { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1676 "src/parser.cc"
    break;

  case 100: // expr: expr minus expr
#line 199 "parser.yy"
                                        { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1682 "src/parser.cc"
    break;

  case 101: // expr: expr star expr
#line 200 "parser.yy"
                                       { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1688 "src/parser.cc"
    break;

  case 102: // expr: expr slash expr
#line 201 "parser.yy"
                                        { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1694 "src/parser.cc"
    break;

  case 103: // expr: expr percent expr
#line 202 "parser.yy"
                                          { yylhs.value.as < std::pair<std::string,std::string> > () = cg.exproperation(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),yystack_[1].value.as < std::string > ()); }
#line 1700 "src/parser.cc"
    break;

  case 104: // expr: minus expr
#line 203 "parser.yy"
                                        { yylhs.value.as < std::pair<std::string,std::string> > () = cg.unaryminus(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1706 "src/parser.cc"
    break;

  case 105: // expr: not expr
#line 204 "parser.yy"
                                      { yylhs.value.as < std::pair<std::string,std::string> > () = cg.unarynot(yystack_[0].value.as < std::pair<std::string,std::string> > ()); }
#line 1712 "src/parser.cc"
    break;

  case 106: // expr: openparantheses expr closeparantheses
#line 205 "parser.yy"
                                                                   { yylhs.value.as < std::pair<std::string,std::string> > () = yystack_[1].value.as < std::pair<std::string,std::string> > (); }
#line 1718 "src/parser.cc"
    break;

  case 107: // lvalue: id
#line 208 "parser.yy"
                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1724 "src/parser.cc"
    break;

  case 108: // lvalue: expr dot id
#line 209 "parser.yy"
                                     {}
#line 1730 "src/parser.cc"
    break;

  case 109: // lvalue: expr openbracket expr closebracket
#line 210 "parser.yy"
                                                         {}
#line 1736 "src/parser.cc"
    break;

  case 110: // call: id openparantheses actuals closeparantheses
#line 213 "parser.yy"
                                                               {}
#line 1742 "src/parser.cc"
    break;

  case 111: // call: expr dot id openparantheses actuals closeparantheses
#line 214 "parser.yy"
                                                                   {}
#line 1748 "src/parser.cc"
    break;

  case 112: // actuals: actualscontent
#line 217 "parser.yy"
                                          {}
#line 1754 "src/parser.cc"
    break;

  case 113: // actuals: %empty
#line 218 "parser.yy"
                                    {}
#line 1760 "src/parser.cc"
    break;

  case 114: // actualscontent: expr comma actualscontent
#line 221 "parser.yy"
                                  {}
#line 1766 "src/parser.cc"
    break;

  case 115: // actualscontent: expr
#line 222 "parser.yy"
               { }
#line 1772 "src/parser.cc"
    break;

  case 116: // constant: integer
#line 225 "parser.yy"
                                { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[0].value.as < std::string > (),"int"}; }
#line 1778 "src/parser.cc"
    break;

  case 117: // constant: float
#line 226 "parser.yy"
                           { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[0].value.as < std::string > (),"double"}; }
#line 1784 "src/parser.cc"
    break;

  case 118: // constant: boolean
#line 227 "parser.yy"
                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[0].value.as < std::string > (),"bool"}; }
#line 1790 "src/parser.cc"
    break;

  case 119: // constant: string
#line 228 "parser.yy"
                            { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[0].value.as < std::string > (),"string"}; }
#line 1796 "src/parser.cc"
    break;

  case 120: // constant: nullkw
#line 229 "parser.yy"
                                      {}
#line 1802 "src/parser.cc"
    break;


#line 1806 "src/parser.cc"

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
  "minusequal", "starequal", "slashequal", "not", "dot", "$accept", "sp",
  "program", "macro", "declarations", "declaration", "variabledecl",
  "variable", "type", "functiondecl", "$@1", "$@2", "formals", "formalsp",
  "classdecl", "fields", "field", "accessmode", "stmtblock", "$@3",
  "stmtblockcontent", "statements", "stmt", "ifstmt", "$@4", "elsestmt",
  "$@5", "whilestmt", "$@6", "$@7", "forstmt", "$@8", "$@9", "$@10",
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


  const signed char parser::yypact_ninf_ = -105;

  const signed char parser::yytable_ninf_ = -31;

  const short
  parser::yypact_[] =
  {
      81,  -105,     2,     4,  -105,  -105,  -105,    10,  -105,    12,
      20,  -105,    81,  -105,    85,  -105,    16,    13,  -105,  -105,
      25,  -105,   -24,   -13,  -105,  -105,  -105,  -105,    -1,  -105,
    -105,   113,    -9,   113,    23,    90,    31,  -105,  -105,  -105,
      45,    -9,    21,    39,   113,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,    51,    51,  -105,  -105,  -105,   134,    26,
    -105,  -105,  -105,    58,    60,    63,  -105,  -105,   220,   114,
     123,  -105,    70,    71,    72,    73,  -105,  -105,    75,   126,
      77,    82,    83,  -105,   220,   220,   220,   134,  -105,    91,
    -105,   177,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   246,
     167,  -105,  -105,   220,   220,  -105,   220,    89,   141,   589,
    -105,  -105,   220,   220,    94,    98,   220,  -105,   220,   220,
     220,     8,   276,   -10,  -105,  -105,  -105,  -105,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   146,   220,   220,   220,   220,   220,   306,   100,
    -105,   336,   220,  -105,  -105,   366,    41,   589,  -105,  -105,
     396,   426,   456,   486,  -105,   529,   -10,   -10,     8,     8,
     -10,    14,    14,    14,    14,   520,   520,   648,   619,   103,
     589,   589,   589,   589,   589,   220,  -105,  -105,   559,   154,
     113,   171,   220,  -105,  -105,  -105,  -105,  -105,   220,  -105,
     177,  -105,   220,    -8,  -105,   589,   124,   165,   177,   589,
    -105,  -105,  -105,  -105,  -105,   179,   177,   220,  -105,  -105,
     129,   177,  -105
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    18,     0,     0,    15,    16,    17,     0,    14,     0,
       0,     2,     0,     4,     8,     9,     0,     0,    10,    11,
       0,     5,     0,     0,     1,     3,     7,    12,    13,    19,
       6,    25,    35,    25,    27,     0,     0,    24,    33,    34,
       0,    35,     0,     0,     0,    13,    22,    28,    29,    31,
      32,    20,    26,     0,     0,    36,    23,    21,    40,   107,
     119,    43,   116,     0,     0,     0,   118,   120,    67,     0,
       0,    74,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,   117,     0,     0,     0,    40,    51,     0,
      39,    40,    44,    45,    46,    49,    47,    48,    50,     0,
      73,    75,    72,   113,     0,    57,    67,   107,     0,    66,
      65,    78,     0,     0,     0,     0,     0,    68,     0,     0,
       0,   104,     0,   105,    38,    37,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
     112,     0,     0,    60,    64,     0,     0,    71,    76,    77,
       0,     0,     0,     0,   106,     0,   102,   103,    99,   100,
     101,    96,    98,    95,    97,    93,    94,    92,    91,   108,
      86,    87,    88,    89,    90,     0,   110,    52,     0,     0,
       0,     0,     0,    83,    81,    82,    80,   109,   113,   114,
       0,    58,     0,     0,    69,    70,     0,    56,     0,    61,
      79,   111,    54,    53,    59,     0,     0,    67,    55,    62,
       0,     0,    63
  };

  const short
  parser::yypgoto_[] =
  {
    -105,  -105,   176,  -105,   175,  -105,   -32,   -22,     0,   150,
    -105,  -105,   160,   155,  -105,   162,  -105,  -105,    57,  -105,
     117,   110,  -102,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -104,  -105,  -105,  -105,
     -67,  -105,  -105,    27,    36,  -105
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    10,    11,    12,    13,    14,    15,    16,    35,    18,
      54,    53,    36,    37,    19,    40,    41,    42,    88,    58,
      89,    90,    91,    92,   200,   213,   216,    93,   152,   208,
      94,   189,   215,   220,    95,    96,   108,    97,    98,   156,
      99,   100,   101,   149,   150,   102
  };

  const short
  parser::yytable_[] =
  {
      17,   109,   153,   128,    29,    20,    38,    39,    21,    34,
      49,    34,    17,    22,    17,    23,    28,   121,   122,   123,
      24,   128,    34,    27,     1,    29,    87,   128,    30,   -18,
       4,     5,     6,    31,   129,   130,   148,   151,   -18,   109,
     129,   130,    17,     7,     8,   155,   157,   -30,    32,   160,
     210,   161,   162,   163,   133,    87,    33,   142,   131,   132,
     133,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   142,   180,   181,   182,   183,
     184,   142,    44,   103,     1,   188,     2,     3,     1,    46,
       4,     5,     6,    45,     4,     5,     6,    51,   207,   191,
     192,    47,    29,     7,     8,     9,   214,     7,     8,     9,
      56,    57,    55,   219,   218,   104,     1,   105,   148,   222,
     106,   110,     4,     5,     6,   205,   111,   112,   113,   114,
     115,   148,   116,   117,   118,   209,     8,    59,    60,   119,
     120,    61,    62,     4,     5,     6,   103,   125,   154,   179,
     109,    63,   158,    64,    65,    66,   159,     8,   186,    67,
     198,   202,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   204,    84,
     107,    60,   211,   212,    61,    62,   217,   221,    25,    26,
     203,    85,    50,    43,    63,    55,    64,    65,    66,    52,
      86,   126,    67,    48,   124,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   199,    84,   107,    60,   206,     0,   143,    62,   144,
     145,   146,   147,     0,    85,     0,     0,     0,    55,     0,
       0,    66,     0,    86,     0,    67,     0,     0,     0,     0,
      70,    71,    72,   127,    74,    75,    76,    77,    78,   128,
      80,    81,    82,    83,     0,    84,     0,     0,     0,     0,
       0,     0,   129,   130,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,   164,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,     0,   185,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,   187,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,     0,   190,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,   193,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,   194,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,   128,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   130,   195,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
     131,   132,   133,   128,   134,   135,   136,   137,   138,   139,
     140,   141,   128,   197,   196,     0,   129,   130,     0,     0,
       0,     0,     0,   142,     0,   129,   130,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,     0,   134,   135,
     136,   137,   128,   131,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   129,   130,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,   128,   131,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   129,   130,   201,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,   128,   131,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,   128,     0,   131,   132,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,   131,   132,   133,     0,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142
  };

  const short
  parser::yycheck_[] =
  {
       0,    68,   106,    13,    12,     3,    15,    16,     4,    31,
      42,    33,    12,     3,    14,     3,     3,    84,    85,    86,
       0,    13,    44,     7,     3,    12,    58,    13,     3,     3,
       9,    10,    11,    57,    26,    27,   103,   104,    12,   106,
      26,    27,    42,    22,    23,   112,   113,    56,    61,   116,
      58,   118,   119,   120,    46,    87,    57,    67,    44,    45,
      46,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    67,   143,   144,   145,   146,
     147,    67,    59,    57,     3,   152,     5,     6,     3,    58,
       9,    10,    11,     3,     9,    10,    11,    58,   200,    58,
      59,    56,    12,    22,    23,    24,   208,    22,    23,    24,
      53,    54,    61,   217,   216,    57,     3,    57,   185,   221,
      57,     7,     9,    10,    11,   192,     3,    57,    57,    57,
      57,   198,    57,     7,    57,   202,    23,     3,     4,    57,
      57,     7,     8,     9,    10,    11,    57,    56,     7,     3,
     217,    17,    58,    19,    20,    21,    58,    23,    58,    25,
      57,     7,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     7,    45,
       3,     4,    58,    18,     7,     8,     7,    58,    12,    14,
     190,    57,    42,    33,    17,    61,    19,    20,    21,    44,
      66,    91,    25,    41,    87,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   185,    45,     3,     4,   198,    -1,    60,     8,    62,
      63,    64,    65,    -1,    57,    -1,    -1,    -1,    61,    -1,
      -1,    21,    -1,    66,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,     7,    34,    35,    36,    37,    38,    13,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    13,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    13,    48,    49,    50,    51,    52,    53,
      54,    55,    13,    14,    58,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    -1,    48,    49,
      50,    51,    13,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    26,    27,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    13,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    26,    27,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    13,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    13,    -1,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     5,     6,     9,    10,    11,    22,    23,    24,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    82,
       3,     4,     3,     3,     0,    70,    72,     7,     3,    12,
       3,    57,    61,    57,    75,    76,    80,    81,    15,    16,
      83,    84,    85,    80,    59,     3,    58,    56,    83,    74,
      77,    58,    81,    79,    78,    61,    86,    86,    87,     3,
       4,     7,     8,    17,    19,    20,    21,    25,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    45,    57,    66,    74,    86,    88,
      89,    90,    91,    95,    98,   102,   103,   105,   106,   108,
     109,   110,   113,    57,    57,    57,    57,     3,   104,   108,
       7,     3,    57,    57,    57,    57,    57,     7,    57,    57,
      57,   108,   108,   108,    88,    56,    89,     7,    13,    26,
      27,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    67,    60,    62,    63,    64,    65,   108,   111,
     112,   108,    96,   104,     7,   108,   107,   108,    58,    58,
     108,   108,   108,   108,    58,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,     3,
     108,   108,   108,   108,   108,    59,    58,    58,   108,    99,
      59,    58,    59,    58,    58,    58,    58,    14,    57,   112,
      92,    58,     7,    76,     7,   108,   111,    90,    97,   108,
      58,    58,    18,    93,    90,   100,    94,     7,    90,   104,
     101,    58,    90
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    75,    76,    76,    76,    76,    76,    76,
      78,    77,    79,    77,    80,    80,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    87,    86,    88,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    92,    91,    94,    93,    93,    96,    97,    95,
      99,   100,   101,    98,   102,   103,   104,   104,   105,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     2,
       0,     7,     0,     7,     1,     0,     3,     1,     5,     2,
       0,     2,     2,     1,     1,     0,     0,     4,     2,     1,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     7,     0,     3,     0,     0,     0,     7,
       0,     0,     0,    12,     3,     2,     1,     0,     2,     5,
       3,     1,     1,     1,     1,     1,     3,     3,     2,     6,
       4,     4,     4,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     3,     4,
       4,     6,     1,     0,     3,     1,     1,     1,     1,     1,
       1
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    64,    64,    66,    67,    69,    70,    72,    73,    75,
      76,    77,    79,    81,    83,    84,    85,    86,    87,    88,
      90,    90,    91,    91,    93,    94,    96,    97,    99,   101,
     102,   104,   105,   107,   108,   109,   111,   111,   113,   114,
     116,   117,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   132,   132,   134,   134,   135,   137,   137,   137,
     139,   139,   139,   139,   141,   143,   145,   146,   148,   152,
     155,   156,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   208,   209,   210,
     213,   214,   217,   218,   221,   222,   225,   226,   227,   228,
     229
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
#line 2626 "src/parser.cc"

#line 231 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
