#ifndef HERO
#define HERO

#include "Sort.h"
#include <iostream>
#include <vector>

/**
	@brief Class Hero
	Classe de Hero, permettant de gérer les sorts des différents héros
*/
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
	/**
		@brief Fonction: getTabSort
		Permet de retourner le tableau de sort
		@return Tableau de Sort
		@code
			h2.getTabSort();
		@endcode	
	*/
	std::vector<Sort> getTabSort();
	/**
		@brief Procédure: setTabSort
		Permet de modifier le tableau de sort
		@param Tableau de sort
		@code
			h2.setTabSort(tabSort);
		@endcode	
	*/
	void setTabSort(const std::vector<Sort> &_tabSort);
		/**
		@brief Procédure: setTabSort
		Permet de modifier l'indice du héros
		@param Entier indice, Classz Sort
		@code
			h2.setHeroIndice(indice, sort);
		@endcode	
	*/
	void setHeroIndice(const int &indice, Sort sort);
};

#endif