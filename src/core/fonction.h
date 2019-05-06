#ifndef FONCTION
#define FONCTION
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Vect.h"
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