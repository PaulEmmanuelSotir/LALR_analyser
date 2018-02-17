#ifndef ETAT_H
#define ETAT_H
#include <string>
#include "symbole.h"

class Automate;

class Etat {
   public:
      virtual ~Etat() = default;
      void print() const;
      virtual bool transition(Automate& automate, Symbole s) const = 0;
};

class E0 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E1 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E2 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E3 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E4 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E5 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E6 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E7 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E8 : public Etat { bool transition(Automate& automate, Symbole s) const; };
class E9 : public Etat { bool transition(Automate& automate, Symbole s) const; };

#endif
