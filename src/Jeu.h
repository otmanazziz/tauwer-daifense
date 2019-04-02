#ifndef JEU
#define JEU
#include "Niveau.h"
#include <vector>
#include <string>
#include <iostream>
#include "fonction.h"
#include "Menu.h"
class Jeu{
	private:
		std::vector<std::string> tabLienCarte;
		Menu principale;
		Niveau *niv;
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
			@code
				i2.actionAuto();
			@endcode	
		*/
		void actionAuto(float delta);
};

#endif