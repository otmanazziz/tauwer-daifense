#ifndef CHEMIN
#define CHEMIN
#include <vector>
#include "Vect.h"
class Chemin{
	private : 
		std::vector<Vect> tabEtape ; 
	public :
		Chemin(const std::vector<Vect> &  v);
		~Chemin();
		void ajouterEtape(const Vect & v);
		Vect prochaineEtape(const int & e );
		
	
};

#endif