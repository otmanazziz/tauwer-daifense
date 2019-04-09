#ifndef TOUR
#define TOUR

#include "Vect.h"
#include "Attaque.h"

/**
	@brief Class Tour
	Classe de Tour permettant de gérer la vitesse d'attaque, la portée, la position et l'attaque d'une tour
*/
class Tour{
private:
	float vitesseAtq;
	int portee;
	Vect position;
	Attaque attaque;
	bool aAttaquer;
	bool spawn;
public:
	/**
		@brief Constructeur par défaut: Tour
		Permet de créer la tour par défaut
		@code
		Tour t;
		@endcode
	*/
	Tour();
	/**
		@brief Constructeur par copie: Tour
		Permet de créer par copie une nouvelle tour.
		@param Classe Tour
		@code
			Tour t1(t);
		@endcode
	*/
	Tour(const Tour &_tour);
	/**
		@brief Constructeur: Tour
		Permet de créer le constructeur de la tour avec les données privées de la fonction.
		@param Réel, Entier, Classe Vecteur, Classe Attaque
		@code
			Tour t2(1.32, 4, v1, a1);
		@endcode
	*/
	Tour(const float &_vitesseAtq, const int &_portee, const Vect &_position,const int &z ,const int &d, const bool &s);
	/**
		@brief Destructeur
		Permet de détruire la Tour
	*/
	~Tour();
	/**
		@brief Booléen: getSpawn
		Permet de retourner le spawn de la tour
		@return Booléen
		@code
			t2.getSpawn();
		@endcode
	*/
	bool getSpawn();
	/**
		@brief Fonction: getVitAtq
		Permet de retourner le réel de la vitesse d'attaque
		@return Réel
		@code
			t2.getVitAtq();
		@endcode
	*/
	float getVitAtq();
	/**
		@brief Fonction: getPortee
		Permet de retourner l'entier de la portée
		@return Entier
		@code
			t2.getPortee();
		@endcode
	*/
	int getPortee();
	/**
		@brief Vecteur: getPosition
		Permet de retourner le vecteur de la position
		@return Vecteur
		@code
			t2.getPosition();
		@endcode
	*/
	Vect getPosition();
	/**
		@brief Procédure: setSpawn
		Permet de modifier le booléen du spawn de la tour
		@param Booléen
		@code
			t2.setSpawn(true);
		@endcode
	*/
	void setSpawn();
	/**
		@brief Procédure: setVitAtq
		Permet de modifier le réel de la vitesse d'attaque
		@param Réel
		@code
			t2.setVitAtq(4.8);
		@endcode
	*/
	void setVitAtq(const float &_vitesseAtq);
	/**
		@brief Procédure: setPortee
		Permet de modifier l'entier de la portée
		@param Entier
		@code
			t2.setPortee(2);
		@endcode
	*/
	void setPortee(const float &_portee);
	/**
		@brief Procédure: setPosition
		Permet de modifier le vecteur de la position
		@param Vecteur
		@code
			t2.setPosition(v1);
		@endcode
	*/
	void setPosition(const Vect &_position);
	/**
		@brief Procédure: affiche
		Permet d'afficher la vitesse d'attaque, la portée, la position et ses attaques
		@code
			t2.affiche();
		@endcode
	*/
	void affiche();
	/**
	@brief Booléen: estAPortee
	Vérifie si la tour a détecté un ennemi (ici des coordonnées d'un vecteur) dans sa portée
	@param Classe Vect
	@return Booléen
	@code
		t.estAPortee(v);
	@endcode
	*/
	bool estAPortee(const Vect &pos)const;
	int getDegat();
	Attaque getAttaque();
	void setAAttaquer(bool b);
};

#endif
//AJOUTER LES ATTAQUES