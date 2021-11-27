/* Parser for calc++.   -*- C++ -*-

   Copyright (C) 2005-2015, 2018-2021 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

%skeleton "lalr1.cc" // -*- C++ -*-
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
using namespace std;
}

%define api.token.prefix {TOK_}


%token <std::string> id
%token <std::string> string
%token define import semicolon integer double bool string_kw
%token openclosebracket;
%token openbracket closebracket private public if else while for
%token boolean void int class nullkw slash percent
%token return break new this newarray print readinteger readline
%token line func btoi continue dtoi itob itod 
%token  float plus minus star div  lessthanequal greaterthanequal
%token lessthan greaterthan equal notequal and or  closebrace
%token openparantheses closeparantheses comma assign openbrace
%token plusequal minusequal starequal slashequal not dot



%printer { yyo << $$; } <*>;

%%
%start program;

program: macro program { }
       | declerations {  }

macro: import string { }
     | define id id { }

declerations: declaration declerations { }
            | declaration {  }

declaration: variabledecl { }
           | functiondecl { }
           | classdecl { }

variabledecl: variable semicolon { }

variable: type id { }

type: int { }
    | double { }
    | bool { }
    | string_kw { }
    | id { }
    | type openclosebracket { }

functiondecl: type id openparantheses formals closeparantheses stmtblock { }
            | void id openparantheses formals closeparantheses stmtblock { }
            
formals: formalsp { }
       | %empty {  }

formalsp: variable comma formalsp { }
        | variable { }

classdecl: class id openbrace fields closebrace { cout << "dally"; }

fields: field fields { }
      | %empty

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
      | if openparantheses expr closeparantheses stmt elsestmt{ }

elsestmt: else stmt { }

whilestmt: while openparantheses expr closeparantheses stmt { }

forstmt: for openparantheses nexpr semicolon expr semicolon nexpr closeparantheses stmt { }

returnstmt: return nexpr semicolon { }

breakstmt: break semicolon { }

nexpr: expr { }
    | %empty { }

continuestmt: continue semicolon { }


printstmt:
        print openparantheses printcontent  closeparantheses semicolon       {}



printcontent: printcontent comma expr {}
            | expr {}

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
    |   constant                    {}
    |   lvalue                      {}
    |   this                        {}
    |   call                        {}
    |   openparantheses expr closeparantheses                      {}
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
        id                       { cout << "id e too lvalue: " << $1 << endl;}
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
        integer                 {}
    |   float              {}
    |   boolean                {}
    |   string              {}
    |   nullkw                        {}




%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
