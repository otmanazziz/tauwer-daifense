#ifndef NIVEAU
#define NIVEAU
#include "Carte.h"
#include "Hero.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
class Niveau{
	private : 
		Carte carte;
		Hero * hero;
		unsigned int Or;
		int score;
	public :
	
		Niveau();
		Niveau(const std::string & f);

		Carte getCarte();
		unsigned int getOr();
		Carte *addrGetCarte();
		void maj(float delta);
		void ajouterOr(unsigned int o);
		void retirerOr(unsigned int o);
		void affiche();

};

#endif