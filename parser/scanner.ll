/* Scanner for decaf compiler.   -*- C++ -*-

   Copyright (C) 2005-2015, 2018-2021 Free Software Foundation, Inc.

   This is taken from from the calc++ example of the bison software.
   It is userd to lex the decaf code.
   It is used under GNU GPL v3.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include <cctype>
# include "driver.hh"
# include "parser.hh"

    using namespace std;
%}

%{
#if defined __clang__
# define CLANG_VERSION (__clang_major__ * 100 + __clang_minor__)
#endif

// Clang and ICC like to pretend they are GCC.
#if defined __GNUC__ && !defined __clang__ && !defined __ICC
# define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 6.4.0, 7.3.0 with -O3.
#if defined GCC_VERSION && 600 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// This example uses Flex's C back end, yet compiles it as C++.
// So expect warnings about C style casts and NULL.
#if defined CLANG_VERSION && 500 <= CLANG_VERSION
# pragma clang diagnostic ignored "-Wold-style-cast"
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined GCC_VERSION && 407 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wold-style-cast"
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

// Old versions of Flex (2.5.35) generate an incomplete documentation comment.
//
//  In file included from src/scan-code-c.c:3:
//  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
//        [-Werror,-Wdocumentation]
//   * @param line_number
//     ~~~~~~~~~~~~~~~~~^
//  1 error generated.
#if FLEX_VERSION < 206 && defined CLANG_VERSION
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

// Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
// GCC 7 and Clang 6.
#if FLEX_VERSION < 206
# if defined CLANG_VERSION && 600 <= CLANG_VERSION
#  pragma clang diagnostic ignored "-Wdeprecated-register"
# elif defined GCC_VERSION && 700 <= GCC_VERSION
#  pragma GCC diagnostic ignored "-Wregister"
# endif
#endif

#if FLEX_VERSION < 206
# if defined CLANG_VERSION
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshorten-64-to-32"
#  pragma clang diagnostic ignored "-Wsign-conversion"
# elif defined GCC_VERSION
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
# endif
#endif

// Flex 2.6.4, GCC 9
// warning: useless cast to type 'int' [-Wuseless-cast]
// 1361 |   YY_CURRENT_BUFFER_LVALUE->yy_buf_size = (int) (new_size - 2);
//      |                                                 ^
#if defined GCC_VERSION && 900 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
%}

%option noyywrap batch debug

comment             \/\/(.)*$

ws                  [ \t\f]+
alpha               [A-Za-z]
dig                 [0-9]

openclosebracket    \[{ws}*\]
string              \"([^\n"\\]|\\[^\n\r])*\"

id                  {alpha}({alpha}|{dig}|_)*

float               {dig}+\.{dig}*([eE][-+]?{dig}+)?

integerd            {dig}+
integerx            0x({dig}|[ABCDEFabcdef])+
integer             {integerd}|{integerx}

void                void
int                 int
double              double
bool                bool
string_kw           string
class               class
null                null
for                 for
while               while
if                  if
else                else
return              return
break               break
new                 new
this                this
NewArray            NewArray
Print               Print
ReadInteger         ReadInteger
ReadLine            ReadLine

btoi                btoi    
continue            continue
dtoi                dtoi    
itob                itob    
itod                itod    
private             private   
public              public   

define              define


plus                \+
minus               -
star                \*
slash                 \/
percent             %
lessthan            <
greaterthan         >
lessthanequal       <=
greaterthanequal    >=
equal               ==
notequal            !=
and                 &&
or                  \|\|
openbrace           \{
closebrace          \}
openbracket         \[
closebracket        \]
openparantheses        \(
closeparantheses        \)
comma               ,
assign              =
semicolon           ;
plusequal           \+=
minusequal          -=
starequal           \*=
slashqual           \/=
not                 !
dot                 \.


boolean             true|false

import              import
line                __line__
func                __func__

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
  //std::cout << yytext << std::endl;
%}
<<EOF>>    return yy::parser::make_YYEOF (loc);
{ws}        loc.step();
\n+         loc.lines(yyleng); loc.step();

{string}              return yy::parser::make_string(yytext,loc);

{boolean}             return yy::parser::make_boolean(yytext,loc);
{void}                return yy::parser::make_void(yytext,loc);
{int}                 return yy::parser::make_int(yytext,loc);
{double}              return yy::parser::make_double(yytext,loc);
{bool}                return yy::parser::make_bool(yytext,loc);
{string_kw}           return yy::parser::make_string_kw(yytext,loc);
{class}               return yy::parser::make_class(yytext,loc);
{null}                return yy::parser::make_nullkw(yytext,loc);
{for}                 return yy::parser::make_for(yytext,loc);
{while}               return yy::parser::make_while(yytext,loc);
{if}                  return yy::parser::make_if(yytext,loc);
{else}                return yy::parser::make_else(yytext,loc);
{return}              return yy::parser::make_return(yytext,loc);
{break}               return yy::parser::make_break(yytext,loc);
{new}                 return yy::parser::make_new(yytext,loc);
{this}                return yy::parser::make_this(yytext,loc);
{NewArray}            return yy::parser::make_newarray(yytext,loc);
{Print}               return yy::parser::make_print(yytext,loc);
{ReadInteger}         return yy::parser::make_readinteger(yytext,loc);
{ReadLine}            return yy::parser::make_readline(yytext,loc);
{import}              return yy::parser::make_import(yytext,loc);
{line}                return yy::parser::make_line(yytext,loc);
{func}                return yy::parser::make_func(yytext,loc);
{btoi}                return yy::parser::make_btoi(yytext,loc);
{continue}            return yy::parser::make_continue(yytext,loc);
{dtoi}                return yy::parser::make_dtoi(yytext,loc);
{itob}                return yy::parser::make_itob(yytext,loc);
{itod}                return yy::parser::make_itod(yytext,loc);
{private}             return yy::parser::make_private(yytext,loc);
{public}              return yy::parser::make_public(yytext,loc);
{define}              return yy::parser::make_define(yytext,loc);
{integer}             return yy::parser::make_integer(yytext,loc);
{float}               return yy::parser::make_float(yytext,loc);

{comment}             loc.step();


{id}              { return yy::parser::make_id(yytext,loc);}

{ws}              loc.step();





"/*"              { /* comment e hamintori */
                    loc.step();
                  int c;
                  while((c = yyinput()) != 0)
                        loc.step();
                      if(c == '*'){
                          if((c = yyinput()) == '/')
                              break;
                          else
                              unput(c);
                      } else if (c == '\n')
                          loc.lines(1);
                      
                  }

