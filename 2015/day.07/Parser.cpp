// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "grammar_wire_machine.y"

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include "Expression.h"
#include "Scanner.hpp"
#include "WireMachine.h" 

#line 51 "Parser.cpp"


#include "Parser.hpp"


// Unqualified %code blocks.
#line 39 "grammar_wire_machine.y"

  namespace wiremachine {
    long long ivars['Z' - 'A' + 1];
    double fvars['z' - 'a' + 1];

    long long factorial(long long n) {
      if (n < 2) {
        return 1;
      } else {
        return n * factorial(n - 1);
      }
    }
    
    void make_WireNode(std::shared_ptr<Expression> expr, std::string name, WireNode& w) {
      w.Name = name;

      switch(expr->Type) {
        case VALUE:
          w.Type = IMMEDIATE;
          w.Value = expr->Value;
          w.Connections[0] = "";
          w.Connections[1] = "";
          break;
        case NOT:
          w.Type = OP_NOT;
          w.Value = 0;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break; 
        case AND:
          w.Type = OP_AND_2_OPS;
          w.Value = 0;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = expr->Operands[1];
          break;
        case AND_SINGLE:
          w.Type = OP_AND_1_OP;
          w.Value = expr->Value;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break;
        case OR:
          w.Type = OP_OR_2_OPS;
          w.Value = 0;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = expr->Operands[1];
          break;
        case OR_SINGLE:
          w.Type = OP_OR_1_OP;
          w.Value = expr->Value;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break;
        case SHIFTL:
          w.Type = OP_SHIFT_L;
          w.Value = expr->Value;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break;
        case SHIFTR:
          w.Type = OP_SHIFT_R;
          w.Value = expr->Value;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break;
        case WIRE:
          w.Type = SINGLE;
          w.Value = 0;
          w.Connections[0] = expr->Operands[0];
          w.Connections[1] = "";
          break;
      }
    } 

    WireMachine m;
    WireNode w;
  } // namespace wiremachine

#line 137 "Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 17 "grammar_wire_machine.y"
namespace wiremachine {
#line 211 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (yyscan_t scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expr: // expr
        value.copy< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.copy< unsigned short > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< std::shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.move< unsigned short > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.YY_MOVE_OR_COPY< unsigned short > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.move< unsigned short > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.copy< unsigned short > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_USHORT: // USHORT
        value.move< unsigned short > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_WIRE_NAME: // WIRE_NAME
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_USHORT: // USHORT
        yylhs.value.emplace< unsigned short > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // line: EOL
#line 123 "grammar_wire_machine.y"
                                      { }
#line 770 "Parser.cpp"
    break;

  case 5: // line: QUERY WIRE_NAME
#line 125 "grammar_wire_machine.y"
          { 
            unsigned short w = 0; 
            try {
              w = m.QueryWireNodeValue(yystack_[0].value.as < std::string > (), 0);
              std::cout << yystack_[0].value.as < std::string > () << "=" << w << endl; 
            } catch(std::string exc) {
              std::cout << "Error: " << exc << std::endl; 
            }
          }
#line 784 "Parser.cpp"
    break;

  case 6: // line: expr CONNECT WIRE_NAME EOL
#line 135 "grammar_wire_machine.y"
          { 
            make_WireNode(yystack_[3].value.as < std::shared_ptr<Expression> > (), yystack_[1].value.as < std::string > (), w);
            w.print();
            m.AddWireNode(w);
          }
#line 794 "Parser.cpp"
    break;

  case 7: // line: error EOL
#line 140 "grammar_wire_machine.y"
                                      { yyerrok; }
#line 800 "Parser.cpp"
    break;

  case 8: // expr: USHORT
#line 142 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, yystack_[0].value.as < unsigned short > ()); }
#line 806 "Parser.cpp"
    break;

  case 9: // expr: WIRE_NAME
#line 143 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(WIRE, 0, yystack_[0].value.as < std::string > ()); }
#line 812 "Parser.cpp"
    break;

  case 10: // expr: OP_NOT WIRE_NAME
#line 144 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(NOT, 0, yystack_[0].value.as < std::string > ()); }
#line 818 "Parser.cpp"
    break;

  case 11: // expr: OP_NOT USHORT
#line 145 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, ~yystack_[0].value.as < unsigned short > ()); }
#line 824 "Parser.cpp"
    break;

  case 12: // expr: WIRE_NAME OP_AND WIRE_NAME
#line 146 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(AND, 0, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 830 "Parser.cpp"
    break;

