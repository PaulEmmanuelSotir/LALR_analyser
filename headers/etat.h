#ifndef ETAT_H
#define ETAT_H
#include <string>
#include "symbol.h"

class Automate;

class Etat
{
   public:
      virtual ~Etat() = default;
      virtual bool transition(Automate& automate, Symbol s) const = 0;
};

class E0 : public Etat {
public:
      virtual ~E0() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E1 : public Etat {
public:
      virtual ~E1() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E2 : public Etat {
public:
      virtual ~E2() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};
class E3 : public Etat {
public:
      virtual ~E3() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E4 : public Etat {
public:
      virtual ~E4() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E5 : public Etat {
public:
      virtual ~E5() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E6 : public Etat {
public:
      virtual ~E6() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E7 : public Etat {
public:
      virtual ~E7() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E8 : public Etat {
public:
      virtual ~E8() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

class E9 : public Etat {
public:
      virtual ~E9() = default;
      virtual bool transition(Automate& automate, Symbol s) const;
};

#endif
