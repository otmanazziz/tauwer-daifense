#ifndef CHEMIN
#define CHEMIN
#include <vector>
#include "Vect.h"
class chemin{
	private : 
		std::vector<Vect> tabEtape ; 
	public:
		Chemin(const vector<Vect>);
		void ajouterEtape(const Vect & v);
		Vect prochaineEtape(const int & e );
		
	
}

#endif