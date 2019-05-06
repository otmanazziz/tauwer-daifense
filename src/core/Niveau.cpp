#include "Niveau.h"

Niveau::Niveau(): carte() {
	Or = 0;
	score = 0;
	
	
}

Niveau::Niveau(const std::string & f):carte(f){
	Or = 100;
	score = 0;
	
	
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

void Niveau::maj(float delta){
	carte.maj(*this, delta);
}

bool Niveau::perdue(){
	return carte.getBase().getVie() <= 0;
}

bool Niveau::finNiveau(){
	return carte.tailleTabVague() <= 0;
}