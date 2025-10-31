%{
#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include "Expression.h"
#include "Scanner1.hpp"
#include "WireMachine.h" 
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
                    
%token              EOL 
%token              OP_NOT 
%token              OP_AND OP_OR 
%token              OP_RSHIFT OP_LSHIFT
%token              CONNECT 
%token              QUERY 
%token <std::string> WIRE_NAME
%token <unsigned short> USHORT
%type  <std::shared_ptr<Expression>> expr

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
    WireMachine m;
  } // namespace calc
} // %code

%%
lines   : %empty
        | lines line
;
 
line    : EOL                         { }
        | QUERY WIRE_NAME             
          { 
            std::cout << "Query matched for wire " << $2 <<  std::endl;
            unsigned short w = 0; 
            try {
              w = m.QueryWireNodeValue($2);
              std::cout << $2 << "=" << w << endl; 
            } catch(std::string exc) {
              std::cout << "Error: " << exc << std::endl; 
            }
          }
        | expr CONNECT WIRE_NAME EOL  
          { 
            $1->print(); 
            std::cout << "wire=" << $3 << std::endl;
            WireNode w;
            w.Name = $3;
            switch($1->Type) {
              case VALUE:
                w.Type = IMMEDIATE;
                w.Value = $1->Value;
                m.AddWireNode(w);
                break;
              case WIRE:
                w.Type = SINGLE;
                w.Connections[0] = $1->Operands[0];
                m.AddWireNode(w);
                break;
              case NOT:
                w.Type = OP_NOT;
                w.Connections[0] = $1->Operands[0];
                m.AddWireNode(w);
                break;
            }
          }
        | error EOL                   { yyerrok; }
        ;
expr    : USHORT                      { $$ = std::make_shared<Expression>(VALUE, $1); }
        | WIRE_NAME                   { $$ = std::make_shared<Expression>(WIRE, 0, $1); }
        | OP_NOT WIRE_NAME            { $$ = std::make_shared<Expression>(NOT, 0, $2); }
        | OP_NOT USHORT               { $$ = std::make_shared<Expression>(VALUE, ~$2); }
        | WIRE_NAME OP_AND WIRE_NAME  { $$ = std::make_shared<Expression>(AND, 0, $1, $3); }
        | USHORT    OP_AND WIRE_NAME  { $$ = std::make_shared<Expression>(AND_SINGLE, $1, $3); }
        | WIRE_NAME OP_AND USHORT     { $$ = std::make_shared<Expression>(AND_SINGLE, $3, $1); }
        | USHORT    OP_AND USHORT     { $$ = std::make_shared<Expression>(VALUE, $1 & $3); }
        | WIRE_NAME OP_OR WIRE_NAME   { $$ = std::make_shared<Expression>(OR, 0, $1, $3); }
        | USHORT    OP_OR WIRE_NAME   { $$ = std::make_shared<Expression>(OR_SINGLE, $1, $3); }
        | WIRE_NAME OP_OR USHORT      { $$ = std::make_shared<Expression>(OR_SINGLE, $3, $1); }
        | USHORT    OP_OR USHORT      { $$ = std::make_shared<Expression>(VALUE, $1 | $3); }
        | USHORT    OP_LSHIFT USHORT  { $$ = std::make_shared<Expression>(VALUE, $1 >> $3); }
        | WIRE_NAME OP_LSHIFT USHORT  { $$ = std::make_shared<Expression>(SHIFTL, $3, $1); }
        | USHORT    OP_RSHIFT USHORT  { $$ = std::make_shared<Expression>(VALUE, $1 << $3); }
        | WIRE_NAME OP_RSHIFT USHORT  { $$ = std::make_shared<Expression>(SHIFTR, $3, $1); }
%%
  
void calc::Parser::error(const std::string& msg) {
  std::cerr << msg << '\n';
}

