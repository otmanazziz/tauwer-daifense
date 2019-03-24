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
			Permet de retourner un tableau de vagues d'ennemis
			@return Tableau de Vague
			@code
				v2.getVague();
			@endcode
		*/

		std::vector<Monstre> getVague()const;
		Monstre getIndiceMonstre(const int & n)const;
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
			@brief Entier: getnbMonstreRestant
			Permet de retourner le nombre de monstres restant
			@return Entier
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
			@brief Procédure: setNbMonstreRestant			
			Permet de définir le nombre d'ennemis restants dans la classe sélectionnée
			@param Entier
			@code
				v2.setNbMonstreRestant(6);
			@endcode
		*/

		bool vagueVide()const;
		/**
			@brief Procédure: ennemiMort			
			Permet d'actualiser la taille du tableau de monstres, si un monstre est mort
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
	
		void avancerMonstre(const std::vector<Chemin> &tabChemin);
	
		void spawnerMonstre();
		
		void affiche();
	
		void monstresBase(Base & b);

		unsigned int tailleVague()const;


};

#endif