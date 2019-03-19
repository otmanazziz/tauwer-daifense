#include "Carte.h"

Carte::Carte(const std::string & f){
	fichier = f ;
	reinit();
}

Carte::~Carte(){
	tabTour.clear();
	tabChemin.clear();
	tabVague.clear();
}

bool Carte::reinit(){
	//a coder le fait daller chercher dans un fichier 
	std::ifstream f ; 
	f.open(fichier.c_str());
	if(!f.is_open()) { 
		//erreur
		return false ;
	}
	tabTour.clear();
	tabVague.clear();
	tabChemin.clear();
	std::string ligne;
	std::vector<std::string> l;
	int i = 0;
	while(!f.eof()) {
		getline(f,ligne);
		l = split(ligne,':');
		
			if(l[0] ==  "tour"){
				tabTour.push_back(Tour(std::stof(l[1]),std::stoi(l[2]),Vect(std::stof(l[3]),std::stof(l[4]))));
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

Tour Carte::tourIndice(const int & i){
	
return tabTour[i];	
}