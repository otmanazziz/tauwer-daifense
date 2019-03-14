#ifndef MONSTRE
#define MONSTRE

#include "Vect.h"
class Monstre{
private:
	Vect pos ; 
	float vitesse ;
	int vie ; 
	int etape ;

public:
	
	Monstre(const int & v , const float & vit , const Vect & p );
	void perdreVie(const int & n );
	
}

#endif