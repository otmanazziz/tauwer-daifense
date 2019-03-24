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
		Carte *addrGetCarte();
		
		void ajouterOr(unsigned int o);
		void retirerOr(unsigned int o);
		void affiche();

};

#endif