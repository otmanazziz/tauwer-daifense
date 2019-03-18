#ifndef CARTE
#define CARTE
#include "Tour.h"
#include "Chemin.h"
#include "Base.h"
#include "Vague.h"
#include "fonction.h"
#include "Monstre.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Carte{
	private: 
		std::vector<Tour> tabTour;
		std::vector<Chemin> tabChemin;
		std::vector<Vague> tabVague;
		Base base;
		std::string fichier;
	public:
		Carte(const std::string & f);
		~Carte();
		bool reinit();
		Tour tourIndice(const int & i); 
};

#endif

