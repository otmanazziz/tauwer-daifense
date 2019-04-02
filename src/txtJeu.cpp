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
	for( int i = 0 ; i < 40 ; i++) for( int j = 0 ; j < 40 ; j++)win.print(i,j,'.');
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
	if (jeu.getNiveau()->addrGetCarte()->tailleTabVague() > 0){
		for(unsigned int i = 0 ; i < jeu.getNiveau()->getCarte().vagueIndice(0).getVague().size();i++){
			if(jeu.getNiveau()->addrGetCarte()->addrVagueIndice(0)->addrGetIndiceMonstre(i)->getSpawn()){
				
				v =jeu.getNiveau()->getCarte().vagueIndice(0).getVague()[i].getPos(); 
				win.print(v.getX(), v.getY(), 'M');
			}
		}
	}
	v = jeu.getNiveau()->addrGetCarte()->getBase().getPosition();
	win.print(v.getX(), v.getY(),'B');
	win.draw(); 
	//std::cout<<std::endl;
	//jeu.getNiveau()->affiche();
}

void txtBoucle(Jeu & jeu){
	WinTXT win (40, 40);

	bool ok = true;
	int c;
	int x = -1;
	int y = -1;

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
        	case 't':
        jeu.actionAuto(200, x, y);
        		break;

        }

	} while (ok);

}
