#include "Carte.h"

Carte::Carte(const Carte & c){
	tabTour = c.tabTour;
	tabVague = c.tabVague;
	tabChemin = c.tabChemin;
}

Carte::Carte(){
}

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
	std::vector<Vect> cms;
	std::vector<std::string> vms ;
	std::vector<std::string> vmss ; 
	unsigned int j ;
	while(!f.eof()) {
		getline(f,ligne);
		l = split(ligne,':');
		
			if(l[0] ==  "tour"){
				tabTour.push_back(Tour(std::stof(l[1]),std::stoi(l[2]),Vect(std::stof(l[3]),std::stof(l[4]))));
				
			}
			else if(l[0] ==  "vague"){
				vms = split(l[3],',');
				for( j = 0 ; j < vms.size() ; j++){
					vmss = split(vms[int(j)],'/');
					tms.emplace_back( std::stoi(vmss[2]), std::stof(vmss[1]), std::stoi(vmss[2]),Vect(std::stof(vmss[3]),std::stof(vmss[4]))); 
					vmss.clear();
				}
				tabVague.emplace_back(std::stof(l[1]) , std::stof(l[2]) ,tms);
				vms.clear();
				tms.clear();
				
			}
			else if(l[0] ==  "chemin"){
				for(j = 1 ; j < l.size() ; j++){
					vms = split(l[int(j)],',');//std::cout<<vms.size()<<std::endl;
					cms.emplace_back(std::stof(vms[0]),std::stof(vms[1]));
					vms.clear();
				}
				vms.clear();
				tabChemin.emplace_back(cms);
				cms.clear();
			} else {}
		 
		
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

Chemin Carte::cheminIndice(const int & i){
	return tabChemin[i];	
}

unsigned int Carte::tailleTabTour(){
	return tabTour.length();
}
unsigned int Carte::tailleTabChemin(){
	return tabChemin.length();
}
unsigned int CartetailleTabVague(){
	return tabVague.length();
}

Tour & Carte::tourIndice(const int & i){
	return &tabTour[i];	
}

Vague & Carte::vagueIndice(const int & i){
	return &tabVague[i];	
}

Chemin & Carte::cheminIndice(const int & i){
	return &tabChemin[i];	
}