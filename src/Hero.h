#ifndef HERO
#define HERO

#include "Sort.h"
#include <iostream>

class Hero{
private:
	std::vector<Sort> tabSort;
public:
	/**
		@brief Constructeur par défaut: Hero
		Permet de créer le héros par défaut
		@code
		Hero h;
		@endcode
	*/		
	Hero();
	/**
 		@brief Constructeur par copie: Hero
 		Permet de créer par copie un nouveau héros.	
 		@param Classe Hero
 		@code
 			Hero h1(h);
 		@endcode	
 	*/	
	Hero(const Hero &_Hero);
	/**
		@brief Constructeur:Hero
		Permet de créer le constructeur de Hero avec les données privées de la fonction
		@param Tableau de sort
		@code
			Hero h2(tabS1)
		@endcode	

	*/
	Hero(const std::vector<Sort> &_tabSort);
	/** 
		@brief Destructeur
		Permet de détruire le héros

	*/
	~Hero();

};

#endif