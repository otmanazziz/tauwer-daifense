#include "Niveau.h"

Niveau::Niveau(): carte() {
	Or = 0;
	score = 0;
	hero = NULL;
	
}

Niveau::Niveau(const std::string & f):carte(f){
	Or = 0;
	score = 0;
	hero = NULL;
	
	//carte.getBase().affiche();
	
}

Carte Niveau::getCarte(){
	//std::cout <<" getCarte"; carte.getBase().affiche();
	return carte;
}

void Niveau::ajouterOr(unsigned int o){
	Or =+ o;
}

void Niveau::retirerOr(unsigned int o){
	Or =- o;
}

