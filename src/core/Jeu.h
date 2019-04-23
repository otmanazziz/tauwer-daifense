#ifndef _JEU_H
#define _JEU_H
#include "Niveau.h"
#include <vector>
#include <string>
#include <iostream>
#include "fonction.h"
#include "Menu.h"
/**
	@brief Class Jeu
	Classe de Jeu permettant de gérer le menu, les cartes et les niveaux
*/
class Jeu{
	private:
		std::vector<std::string> tabLienCarte;
		Menu principale;
		Tour * tourSelectionne;
		std::vector<Bouton> tabBouton;
		std::vector<Bouton> tabBoutonTour;
		Niveau *niv;
		bool pause;
		Bouton bpause;
	public :
		/**
			@brief Constructeur par défaut: Jeu
			Permet de créer le jeu par défaut
			@code
				Jeu j;
			@endcode
		*/	
		Jeu();
		/** 
			@brief Destructeur
			Permet de détruire le jeu

		*/
		~Jeu();
		/**
			@brief Procédure: afficheCarteDispo
			Permet d'afficher la carte
			@code
				j2.afficheCarteDispo();
			@endcode	
		*/
		void afficheCarteDispo();
		/**
			@brief Fonction: getNiveau
			Permet de retourner le pointeur de niveau
			@return Niveau niv
			@code
				j2->getNiveau();
			@endcode	
		*/
		Niveau *getNiveau(); 
		/**
			@brief Procédure: actionAuto
			Permet d'avoir des actions automatiques
			@param Réel delta
			@code
				i2.actionAuto();
			@endcode	
		*/
		void actionAuto(float delta);

		void clique(int x, int y,int taille);
		Tour * tourSelect();
		std::vector<Bouton> * renvoieBoutonAmelioration();

		std::vector<Bouton> * renvoieBoutonTour();
		void changerMap(int m);
		bool getPause();
		Bouton getBoutonPause();

};

#endif