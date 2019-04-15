#ifndef SORT
#define SORT

#include "Attaque.h"
#include <string>

/**
	@brief Class Sort
	Classe de Sort, permettant de gérer le nom et l'attaque d'un sort
*/
class Sort{
private:
	std::string nom;
	Attaque attaque;
public:
	/**
		@brief Constructeur par défaut: Sort
		Permet de créer le sort par défaut
		@code
		Sort s;
		@endcode
	*/	
	Sort();
	 	/**
 		@brief Constructeur par copie: Sort
 		Permet de créer par copie un nouveau sort	
 		@param Classe Sort
 		@code
 			Sort s1(s);
 		@endcode	
 	*/	
	Sort(const Sort &_Sort);
	/**
		@brief Constructeur:Sort
		Permet de créer le constructeur du sort avec les données privées de la fonction
		@param Chaîne de caractères, Classe Attaque
		@code
			Sort s2("", a2)
		@endcode	

	*/
	Sort(const std::string &_nom, const Attaque &_attaque);
		/** 
		@brief Destructeur
		Permet de détruire le sort

	*/
	~Sort();
		/**
		@brief Fonction:getNom
		Permet de retourner la chaîne de caractères représentant le nom du sort
		@return Chaîne de caractère
		@code
			s2.getNom();
		@endcode	


	*/

	std::string getNom();
		/**
		@brief Sort:getAttaque
		Permet de retourner l'attaque associé au sort
		@return Sort
		@code
			s2.getAttaque();
		@endcode	


	*/
	Attaque getAttaque();
		/**
		@brief Procédure: setNom
		Permet de modifier la chaîne de caractère représentant le nom du sort
		@param Chaîne de caractère
		@code
			s2.setZone("a");
		@endcode	
	*/


	void setNom(const std::string &_nom);
		/**
		@brief Procédure: setAttaque
		Permet de modifier l'attaque
		@param Attaque
		@code
			s2.setEffet(a2);
		@endcode	

	*/

	void setAttaque(const Attaque &_attaque);
};

#endif