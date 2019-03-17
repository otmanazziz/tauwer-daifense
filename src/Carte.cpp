#include "Carte.h"

Carte::Carte(const string & f){
	fichier = f ;
	reinitCarte();
}

bool Carte::reinit(){
	//a coder le fait daller chercher dans un fichier 
	ifstream f ; 
	f.open(fichier.c_str());
	if(!f.is_open()) { 
		//erreur
		return false ;
	}
	string ligne;
	while(!f.eof()) {
		getLine(f,ligne);
		
	}
	f.close();
	return true;
}