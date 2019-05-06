#ifndef NIVEAU
#define NIVEAU
#include "Carte.h"
#include "Hero.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
/**
	@brief Class Niveau
	Classe de Niveau permettant de gérer les caractéristique d'un niveau (la carte, le héro, l'or et le score)
*/
class Niveau{
	private : 
		Carte carte;
		unsigned int Or;
		unsigned int score;
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
		Carte getCarte()const;
	/**
		@brief Fonction: getOr
		Permet de retourner le nombre d'or
		@return Entier positif or
		@code
			n2.getOr();
		@endcode	
	*/	
		unsigned int getOr()const;
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
		void maj(const float &delta);
	/**
		@brief Procédure: ajouterOr
		Permet de gagner de l'or en tuant des ennemis
		@param Entier positif o
		@code
			n2.ajouterOr(o);
		@endcode	
	*/	
		void ajouterOr(const unsigned int & o);
	/**
		@brief Procédure: retirerOr
		Permet de perdre de l'or en tuant des ennemis
		@param Entier positif o
		@code
			n2.ajouterOr(o);
		@endcode	
	*/		
		void retirerOr(const unsigned int & o);
	/**
		@brief Procédure: affiche
		Permet d'afficher le niveau
		@code
			n2.affiche();
		@endcode	
	*/		
		void affiche()const;
	/**
		@brief Booléen: perdue
		Permet de savoir si le niveau est perdue ou non
		@code
			n2.perdue();
		@endcode	
	*/
		bool perdue()const;
	/**
		@brief Booléen: finNiveau
		Permet de savoir si le niveau est finie ou non
		@code
			n2.finNiveau();
		@endcode	
	*/
		bool finNiveau()const;
	/**
		@brief Entier : getScore() 
		Retourne le score
		@code
			n2.finNiveau();
		@endcode	
	*/
		unsigned int getScore()const;

};

#endif