#include <FlexLexer.h>
#include "tokens.hpp"
#include <iostream>
using namespace std;
void scan(istream& i,ostream& o)
{
    int res;
    FlexLexer* lexer = new yyFlexLexer(&i);
    while((res = lexer->yylex()) != 0){
        switch(res){
            case ID: o << "T_ID " << lexer->YYText() << endl; break;
            case VOID:          o << "void"          << endl; break;
            case INT:           o << "int"           << endl; break;
            case DOUBLE:        o << "double"        << endl; break;
            case BOOL:          o << "bool"          << endl; break; 
            case STRING_KW:     o << "string"        << endl; break; 
            case CLASS:         o << "class"         << endl; break; 
            case _NULL:         o << "null"          << endl; break; 
            case FOR:           o << "for"           << endl; break; 
            case WHILE:         o << "while"         << endl; break; 
            case IF:            o << "if"            << endl; break; 
            case ELSE:          o << "else"          << endl; break; 
            case RETURN:        o << "return"        << endl; break; 
            case BREAK:         o << "break"         << endl; break; 
            case NEW:           o << "new"           << endl; break; 
            case THIS:          o << "this"          << endl; break; 
            case NEWARRAY:      o << "NewArray"      << endl; break; 
            case PRINT:         o << "Print"         << endl; break; 
            case READINTEGER:   o << "ReadInteger"   << endl; break; 
            case READLINE:      o << "ReadLine"      << endl; break; 

            case INTEGER:
             o << "T_INTLITERAL " << lexer->YYText() << endl; break; 
            case FLOAT:         
             o << "T_DOUBLELITERAL " << lexer->YYText() << endl; break;

            case PLUS:                o << "+"  << endl; break;    
            case MINUS:               o << "-"  << endl; break;   
            case STAR:                o << "*"  << endl; break;   
            case LESSTHAN:            o << "<"  << endl; break;   
            case GREATERTHAN:         o << ">"  << endl; break;   
            case LESSTHANEQUAL:       o << "<=" << endl; break;
            case GREATERTHANEQUAL:    o << ">=" << endl; break;
            case EQUAL:               o << "==" << endl; break;
            case NOTEQUAL:            o << "!=" << endl; break;
            case AND:                 o << "&&" << endl; break;
            case OR:                  o << "||" << endl; break;
            case OPENBRACE:           o << "{" << endl; break; 
            case CLOSEBRACE:          o << "}" << endl; break;   
            case OPENBRACKET:         o << "[" << endl; break; 
            case CLOSEBRACKET:        o << "]" << endl; break; 
            case OPENPARANTHESES:     o << "(" << endl; break; 
            case CLOSEPARANTHESES:    o << ")" << endl; break;
            case COMMA:               o << "," << endl; break;  
            case ASSIGN:              o << "=" << endl; break;
            case SEMICOLON:           o << ";" << endl; break;

            case IMPORT:              o << "import" << endl; break; 
            case LINE:                o << "__line__" << endl; break;
            case FUNC:                o << "__func__" << endl; break; 
            case STRING:                               
             o << "T_STRINGLITERAL " << lexer->YYText() << endl; break;

            case BOOLEAN: 
             o << "T_BOOLEANLITERAL " << lexer->YYText() << endl; break;
            case PLUSEQUAL:           o << "+=" << endl; break;
            case MINUSEQUAL:          o << "-=" << endl; break;
            case STAREQUAL:           o << "*=" << endl; break;
            case SLASHEQUAL:          o << "/=" << endl; break;
            case PLUSPLUS:            o << "++" << endl; break;
            case MINUSMINUS:          o << "--" << endl; break;
            case NOT:                 o << "!" << endl; break;
            case DOT:                 o << "." << endl; break;
            case DIVISION:            o << "/" << endl; break;
            case PERCENT:             o << "%" << endl; break;

            case BTOI:                o << "btoi"      << endl; break; 
            case CONTINUE:            o << "continue" << endl; break;
            case DTOI:                o << "dtoi"      << endl; break;
            case ITOB:                o << "itob"      << endl; break;
            case ITOD:                o << "itod"      << endl; break;
            case PRIVATE:             o << "private"   << endl; break; 
            case PUBLIC:              o << "public"    << endl; break; 
            case DEFINE:              o << "define"    << endl; break;
 
 
         }
     }
}
