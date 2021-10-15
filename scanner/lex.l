%option noyywrap

%{
#include "tokens.hpp"
using namespace std;
%}


string              \"([^\n"\\]|\\[^\n\r])*\"

comment             \/\/(.)*$

ws                  [ \t\f]+
alpha               [A-Za-z]
dig                 [0-9]

id                  ({alpha}|_)({alpha}|{dig}|_)*

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
div                 \/
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
openparantheses     \(
closeparantheses    \)
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
%%

{string}          return STRING;

{boolean}         return BOOLEAN;

{void}            return VOID;
{int}             return INT;
{double}          return DOUBLE;
{bool}            return BOOL;
{string_kw}       return STRING_KW;
{class}           return CLASS;
{null}            return _NULL;
{for}             return FOR;
{while}           return WHILE;
{if}              return IF;
{else}            return ELSE;
{return}          return RETURN;
{break}           return BREAK;
{new}             return NEW;
{this}            return THIS;
{NewArray}        return NEWARRAY;
{Print}           return PRINT;
{ReadInteger}     return READINTEGER;
{ReadLine}        return READLINE;
{import}          return IMPORT;
{line}            return LINE;
{func}            return FUNC;
{btoi}                return BTOI;
{continue}            return CONTINUE;
{dtoi}                return DTOI;    
{itob}                return ITOB;    
{itod}                return ITOD;    
{private}             return PRIVATE;
{public}              return PUBLIC;  

{define}              return DEFINE;

{integer}         return INTEGER;

{float}           return FLOAT;

{comment}         return -1;

{id}              return ID;

{ws}              return -1;

"/*"              { /* comment e hamintori */
                  int c;
                  while((c = yyinput()) != 0)
                      if(c == '*'){
                          if((c = yyinput()) == '/')
                              break;
                          else
                              unput(c);
                      }
                      return -1;
                  }

\n                return -1;


{plus}                return PLUS;
{minus}               return MINUS;
{star}                return STAR;
{div}                 return DIVISION;
{percent}             return PERCENT;
{lessthan}            return LESSTHAN;
{greaterthan}         return GREATERTHAN;
{lessthanequal}       return LESSTHANEQUAL;
{greaterthanequal}    return GREATERTHANEQUAL;
{equal}               return EQUAL;
{notequal}            return NOTEQUAL;
{and}                 return AND;
{or}                  return OR;
{openbrace}           return OPENBRACE;
{closebrace}          return CLOSEBRACE;
{openbracket}         return OPENBRACKET;
{closebracket}        return CLOSEBRACKET;
{openparantheses}     return OPENPARANTHESES;
{closeparantheses}    return CLOSEPARANTHESES;
{comma}               return COMMA;
{assign}              return ASSIGN;
{semicolon}           return SEMICOLON;
{plusequal}           return PLUSEQUAL;
{minusequal}          return MINUSEQUAL;
{starequal}           return STAREQUAL;
{slashqual}           return SLASHEQUAL;
{not}                 return NOT;
{dot}                 return DOT;

%%
