// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_PARSER_HH_INCLUDED
# define YY_YY_SRC_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 11 "parser.yy"

  # include <string>
  class driver;

#line 54 "src/parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 194 "src/parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // variable
      // expr
      // constant
      char dummy1[sizeof (std::pair<std::string,std::string>)];

      // id
      // string
      // define
      // import
      // semicolon
      // integer
      // double
      // bool
      // string_kw
      // openclosebracket
      // openbracket
      // closebracket
      // private
      // public
      // if
      // else
      // while
      // for
      // boolean
      // void
      // int
      // class
      // nullkw
      // slash
      // percent
      // return
      // break
      // new
      // this
      // newarray
      // print
      // readinteger
      // readline
      // line
      // func
      // btoi
      // continue
      // dtoi
      // itob
      // itod
      // float
      // plus
      // minus
      // star
      // div
      // lessthanequal
      // greaterthanequal
      // lessthan
      // greaterthan
      // equal
      // notequal
      // and
      // or
      // closebrace
      // openparantheses
      // closeparantheses
      // comma
      // assign
      // openbrace
      // plusequal
      // minusequal
      // starequal
      // slashequal
      // not
      // dot
      // program
      // macro
      // declarations
      // declaration
      // variabledecl
      // type
      // functiondecl
      // classdecl
      // fields
      // field
      // accessmode
      // stmtblock
      // stmtblockcontent
      // statements
      // stmt
      // ifstmt
      // elsestmt
      // whilestmt
      // forstmt
      // returnstmt
      // breakstmt
      // nexpr
      // continuestmt
      // printstmt
      // printcontent
      // lvalue
      // call
      // actuals
      // actualscontent
      char dummy2[sizeof (std::string)];

      // formals
      // formalsp
      char dummy3[sizeof (std::vector<std::pair<std::string,std::string>>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_YYEOF = 0,                 // "end of file"
    TOK_YYerror = 1,               // error
    TOK_YYUNDEF = 2,               // "invalid token"
    TOK_id = 3,                    // id
    TOK_string = 4,                // string
    TOK_define = 5,                // define
    TOK_import = 6,                // import
    TOK_semicolon = 7,             // semicolon
    TOK_integer = 8,               // integer
    TOK_double = 9,                // double
    TOK_bool = 10,                 // bool
    TOK_string_kw = 11,            // string_kw
    TOK_openclosebracket = 12,     // openclosebracket
    TOK_openbracket = 13,          // openbracket
    TOK_closebracket = 14,         // closebracket
    TOK_private = 15,              // private
    TOK_public = 16,               // public
    TOK_if = 17,                   // if
    TOK_else = 18,                 // else
    TOK_while = 19,                // while
    TOK_for = 20,                  // for
    TOK_boolean = 21,              // boolean
    TOK_void = 22,                 // void
    TOK_int = 23,                  // int
    TOK_class = 24,                // class
    TOK_nullkw = 25,               // nullkw
    TOK_slash = 26,                // slash
    TOK_percent = 27,              // percent
    TOK_return = 28,               // return
    TOK_break = 29,                // break
    TOK_new = 30,                  // new
    TOK_this = 31,                 // this
    TOK_newarray = 32,             // newarray
    TOK_print = 33,                // print
    TOK_readinteger = 34,          // readinteger
    TOK_readline = 35,             // readline
    TOK_line = 36,                 // line
    TOK_func = 37,                 // func
    TOK_btoi = 38,                 // btoi
    TOK_continue = 39,             // continue
    TOK_dtoi = 40,                 // dtoi
    TOK_itob = 41,                 // itob
    TOK_itod = 42,                 // itod
    TOK_float = 43,                // float
    TOK_plus = 44,                 // plus
    TOK_minus = 45,                // minus
    TOK_star = 46,                 // star
    TOK_div = 47,                  // div
    TOK_lessthanequal = 48,        // lessthanequal
    TOK_greaterthanequal = 49,     // greaterthanequal
    TOK_lessthan = 50,             // lessthan
    TOK_greaterthan = 51,          // greaterthan
    TOK_equal = 52,                // equal
    TOK_notequal = 53,             // notequal
    TOK_and = 54,                  // and
    TOK_or = 55,                   // or
    TOK_closebrace = 56,           // closebrace
    TOK_openparantheses = 57,      // openparantheses
    TOK_closeparantheses = 58,     // closeparantheses
    TOK_comma = 59,                // comma
    TOK_assign = 60,               // assign
    TOK_openbrace = 61,            // openbrace
    TOK_plusequal = 62,            // plusequal
    TOK_minusequal = 63,           // minusequal
    TOK_starequal = 64,            // starequal
    TOK_slashequal = 65,           // slashequal
    TOK_not = 66,                  // not
    TOK_dot = 67                   // dot
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 68, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_id = 3,                                // id
        S_string = 4,                            // string
        S_define = 5,                            // define
        S_import = 6,                            // import
        S_semicolon = 7,                         // semicolon
        S_integer = 8,                           // integer
        S_double = 9,                            // double
        S_bool = 10,                             // bool
        S_string_kw = 11,                        // string_kw
        S_openclosebracket = 12,                 // openclosebracket
        S_openbracket = 13,                      // openbracket
        S_closebracket = 14,                     // closebracket
        S_private = 15,                          // private
        S_public = 16,                           // public
        S_if = 17,                               // if
        S_else = 18,                             // else
        S_while = 19,                            // while
        S_for = 20,                              // for
        S_boolean = 21,                          // boolean
        S_void = 22,                             // void
        S_int = 23,                              // int
        S_class = 24,                            // class
        S_nullkw = 25,                           // nullkw
        S_slash = 26,                            // slash
        S_percent = 27,                          // percent
        S_return = 28,                           // return
        S_break = 29,                            // break
        S_new = 30,                              // new
        S_this = 31,                             // this
        S_newarray = 32,                         // newarray
        S_print = 33,                            // print
        S_readinteger = 34,                      // readinteger
        S_readline = 35,                         // readline
        S_line = 36,                             // line
        S_func = 37,                             // func
        S_btoi = 38,                             // btoi
        S_continue = 39,                         // continue
        S_dtoi = 40,                             // dtoi
        S_itob = 41,                             // itob
        S_itod = 42,                             // itod
        S_float = 43,                            // float
        S_plus = 44,                             // plus
        S_minus = 45,                            // minus
        S_star = 46,                             // star
        S_div = 47,                              // div
        S_lessthanequal = 48,                    // lessthanequal
        S_greaterthanequal = 49,                 // greaterthanequal
        S_lessthan = 50,                         // lessthan
        S_greaterthan = 51,                      // greaterthan
        S_equal = 52,                            // equal
        S_notequal = 53,                         // notequal
        S_and = 54,                              // and
        S_or = 55,                               // or
        S_closebrace = 56,                       // closebrace
        S_openparantheses = 57,                  // openparantheses
        S_closeparantheses = 58,                 // closeparantheses
        S_comma = 59,                            // comma
        S_assign = 60,                           // assign
        S_openbrace = 61,                        // openbrace
        S_plusequal = 62,                        // plusequal
        S_minusequal = 63,                       // minusequal
        S_starequal = 64,                        // starequal
        S_slashequal = 65,                       // slashequal
        S_not = 66,                              // not
        S_dot = 67,                              // dot
        S_YYACCEPT = 68,                         // $accept
        S_sp = 69,                               // sp
        S_program = 70,                          // program
        S_macro = 71,                            // macro
        S_declarations = 72,                     // declarations
        S_declaration = 73,                      // declaration
        S_variabledecl = 74,                     // variabledecl
        S_variable = 75,                         // variable
        S_type = 76,                             // type
        S_functiondecl = 77,                     // functiondecl
        S_78_1 = 78,                             // $@1
        S_79_2 = 79,                             // $@2
        S_formals = 80,                          // formals
        S_formalsp = 81,                         // formalsp
        S_classdecl = 82,                        // classdecl
        S_fields = 83,                           // fields
        S_field = 84,                            // field
        S_accessmode = 85,                       // accessmode
        S_stmtblock = 86,                        // stmtblock
        S_87_3 = 87,                             // $@3
        S_stmtblockcontent = 88,                 // stmtblockcontent
        S_statements = 89,                       // statements
        S_stmt = 90,                             // stmt
        S_ifstmt = 91,                           // ifstmt
        S_elsestmt = 92,                         // elsestmt
        S_whilestmt = 93,                        // whilestmt
        S_forstmt = 94,                          // forstmt
        S_returnstmt = 95,                       // returnstmt
        S_breakstmt = 96,                        // breakstmt
        S_nexpr = 97,                            // nexpr
        S_continuestmt = 98,                     // continuestmt
        S_printstmt = 99,                        // printstmt
        S_printcontent = 100,                    // printcontent
        S_expr = 101,                            // expr
        S_lvalue = 102,                          // lvalue
        S_call = 103,                            // call
        S_actuals = 104,                         // actuals
        S_actualscontent = 105,                  // actualscontent
        S_constant = 106                         // constant
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.move< std::pair<std::string,std::string> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.move< std::vector<std::pair<std::string,std::string>> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::string,std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::string,std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::pair<std::string,std::string>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::pair<std::string,std::string>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.template destroy< std::pair<std::string,std::string> > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.template destroy< std::vector<std::pair<std::string,std::string>> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_YYEOF
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_YYUNDEF));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_id <= tok && tok <= token::TOK_dot));
#endif
      }
    };

    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::TOK_YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::TOK_YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_id (std::string v, location_type l)
      {
        return symbol_type (token::TOK_id, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_id (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_id, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_string (std::string v, location_type l)
      {
        return symbol_type (token::TOK_string, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_string (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_string, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_define (std::string v, location_type l)
      {
        return symbol_type (token::TOK_define, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_define (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_define, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_import (std::string v, location_type l)
      {
        return symbol_type (token::TOK_import, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_import (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_import, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_semicolon (std::string v, location_type l)
      {
        return symbol_type (token::TOK_semicolon, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_semicolon (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_semicolon, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_integer (std::string v, location_type l)
      {
        return symbol_type (token::TOK_integer, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_integer (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_integer, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_double (std::string v, location_type l)
      {
        return symbol_type (token::TOK_double, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_double (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_double, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_bool (std::string v, location_type l)
      {
        return symbol_type (token::TOK_bool, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_bool (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_bool, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_string_kw (std::string v, location_type l)
      {
        return symbol_type (token::TOK_string_kw, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_string_kw (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_string_kw, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openclosebracket (std::string v, location_type l)
      {
        return symbol_type (token::TOK_openclosebracket, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_openclosebracket (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_openclosebracket, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openbracket (std::string v, location_type l)
      {
        return symbol_type (token::TOK_openbracket, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_openbracket (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_openbracket, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closebracket (std::string v, location_type l)
      {
        return symbol_type (token::TOK_closebracket, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_closebracket (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_closebracket, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_private (std::string v, location_type l)
      {
        return symbol_type (token::TOK_private, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_private (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_private, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_public (std::string v, location_type l)
      {
        return symbol_type (token::TOK_public, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_public (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_public, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_if (std::string v, location_type l)
      {
        return symbol_type (token::TOK_if, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_if (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_if, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_else (std::string v, location_type l)
      {
        return symbol_type (token::TOK_else, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_else (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_else, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_while (std::string v, location_type l)
      {
        return symbol_type (token::TOK_while, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_while (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_while, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_for (std::string v, location_type l)
      {
        return symbol_type (token::TOK_for, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_for (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_for, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_boolean (std::string v, location_type l)
      {
        return symbol_type (token::TOK_boolean, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_boolean (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_boolean, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_void (std::string v, location_type l)
      {
        return symbol_type (token::TOK_void, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_void (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_void, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_int (std::string v, location_type l)
      {
        return symbol_type (token::TOK_int, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_int (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_int, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_class (std::string v, location_type l)
      {
        return symbol_type (token::TOK_class, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_class (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_class, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_nullkw (std::string v, location_type l)
      {
        return symbol_type (token::TOK_nullkw, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_nullkw (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_nullkw, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_slash (std::string v, location_type l)
      {
        return symbol_type (token::TOK_slash, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_slash (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_slash, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_percent (std::string v, location_type l)
      {
        return symbol_type (token::TOK_percent, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_percent (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_percent, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_return (std::string v, location_type l)
      {
        return symbol_type (token::TOK_return, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_return (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_return, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_break (std::string v, location_type l)
      {
        return symbol_type (token::TOK_break, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_break (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_break, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_new (std::string v, location_type l)
      {
        return symbol_type (token::TOK_new, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_new (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_new, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_this (std::string v, location_type l)
      {
        return symbol_type (token::TOK_this, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_this (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_this, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_newarray (std::string v, location_type l)
      {
        return symbol_type (token::TOK_newarray, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_newarray (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_newarray, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_print (std::string v, location_type l)
      {
        return symbol_type (token::TOK_print, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_print (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_print, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_readinteger (std::string v, location_type l)
      {
        return symbol_type (token::TOK_readinteger, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_readinteger (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_readinteger, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_readline (std::string v, location_type l)
      {
        return symbol_type (token::TOK_readline, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_readline (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_readline, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_line (std::string v, location_type l)
      {
        return symbol_type (token::TOK_line, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_line (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_line, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_func (std::string v, location_type l)
      {
        return symbol_type (token::TOK_func, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_func (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_func, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_btoi (std::string v, location_type l)
      {
        return symbol_type (token::TOK_btoi, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_btoi (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_btoi, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_continue (std::string v, location_type l)
      {
        return symbol_type (token::TOK_continue, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_continue (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_continue, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_dtoi (std::string v, location_type l)
      {
        return symbol_type (token::TOK_dtoi, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_dtoi (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_dtoi, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_itob (std::string v, location_type l)
      {
        return symbol_type (token::TOK_itob, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_itob (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_itob, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_itod (std::string v, location_type l)
      {
        return symbol_type (token::TOK_itod, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_itod (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_itod, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_float (std::string v, location_type l)
      {
        return symbol_type (token::TOK_float, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_float (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_float, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_plus (std::string v, location_type l)
      {
        return symbol_type (token::TOK_plus, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_plus (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_plus, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_minus (std::string v, location_type l)
      {
        return symbol_type (token::TOK_minus, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_minus (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_minus, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_star (std::string v, location_type l)
      {
        return symbol_type (token::TOK_star, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_star (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_star, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_div (std::string v, location_type l)
      {
        return symbol_type (token::TOK_div, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_div (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_div, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_lessthanequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_lessthanequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_lessthanequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_lessthanequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_greaterthanequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_greaterthanequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_greaterthanequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_greaterthanequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_lessthan (std::string v, location_type l)
      {
        return symbol_type (token::TOK_lessthan, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_lessthan (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_lessthan, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_greaterthan (std::string v, location_type l)
      {
        return symbol_type (token::TOK_greaterthan, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_greaterthan (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_greaterthan, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_equal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_equal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_equal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_equal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_notequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_notequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_notequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_notequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_and (std::string v, location_type l)
      {
        return symbol_type (token::TOK_and, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_and (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_and, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_or (std::string v, location_type l)
      {
        return symbol_type (token::TOK_or, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_or (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_or, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closebrace (std::string v, location_type l)
      {
        return symbol_type (token::TOK_closebrace, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_closebrace (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_closebrace, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openparantheses (std::string v, location_type l)
      {
        return symbol_type (token::TOK_openparantheses, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_openparantheses (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_openparantheses, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closeparantheses (std::string v, location_type l)
      {
        return symbol_type (token::TOK_closeparantheses, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_closeparantheses (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_closeparantheses, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_comma (std::string v, location_type l)
      {
        return symbol_type (token::TOK_comma, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_comma (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_comma, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_assign (std::string v, location_type l)
      {
        return symbol_type (token::TOK_assign, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_assign (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_assign, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openbrace (std::string v, location_type l)
      {
        return symbol_type (token::TOK_openbrace, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_openbrace (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_openbrace, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_plusequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_plusequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_plusequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_plusequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_minusequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_minusequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_minusequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_minusequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_starequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_starequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_starequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_starequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_slashequal (std::string v, location_type l)
      {
        return symbol_type (token::TOK_slashequal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_slashequal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_slashequal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_not (std::string v, location_type l)
      {
        return symbol_type (token::TOK_not, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_not (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_not, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_dot (std::string v, location_type l)
      {
        return symbol_type (token::TOK_dot, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_dot (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_dot, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 699,     ///< Last index in yytable_.
      yynnts_ = 39,  ///< Number of nonterminal symbols.
      yyfinal_ = 24 ///< Termination state number.
    };


    // User arguments.
    driver& drv;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.copy< std::pair<std::string,std::string> > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.copy< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_constant: // constant
        value.move< std::pair<std::string,std::string> > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formals: // formals
      case symbol_kind::S_formalsp: // formalsp
        value.move< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2965 "src/parser.hh"




#endif // !YY_YY_SRC_PARSER_HH_INCLUDED
