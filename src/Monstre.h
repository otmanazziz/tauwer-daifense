#ifndef MONSTRE
#define MONSTRE

#include "Vect.h"
class Monstre{
private:
<<<<<<< HEAD
	Vect pos; 
	float vitesse;
	int entier; 
	int etape;

public:
	Monstre();
	void perdreVie(const int &n);
=======
	Vect pos ; 
	float vitesse ;
	int vie ; 
	int etape ;

public:
	
	Monstre(const int & v , const float & vit , const Vect & p );
	void perdreVie(const int & n );
>>>>>>> bf8618b9a587fc4cf283109e9e4aacf916325cf9
	
}

#endif