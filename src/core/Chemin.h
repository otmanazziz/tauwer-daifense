#ifndef CHEMIN
#define CHEMIN
#include <vector>
#include "Vect.h"
/**
	@brief Class Chemin
	Classe de Chemin, permettant de gérer les étapes constituant le chemin
*/
class Chemin{
	private : 
		std::vector<Vect> tabEtape ; 
	public :
	/**
 		@brief Constructeur par copie: Chemin
 		Permet de créer par copie un nouveau chemin 
 		@param Vecteur v
 		@code
 			Chemin c1(v);
 		@endcode	
 	*/	
		Chemin(const std::vector<Vect> &  v);
			/** 
		@brief Destructeur
		Permet de détruire le chemin

	*/
		~Chemin();
	/**
		@brief Procédure: ajouterEtape
		Permet d'ajouter une étape dans le chemin
		@param Vecteur v
		@code
			c1.ajouterEtape(v);
		@endcode	
	*/
		void ajouterEtape(const Vect & v);
	/**
		@brief Fonction: prochaineEtape
		Permet d'avoir la prochaine étape du chemin
		@param Entier e
		@code
			c1.prochaineEtape(e);
		@endcode	
	*/
		Vect prochaineEtape(const int & e )const;
	/**
		@brief Fonction: tailleChemin
		Permet d'avoir l'entier positif de la taille du chemin
		@code
			c1.tailleChemin();
		@endcode	
	*/
		unsigned int tailleChemin();
	/**
		@brief Procédure: affiche
		Permet d'afficher les chemins
		@code
			c1.affiche();
		@endcode	
	*/	
	void affiche();
	
};

#endif