#ifndef IMAGE
#define IMAGE

#include "Couleur.h"
#include "Vect.h"
#include <iostream>
#include <vector>

/**
	@brief Class Image
	Classe d'Image permettant de gérer les couleurs de l'image et la taille
*/
class Image{
private:
	std::vectore<Couleur> tabCouleur;
	Vect dim;
public:
	/**
		@brief Constructeur par défaut: Image
		Permet de créer l'image par défaut
		@code
			Image i
		@endcode
	*/	
	Image();
	/**
 		@brief Constructeur par copie: Image
 		Permet de créer par copie une nouvelle image
 		@param Classe Image
 		@code
 			Image i1(i);
 		@endcode	
 	*/	
	Image(const Image &_image);
	/**
		@brief Constructeur par copie:Image
		Construit par copie la classe Image avec les valeurs
		@param Tableau de Couleur, Vecteur dimension
		@code
			Image i2( Tableau de couleur, dimension);
		@endcode
	*/
	Image(const std::vectore<Couleur> &_tabCouleur, const Vect &_dim);
	/**
		@brief Destructeur: Image
		Détruit la classe Image
	*/	
	~Image();
		/**
			@brief Tableau de Couleur: getTabCouleur
			Permet de retourner un tableau de couleur
			@return Tableau de Couleur
			@code
				i2.getTabCouleur();
			@endcode
		*/	

	std::vector<Couleur> getTabCouleur();
		/**
		@brief Classe Vecteur: getDim
		Permet de retourner le vecteur de dim
		@return Vecteur dim
		@code
			i2.getDim();
		@endcode
	*/
	Vect getDim();
	/**
		@brief Procédure: setTabCouleur
		Permet de modifier le tableau de couleur
		@param Tableau de couleur
		@code
			i2.setTabCouleur(Tabl de Couleur);
		@endcode	
	*/

	void setTabCouleur(const std::vector<Couleur> &_tabCouleur);
	/**
		@brief Procédure: setDim
		Permet de modifier la dimension
		@param Vecteur dim
		@code
			i2.setDim(dim);
		@endcode	
	*/

	void setDim(const Vec &_dim);

};
#endif