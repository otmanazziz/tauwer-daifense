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
		Carte();
		Carte(const Carte & c);
		Carte(const std::string & f);
		~Carte();
		bool reinit();
		Tour tourIndice(const int & i); 
		Vague vagueIndice(const int & i);
		Chemin cheminIndice(const int & i);

		unsigned int tailleTabTour();
		unsigned int tailleTabChemin();
		unsigned int tailleTabVague();

		Tour& addrTourIndice(const int & i);

		Vague & addrVagueIndice(const int & i);

		Chemin & addrCheminIndice(const int & i);
};

#endif

