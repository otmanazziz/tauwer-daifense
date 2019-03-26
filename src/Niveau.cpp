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

unsigned int Niveau::getOr(){
	return Or;
}

Carte *Niveau::addrGetCarte(){
	return &carte;
}


void Niveau::ajouterOr(unsigned int o){
	Or += o;
}

void Niveau::retirerOr(unsigned int o){
	Or = ((int(Or)- int(o)) <= 0) ? 0 : Or - o;
}

void Niveau::affiche(){
	std::cout<<"Or : "<<Or<<std::endl<<"Score : "<<score<<std::endl;
	carte.affiche();
	
}

void Niveau::maj(){
	carte.maj(*this);
}