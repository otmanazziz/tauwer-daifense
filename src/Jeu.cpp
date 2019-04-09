#include "Jeu.h"
#include <stdio.h>
#include <dirent.h>

Jeu::Jeu(){
	DIR * rep = opendir(".");
    std::vector<std::string> s;
    if (rep != NULL)
    {
        struct dirent * ent;
         
        while ((ent = readdir(rep)) != NULL)
        {
        	s = split(ent->d_name, '.');
			
			if( s.back().compare(std::string("map")) == 0)tabLienCarte.push_back(ent->d_name);
        }
         
        closedir(rep);
    }
	niv = new Niveau(tabLienCarte[0]);

	tourSelectionne = NULL;

	//Pour placer les boutons d'amélioration
	Vect v(0, 10);
	Vect v1(0, 20);
	Vect v2 (0, 30);
	Vect t(10, 10);
	tabBouton.emplace_back("", v, t);
	tabBouton.emplace_back("", v1, t);
	tabBouton.emplace_back("", v2, t);

	Vect t2(25, 25); // Taille du sprite
	for (unsigned int i = 0 ; i < niv->addrGetCarte()->tailleTabTour(); i++){
		tabBoutonTour.emplace_back("", niv->addrGetCarte()->addrTourIndice(i)->getPosition(), t2);
	}

}

Jeu::~Jeu(){
	delete niv;
}
void Jeu::afficheCarteDispo(){
	for(unsigned int i = 0 ; i < tabLienCarte.size() ; i++){
		std::cout<< tabLienCarte[i] << std::endl;
	}
}

Niveau *Jeu::getNiveau(){
	
	return niv;
	
}





void Jeu::actionAuto(float delta){
		niv->maj(delta/1000.0);
		//std::cout<<x<<" "<<y<<std::endl;
}

