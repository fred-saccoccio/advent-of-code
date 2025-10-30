%{
#include <iostream>
#include <string>
#include <cmath>
#include "Scanner1.hpp"
%}
 
%require "3.7.4"
%language "C++"
%defines "Parser1.hpp"
%output "Parser1.cpp"
  
%define api.parser.class {Parser}
%define api.namespace {calc}
%define api.value.type variant
%param {yyscan_t scanner}
   
%code provides
{
  #define YY_DECL \
  int yylex(calc::Parser::semantic_type *yylval, yyscan_t yyscanner)
  YY_DECL;
}
                    
%token              OP_NOT 
%token              OP_AND OP_OR 
%token              OP_RSHIFT OP_LSHIFT
%token              CONNECT 
%token              EOL LPAREN RPAREN
%token <char>       WIRE_NAME 
%token <unsigned short> USHORT 
                       
%code
{
  namespace calc {
    long long ivars['Z' - 'A' + 1];
    double fvars['z' - 'a' + 1];

    long long factorial(long long n) {
      if (n < 2) {
        return 1;
      } else {
        return n * factorial(n - 1);
      }
    }
  } // namespace calc
} // %code

%%
lines   : %empty
        | lines line
;
 
line    : EOL                         { std::cerr << "Read an empty line.\n"; }
        | USHORT CONNECT WIRE_NAME EOL 
          { 
            std::cout << "syn:Immediate connection matched\n";
            std::cout << "syn:Set level " << $1 << " to '" << $3 << "'" << std::endl; 
           }
        | WIRE_NAME CONNECT WIRE_NAME { std::cout << "syn:Connect '" << $1 << "' to '" << $3 << "'\n"; }
        | error EOL                   { yyerrok; }
        ;
 
%%
  
void calc::Parser::error(const std::string& msg) {
  std::cerr << msg << '\n';
}

