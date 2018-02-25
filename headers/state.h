#ifndef ETAT_H
#define ETAT_H
#include <string>
#include "symbol.h"

class Lexer;

class State
{
   public:
      virtual ~State() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const = 0;
};

class E0 : public State {
public:
      virtual ~E0() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E1 : public State {
public:
      virtual ~E1() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E2 : public State {
public:
      virtual ~E2() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};
class E3 : public State {
public:
      virtual ~E3() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E4 : public State {
public:
      virtual ~E4() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E5 : public State {
public:
      virtual ~E5() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E6 : public State {
public:
      virtual ~E6() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E7 : public State {
public:
      virtual ~E7() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E8 : public State {
public:
      virtual ~E8() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

class E9 : public State {
public:
      virtual ~E9() = default;
      virtual bool transition(Lexer& lexer, Symbol s) const;
};

#endif
