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
	Vect v(0, 120);
	Vect v1(0, 180);
	Vect v2 (0, 240);
	Vect t(60, 60);
	tabBouton.emplace_back("Attaque", v, t);
	tabBouton.emplace_back("VitesseAtq", v1, t);
	tabBouton.emplace_back("Portee", v2, t);

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

void Jeu::clique(int x, int y){
	Vect v(x, y);
	for (unsigned int i = 0; i < niv->addrGetCarte()->tailleTabTour(); i++){
		if (tabBoutonTour[i].clique(v))
			tourSelectionne = niv->addrGetCarte()->addrTourIndice(i);
	}
	if (tourSelectionne != NULL){
		for (unsigned int j = 0; j < 3; j++){
			if (tabBouton[j].clique(v))
				std::cout<<"ouais.\n";
				//ameliorerTour(j, )
		}
	}
}

 Tour * Jeu::tourSelect(){

return tourSelectionne;

}

std::vector<Bouton> * Jeu::renvoieBoutonAmelioration(){
	return &tabBouton;

}

std::vector<Bouton> * Jeu::renvoieBoutonTour(){
	return &tabBoutonTour;

}