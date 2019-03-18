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
	std::vector<Monstre> tms;
	std::vector<std::string> vms ;
	std::vector<std::string> vmss ;
	int i = 0;
	while(!f.eof()) {
		getline(f,ligne);
		l = split(ligne,':');
		
			if(l[0] ==  "tour"){
				tabTour.push_back(Tour(std::stof(l[1]),std::stoi(l[2]),Vect(std::stof(l[3]),std::stof(l[4]))));
				
			}
			else if(l[0] ==  "vague"){
				vms = split(l[3],',');
				for(unsigned int j = 0 ; j < vms.size() ; j++){
					vmss = split(vms[i],'/');
					tms.push_back( Monstre(std::stoi(vmss[0]), std::stof(vmss[1]), std::stoi(vmss[2]),Vect(std::stof(vmss[3]),std::stof(vmss[4])))); 
					vmss.clear();
				}
				tabVague.push_back( Vague(std::stof(l[1]) , std::stof(l[2]) ,tms));
				tms.clear();
				vms.clear();
			}
			else if(l[0] ==  "Chemin"){
				
			} else {}
		 
		i++;
		l.clear();
	}
	f.close();
	return true;
}

Tour Carte::tourIndice(const int & i){
	
return tabTour[i];	
}

Vague Carte::vagueIndice(const int & i){
	
return tabVague[i];	
}