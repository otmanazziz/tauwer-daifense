#include "Jeu.h"
#include <stdio.h>
#include <dirent.h>
#include <string>
Jeu::Jeu(){
	DIR * rep = opendir("./data/map");
    std::vector<std::string> s;
    if (rep != NULL)
    {
        struct dirent * ent;
         
        while ((ent = readdir(rep)) != NULL)
        {	
        	s = split(ent->d_name, '.');
			
			if( s.back().compare(std::string("map")) == 0){std::cout<<ent->d_name<<std::endl;tabLienCarte.push_back(ent->d_name);}
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

	Vect t2(1,1); // Taille du sprite
	for (unsigned int i = 0 ; i < niv->addrGetCarte()->tailleTabTour(); i++){
		tabBoutonTour.emplace_back(""+i, niv->addrGetCarte()->addrTourIndice(i)->getPosition(), t2);
		tabBoutonTour.back().getTaille().afficheVect();
		tabBoutonTour.back().getPos().afficheVect();
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

void Jeu::clique(int x, int y ,int  taille){
	Vect v(x, y);
	for (unsigned int i = 0; i < niv->addrGetCarte()->tailleTabTour(); i++){
		if (tabBoutonTour[i].clique(v/float(taille))){
			tourSelectionne = niv->addrGetCarte()->addrTourIndice(i);
			tourSelectionne->affiche();std::cout<<i<<std::endl;
		}
	}
	if (tourSelectionne != NULL){
		unsigned int nbGold;
			if (tabBouton[0].clique(v)){
				nbGold = 1.1 * tourSelectionne->getAttaque().getDegats();
				if(nbGold <= niv->getOr()){
					niv->retirerOr(nbGold);
					tourSelectionne->addDegat(1);
				}
			}
				
				//ameliorerTour(j, )
		
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