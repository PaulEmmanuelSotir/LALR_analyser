#ifndef SYMBOLE_H
#define SYMBOLE_H
#include <string>
#include <map>

//TODO: remplacer par une class enum et verifier qu'il fallait bien ajouter EXPR
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXPR, ERREUR }; 
const std::string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXPR", "ERREUR" };

// TODO: Rendre les classes imutables
class Symbole {
	public:
		Symbole(int i) : ident(i) { };
		virtual ~Symbole() = default;
		operator int() const { return ident; };
		virtual void Affiche() const;
	protected:
		const int ident; // TODO: remplacer ident par l'utilisation de l'enum (underlying value)
};

class Expr : public Symbole {
	public:
		Expr() : Symbole(EXPR) { };
		virtual ~Expr() = default;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { };
      virtual ~Entier() = default;
      virtual void Affiche() const;
   protected:
      const int valeur;
};

#endif
