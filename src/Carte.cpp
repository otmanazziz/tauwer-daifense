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
	vector<string> l;
	int i = 0;
	while(!f.eof()) {
		getLine(f,ligne);
		l = split(ligne,':');
		switch(l[0]){
			case "tour" :
				break;
			case "tour" :
				break;
			case "tour" :
				break;
			case "tour" :
				break;
				
				
				
				
		}
		i++;
	}
	f.close();
	return true;
}