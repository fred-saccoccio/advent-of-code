#ifndef __TYPE_EXPRESSION__
#define __TYPE_EXPRESSION__

#include<string>
#include <iostream>

enum TypeExpr {
  VALUE,
  NOT,
  AND,
  AND_SINGLE,
  OR,
  OR_SINGLE,
  SHIFTL,
  SHIFTR,
  WIRE
};

struct Expression {
  TypeExpr Type;
  unsigned short Value;
  std::string Operands[2];
  Expression(TypeExpr t, unsigned short v = 0, 
      std::string op1 = "", 
      std::string op2 ="") {
    Type = t;
    Value = v;
    Operands[0] = op1;
    Operands[1] = op2;
  } 
  void print() {
    std::cout << "Type=" << typeToStr(Type) << std::endl;
    std::cout << "Value=" << Value << std::endl;
    std::cout << "Operands[0]=" << Operands[0] << std::endl;
    std::cout << "Operands[1]=" << Operands[1] << std::endl;
  }
  
  private:
  std::string typeToStr(TypeExpr t) {
    switch(t) {
      case VALUE:
        return std::string("VALUE");
      case NOT:
        return std::string("NOT");
      case AND:
        return std::string("AND");
      case AND_SINGLE:
        return std::string("AND_SINGLE");
      case OR:
        return std::string("OR");
      case OR_SINGLE:
        return std::string("OR_SINGLE");
      case SHIFTL:
        return std::string("SHIFTL");
      case SHIFTR:
        return std::string("SHIFTR");
      case WIRE:
        return std::string("WIRE");
      default:
        return std::string("UNKNOWN");
    }
  } 
};

#endif

/*
#ifndef AST_HPP 
#define AST_HPP 
#include <memory> 
#include <iostream> 
#include <string> 
struct Expr { 
  virtual ~Expr() = default; 
  virtual void print() const = 0; 
}; 
struct IntExpr : Expr {
  int value; 
  IntExpr(int v) : value(v) {} 
  void print() const override { 
    std::cout << value; 
  } 
}; 
struct AddExpr : Expr { 
  std::shared_ptr<Expr> left, right; 
  AddExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r) : left(std::move(l)), right(std::move(r)) {} 
  void print() const override { 
    std::cout << "("; 
    left->print(); 
    std::cout << " + "; 
    right->print(); 
    std::cout << ")"; 
  } 
}; 
struct MulExpr : Expr { 
  std::shared_ptr<Expr> left, right; 
  MulExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r) : left(std::move(l)), right(std::move(r)) {} 
  void print() const override { 
    std::cout << "("; 
    left->print(); 
    std::cout << " * "; 
    right->print(); 
    std::cout << ")"; 
  } 
}; 
#endif
*/
