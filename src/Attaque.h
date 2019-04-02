#ifndef ATTAQUE
#define ATTAQUE

#include "Effet.h"
/**
	@brief Class Attaque
	Classe de d'attaque, permettant de gérer l'attaque des tours, et la portée des attaques
*/
class Attaque{
private:
	float zone;
	//Effet effet;
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
	Attaque(const float &_zone, const int &_degats);
	/** 
		@brief Destructeur
		Permet de détruire l'attaque

	*/
	~Attaque();
	/**
		@brief Fonction: getZone
		Permet de retourner lé réel de la zone
		@return Réel
		@code
			a2.getZone();
		@endcode	
	*/

	float getZone();
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
		Permet de modifier le réel représentant la zone d'attaque
		@param Réel
		@code
			a2.setZone(2);
		@endcode	
	*/

	void setZone(const float &_zone);
	/**
		@brief Procédure: setDegats
		Permet de modifier l'entier des dégats
		@param Entier
		@code
			a2.setDegats(5);
		@endcode	

	*/

	void setDegats(const int &_degats);

};

#endif