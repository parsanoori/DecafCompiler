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
#line 30 "parser.yy"

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
      // id
      // string
      char dummy1[sizeof (std::string)];
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
        S_program = 69,                          // program
        S_macro = 70,                            // macro
        S_declerations = 71,                     // declerations
        S_declaration = 72,                      // declaration
        S_variabledecl = 73,                     // variabledecl
        S_variable = 74,                         // variable
        S_type = 75,                             // type
        S_functiondecl = 76,                     // functiondecl
        S_formals = 77,                          // formals
        S_formalsp = 78,                         // formalsp
        S_classdecl = 79,                        // classdecl
        S_fields = 80,                           // fields
        S_field = 81,                            // field
        S_accessmode = 82,                       // accessmode
        S_stmtblock = 83,                        // stmtblock
        S_stmtblockcontent = 84,                 // stmtblockcontent
        S_statements = 85,                       // statements
        S_stmt = 86,                             // stmt
        S_ifstmt = 87,                           // ifstmt
        S_elsestmt = 88,                         // elsestmt
        S_whilestmt = 89,                        // whilestmt
        S_forstmt = 90,                          // forstmt
        S_returnstmt = 91,                       // returnstmt
        S_breakstmt = 92,                        // breakstmt
        S_nexpr = 93,                            // nexpr
        S_continuestmt = 94,                     // continuestmt
        S_printstmt = 95,                        // printstmt
        S_printcontent = 96,                     // printcontent
        S_expr = 97,                             // expr
        S_lvalue = 98,                           // lvalue
        S_call = 99,                             // call
        S_actuals = 100,                         // actuals
        S_constant = 101                         // constant
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.move< std::string > (std::move (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.template destroy< std::string > ();
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
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_YYUNDEF)
                   || (token::TOK_define <= tok && tok <= token::TOK_dot));
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
        YY_ASSERT ((token::TOK_id <= tok && tok <= token::TOK_string));
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
      make_define (location_type l)
      {
        return symbol_type (token::TOK_define, std::move (l));
      }
