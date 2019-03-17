#ifndef TOUR
#define TOUR

#include "Vect.h"
#include "Attaque.h"

class Tour{
private:
	float vitesseAtq;
	int portee;
	Vect position;
	Attaque attaque;
public:
	Tour();
	Tour(const Tour &_tour);
	Tour(const float &_vitesseAtq, const int &_portee, const Vect _position);
	~Tour();

	float getVitAtq();
	int getPortee();
	Vect getPosition();

	void setVitAtq(const float &_vitesseAtq);
	void setPortee(const float &_portee);
	void setPosition(const Vect &_position);

	void affiche();

};

#endif