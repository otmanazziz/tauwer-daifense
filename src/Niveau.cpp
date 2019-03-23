#include "Niveau.h"

Niveau::Niveau(){
	Or = 0;
	score = 0;
	hero = NULL;
}

Niveau::Niveau(const std::string & f){
	
}

Carte Niveau::getCarte(){
	return carte;
}
