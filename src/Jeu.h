#ifndef JEU
#define JEU
#include "Niveau.h"
#include <vector>
#include <string>
#include <iostream>
#include "fonction.h"
class Jeu{
	private:
		std::vector<std::string> tabLienCarte;
	public :
	
		Jeu();
		void afficheCarteDispo();
	
};

#endif