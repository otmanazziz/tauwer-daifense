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





void Jeu::actionAuto(){
		niv->maj();
}

/*
	unsigned int nbTourDansNiveau = niv->getCarte().tailleTabTour();
	unsigned int nbCheminDansNiveau = niv->getCarte().tailleTabChemin();
	Vect v;

	

	

	

	

	

	unsigned int nbEnnemisDansVague = niv->getCarte().vagueIndice(0).getVague().size();
	for (unsigned int k = 0; k < nbTour; k++){

		for (unsigned int j = 0; j < nbEnnemisDansVague; j++){
			Vect v1 = niv->getCarte().vagueIndice(0).getVague()[j].getPos();
			//win.print(v1.getX(), v1.getY(), 'M');
			bool TourAPorteeDeMonstre = niv->getCarte().tourIndice(int(k)).estAPortee(v1);
			if (TourAPorteeDeMonstre && !aDejaDetecteEnnemi){
				aDejaDetecteEnnemi = true;

				std::cout << "La Tour " << k + 1 << " a detecte l'ennemi " << j + 1 << ". ";
				niv->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(j)->perdreVie(1);
				std::cout << "Il perd donc " << niv->getCarte().tourIndice(k).getAttaque().getDegats() << " points de vie et il lui reste " << niv->getCarte().vagueIndice(0).getVague()[j].getVie() << " points de vie.\n";
				if (niv->getCarte().vagueIndice(0).getVague()[j].estMort()){
					std::cout << "L'ennemi " << j + 1 << " est mort.\n";
					niv->getCarte().vagueIndice(0).ennemiMort();
					j--;
				}
			}

		}
		aDejaDetecteEnnemi = false;
	}
	//win.print(v.getX(), v.getY(),'B');
	//win.draw(); 
*/