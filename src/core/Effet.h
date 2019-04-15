#ifndef EFFET
#define EFFET
/**
	@brief Class Effet
	Classe d'Effet, permettant de gérer l'effet 
*/
class Effet{
private:
	int valeur;
	
public:
	/**
		@brief Constructeur par défaut: Effet
		Permet de créer l'effet par défaut
		@code
			Effet e;
		@endcode
	*/	
	Effet();
	/**
 		@brief Constructeur par copie: Effet
 		Permet de créer par copie un nouvel effet	
 		@param Effet
 		@code
 			Effet e1(e)
 		@endcode	
 	*/
 	Effet(const Effet &_effet);	
 	/**
		@brief Constructeur:Effet
		Permet de créer le constructeur de l'effet avec les données privées de la fonction
		@param Entier
		@code
			Effet e2(1)
		@endcode	

	*/
	Effet(const int &_val);
		/** 
		@brief Destructeur
		Permet de détruire l'effet

	*/
	~Effet();
	/**
		@brief Fonction:getValeur
		Permet de retourner l'entier représentant la valeur de l'effet
		@return Entier
		@code
			e2.getValeur();
		@endcode	


	*/

	int getValeur();
	
		/**
		@brief Procédure: setValeur
		Permet de modifier la valeur de l'effet
		@param Entier
		@code
			e2.setValeur(3);
		@endcode	

	*/

	void setValeur(const int &_val);
		/**
		@brief Procédure: afficheEffet
		Permet d'afficher l'effet
		@param Entier
		@code
			e2.afficheEffet();
		@endcode	

	*/

	void afficheEffet();

};
#endif