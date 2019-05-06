#include "Niveau.h"

Niveau::Niveau(): carte() {
	Or = 0;
	score = 0;
	
	
}

Niveau::Niveau(const std::string & f):carte(f){
	Or = 100;
	score = 0;
	
	
}

Carte Niveau::getCarte()const{
	return carte;
}

unsigned int Niveau::getOr()const{
	return Or;
}

Carte *Niveau::addrGetCarte(){
	return &carte;
}


void Niveau::ajouterOr(const unsigned int & o){
	Or += o;
	score += o;
}

void Niveau::retirerOr(const unsigned int &o){
	Or = ((int(Or)- int(o)) <= 0) ? 0 : Or - o;
}

void Niveau::affiche()const{
	std::cout<<"Or : "<<Or<<std::endl<<"Score : "<<score<<std::endl;
	carte.affiche();
	
}

void Niveau::maj(const float & delta){
	carte.maj(*this, delta);
}

bool Niveau::perdue()const{
	return carte.getBase().getVie() <= 0;
}

bool Niveau::finNiveau()const{
	return carte.tailleTabVague() <= 0;
}

unsigned int Niveau::getScore()const{
	return score;
}