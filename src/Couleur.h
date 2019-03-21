#ifndef COULEUR
#define COULEUR

class Couleur{
private:
	unsigned char r;
	unsigned char v;
	unsigned char b;
	float opacity; //opacity between 0.0 and 1.0
public:
	/**
		@brief Constructeur par défaut: Couleur
		Permet de créer la couleur par défaut
		@code
		Couleur c;
		@endcode
	*/	
	Couleur();
	/**
		@brief Constructeur:Couleur
		Permet de créer le constructeur de la couleur avec les données privées de la fonction
		@param Entier positif r,Entier positif v, Entier positif b, Réel opacity
		@code
			Couleur c2(r ,v , b, opacity)
		@endcode	

	*/
	Couleur(const unsigned char &_r, const unsigned char &_v, const unsigned char &_b, const float &_opacity);
	 /**
 		@brief Constructeur par copie: Couleur
 		Permet de créer par copie une nouvelle couleur	
 		@param Classe Couleur
 		@code
 			Couleur c1(c);
 		@endcode	
 	*/
	Couleur(const Couleur &_couleur);
	/** 
		@brief Destructeur
		Permet de détruire la couleur

	*/
	~Couleur();
	/**
		@brief Fonction: getR
		Permet de retourner l'entier de la couleur rouge
		@return Entier r
		@code
			c2.getR();
		@endcode	
	*/

	unsigned char getR();
	/**
		@brief Fonction: getV
		Permet de retourner l'entier de la couleur verte
		@return Entier v
		@code
			c2.getV();
		@endcode	
	*/
	unsigned char getV();
	/**
		@brief Fonction: getB
		Permet de retourner l'entier de la couleur bleue
		@return Entier b
		@code
			c2.getB();
		@endcode	
	*/
	unsigned char getB();
	/**
		@brief Fonction: getOpacity
		Permet de retourner le réel de l'opacité
		@return Réel o
		@code
			c2.getOpacity();
		@endcode	
	*/
	float getOpacity();
	/**
		@brief Fonction: operator=
		Permet d'affecter une couleur à une autre
		@return Class Couleur
		@code
			c2.operator=();
		@endcode	
	*/
	Couleur operator=(const Couleur &_Couleur);
	/**
		@brief Procédure: setR
		Permet de modifier l'entier représentant la couleur rouge
		@param Entier positif r
		@code
			c2.setR(r);
		@endcode	
	*/
	void setR(const unsigned char &_r);
	/**
		@brief Procédure: setV
		Permet de modifier l'entier représentant la couleur verte
		@param Entier positif v
		@code
			c2.setV(v);
		@endcode	
	*/
	void setV(const unsigned char &_v);
	/**
		@brief Procédure: setB
		Permet de modifier l'entier représentant la couleur bleue
		@param Entier positif b
		@code
			c2.setB(b);
		@endcode	
	*/
	void setB(const unsigned char &_b);
	/**
		@brief Procédure: setOpacity
		Permet de modifier l'opacité de la couleur
		@param Réel o
		@code
			c2.setOpacity(o);
		@endcode	
	*/
	void setOpacity(const float &_opacity);

	void testRegression();
};

#endif