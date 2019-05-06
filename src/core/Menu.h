#ifndef MENU
#define MENU

#include "Vect.h"
#include "Bouton.h"
#include <vector>
#include <iostream>
/**
	@brief Class Menu
	Classe de Menu, permettant de gérer le nombre de boutons du menu
*/
class Menu{
private:
	std::vector<Bouton> tabBouton;
public:
	/**
		@brief Constructeur par défaut: Menu
		Permet de créer le menu par défaut
		@code
		Menu m;
		@endcode
	*/	
	Menu();
	 /**
 		@brief Constructeur par copie: Menu
 		Permet de créer par copie un nouveau Menu
 		@param Classe Menu
 		@code
 			Menu m1(m);
 		@endcode	
 	*/	
	Menu(const Menu &_Menu);
	/**
		@brief Constructeur:Menu
		Permet de créer le constructeur du menu avec les données privées de la fonction
		@param Tab de Bouton tabBouton
		@code
			Menu m2(tabBouton)
		@endcode	

	*/
	Menu(const std::vector<Bouton> &_tabBouton);
	/** 
		@brief Destructeur
		Permet de détruire le menu

	*/
	~Menu();
	/**
		@brief Fonction: getTabBouton
		Permet de retourner le tableau de bouton
		@return Tableau de Bouton tabBouton
		@code
			m2.getTabBouton();
		@endcode	
	*/
	std::vector<Bouton> getTabBouton()const;
	/**
		@brief Procédure: setTabBouton
		Permet de modifier le tableau de bouton
		@param Tableau de Bouton tabBouton
		@code
			m2.setTabBouton(tabBouton);
		@endcode	
	*/

	void setTabBouton(const std::vector<Bouton> &_tabBouton);
	/**
		@brief Procédure: setBoutonIndice
		Permet de modifier l'indice du bouton'
		@param Entier indice, Classe Bouton
		@code
			m2.setBoutonIndice(indice, bouton);
		@endcode	
	*/
	void setBoutonIndice(const int &indice,const Bouton & bouton);
	/**
		@brief Fonction: getBoutonIndice
		Permet de retourner l'indide du bouton
		@return Classe Bouton
		@code
			m2.getBoutonIndice();
		@endcode	
	*/	
	Bouton getBoutonIndice(const int &indice)const;
	/**
		@brief Procédure: ajouterBouton
		Permet d'ajouter un bouton dans le menu
		@param Classe Bouton
		@code
			m2.ajouterBouton(Bouton);
		@endcode	

	*/
	void ajouterBouton(const Bouton &_bouton);
	/**
		@brief Procédure: supprimerBoutonIndice
		Permet de supprimer l'indice d'un bouton dans le menu
		@param Entier indice
		@code
			m2.supprimerBoutonIndice(indice);
		@endcode	

	*/	
	void supprimerBoutonIndice(const int &indice);
	/**
		@brief Procédure: affihcerTabBouton
		Permet d'afficher' un bouton dans le menu
		@param 
		@code
			m2.afficherTabBouton();
		@endcode	

	*/

	void afficherTabBouton()const;
	/**
		@brief Fonction: getTaille
		Permet de retourner la taille du menu
		@return Entier positif
		@code
			m2.getTaille();
		@endcode	
	*/
	unsigned int getTaille()const;

};

#endif