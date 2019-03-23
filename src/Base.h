#ifndef BASE
#define BASE
#include "Vect.h"
class Base{
private:
	int vie;
	Vect position;
public:
	/**
		@brief Constructeur par défaut: Base
		Permet de créer la base par défaut
		@code
		Base b;
		@endcode
	*/
	Base();
	/**
		@brief Constructeur:Base
		Permet de créer le constructeur de la base avec les données privées de la fonction
		@param Entier vie, Vec Position
		@code
			Base b2(100 ,Position)
		@endcode	

	*/
	Base(const int &_vie, const Vect &_position);
	/**
 		@brief Constructeur par copie: Base
 		Permet de créer par copie une nouvelle base.
 		@param Classe Base
 		@code
 			Base b1(b);
 		@endcode	
 	*/	
	Base(const Base &_Base);
	/** 
		@brief Destructeur
		Permet de détruire la base

	*/
	~Base();
		/**
		@brief Fonction: getVie
		Permet de retourner l'entier de la vie
		@return Entier vie
		@code
			b2.getVie();
		@endcode	
	*/

	int getVie();
	/**
		@brief Fonction: getPosition
		Permet de retourner le vecteur position
		@return Vecteur position
		@code
			b2.getPosition();
		@endcode	
	*/
	Vect getPosition();
	/**
		@brief Procédure: setVie
		Permet de modifier l'entier représentant la vie de la base
		@param Entier vie
		@code
			b2.setVie(200);
		@endcode	
	*/


	void setVie(const int &_vie);
	/**
		@brief Procédure: setPosition
		Permet de modifier le vecteur poisition de la base
		@param Vecteur Position
		@code
			b2.setPosition(Position);
		@endcode	
	*/

	void setPosition(const Vect &_position);
	/**
		@brief Procédure: perdreVie
		Permet de modifier la vie de la base
		@param Entier vie perdue
		@code
			b2.perdeVie(10);
		@endcode	
	*/


	void perdreVie(const int &viePerdue);
	
	void affiche();
};

#endif