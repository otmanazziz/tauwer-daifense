#ifndef FONCTION
#define FONCTION
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Vect.h"

	/**
		@brief Tableau de chaînes de caractères: split
		Permet de retourner un tabkeau de chaines de caractères contenant la chaine de caractères s et étant séparé par le caractère c
        @param Chaîne de caractères s, caractère c
		@return tableau de chaînes de caractères
		@code
			aV.split(s, ".");
		@endcode	
	*/
std::vector<std::string> split(const std::string & s , const char & c );
	/**
		@brief Booléen: avancerVers
		Permet de savoir si l'ennemi à avancer vers une position
        @param Réel v, Vect m, Vect e
		@code
			aV.avancerVers(v,m,e);
		@endcode	
	*/
bool avancerVers(float v ,Vect & m, const Vect & e);
#endif