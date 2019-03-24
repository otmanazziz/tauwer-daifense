#ifndef MONSTRE
#define MONSTRE

#include <iostream>
#include "Vect.h"
#include "fonction.h"
class Monstre{
private:
	Vect pos; 
	float vitesse;
	int vie; 
	int etape;
	int numChem;
	int gold;
	bool spawn;

public:
	/**
		@brief Constructeur par défaut: Monstre
		Construit par défaut la classe Monstre
		@code
			Monstre m;
		@endcode
	*/
	Monstre();
	/**
		@brief Constructeur par copie: Monstre
		Construit par copie la classe Monstre avec une autre classe
		@param Classe Monstre
		@code
			Monstre m1(m);
		@endcode
	*/
	Monstre(const Monstre &_monstre);
	/**
		@brief Constructeur par copie: Monstre
		Construit par copie la classe Monstre avec les valeurs
		@param Classe Vecteur, Réel, 2 entiers
		@code
			Monstre m2(  45,1.6, 1 , vect);
		@endcode
	*/
	Monstre(const int &_vie, const float &_vitesse,const int &_numChemin ,const Vect &_pos);
	/**
		@brief Destructeur: Monstre
		Détruit la classe Monstre
	*/
	~Monstre();

	/**
		@brief Classe Vecteur: getPos
		Permet de retourner les coordonnées du monstre
		@return Classe Vecteur
		@code
			m.getPos();
		@endcode
	*/
	Vect getPos()const;
	/**
		@brief Réel: getVitesse
		Permet de retourner la vitesse du monstre
		@return Réel
		@code
			m.getVitesse();
		@endcode
	*/
	float getVitesse()const;
	/**
		@brief Entier: getVie
		Permet de retourner la vie du monstre
		@return Entier
		@code
			m.getVie();
		@endcode
	*/
	int getVie()const;
	/**
		@brief Entier: getEtape
		Permet de retourner les étapes du monstre
		@return Entier
		@code
			m.getEtape();
		@endcode
	*/
	int getEtape()const;
	/**
		@brief Entier: getGold
		Permet de retourner l'or donné par le monstre
		@return Entier
		@code
			m.getGold();
		@endcode
	*/
	int getGold()const;

	/**
		@brief Procédure: setPos
		Permet de modifier les coordonnées du monstre
		@param Classe Vecteur
		@code
			m.setPos(v2);
		@endcode
	*/
	void setPos(const Vect &_pos);
	/**
		@brief Procédure: setVitesse
		Permet de modifier la vitesse du monstre
		@param Réel
		@code
			m.setVitesse(1.8);
		@endcode
	*/
	void setVitesse(const float &_vitesse);
	/**
		@brief Procédure: setVie
		Permet de modifier la vie du monstre
		@param Entier
		@code
			m.setVie(150);
		@endcode
	*/
	void setVie(const int &_vie);
	/**
		@brief Procédure: setEtape
		Permet de modifier les étapes du monstre
		@param Entier
		@code
			m.setEtape(7);
		@endcode
	*/
	void setEtape(const int &_etape);

	/**
		@brief Procédure: perdreVie
		Permet de retirer les points de vie du monstre
		@param Entier
		@code
			m.perdreVie(15);
		@endcode
	*/
	bool perdreVie(const int &n);
	/**
		@brief Booléen: estMort
		Permet de vérifier si le monstre est mort (points de vie a 0)
		@return Booléen
		@code
			m.estMort();
		@endcode
	*/
	bool estMort();
	int getNumChem()const;
	bool getSpawn()const;
	void spawner();
	void avancer(const Vect & v );
	void test();
	void affiche();
};

#endif