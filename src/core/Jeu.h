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
		Menu menuMap;
		Tour * tourSelectionne;
		std::vector<Bouton> tabBouton;
		std::vector<Bouton> tabBoutonTour;
		Niveau *niv;
		bool pause;
		Bouton bpause;
		int mapSelect;
		bool gagner;
		bool perdue;
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
		void afficheCarteDispo()const;
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
		void actionAuto(const float &delta);
		/**
			@brief Procédure: clique
			Permet de savoir si le curseur est sur le jeu ou pas
			@param Entier x, Entier y, Entier taille
			@code
				i2.clique(x,y,taille);
			@endcode	
		*/


		void clique(const int & x, const int & y , const int & taille);
		/**
			@brief Fonction: tourSelect
			Permet de retourner la tour sélectionner
			@return tourSelect
			@code
				i2.tourSelect();
			@endcode	
		*/	
		Tour * tourSelect();
		/**
			@brief Tableau de Bouton: renvoieBoutonAmelioration
			Permet de retourner un tableau de bouton
			@return Tableau de Bouton
			@code
				i2.renvoieBoutonAmelioration();
			@endcode
		*/
		std::vector<Bouton> * renvoieBoutonAmelioration();
		/**
			@brief Tableau de Bouton: renvoieBoutonTour
			Permet de retourner un tableau de bouton
			@return Tableau de Bouton
			@code
				i2.renvoirBoutonTour();
			@endcode
		*/
		std::vector<Bouton> * renvoieBoutonTour();
		/**
			@brief Procédure: changerMap
			Permet d'avoir de changer de carte
			@param Entier m
			@code
				i2.changerMap(m);
			@endcode	
		*/
		void changerMap(const int & m);
		/**
			@brief Booléen: getPause
			Permet de savoir si le jeu est en pause
			@code
				i2.getPause();
			@endcode	
		*/
		bool getPause()const;
		/**
			@brief Fonction: getBoutonPause
			Permet de retourner un bouton
			@return Bouton
			@code
				i2.getBoutonPause();
			@endcode	
		*/
		Bouton getBoutonPause()const;
		/**
			@brief Procédure: Pause
			Permet de mettre en pause
			@code
				i2.Pause();
			@endcode	
		*/
		void Pause();
		/**
			@brief Chaine de caractère: getImageMaps
			Permet de retourner le nom de l'image de la map sélectionnée
			@return Nom de l'image qu'on sélectionne
			@code
				i2.getImageMap();
			@endcode
		*/
		std::string getImageMap()const;
		/**
			@brief Fonction: getMenuMap
			Permet de retourner le menu
			@return IMenu
			@code
				i2.getMenuMap();
			@endcode
		*/
		Menu getMenuMap()const;
		/**
			@brief Booléen: getGagner
			Permet de savoir si la partie a été gagnée
			@code
				i2.getGagner();
			@endcode	
		*/
		bool getGagner()const;
		/**
			@brief Booléen: getPerdue
			Permet de savoir si la partie a été perdue
			@code
				i2.getPerdue();
			@endcode	
		*/
		bool getPerdue()const; 
};

#endif