#else
      static
      symbol_type
      make_define (const location_type& l)
      {
        return symbol_type (token::TOK_define, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_import (location_type l)
      {
        return symbol_type (token::TOK_import, std::move (l));
      }
#else
      static
      symbol_type
      make_import (const location_type& l)
      {
        return symbol_type (token::TOK_import, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_semicolon (location_type l)
      {
        return symbol_type (token::TOK_semicolon, std::move (l));
      }
#else
      static
      symbol_type
      make_semicolon (const location_type& l)
      {
        return symbol_type (token::TOK_semicolon, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_integer (location_type l)
      {
        return symbol_type (token::TOK_integer, std::move (l));
      }
#else
      static
      symbol_type
      make_integer (const location_type& l)
      {
        return symbol_type (token::TOK_integer, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_double (location_type l)
      {
        return symbol_type (token::TOK_double, std::move (l));
      }
#else
      static
      symbol_type
      make_double (const location_type& l)
      {
        return symbol_type (token::TOK_double, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_bool (location_type l)
      {
        return symbol_type (token::TOK_bool, std::move (l));
      }
#else
      static
      symbol_type
      make_bool (const location_type& l)
      {
        return symbol_type (token::TOK_bool, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_string_kw (location_type l)
      {
        return symbol_type (token::TOK_string_kw, std::move (l));
      }
#else
      static
      symbol_type
      make_string_kw (const location_type& l)
      {
        return symbol_type (token::TOK_string_kw, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openclosebracket (location_type l)
      {
        return symbol_type (token::TOK_openclosebracket, std::move (l));
      }
#else
      static
      symbol_type
      make_openclosebracket (const location_type& l)
      {
        return symbol_type (token::TOK_openclosebracket, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openbracket (location_type l)
      {
        return symbol_type (token::TOK_openbracket, std::move (l));
      }
#else
      static
      symbol_type
      make_openbracket (const location_type& l)
      {
        return symbol_type (token::TOK_openbracket, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closebracket (location_type l)
      {
        return symbol_type (token::TOK_closebracket, std::move (l));
      }
#else
      static
      symbol_type
      make_closebracket (const location_type& l)
      {
        return symbol_type (token::TOK_closebracket, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_private (location_type l)
      {
        return symbol_type (token::TOK_private, std::move (l));
      }
#else
      static
      symbol_type
      make_private (const location_type& l)
      {
        return symbol_type (token::TOK_private, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_public (location_type l)
      {
        return symbol_type (token::TOK_public, std::move (l));
      }
#else
      static
      symbol_type
      make_public (const location_type& l)
      {
        return symbol_type (token::TOK_public, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_if (location_type l)
      {
        return symbol_type (token::TOK_if, std::move (l));
      }
#else
      static
      symbol_type
      make_if (const location_type& l)
      {
        return symbol_type (token::TOK_if, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_else (location_type l)
      {
        return symbol_type (token::TOK_else, std::move (l));
      }
#else
      static
      symbol_type
      make_else (const location_type& l)
      {
        return symbol_type (token::TOK_else, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_while (location_type l)
      {
        return symbol_type (token::TOK_while, std::move (l));
      }
#else
      static
      symbol_type
      make_while (const location_type& l)
      {
        return symbol_type (token::TOK_while, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_for (location_type l)
      {
        return symbol_type (token::TOK_for, std::move (l));
      }
#else
      static
      symbol_type
      make_for (const location_type& l)
      {
        return symbol_type (token::TOK_for, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_boolean (location_type l)
      {
        return symbol_type (token::TOK_boolean, std::move (l));
      }
#else
      static
      symbol_type
      make_boolean (const location_type& l)
      {
        return symbol_type (token::TOK_boolean, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_void (location_type l)
      {
        return symbol_type (token::TOK_void, std::move (l));
      }
#else
      static
      symbol_type
      make_void (const location_type& l)
      {
        return symbol_type (token::TOK_void, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_int (location_type l)
      {
        return symbol_type (token::TOK_int, std::move (l));
      }
#else
      static
      symbol_type
      make_int (const location_type& l)
      {
        return symbol_type (token::TOK_int, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_class (location_type l)
      {
        return symbol_type (token::TOK_class, std::move (l));
      }
#else
      static
      symbol_type
      make_class (const location_type& l)
      {
        return symbol_type (token::TOK_class, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_nullkw (location_type l)
      {
        return symbol_type (token::TOK_nullkw, std::move (l));
      }
#else
      static
      symbol_type
      make_nullkw (const location_type& l)
      {
        return symbol_type (token::TOK_nullkw, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_slash (location_type l)
      {
        return symbol_type (token::TOK_slash, std::move (l));
      }
#else
      static
      symbol_type
      make_slash (const location_type& l)
      {
        return symbol_type (token::TOK_slash, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_percent (location_type l)
      {
        return symbol_type (token::TOK_percent, std::move (l));
      }
#else
      static
      symbol_type
      make_percent (const location_type& l)
      {
        return symbol_type (token::TOK_percent, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_return (location_type l)
      {
        return symbol_type (token::TOK_return, std::move (l));
      }
#else
      static
      symbol_type
      make_return (const location_type& l)
      {
        return symbol_type (token::TOK_return, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_break (location_type l)
      {
        return symbol_type (token::TOK_break, std::move (l));
      }
#else
      static
      symbol_type
      make_break (const location_type& l)
      {
        return symbol_type (token::TOK_break, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_new (location_type l)
      {
        return symbol_type (token::TOK_new, std::move (l));
      }
#else
      static
      symbol_type
      make_new (const location_type& l)
      {
        return symbol_type (token::TOK_new, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_this (location_type l)
      {
        return symbol_type (token::TOK_this, std::move (l));
      }
#else
      static
      symbol_type
      make_this (const location_type& l)
      {
        return symbol_type (token::TOK_this, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_newarray (location_type l)
      {
        return symbol_type (token::TOK_newarray, std::move (l));
      }
#else
      static
      symbol_type
      make_newarray (const location_type& l)
      {
        return symbol_type (token::TOK_newarray, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_print (location_type l)
      {
        return symbol_type (token::TOK_print, std::move (l));
      }
#else
      static
      symbol_type
      make_print (const location_type& l)
      {
        return symbol_type (token::TOK_print, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_readinteger (location_type l)
      {
        return symbol_type (token::TOK_readinteger, std::move (l));
      }
#else
      static
      symbol_type
      make_readinteger (const location_type& l)
      {
        return symbol_type (token::TOK_readinteger, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_readline (location_type l)
      {
        return symbol_type (token::TOK_readline, std::move (l));
      }
#else
      static
      symbol_type
      make_readline (const location_type& l)
      {
        return symbol_type (token::TOK_readline, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_line (location_type l)
      {
        return symbol_type (token::TOK_line, std::move (l));
      }
#else
      static
      symbol_type
      make_line (const location_type& l)
      {
        return symbol_type (token::TOK_line, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_func (location_type l)
      {
        return symbol_type (token::TOK_func, std::move (l));
      }
#else
      static
      symbol_type
      make_func (const location_type& l)
      {
        return symbol_type (token::TOK_func, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_btoi (location_type l)
      {
        return symbol_type (token::TOK_btoi, std::move (l));
      }
#else
      static
      symbol_type
      make_btoi (const location_type& l)
      {
        return symbol_type (token::TOK_btoi, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_continue (location_type l)
      {
        return symbol_type (token::TOK_continue, std::move (l));
      }
#else
      static
      symbol_type
      make_continue (const location_type& l)
      {
        return symbol_type (token::TOK_continue, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_dtoi (location_type l)
      {
        return symbol_type (token::TOK_dtoi, std::move (l));
      }
#else
      static
      symbol_type
      make_dtoi (const location_type& l)
      {
        return symbol_type (token::TOK_dtoi, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_itob (location_type l)
      {
        return symbol_type (token::TOK_itob, std::move (l));
      }
#else
      static
      symbol_type
      make_itob (const location_type& l)
      {
        return symbol_type (token::TOK_itob, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_itod (location_type l)
      {
        return symbol_type (token::TOK_itod, std::move (l));
      }
#else
      static
      symbol_type
      make_itod (const location_type& l)
      {
        return symbol_type (token::TOK_itod, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_float (location_type l)
      {
        return symbol_type (token::TOK_float, std::move (l));
      }
#else
      static
      symbol_type
      make_float (const location_type& l)
      {
        return symbol_type (token::TOK_float, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_plus (location_type l)
      {
        return symbol_type (token::TOK_plus, std::move (l));
      }
#else
      static
      symbol_type
      make_plus (const location_type& l)
      {
        return symbol_type (token::TOK_plus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_minus (location_type l)
      {
        return symbol_type (token::TOK_minus, std::move (l));
      }
#else
      static
      symbol_type
      make_minus (const location_type& l)
      {
        return symbol_type (token::TOK_minus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_star (location_type l)
      {
        return symbol_type (token::TOK_star, std::move (l));
      }
#else
      static
      symbol_type
      make_star (const location_type& l)
      {
        return symbol_type (token::TOK_star, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_div (location_type l)
      {
        return symbol_type (token::TOK_div, std::move (l));
      }
#else
      static
      symbol_type
      make_div (const location_type& l)
      {
        return symbol_type (token::TOK_div, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_lessthanequal (location_type l)
      {
        return symbol_type (token::TOK_lessthanequal, std::move (l));
      }
#else
      static
      symbol_type
      make_lessthanequal (const location_type& l)
      {
        return symbol_type (token::TOK_lessthanequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_greaterthanequal (location_type l)
      {
        return symbol_type (token::TOK_greaterthanequal, std::move (l));
      }
#else
      static
      symbol_type
      make_greaterthanequal (const location_type& l)
      {
        return symbol_type (token::TOK_greaterthanequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_lessthan (location_type l)
      {
        return symbol_type (token::TOK_lessthan, std::move (l));
      }
#else
      static
      symbol_type
      make_lessthan (const location_type& l)
      {
        return symbol_type (token::TOK_lessthan, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_greaterthan (location_type l)
      {
        return symbol_type (token::TOK_greaterthan, std::move (l));
      }
#else
      static
      symbol_type
      make_greaterthan (const location_type& l)
      {
        return symbol_type (token::TOK_greaterthan, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_equal (location_type l)
      {
        return symbol_type (token::TOK_equal, std::move (l));
      }
#else
      static
      symbol_type
      make_equal (const location_type& l)
      {
        return symbol_type (token::TOK_equal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_notequal (location_type l)
      {
        return symbol_type (token::TOK_notequal, std::move (l));
      }
#else
      static
      symbol_type
      make_notequal (const location_type& l)
      {
        return symbol_type (token::TOK_notequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_and (location_type l)
      {
        return symbol_type (token::TOK_and, std::move (l));
      }
#else
      static
      symbol_type
      make_and (const location_type& l)
      {
        return symbol_type (token::TOK_and, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_or (location_type l)
      {
        return symbol_type (token::TOK_or, std::move (l));
      }
#else
      static
      symbol_type
      make_or (const location_type& l)
      {
        return symbol_type (token::TOK_or, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closebrace (location_type l)
      {
        return symbol_type (token::TOK_closebrace, std::move (l));
      }
#else
      static
      symbol_type
      make_closebrace (const location_type& l)
      {
        return symbol_type (token::TOK_closebrace, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openparantheses (location_type l)
      {
        return symbol_type (token::TOK_openparantheses, std::move (l));
      }
#else
      static
      symbol_type
      make_openparantheses (const location_type& l)
      {
        return symbol_type (token::TOK_openparantheses, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_closeparantheses (location_type l)
      {
        return symbol_type (token::TOK_closeparantheses, std::move (l));
      }
#else
      static
      symbol_type
      make_closeparantheses (const location_type& l)
      {
        return symbol_type (token::TOK_closeparantheses, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_comma (location_type l)
      {
        return symbol_type (token::TOK_comma, std::move (l));
      }
#else
      static
      symbol_type
      make_comma (const location_type& l)
      {
        return symbol_type (token::TOK_comma, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_assign (location_type l)
      {
        return symbol_type (token::TOK_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_assign (const location_type& l)
      {
        return symbol_type (token::TOK_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_openbrace (location_type l)
      {
        return symbol_type (token::TOK_openbrace, std::move (l));
      }
#else
      static
      symbol_type
      make_openbrace (const location_type& l)
      {
        return symbol_type (token::TOK_openbrace, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_plusequal (location_type l)
      {
        return symbol_type (token::TOK_plusequal, std::move (l));
      }
#else
      static
      symbol_type
      make_plusequal (const location_type& l)
      {
        return symbol_type (token::TOK_plusequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_minusequal (location_type l)
      {
        return symbol_type (token::TOK_minusequal, std::move (l));
      }
#else
      static
      symbol_type
      make_minusequal (const location_type& l)
      {
        return symbol_type (token::TOK_minusequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_starequal (location_type l)
      {
        return symbol_type (token::TOK_starequal, std::move (l));
      }
#else
      static
      symbol_type
      make_starequal (const location_type& l)
      {
        return symbol_type (token::TOK_starequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_slashequal (location_type l)
      {
        return symbol_type (token::TOK_slashequal, std::move (l));
      }
#else
      static
      symbol_type
      make_slashequal (const location_type& l)
      {
        return symbol_type (token::TOK_slashequal, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_not (location_type l)
      {
        return symbol_type (token::TOK_not, std::move (l));
      }
#else
      static
      symbol_type
      make_not (const location_type& l)
      {
        return symbol_type (token::TOK_not, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_dot (location_type l)
      {
        return symbol_type (token::TOK_dot, std::move (l));
      }
#else
      static
      symbol_type
      make_dot (const location_type& l)
      {
        return symbol_type (token::TOK_dot, l);
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
      yylast_ = 765,     ///< Last index in yytable_.
      yynnts_ = 34,  ///< Number of nonterminal symbols.
      yyfinal_ = 23 ///< Termination state number.
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.copy< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_string: // string
        value.move< std::string > (YY_MOVE (s.value));
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
#line 2420 "src/parser.hh"




#endif // !YY_YY_SRC_PARSER_HH_INCLUDED
