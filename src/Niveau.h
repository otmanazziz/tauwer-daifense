#ifndef NIVEAU
#define NIVEAU
#include "Carte.h"
#include "Hero.h"
#include <string>
class Niveau{
	private : 
		Carte carte;
		Hero * hero;
		int Or;
		int score;
		int difficulter;
	public :
	
		Niveau();
		Niveau(const std::string & f);
	
	
	
};

#endif