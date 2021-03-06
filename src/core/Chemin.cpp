#include "Chemin.h"



Chemin::Chemin(const std::vector<Vect> & t ){
		tabEtape = t ; 		
}

Chemin::~Chemin(){
	tabEtape.clear();
}

void Chemin::ajouterEtape(const Vect & v){
	tabEtape.push_back(v);
}

Vect Chemin::prochaineEtape(const int & e)const{
	return tabEtape[e];
}

void  Chemin::affiche()const{
	for (unsigned int i = 0 ; i < tabEtape.size();i++) tabEtape[int(i)].afficheVect();
}

unsigned int Chemin::tailleChemin()const{
		return tabEtape.size();
}