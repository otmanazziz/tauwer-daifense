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
class Niveau;
class Carte{
	private: 
		std::vector<Tour> tabTour;
		std::vector<Chemin> tabChemin;
		std::vector<Vague> tabVague;
		Base base;
		std::string fichier;
	public:
		/**
			@brief Constructeur par défaut: Carte
			Permet de créer la carte par défaut
			@code
			Carte c;
			@endcode
		*/
		Carte();
		/**
 			@brief Constructeur par copie: Carte
 			Permet de créer par copie une nouvelle carte
 			@code
 			Carte c1(c);
 			@endcode	
 		*/	
		Carte(const Carte & c);
		/**
			@brief Constructeur:Carte
			Permet de créer le constructeur de la carte avec les données privées de la fonction
			@param Chaîne de caractère f
			@code
			Carte c2(Chaîne de caractère)
			@endcode	

		*/
		Carte(const std::string & f);
		/** 
			@brief Destructeur
			Permet de détruire la carte

		*/
		~Carte();
		bool reinit();
		Tour tourIndice(const int & i); 
		Vague vagueIndice(const int & i);
		Chemin cheminIndice(const int & i);

		unsigned int tailleTabTour();
		unsigned int tailleTabChemin();
		unsigned int tailleTabVague();

		Tour * addrTourIndice(const int & i);

		Vague * addrVagueIndice(const int & i);

		Chemin * addrCheminIndice(const int & i);
		void maj(Niveau & n);
		Base getBase();
		void setFichier(const std::string & f);
		void affiche();
};

#endif

