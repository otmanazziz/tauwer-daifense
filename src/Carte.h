#ifndef CARTE
#define CARTE
#include "Tour.h"
#include "Chemin.h"
#include "Base.h"
#include "Vague.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
class Carte{
	private: 
		vector<Tour> tabTour;
		vector<Chemin> tabChemin;
		vector<Vague> tabVague;
		Base base;
		string fichier;
	public :
		Carte(const string & f);
		bool reinit();
}

#endif

