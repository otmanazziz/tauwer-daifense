#ifndef VECT
#define VECT

#include <assert.h>

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
		@code
			Vect v;
		@endcode
		*/
		Vect();
		/**
		@brief Constructeur par copie: Vect
		Permet de créer le vecteur par copie
		@param vect: Vecteur
		@code
			Vect v1(v);
		@endcode
		*/
		Vect(const Vect &vec);
		/**
		@brief Constructeur: Vect
		Permet de créer le vecteur avec des coordonnées
		@param xV: coordonnée x, xY: coordonnée y
		@code
			Vect v2(4.8, 5.6);
		@endcode
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
		@code
			Vect v3 = v1 + v2;
		@endcode
		*/
		Vect operator+(const Vect &vector2)const;
		/**
		@brief Vecteur: Opérateur *
		Permet de retourner le produit de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		@code
			Vect v3 = v1 * v2;
		@endcode
		*/
		Vect operator*(const Vect &vector2)const;
		/**
		@brief Vecteur: Opérateur -
		Permet de retourner la différence de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		@code
			Vect v3 = v1 - v2;
		@endcode
		*/
		Vect operator-(const Vect &vector2)const;
		/**
		@brief Vecteur: Opérateur /
		Permet de retourner le quotient de 2 vecteurs
		@param vector2: Un autre vecteur
		@return La somme de 2 vecteurs
		@code
			Vect v3 = v1 / v2;
		@endcode
		*/
		Vect operator/(const Vect &vector2)const;
		/**
		@brief Vecteur: Opérateur =
		Permet d'affecter un vecteur à un autre'
		@param vector2: Un autre vecteur
		@return none
		@code
			Vect v3 = v2;
		@endcode
		*/
		void operator=(const Vect &vector2);
		/**
		@brief Vecteur: Opérateur ==
		Permet de vérifier si un vecteur est égal à un autre
		@param vector2: Un autre vecteur
		@return none
		@code
			v3 == v2;
		@endcode
		*/
		bool operator==(const Vect &vector2)const;
		/**
		@brief Fonction: getX
		Permet de retourner le vecteur X
		@param none
		@return x: coordonnée du vecteur privé
		@code
			v.getX();
		@endcode
		*/
		float getX() const;
		/**
		@brief Fonction: getY
		Permet de retourner le vecteur Y
		@param none
		@return y: coordonnée du vecteur privé
		@code
			v.getY();
		@endcode
		*/
		float getY() const;
		/**
		@brief Procédure: setVect
		Permet de définir le vecteur privé
		@param vector: Un autre vecteur
		@return none
		@code
			v.setVect(vecteur1);
		@endcode
		*/
		void setVect(const Vect &vector);
		/**
		@brief Procédure: afficheVect
		Permet d'afficher les coordonnées du vecteur
		@code
			v.afficheVect();
		@endcode
		*/
		void afficheVect();
		/**
		@brief Réel: module
		Retourne le module d'un vecteur
		@return Réel
		@code
			v.module();
		@endcode
		*/
		float module()const;
		/**
		@brief Procédure: testRegression
		Fait des tests de Régression
		@code
			v.testRegression();
		@endcode
		*/
		void testRegression();
		Vect operator*(float f)const;
		Vect operator/(float f)const;
		Vect operator%(const int & i)const;
};


#endif
