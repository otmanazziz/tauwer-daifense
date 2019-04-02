#ifndef BOUTON
#define BOUTON

#include <string>
#include "Vect.h"

/**
	@brief Class Bouton
	Classe de boutons, permettant de gérer les positions des boutons, leurs tailles et le nom des boutons
*/
class Bouton{
private:
	std::string nom;
	Vect pos;
	Vect taille;
public:
	/**
		@brief Constructeur par défaut: Bouton
		Permet de créer le bouton par défaut
		@code
		Bouton b;
		@endcode
	*/	
	Bouton();
	 /**
 		@brief Constructeur par copie: Bouton
 		Permet de créer par copie un nouveau bouton
 		@param Bouton b
 		@code
 			Bouton b1(b);
 		@endcode	
 	*/	
	Bouton(const Bouton &_Bouton);
	/**
		@brief Constructeur:Bouton
		Permet de créer le constructeur du bouton avec les données privées de la fonction
		@param Chaîne de caractère Nom, Vecteur Position, Vecteur Taille
		@code
			Bouton b2(Chaîne de caractère , Vecteur Position , Vecteur Taille)
		@endcode	

	*/
	Bouton(const std::string &_nom, const Vect &_pos, const Vect &_taille);
	/** 
		@brief Destructeur
		Permet de détruire le bouton

	*/
	~Bouton();
	/**
		@brief Fonction: getNom
		Permet de retourner le nom du bouton
		@return Chaîne de caractère NOm
		@code
			b2.getNom();
		@endcode	
	*/
	std::string getNom();
	/**
		@brief Fonction: getPos
		Permet de retourner la position du bouton
		@return Vecteur Position
		@code
			b2.getPos();
		@endcode	
	*/
	Vect getPos();
	/**
		@brief Fonction: getTaille
		Permet de retourner la taille du bouton
		@return Vecteur Taille
		@code
			b2.getTaille();
		@endcode	
	*/
	Vect getTaille();
	/**
		@brief Procédure: setNom
		Permet de modifier le nom représentant la base
		@param Chaîne de caractère nom
		@code
			b2.setNom(Nom);
		@endcode	
	*/

	void setNom(const std::string &_nom);
	/**
		@brief Procédure: setPos
		Permet de modifier la position du bouton
		@param Vecteur Pos
		@code
			b2.setZone(Pos);
		@endcode	
	*/

	void setPos(const Vect &_pos);
	/**
		@brief Procédure: setTaille
		Permet de modifier la taille du bouton
		@param Vecteur Taille
		@code
			b2.setZone(Taille);
		@endcode	
	*/
	void setTaille(const Vect &_taille);
	/**
		@brief Booléen: clique
		Permet de savoir si le curseur est sur le bouton ou pas
		@param Vecteur Pos
		@code
			b2.clique(Pos);
		@endcode	
	*/

	bool clique(const Vect &_pos);
};

#endif