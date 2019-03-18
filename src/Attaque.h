#ifndef ATTAQUE
#define ATTAQUE

#include"Effet.h"

class Attaque{
private:
	int zone;
	Effet effet;
	int degats;
public:
	/**
		@brief Constructeur par défaut: Attaque
		Permet de créer l'attaque par défaut
		@code
		Attaque a;
		@endcode
	*/	
 	Attaque();
 	/**
 		@brief Constructeur par copie: Attaque
 		Permet de créer par copie une nouvelle attaque.	
 		@param Classe Attaque
 		@code
 			Attaque a1(a);
 		@endcode	
 	*/	
	Attaque(const Attaque &_Attaque);
	/**
		@brief Constructeur:Attaque
		Permet de créer le constructeur de l'attaque avec les données privées de la fonction
		@param Entier, Classe Effet, Entier
		@code
			Attaque a2(1 , e2 , 1)
		@endcode	

	*/
	Attaque(const int &_zone, const Effet &_effet, int &_degats);
	/** 
		@brief Destructeur
		Permet de détruire l'attaque

	*/
	~Attaque();
	/**
		@brief Fonction: getZone
		Permet de retourner l'entier dd la zone
		@return Entier
		@code
			a2.getZone();
		@endcode	
	*/

	int getZone();
	/**
		@brief Effet: getEffet
		Permet de retourner l'effet de l'attaque
		@return Effet
		@code
			a2.getEffet();
		@endcode	


	*/
	Effet getEffet();
	/**
		@brief Fonction: getDegats
		Permet de retourner l'entier des dégats
		@return Entier
		@code
			a2.getDegats();
		@endcode	
	*/
	int getDegats();
	/**
		@brief Procédure: setZone
		Permet de modifier l'entier représentant la zone d'attaque
		@param Entier
		@code
			a2.setZone(2);
		@endcode	
	*/

	void setZone(const int &_zone);
	/**
		@brief Procédure: setEffet
		Permet de modifier l'effet
		@param Effet
		@code
			a2.setEffet(e1);
		@endcode	

	*/
	void setEffet(const Effet &_effet);
	/**
		@brief Procédure: setDegats
		Permet de modifier les dégats
		@param Entier
		@code
			a2.setDegats(5);
		@endcode	

	*/

	void setDegats(const int &_degats);

};

#endif