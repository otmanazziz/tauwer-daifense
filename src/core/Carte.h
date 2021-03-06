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
/**
	@brief Class Carte
	Classe de carte, permettant de gérer les informations de la carte
*/
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
	/**
		@brief Booléen: reinit
		Permet de savoir si la carte a été réinitialisé 
		@code
			c2.reinit();
		@endcode	
	*/
		bool reinit();
	/**
		@brief Fonction: tourIndice
		Permet de retourner la tour à l'indice i
		@param Entier i
		@return Tour Indice
		@code
			c2.tourIndice(i);
		@endcode	
	*/
		Tour tourIndice(const int & i)const; 
	/**
		@brief Fonction: vagueIndice
		Permet de retourner la vague à l'indice i
		@param Entier i
		@return Vague Indice
		@code
			c2.vagueIndice(i);
		@endcode	
	*/	
		Vague vagueIndice(const int & i)const;
	/**
		@brief Fonction: cheminIndice
		Permet de retourner le chemin à l'indice i
		@param Entier i
		@return Chemin Indice
		@code
			c2.cheminIndice(i);
		@endcode	
	*/	
		Chemin cheminIndice(const int & i)const;
	/**
		@brief Fonction: tailleTabTour
		Permet de retourner la taille du tableau de tour (nombre de tour)
		@return Entier
		@code
			c2.tailleTabTour();
		@endcode	
	*/
		unsigned int tailleTabTour()const;
	/**
		@brief Fonction: tailleTabChemin
		Permet de retourner la taille du tableau de chemin (nombre de chemin)
		@return Entier
		@code
			c2.tailleTabChemin();
		@endcode	
	*/
		unsigned int tailleTabChemin()const;
	/**
		@brief Fonction: tailleTabVague
		Permet de retourner la taille du tableau de vague (nombre de vague)
		@return Entier
		@code
			c2.tailleTabVague();
		@endcode	
	*/
		unsigned int tailleTabVague()const;
	/**
		@brief Fonction: addrTourIndice
		Permet de retourner le pointeur de la tour à l'indice i
		@param Entier i
		@return Tour
		@code
			c2.addrTourIndice(i);
		@endcode	
	*/

		Tour * addrTourIndice(const int & i);
	/**
		@brief Fonction: addrVagueIndice
		Permet de retourner le pointeur de la vague à l'indice i
		@param Entier i
		@return Vague
		@code
			c2.addrVagueIndice(i);
		@endcode	
	*/

		Vague * addrVagueIndice(const int & i);
	/**
		@brief Fonction: addrCheminIndice
		Permet de retourner le pointeur du chemin à l'indice i
		@param Entier i
		@return Chemin
		@code
			c2.addrCheminIndice(i);
		@endcode	
	*/

		Chemin * addrCheminIndice(const int & i);
	/**
		@brief Procédure: maj			
		Permet de mettre à jour la carte
		@param Niveau n, Réel delta
		@code
			c2.maj(n,delta);
		@endcode
	*/
		void maj(Niveau & n, const float &delta);
	/**
		@brief Fonction: getBase
		Permet de retourner la base
		@return Base
		@code
			c2.getBase(i);
		@endcode	
	*/
		Base getBase()const;
	/**
		@brief Procédure: setFichier		
		Permet de changer de fichiers
		@param Chaîne de caractère f
		@code
			c2.setFichier(f);
		@endcode
	*/
		void setFichier(const std::string & f);
	/**
		@brief Procédure: affiche
		Permet d'afficher la carte
		@code
			c2.affiche();
		@endcode	
	*/	
		void affiche()const;
};

#endif

