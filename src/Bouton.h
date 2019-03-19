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
	Bouton();
	Bouton(const Bouton &_Bouton);
	Bouton(const std::string &_nom, const Vect &_pos, const Vect &_taille);
	~Bouton();

	std::string getNom();
	Vect getPos();
	Vect getTaille();

	void setNom(const std::string &_nom);
	void setPos(const Vect &_pos);
	void setTaille(const Vect &_taille);

	bool clique(const Vect &_pos);
};

#endif