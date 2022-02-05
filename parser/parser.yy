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

stmtblock: openbrace { cg.openstmtblock(); } stmtblockcontent closebrace { cg.closestmtblock(); }

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

//%right  else closeparantheses;
ifstmt:
       if openparantheses expr closeparantheses { cg.ifstmt($3); } stmt elsestmt { }

elsestmt: else { cg.elselabel(); } stmt { cg.endelse(); }
        | %empty { cg.endiflabel(); }

whilestmt: while openparantheses { cg.whilestmt1(); } expr closeparantheses { cg.whilestmt2($3); } stmt { cg.whilestmt3(); }

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

%left comma;
%left assign plusequal slashequal minusequal starequal;
%left or;
%left and;
%left equal notequal;
%left lessthan greaterthan lessthanequal greaterthanequal;
%left plus minus;
%left star slash percent;
%left not;
%left dot;
%right openparantheses openbracket openbrace;

expr:
        constant                    { $$ = cg.addconstant($1); }
    |   lvalue                      { $$ = cg.findid($1); }
    |   this                        {}
    |   call                        {}
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
    |   lvalue assign expr               { $$ = cg.assignexpr($1,$3); }
    |   lvalue plusequal expr             { $$ = cg.assignexproperation($1,$3,$2); }
    |   lvalue minusequal expr             { $$ = cg.assignexproperation($1,$3,$2); }
    |   lvalue starequal expr             { $$ = cg.assignexproperation($1,$3,$2); }
    |   lvalue slashequal expr             { $$ = cg.assignexproperation($1,$3,$2); }
    |   expr or expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr and expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr equal expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr notequal expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr lessthan expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr lessthanequal expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr greaterthan expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr greaterthanequal expr                { $$ = cg.exproperation($1,$3,$2); }
    |   expr plus expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr minus expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr star expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr slash expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   expr percent expr                 { $$ = cg.exproperation($1,$3,$2); }
    |   minus expr                      { $$ = cg.unaryminus($2); }
    |   not expr                      {}
    |   openparantheses expr closeparantheses                      { $$ = $2; }

lvalue:
        id                       { $$ = $1; }
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
