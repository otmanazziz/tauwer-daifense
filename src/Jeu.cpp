#include "Jeu.h"
#include <stdio.h>
#include <dirent.h>

Jeu::Jeu(){
	DIR * rep = opendir(".");
    std::vector<std::string> s;
    if (rep != NULL)
    {
        struct dirent * ent;
         
        while ((ent = readdir(rep)) != NULL)
        {
        	s = split(ent->d_name, '.');
			
			if( s.back().compare(std::string("map")) == 0)tabLienCarte.push_back(ent->d_name);
        }
         
        closedir(rep);
    }
	niv = new Niveau(tabLienCarte[0]);
}
Jeu::~Jeu(){
delete niv;	
	
}
void Jeu::afficheCarteDispo(){
	for(unsigned int i = 0 ; i < tabLienCarte.size() ; i++){
		std::cout<< tabLienCarte[i] << std::endl;
	}
}

Niveau *Jeu::getNiveau(){
	
	return niv;
	
}





void Jeu::actionAuto(float delta, int x, int y){
		niv->maj(delta/1000.0);
		//std::cout<<x<<" "<<y<<std::endl;
}

