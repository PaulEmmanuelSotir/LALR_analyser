#include "etat.h"
#include "symbole.h"
#include "automate.h"

// TODO: regler le problème de cast dangeureux en (Expr) dans les réductions
// TODO: éviter la réplication de code et les switch case de merde

// TODO: surcharger << à la place
void print() { }

bool E0::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case INT:
			automate.decalage(s, new E3);
			break;
		case OPENPAR:
			automate.decalage(s, new E2);
			break;
		case EXPR:
			automate.decalage(s, new E1);
			break;
	}
	return false;
}

bool E1::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case PLUS:
			automate.decalage(s, new E4);
			break;
		case MULT:
			automate.decalage(s, new E5);
			break;
		case FIN:
			return true; // accepter
	}
	return false;
}


bool E2::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case INT:
			automate.decalage(s, new E3);
			break;
		case OPENPAR:
			automate.decalage(s, new E2);
			break;
	}
	return false;
}

bool E3::transition(Automate& automate, Symbole s) const {
	// Reduction 5
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce symbole
	Entier s1 = (Entier)automate.popSymbol();
	automate.reduction(1, Expr());
}

bool E4::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case INT:
			automate.decalage(s, new E3);
			break;
		case OPENPAR:
			automate.decalage(s, new E2);
			break;
	}
	return false;
}

bool E5::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case INT:
			automate.decalage(s, new E3);
			break;
		case OPENPAR:
			automate.decalage(s, new E2);
			break;
	}
	return false;
}

bool E6::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case PLUS:
			automate.decalage(s, new E4);
			break;
		case MULT:
			automate.decalage(s, new E5);
			break;
		case CLOSEPAR:
			automate.decalage(s, new E9);
			break;
	}
	return false;
}


bool E7::transition(Automate& automate, Symbole s) const {
	switch(s) {
		case MULT:
			automate.decalage(s, new E5);
			break;
		default:
			// Reduction 2
			automate.pushSymbol(s); // LR(1), on ne consomme pas ce symbole
			Expr s1 = (Expr)automate.popSymbol();
			automate.popSymbol();
			Expr s2 = (Expr)automate.popSymbol();
			automate.reduction(3, Expr());
		break;
	}
	return false;
}

bool E8::transition(Automate& automate, Symbole s) const {
	// Reduction 3
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce symbole
	Expr s1 = (Expr)automate.popSymbol();
	automate.popSymbol();
	Expr s2 = (Expr)automate.popSymbol();
	automate.reduction(3, Expr());
}

bool E9::transition(Automate& automate, Symbole s) const {
	// Reduction 4
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce symbole
	automate.popSymbol();
	Expr s1 = (Expr)automate.popSymbol();
	automate.popSymbol();
	automate.reduction(3, Expr());
}


