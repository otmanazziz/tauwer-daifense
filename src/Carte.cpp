#include "Carte.h"

Carte::Carte(const std::string & f){
	fichier = f ;
	reinit();
}

bool Carte::reinit(){
	//a coder le fait daller chercher dans un fichier 
	std::ifstream f ; 
	f.open(fichier.c_str());
	if(!f.is_open()) { 
		//erreur
		return false ;
	}
	std::string ligne;
	std::vector<std::string> l;
	int i = 0;
	while(!f.eof()) {
		getline(f,ligne);
		l = split(ligne,':');
		
			if(l[0] ==  "tour"){
				
			}
			else if(l[0] ==  "vague"){
				
			}
			else if(l[0] ==  "Chemin"){
				
			} else {}
		
		i++;
	}
	f.close();
	return true;
}