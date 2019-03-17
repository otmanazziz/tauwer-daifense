#ifndef SORT
#define SORT

#include "Attaque.h"
#include <string>

class Sort{
private:
	std::string nom;
	Attaque attaque;
public:
	Sort();
	Sort(const Sort &_Sort);
	Sort(const std::string &_nom, const Attaque &_attaque);
	~Sort();	

	std::string getNom();
	Attaque getAttaque();

	void setNom(const std::string &_nom);
	void setAttaque(const Attaque &_attaque);
};

#endif