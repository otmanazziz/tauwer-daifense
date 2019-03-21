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
	carte = Carte(f);
}

Carte Niveau::getCarte(){
	return carte;	
}

void Niveau::ajouterOr(unsigned int o){
	Or =+ o;
}

void Niveau::retirerOr(unsigned int o){
	Or =- o;
}