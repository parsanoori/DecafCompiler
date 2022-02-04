%skeleton "lalr1.cc"
%require "3.8"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
# include "driver.hh"
#include <iostream>
#include "codegen.h"
#include "dtype.h"
#include <vector>
using namespace std;

codegen &cg = *(codegen::get());
}

%define api.token.prefix {TOK_}


%token <std::string> id
%token <std::string> string
%token <std::string> define import semicolon integer double bool string_kw
%token <std::string> openclosebracket;
%token <std::string> openbracket closebracket private public if else while for
%token <std::string> boolean void int class nullkw slash percent
%token <std::string> return break new this newarray print readinteger readline
%token <std::string> line func btoi continue dtoi itob itod
%token <std::string> float plus minus star div  lessthanequal greaterthanequal
%token <std::string> lessthan greaterthan equal notequal and or  closebrace
%token <std::string> openparantheses closeparantheses comma assign openbrace
%token <std::string> plusequal minusequal starequal slashequal not dot

%nterm <std::string> program macro declaration declarations variabledecl type functiondecl
%nterm <std::string> classdecl fields field accessmode stmtblock stmt stmtblockcontent statements ifstmt elsestmt whilestmt
%nterm <std::string> forstmt returnstmt breakstmt nexpr continuestmt printstmt printcontent lvalue call actuals
%nterm <std::string> actualscontent

%nterm <std::pair<std::string,std::string>> variable constant expr
%nterm <std::vector<std::pair<std::string,std::string>>> formals formalsp


%%
%start sp;

sp: program { cg.writestuff(); }

program: macro program { }
       | declarations { }

macro: import string { }
     | define id id { }

declarations: declaration declarations { }
            | declaration {  }

declaration: variabledecl { }
           | functiondecl { }
           | classdecl { }

variabledecl: variable semicolon { }

variable: type id { cg.variable($1,$2); $$ = {$1,$2}; }

type: int { $$ = $1; }
    | double { $$ = $1; }
    | bool { $$ = $1; }
    | string_kw {  $$ = $1; }
    | id {  $$ = $1; }
    | type openclosebracket {  $$ = $1; }

functiondecl: type id openparantheses formals closeparantheses { cg.addfunction($2,$4); } stmtblock { cg.endfunction(); }
            | void id openparantheses formals closeparantheses { cg.addfunction($2,$4); } stmtblock { cg.endfunction(); }
            
formals: formalsp {  $$ = $1; }
       | %empty {  }

formalsp: variable comma formalsp { $3.push_back($1); $$ = $3; }
        | variable { $$ = {$1}; }

classdecl: class id openbrace fields closebrace {  }

fields: field fields { }
      | %empty { }

field: accessmode variabledecl { }
     | accessmode functiondecl { }

accessmode: private { }
          | public { }
          | %empty { }

stmtblock: openbrace stmtblockcontent closebrace { }

stmtblockcontent: variabledecl stmtblockcontent { }
                | statements { }

statements: %empty { }
          | stmt statements { }

stmt: expr semicolon { }
         | semicolon { }
         | ifstmt { }
         | whilestmt { }
         | forstmt { }
         | breakstmt { }
         | continuestmt { }
         | returnstmt { }
         | printstmt { }
         | stmtblock { }

%right else;
ifstmt: if openparantheses expr closeparantheses stmt { }
      | if openparantheses expr closeparantheses stmt elsestmt { }

elsestmt: else stmt { }

whilestmt: while openparantheses expr closeparantheses stmt { }

forstmt: for openparantheses nexpr semicolon expr semicolon nexpr closeparantheses stmt { }

returnstmt: return nexpr semicolon { }

breakstmt: break semicolon { }

nexpr: expr { }
    | %empty { }

continuestmt: continue semicolon { }


printstmt:
        print openparantheses printcontent  closeparantheses semicolon { cg.printnewline(); }



printcontent: printcontent comma expr { cg.printexpr($3); }
            | expr { cg.printexpr($1); }

%left assign plusequal slashequal lessthan greaterthan lessthanequal;
%left greaterthanequal equal slash percent plus minus star not dot ;
%left minusequal starequal ;
%left and or  comma  notequal;

%right openparantheses openbracket openbrace;

expr:
        lvalue assign expr               {}
    |   lvalue plusequal expr             {}
    |   lvalue minusequal expr             {}
    |   lvalue starequal expr             {}
    |   lvalue slashequal expr             {}
    |   constant                    { $$ = $1; }
    |   lvalue                      {}
    |   this                        {}
    |   call                        {}
    |   openparantheses expr closeparantheses                      { $$ = $2; }
    |   expr plus expr                 {}
    |   expr minus expr                 {}
    |   expr star expr                 {}
    |   expr slash expr                 {}
    |   expr percent expr                 {}
    |   minus expr                      {}
    |   expr lessthan expr                 {}
    |   expr lessthanequal expr                {}
    |   expr greaterthan expr                 {}
    |   expr greaterthanequal expr                {}
    |   expr equal expr                {}
    |   expr notequal expr                {}
    |   expr and expr                {}
    |   expr or expr                {}
    |   not expr                      {}
    |   readinteger openparantheses  closeparantheses             {}
    |   readline openparantheses  closeparantheses                 {}
    |   new id                   {}
    |   newarray openparantheses expr comma type  closeparantheses    {}
    |   itod openparantheses expr   closeparantheses        {}
    |   dtoi openparantheses expr   closeparantheses        {}
    |   itob openparantheses expr   closeparantheses        {}
    |   btoi openparantheses expr   closeparantheses        {}
    |   line                    {}
    |   func                    {}
    
lvalue:
        id                       {}
    |   expr  dot  id                {}
    |   expr openbracket expr closebracket               {}
    
call:
        id openparantheses actuals  closeparantheses           {}
    |   expr  dot  id openparantheses actuals  closeparantheses    {}
    
actuals:
        actualscontent                    {}
    |   %empty                      {}
    
actualscontent:
        expr comma actualscontent {}
        | expr { }

constant:
        integer                 { $$ = {$1,"int"}; }
    |   float              { $$ = {$1,"double"}; }
    |   boolean                { $$ = {$1,"bool"}; }
    |   string              { $$ = {$1,"string"}; }
    |   nullkw                        {}

%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
