#include "Chemin.h"

Chemin::Chemin(const vector<Vect> t ){
		tabEtape = t ; 		
}

void Chemin::ajouterEtape(const Vect & v){
	tabEtape.push_back(v);
}

Vect Chemin::prochaineEtape(const int & e ){
	return tabEtape[e];
}