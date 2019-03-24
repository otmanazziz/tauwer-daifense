#include "Carte.h"

Carte::Carte(const Carte & c){
	tabTour = c.tabTour;
	tabVague = c.tabVague;
	tabChemin = c.tabChemin;
}

Carte::Carte():base(){
}

Carte::Carte(const std::string & f):base(100, Vect(25,25)){
	fichier = f ;
	reinit();
}

Carte::~Carte(){
	tabTour.clear();
	tabChemin.clear();
	tabVague.clear();
}

void Carte::setFichier(const std::string & f){
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
				tabTour.emplace_back(std::stof(l[1]),std::stoi(l[2]),Vect(std::stof(l[3]),std::stof(l[4])) , std::stoi(l[5]) ,std::stoi(l[6]) );
				
			}
			else if(l[0] ==  "vague"){
				vms = split(l[3],',');
				for( j = 0 ; j < vms.size() ; j++){
					vmss = split(vms[int(j)],'/');
					tms.emplace_back( std::stoi(vmss[0]), std::stof(vmss[1]), std::stoi(vmss[2]),tabChemin[std::stoi(vmss[2])].prochaineEtape(0)); 
					vmss.clear();
				}
				tabVague.emplace_back(std::stof(l[1]) , std::stof(l[2]) ,tms);
				vms.clear();
				tms.clear();
				
			}
			else if(l[0] ==  "chemin"){
				for(j = 1 ; j < l.size() ; j++){
					vms = split(l[int(j)],',');
					cms.emplace_back(std::stof(vms[0]),std::stof(vms[1]));
					vms.clear();
				}
				vms.clear();
				tabChemin.emplace_back(cms);
				cms.clear();
			}
			else if(l[0] ==  "base"){
				
				vms = split(l[1],',');
				
				base.setPosition(Vect(std::stof(vms[0]),std::stof(vms[1])));
				base.setVie(100);
				base.affiche();
				for( unsigned int i = 0 ; i < tabChemin.size() ; i++) tabChemin[i].ajouterEtape(Vect(std::stof(vms[0]),std::stof(vms[1])));
				vms.clear();
			}else {}
		 
		
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
	return tabTour.size();
}
unsigned int Carte::tailleTabChemin(){
	return tabChemin.size();
}
unsigned int Carte::tailleTabVague(){
	return tabVague.size();
}

Tour * Carte::addrTourIndice(const int & i){
	return &tabTour[i];	
}

Vague * Carte::addrVagueIndice(const int & i){
	return &tabVague[i];	
}

Chemin * Carte::addrCheminIndice(const int & i){
	return &tabChemin[i];	
}

Base Carte::getBase(){
	//std::cout<<"getbase "; base.affiche();
	return base;
}

void Carte::affiche(){
	unsigned int i;
	std::cout<<std::endl<<"Affichage des Tours :"<<std::endl<<std::endl;
	for (i = 0 ; i < tabTour.size();i++){
		std::cout<<"	tour n°"<<i<<std::endl;
		tabTour[i].affiche();
	}
	std::cout<<std::endl<<"Affichage des Vagues :"<<std::endl<<std::endl;
	for (i = 0 ; i < tabVague.size();i++){
		tabVague[i].affiche();
	}
	std::cout<<std::endl<<"Affichage des Chemins :"<<std::endl<<std::endl;
	for (i = 0 ; i < tabChemin.size();i++){
		std::cout<<"	chemin n°"<<i<<std::endl;
		tabChemin[i].affiche();
	}
	
	std::cout<<std::endl<<"Affichage de la base :"<<std::endl<<std::endl;
	base.affiche();
}








