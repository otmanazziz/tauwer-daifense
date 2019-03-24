#include <iostream>
#ifdef _WIN32
#include <windows.h> 
#else
#include <unistd.h>
#endif // WIN32
#include "WinTXT.h"

#include "Jeu.h"


void txtAff(WinTXT & win, Jeu &jeu){
	unsigned int nbTourDansNiveau = jeu.getNiveau()->getCarte().tailleTabTour();
	unsigned int nbCheminDansNiveau = jeu.getNiveau()->getCarte().tailleTabChemin();
	Vect v;

	win.clear();
	for( int i = 0 ; i < 40 ; i++) for( int j = 0 ; j < 40 ; j++)win.print(i,j,'/');
	for (unsigned int i = 0; i < nbTourDansNiveau; i++){
		v = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();
		//std::cout << "Coordonnees de la tour " << i + 1 << ".";
		win.print(v.getX(), v.getY(), 'T');
	}
	for (unsigned int i = 0; i < nbCheminDansNiveau; i++){
		for( int j = 0 ; j < int(jeu.getNiveau()->getCarte().cheminIndice(i).tailleChemin()) ; j++){
			v = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j);

		//std::cout << "Coordonnees de la tour " << i + 1 << ".";
		win.print(v.getX(), v.getY(), 'X');
		}
	}
	for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
	v =jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos(); 
	win.print(v.getX(), v.getY(),'M');
	}
	v = jeu.getNiveau()->addrGetCarte()->getBase().getPosition();
	win.print(v.getX(), v.getY(),'B');
	win.draw(); 
	std::cout<<std::endl;
	jeu.getNiveau()->affiche();
}

void txtBoucle(Jeu & jeu){
	WinTXT win (40, 40);

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(200);
		#else
		usleep(200000);
        #endif // WIN32
        c = win.getCh();
        switch(c){
        	case 'q':
        		ok = false;
        		break;

        }

	} while (false);

}
/*
	unsigned int nbTourDansNiveau = jeu.getNiveau()->getCarte().tailleTabTour();
	unsigned int nbCheminDansNiveau = jeu.getNiveau()->getCarte().tailleTabChemin();
	Vect v;

	//win.clear();
	
	for( int i = 0 ; i < 40 ; i++)
		for( int j = 0 ; j < 40 ; j++)
			win.print(i,j,'/');
	

	std::cout << "\nLes Tours...\n";
	for (unsigned int i = 0; i < nbTourDansNiveau; i++){
		v = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();
		std::cout << "Coordonnees de la tour " << i + 1 << " | ";
		std::cout << "Attaque: " << jeu.getNiveau()->getCarte().tourIndice(i).getAttaque().getDegats() << ". Vitesse: " << jeu.getNiveau()->getCarte().tourIndice(i).getVitAtq() << ". Portee: " << jeu.getNiveau()->getCarte().tourIndice(i).getPortee() << ". ";
		v.afficheVect();
		//win.print(v.getX(), v.getY(), 'T');
	}

	std::cout << "\nLes chemins...\n";
	for (unsigned int i = 0; i < nbCheminDansNiveau; i++){
		for( int j = 0 ; j < int(jeu.getNiveau()->getCarte().cheminIndice(i).tailleChemin()) ; j++){
			v = jeu.getNiveau()->getCarte().cheminIndice(int(i)).prochaineEtape(j);
			std::cout << "Coordonnees du chemin " << j + 1 << " | ";
			v.afficheVect();
		//win.print(v.getX(), v.getY(), 'X');
		}
	}

	std::cout << "\nLa base...(get position)\n";
	v = jeu.getNiveau()->getCarte().getBase().getPosition();
	v.afficheVect();
	std::cout << "La base...(afficheBase)\n";
	Base b(jeu.getNiveau()->getCarte().getBase());
	b.affiche();

	std::cout << "\nLes monstres...\n";
	for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
		v = jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos();
		std::cout << "Coordonnees du monstre " << i + 1 << " | ";
		std::cout << "Vie: " << jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getVie() << ". ";
		v.afficheVect();
		//win.print(v.getX(), v.getY(),'M');
	}

	std::cout << "\nTentative de detection des monstres par la tourelle...\n";
	unsigned int nbEnnemisDansVague = jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();
	bool aDejaDetecteEnnemi = false;
	unsigned int nbTour = jeu.getNiveau()->getCarte().tailleTabTour();



	for (unsigned int k = 0; k < nbTour; k++){

		for (unsigned int j = 0; j < nbEnnemisDansVague; j++){
			Vect v1 = jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[j].getPos();
			//win.print(v1.getX(), v1.getY(), 'M');
			bool TourAPorteeDeMonstre = jeu.getNiveau()->getCarte().tourIndice(int(k)).estAPortee(v1);
			if (TourAPorteeDeMonstre && !aDejaDetecteEnnemi){
				aDejaDetecteEnnemi = true;

				std::cout << "La Tour " << k + 1 << " a detecte l'ennemi " << j + 1 << ". ";
				jeu.getNiveau()->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(j)->perdreVie(1);
				std::cout << "Il perd donc " << jeu.getNiveau()->getCarte().tourIndice(k).getAttaque().getDegats() << " points de vie et il lui reste " << jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[j].getVie() << " points de vie.\n";
				if (jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[j].estMort()){
					std::cout << "L'ennemi " << j + 1 << " est mort.\n";
					jeu.getNiveau()->getCarte().vagueIndice(0).ennemiMort();
					j--;
				}
			}

		}
		aDejaDetecteEnnemi = false;
	}
	//win.print(v.getX(), v.getY(),'B');
	//win.draw(); 
*/