  case 13: // expr: USHORT OP_AND WIRE_NAME
#line 147 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(AND_SINGLE, yystack_[2].value.as < unsigned short > (), yystack_[0].value.as < std::string > ()); }
#line 836 "Parser.cpp"
    break;

  case 14: // expr: WIRE_NAME OP_AND USHORT
#line 148 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(AND_SINGLE, yystack_[0].value.as < unsigned short > (), yystack_[2].value.as < std::string > ()); }
#line 842 "Parser.cpp"
    break;

  case 15: // expr: USHORT OP_AND USHORT
#line 149 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, yystack_[2].value.as < unsigned short > () & yystack_[0].value.as < unsigned short > ()); }
#line 848 "Parser.cpp"
    break;

  case 16: // expr: WIRE_NAME OP_OR WIRE_NAME
#line 150 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(OR, 0, yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 854 "Parser.cpp"
    break;

  case 17: // expr: USHORT OP_OR WIRE_NAME
#line 151 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(OR_SINGLE, yystack_[2].value.as < unsigned short > (), yystack_[0].value.as < std::string > ()); }
#line 860 "Parser.cpp"
    break;

  case 18: // expr: WIRE_NAME OP_OR USHORT
#line 152 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(OR_SINGLE, yystack_[0].value.as < unsigned short > (), yystack_[2].value.as < std::string > ()); }
#line 866 "Parser.cpp"
    break;

  case 19: // expr: USHORT OP_OR USHORT
#line 153 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, yystack_[2].value.as < unsigned short > () | yystack_[0].value.as < unsigned short > ()); }
#line 872 "Parser.cpp"
    break;

  case 20: // expr: USHORT OP_LSHIFT USHORT
#line 154 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, yystack_[2].value.as < unsigned short > () >> yystack_[0].value.as < unsigned short > ()); }
#line 878 "Parser.cpp"
    break;

  case 21: // expr: WIRE_NAME OP_LSHIFT USHORT
#line 155 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(SHIFTL, yystack_[0].value.as < unsigned short > (), yystack_[2].value.as < std::string > ()); }
#line 884 "Parser.cpp"
    break;

  case 22: // expr: USHORT OP_RSHIFT USHORT
#line 156 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(VALUE, yystack_[2].value.as < unsigned short > () << yystack_[0].value.as < unsigned short > ()); }
#line 890 "Parser.cpp"
    break;

  case 23: // expr: WIRE_NAME OP_RSHIFT USHORT
#line 157 "grammar_wire_machine.y"
                                      { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(SHIFTR, yystack_[0].value.as < unsigned short > (), yystack_[2].value.as < std::string > ()); }
#line 896 "Parser.cpp"
    break;


#line 900 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -7;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -7,     0,    -7,    -1,    -7,     6,    -6,     1,     8,    -7,
      10,    -7,    -7,    -7,    -7,     9,    11,    16,    17,    13,
      15,    18,    19,    21,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    30,    -7
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     1,     0,     4,     0,     0,     9,     8,     3,
       0,     7,    10,    11,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    14,    16,    18,    23,    21,
      13,    15,    17,    19,    22,    20,     0,     6
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -7,    -7,    -7,    -7
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     9,    10
  };

  const signed char
  Parser::yytable_[] =
  {
       2,     3,    11,     4,     5,    14,    15,    16,    17,    18,
       6,     7,     8,    19,    20,    21,    22,    12,    13,    23,
      24,    25,    26,    27,    30,    31,    32,    33,    28,    29,
      34,    35,    36,    37
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     1,     3,     3,     4,    11,     5,     6,     7,     8,
      10,    11,    12,     5,     6,     7,     8,    11,    12,     9,
      11,    12,    11,    12,    11,    12,    11,    12,    12,    12,
      12,    12,    11,     3
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    14,     0,     1,     3,     4,    10,    11,    12,    15,
      16,     3,    11,    12,    11,     5,     6,     7,     8,     5,
       6,     7,     8,     9,    11,    12,    11,    12,    12,    12,
      11,    12,    11,    12,    12,    12,    11,     3
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    13,    14,    14,    15,    15,    15,    15,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     4,     2,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "OP_NOT",
  "OP_AND", "OP_OR", "OP_RSHIFT", "OP_LSHIFT", "CONNECT", "QUERY",
  "WIRE_NAME", "USHORT", "$accept", "lines", "line", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   119,   119,   120,   123,   124,   134,   140,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12
    };
    // Last valid token kind.
    const int code_max = 267;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 17 "grammar_wire_machine.y"
} // wiremachine
#line 1266 "Parser.cpp"

#line 158 "grammar_wire_machine.y"

  
void wiremachine::Parser::error(const std::string& msg) {
  std::cerr << msg << '\n';
}

