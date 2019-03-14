#ifndef VECT
#define VECT

/**
@brief Class Vect
Classe de vecteurs, permettant de gérer les coordonnées dans un espace en 2D
*/
class Vect{
	private:
		float x;
		float y;

	public:
		/**
		@brief Constructeur par défaut: Vect
		Permet de créer le vecteur par défaut
		*/
		Vect();
		/**
		@brief Constructeur par copie: Vect
		Permet de créer le vecteur par copie
		@param vect: Vecteur
		*/
		Vect(const Vect &vec);
		/**
		@brief Constructeur: Vect
		Permet de créer le vecteur avec des coordonnées
		@param xV: coordonnée x, xY: coordonnée y
		*/
		Vect(const float &xV, const float &yV);
		/**
		@brief Destructeur: Vect
		Permet de détruire le vecteur
		*/
		~Vect();
		/**
		@brief Vecteur: Opérateur +
		Permet de retourner la somme de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		*/
		Vect operator+(const Vect &vector2);
		/**
		@brief Vecteur: Opérateur *
		Permet de retourner le produit de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		@code
		
		@endcode
		*/
		Vect operator*(const Vect &vector2);
		/**
		@brief Vecteur: Opérateur -
		Permet de retourner la différence de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		*/
		Vect operator-(const Vect &vector2);
		/**
		@brief Vecteur: Opérateur /
		Permet de retourner le quotient de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		*/
		Vect operator/(const Vect &vector2);
		/**
		@brief Vecteur: Opérateur =
		Permet d'affecter un vecteur à un autre'
		@param vector2: Un autre vecteur
		@return none
		*/
		void operator=(const Vect &vector2);
		/**
		@brief Fonction: getX
		Permet de retourner le vecteur X
		@param none
		@return x: coordonnée du vecteur privé
		@code
			getX();
		@endcode
		*/
		float getX() const;
		/**
		@brief Fonction: getY
		Permet de retourner le vecteur Y
		@param none
		@return y: coordonnée du vecteur privé
		@code
			getY();
		@endcode
		*/
		float getY() const;
		/**
		@brief Procédure: setVect
		Permet de définir le vecteur privé
		@param vector: Un autre vecteur
		@return none
		@code
			setVect(vecteur1);
		@endcode
		*/
		void setVect(const Vect &vector);
		void afficheVect();
};


#endif
