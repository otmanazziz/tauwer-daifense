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
		
		std::vector<Vague> tabVague;
		Base base;
		std::string fichier;
	public:std::vector<Chemin> tabChemin;
		Carte(const std::string & f);
		~Carte();
		bool reinit();
		Tour tourIndice(const int & i); 
		Vague vagueIndice(const int & i);
		Chemin cheminIndice(const int & i);
};

#endif

