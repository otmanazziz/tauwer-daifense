#ifndef MONSTRE
#define MONSTRE

#include "Vect.h"
class Monstre{
private:
	Vect pos; 
	float vitesse;
	int entier; 
	int etape;

public:
	Monstre();
	void perdreVie(const int &n);
	Monstre(const int & v , const float & vit , const Vect & p );
	
};

#endif