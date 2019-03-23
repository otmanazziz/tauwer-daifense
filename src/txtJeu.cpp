#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "WinTXT.h"

#include "Jeu.h"


void txtAff(WinTXT & win,  Jeu &jeu){
	unsigned int nbTourDansNiveau = jeu.getNiveau()->getCarte().tailleTabTour();
	Vect laTour;

	win.clear();

	for (unsigned int i = 0; i < nbTourDansNiveau; i++){
		laTour = jeu.getNiveau()->getCarte().tourIndice(i).getPosition();

		std::cout << "Coordonnees de la tour " << i + 1 << ".\n";
		win.print(laTour.getX(), laTour.getY(), 'T');
	}
}

void txtBoucle(Jeu & jeu){
	WinTXT win (1000, 1000);

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
        c = win.getCh();
        switch(c){
        	case 'q':
        		ok = false;
        		break;

        }

	} while (ok);

}