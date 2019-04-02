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
	/**
		@brief Constructeur par défaut: Niveau
		Permet de créer le niveau par défaut
		@code
			Niveau n;
		@endcode
	*/	
		Niveau();
	/**
 		@brief Constructeur par copie: Niveau
 		Permet de créer par copie un nouveau niveau
 		@param Chaîne de caractère f
 		@code
 			Niveau n1(Chaîne de caractère f);
 		@endcode	
 	*/
		Niveau(const std::string & f);
	/**
		@brief Fonction: getCarte
		Permet de retourner la carte
		@return Carte carte
		@code
			n2.getCarte();
		@endcode	
	*/
		Carte getCarte();
	/**
		@brief Fonction: getOr
		Permet de retourner le nombre d'or
		@return Entier positif or
		@code
			n2.getOr();
		@endcode	
	*/	
		unsigned int getOr();
	/**
		@brief Fonction: addrGetCarte
		Permet de retourner le pointeur de carte
		@return Carte carte
		@code
			n2->addrGetCarte();
		@endcode	
	*/	
		Carte *addrGetCarte();
	/**
		@brief Procédure: maj
		Permet de faire la mise à jour de la carte
		@param Entier delta
		@code
			n2.maj(delta);
		@endcode	
	*/
		void maj(float delta);
	/**
		@brief Procédure: ajouterOr
		Permet de gagner de l'or en tuant des ennemis
		@param Entier positif o
		@code
			n2.ajouterOr(o);
		@endcode	
	*/	
		void ajouterOr(unsigned int o);
	/**
		@brief Procédure: retirerOr
		Permet de perdre de l'or en tuant des ennemis
		@param Entier positif o
		@code
			n2.ajouterOr(o);
		@endcode	
	*/		
		void retirerOr(unsigned int o);
	/**
		@brief Procédure: affiche
		Permet d'afficher le niveau
		@code
			n2.affiche();
		@endcode	
	*/		
		void affiche();

};

#endif