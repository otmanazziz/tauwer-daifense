#ifndef VAGUE
#define VAGUE
#include <vector>
#include "Monstre.h"
#include "Chemin.h"
#include "Vect.h"
#include "Base.h"
/**
@brief Class Vague
Classe de vagues, permettant de gérer les vagues d'ennemis
*/
class Vague{
	private: 
		std::vector<Monstre> monstres; 
		float tempsEnnemi;
		float tempsVague; 
		float cooldownSpawn;
	public:
		/**
			@brief Constructeur par défaut: Vague
			Construit par défaut la classe Vague
			@code
				Vague v;
			@endcode
		*/
		Vague();
		/**
			@brief Constructeur par copie: Vague
			Construit par copie la classe Vague avec une autre classe Vague
			@param Classe Vague: v
			@code
				Vague v1(v);
			@endcode
		*/
		Vague(const Vague &v);
		/**
			@brief Constructeur par copie: Vague
			Construit par copie la classe Vague avec les autres données de la classe Vague
			@param Tableau de Monstre: _monstres, réel: _temps, entier: _nbMonstreRestant
			@code
				Vague v2(tabMonstrosaure, 4.8, 6);
			@endcode
		*/
		Vague(const float &_tempsEnnemi, const float &_tempsVague, const std::vector<Monstre> &_monstres);
		/**
			@brief Destructeur: Vague
			Détruit la classe Vague
		*/
		~Vague();

		/**
			@brief Tableau de Monstre: getVague
			Permet de retourner un tableau d'ennemis
			@return Tableau de monstres
			@code
				v2.getVague();
			@endcode
		*/
		std::vector<Monstre> getVague()const;

		/**
			@brief Monstre: getIndiceMonstre
			Permet de retourner les informations du monstre à l'indice n
			@param Entier: n
			@return Classe monstre
			@code
				v2.getIndiceMonstre(4);
			@endcode	
		*/
		Monstre getIndiceMonstre(const int & n)const;

		/**
			@brief Pointeur sur monstre: addrGetIndiceMonstre
			Permet de retourner un pointeur sur le monstre à l'indice n
			@param Entier: n
			@return Classe monstre (pointeur)
			@code
				v2.addrGetIndiceMonstre(4);
			@endcode	
		*/
		Monstre * addrGetIndiceMonstre(const int & n);

		/**
			@brief Réel: getTempsEnnemi
			Permet de retourner la valeur du temps
			@return Réel
			@code
				v2.getTempsEnnemi();
			@endcode
		*/
		float getTempsEnnemi()const;

		/**
			@brief Réel: getTempsVague
			Permet de retourner la valeur du temps
			@return Réel
			@code
				v2.getTempsVague();
			@endcode
		*/
		float getTempsVague()const ;

		/**
			@brief Procédure: setVague
			Permet de définir la vague actuelle
			@param Tableau de monstres
			@code
				v2.getNbMonstreRestant();
			@endcode
		*/
		void setVague(const std::vector<Monstre> &_monstres);

		/**
			@brief Procédure: setTempsEnnemi			
			Permet de définir le temps entre chaque ennemi dans la carte dans la classe sélectionnée
			@param Réel
			@code
				v2.setTempsEnnemi(1);
			@endcode
		*/
		void setTempsEnnemi(const float &_tempsEnnemi);

		/**
			@brief Procédure: setTempsVague			
			Permet de définir le temps avant la prochaine vague dans la classe sélectionnée
			@param Réel
			@code
				v2.setTempsVague(10);
			@endcode
		*/
		void setTempsVague(const float &_tempsVague);

		/**
			@brief Booléen: vagueVide	
			Permet de vérifier si la vague actuelle est vide
			@return Booléen
			@code
				v2.vagueVide();
			@endcode
		*/
		bool vagueVide()const;

		/**
			@brief Procédure: ennemiMort			
			Permet de retourner l'or du monstre qui meurt (en plus de la supprimer dans le tableau de monstres actuel)
			@param Entier: i
			@code
				v2.ennemiMort();
			@endcode
		*/
		int ennemiMort(const int & i);

		/**
			@brief Procédure: avancementEtape			
			Permet de vérifier l'avancement des étapes des ennemis en fonction de son chemin à prendre
			@param Tableau de Classes Chemin
			@code
				v2.avancementEtape(tabChemin2);
			@endcode
		*/
		void avancementEtape(std::vector<Chemin> &tabChemin);

		/**
			@brief Procédure: avancerMonstre
			Permet de faire avancer le monstre
			@param Chemin tabChemin, Réel delta
			@code
				v2.avancerMonstre(tabChemin, delta);
			@endcode	
		*/
		void avancerMonstre(const std::vector<Chemin> &tabChemin , float delta);

		/**
			@brief Procédure: spawnerMonstre
			Permet de faire apparaitre des monstres dans la vague actuelle
			@param Réel: delta
			@code
				v2.spawnerMonstre();
			@endcode	
		*/
		void spawnerMonstre(float delta);

		/**
			@brief Procédure: affiche
			Permet d'afficher des monstre dans la vague
			@code
				v2.affiche();
			@endcode	
		*/	
		void affiche();

		/**
			@brief Procédure: monstresBase
			Permet de faire disparaitre le monstre quand il arrive à la base et d'enlever un point de vie à la base
			@param Base b
			@code
				v2.monstresBase(b);
			@endcode	
		*/
		void monstresBase(Base & b);

		/**
			@brief Fonction: tailleVague
			Permet de retourner la taille de la vague
			@return Entier
			@code
				v2.tailleVague();
			@endcode	
		*/
		unsigned int tailleVague()const;


};

#endif