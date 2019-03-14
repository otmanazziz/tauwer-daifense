#ifndef MONSTRE
#define MONSTRE

#include "Vect.h"
class Monstre{
private:
	Vect pos ; 
	float vitesse ;
	int entier ; 
	int etape ;

public:
	void perdreVie(const int & n );
	
}

#endif