{openclosebracket}                  return yy::parser::make_openclosebracket(yytext,loc);

{plus}                return yy::parser::make_plus(yytext,loc);
{minus}               return yy::parser::make_minus(yytext,loc);
{star}                return yy::parser::make_star(yytext,loc);
{slash}               return yy::parser::make_slash(yytext,loc);
{percent}             return yy::parser::make_percent(yytext,loc);
{lessthan}            return yy::parser::make_lessthan(yytext,loc);
{greaterthan}         return yy::parser::make_greaterthan(yytext,loc);
{lessthanequal}       return yy::parser::make_lessthanequal(yytext,loc);
{greaterthanequal}    return yy::parser::make_greaterthanequal(yytext,loc);
{equal}               return yy::parser::make_equal(yytext,loc);
{notequal}            return yy::parser::make_notequal(yytext,loc);
{and}                 return yy::parser::make_and(yytext,loc);
{or}                  return yy::parser::make_or(yytext,loc);
{openbrace}           return yy::parser::make_openbrace(yytext,loc);
{closebrace}          return yy::parser::make_closebrace(yytext,loc);
{openbracket}         return yy::parser::make_openbracket(yytext,loc);
{closebracket}        return yy::parser::make_closebracket(yytext,loc);
{openparantheses}     return yy::parser::make_openparantheses(yytext,loc);
{closeparantheses}    return yy::parser::make_closeparantheses(yytext,loc);
{comma}               return yy::parser::make_comma(yytext,loc);
{assign}              return yy::parser::make_assign(yytext,loc);
{semicolon}           return yy::parser::make_semicolon(yytext,loc);
{plusequal}           return yy::parser::make_plusequal(yytext,loc);
{minusequal}          return yy::parser::make_minusequal(yytext,loc);
{starequal}           return yy::parser::make_starequal(yytext,loc);
{slashqual}           return yy::parser::make_slashequal(yytext,loc);
{not}                 return yy::parser::make_not(yytext,loc);
{dot}                 return yy::parser::make_dot(yytext,loc);

"_"             {
                  int c;
                  while(!isspace(c = yyinput())){
                    loc.step();
                    //cout << (char) c << endl;
                  }
                }
                 
%%

//yy::parser::symbol_type
//make_NUMBER (const std::string &s, const yy::parser::location_type& yytext,loc)
//{
//  errno = 0;
//  long n = strtol (s.c_str(), NULL, 10);
//  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
//    throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
//  return yy::parser::make_NUMBER ((int) n, loc);
//}

void
driver::scan_begin ()
{

    yy_flex_debug = trace_scanning;
    if (file.empty () || file == "-")
      yyin = stdin;
    else if (!(yyin = fopen (file.c_str (), "r")))
      {
        std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
        exit (EXIT_FAILURE);
      }
}

void
driver::scan_end ()
{
  fclose (yyin);
}
