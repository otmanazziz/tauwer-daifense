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
	
}

Carte Niveau::getCarte(){
	return carte;
}

Carte *Niveau::addrGetCarte(){
	return &carte;
}


void Niveau::ajouterOr(unsigned int o){
	Or =+ o;
}

void Niveau::retirerOr(unsigned int o){
	Or =- o;
}

void Niveau::affiche(){
	std::cout<<"Or : "<<Or<<std::endl<<"Score : "<<score<<std::endl;
	carte.affiche();
	
}