#include "Jeu.h"
#include <stdio.h>
#include <dirent.h>
#include <string>
Jeu::Jeu(){
	DIR * rep = opendir("./data/map");
    std::vector<std::string> s;
	int i = 0 ;
    if (rep != NULL)
    {
        struct dirent * ent;
        Vect bmap(600,40);
        while ((ent = readdir(rep)) != NULL)
        {	
        	s = split(ent->d_name, '.');
			
			if( s.back().compare(std::string("map")) == 0){
				std::cout<<ent->d_name<<std::endl;
				tabLienCarte.push_back(ent->d_name);
				menuMap.ajouterBouton(Bouton(ent->d_name, Vect(200,i*40),bmap));
				i++;
			}
        }
         
        closedir(rep);
    }
	niv = NULL;
	pause = true ; 
	

	//Pour placer les boutons d'amélioration
	Vect v(0, 120);
	Vect v1(0, 180);
	Vect v2 (0, 240);

	Vect t(60, 60);
	tabBouton.emplace_back("Attaque", v, t);
	tabBouton.emplace_back("VitesseAtq", v1, t);
	tabBouton.emplace_back("Portee", v2, t);
	bpause = Bouton("",Vect(940,0),t);
	

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
	if(!pause)
		niv->maj(delta/1000.0);
		//std::cout<<x<<" "<<y<<std::endl;
}

void Jeu::clique(const int & x, const int & y , const int & taille){

	Vect v(x, y);
	if(!pause){
		for (unsigned int i = 0; i < niv->addrGetCarte()->tailleTabTour(); i++){
			 
			if (tabBoutonTour[i].clique(v+(Vect(taille,taille)/2))){
				tourSelectionne = niv->addrGetCarte()->addrTourIndice(i);
				tourSelectionne->affiche();std::cout<<i<<std::endl;
			}
		}
		if (tourSelectionne != NULL){
			unsigned int nbGold;
			if(tourSelectionne->getSpawn()){	
					
					if (tabBouton[0].clique(v)){
						nbGold = 1.0 * tourSelectionne->getAttaque().getDegats();
						if(nbGold <= niv->getOr()){
							niv->retirerOr(nbGold);
							tourSelectionne->addDegat(5);
						}
					}else if(tabBouton[1].clique(v)){
						nbGold = 8* tourSelectionne->getVitAtq();
						if(nbGold <= niv->getOr()){
							niv->retirerOr(nbGold);
							tourSelectionne->addVitAtq(0.5);
						}
					}else if(tabBouton[2].clique(v)){
						nbGold = 2* tourSelectionne->getPortee();
						if(nbGold <= niv->getOr()){
							niv->retirerOr(nbGold);
							tourSelectionne->addPortee(1);
						}
					}	
			}else{
				if(20 <= niv->getOr()){
					niv->retirerOr(20);
					tourSelectionne->setSpawn(true);
				}
			}	
		}
	}else{
		for(unsigned int i = 0 ; i < menuMap.getTaille(); i++){
			if(menuMap.getBoutonIndice(i).clique(v)){
				changerMap(i);
			}
		}

	} 
	if(bpause.clique(v) && niv != NULL){
		Pause();
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

void Jeu::changerMap(int m){
	if(niv != NULL) delete niv ; 
	niv = new Niveau(tabLienCarte[m]);
	tourSelectionne = NULL;
	Vect t2(64,64); 
	for (unsigned int i = 0 ; i < niv->addrGetCarte()->tailleTabTour(); i++){
		tabBoutonTour.emplace_back(""+i, niv->addrGetCarte()->addrTourIndice(i)->getPosition()*20, t2);
		tabBoutonTour.back().getTaille().afficheVect();
		tabBoutonTour.back().getPos().afficheVect();
	}
	mapSelect = m ;

}

bool Jeu::getPause(){
	return pause;
}

Bouton Jeu::getBoutonPause(){

	return bpause;
}

void Jeu::Pause(){
	pause = !pause;
}

std::string Jeu::getImageMap(){
	std::ifstream f ; 
	f.open(("./data/map/"+tabLienCarte[mapSelect]).c_str());
	if(!f.is_open()) { 
		return "test.png" ;
	}
	std::string ligne;
	getline(f,ligne);
	return "./data/image/map/"+ligne ;

}

Menu Jeu::getMenuMap(){
	return menuMap;
}