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

Vect Chemin::prochaineEtape(const int & e){
	return tabEtape[e];
}