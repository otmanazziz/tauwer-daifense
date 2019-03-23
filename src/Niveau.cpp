#include "Niveau.h"

Niveau::Niveau(){
	Or = 0;
	score = 0;
	hero = NULL;
}

Niveau::Niveau(const std::string & f){
	Or = 0;
	score = 0;
	hero = NULL;
	carte.setFichier(f);
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

