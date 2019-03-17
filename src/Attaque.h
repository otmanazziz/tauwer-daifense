#ifndef ATTAQUE
#define ATTAQUE

#include"Effet.h"

class Attaque{
private:
	int zone;
	Effet effet;
	int degats;
public:
	Attaque();	
	Attaque(const Attaque &_Attaque);
	Attaque(const int &_zone, const Effet &_effet, int &_degats);
	~Attaque();

	int getZone();
	Effet getEffet();
	int getDegats();

	void setZone(const int &_zone);
	void setEffet(const Effet &_effet);
	void setDegats(const int &_degats);

};

#endif