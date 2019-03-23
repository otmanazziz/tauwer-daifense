#ifndef JEU
#define JEU
#include "Niveau.h"
#include <vector>
#include <string>
#include <iostream>
#include "fonction.h"
#include "Menu.h"
class Jeu{
	private:
		std::vector<std::string> tabLienCarte;
		Menu principale;
		Niveau   niv;
	public :
	
		Jeu();
		void afficheCarteDispo();
		Niveau  getNiveau(); 
};

#endif