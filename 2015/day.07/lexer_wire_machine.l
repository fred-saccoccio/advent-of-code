%{
#include <cstdlib>
#include "Parser1.hpp"
using namespace calc;
%}
   
%option reentrant interactive noyywrap noyylineno nodefault outfile="Scanner1.cpp" header="Scanner1.hpp"
    
dseq            ([[:digit:]]+)
exp_opt         ({exp}?)
u_short         ({dseq}) 
wire_name       ([[:lower:]]+)
 
%%
      
{u_short}   yylval->emplace<unsigned short>((unsigned short)strtoul(yytext, nullptr, 10)); return Parser::token::USHORT;
{wire_name} yylval->emplace<char>(yytext[0]); return Parser::token::WIRE_NAME;
"NOT"       return Parser::token::OP_NOT;
"AND"       return Parser::token::OP_AND;
"OR"        return Parser::token::OP_OR;
"LSHIFT"    return Parser::token::OP_LSHIFT;
"RSHIFT"    return Parser::token::OP_RSHIFT;
"->"        std::cout << "lex:CONNECT matched\n"; return Parser::token::CONNECT;
\n          return Parser::token::EOL;
<<EOF>>     return Parser::token::YYEOF;
.           /* no action on unmatched input */
       
%%
        
int main() {
  yyscan_t scanner;
  yylex_init(&scanner);
  calc::Parser parser{ scanner };
  std::cout.precision(10);
  parser.parse();
  yylex_destroy(scanner);
}

