#include "Monstre.h"

Monstre::Monstre(){
	vie = 0;
	etape = 0;
	vitesse = 0;
	spawn = false;
}

Monstre::Monstre(const Monstre &_monstre){
	vie = _monstre.vie;
	etape = _monstre.etape;
	vitesse = _monstre.vitesse;
	numChem = _monstre.numChem;
	pos = _monstre.pos;
	spawn = false;
}

Monstre::Monstre(const int &_vie, const float &_vitesse,const int &_numChemin ,const Vect &_pos){
	vie = _vie;
	vitesse = _vitesse;
	pos = _pos;
	numChem = _numChemin;
	etape = 1;
	spawn = false;
}

Monstre::~Monstre(){
	vie = 0;
	etape = 0;
	vitesse = 0;
}

Vect Monstre::getPos()const{
	return pos;
}

float Monstre::getVitesse()const{
	return vitesse;
}

int Monstre::getVie()const{
	return vie;
}

int Monstre::getEtape()const{
	return etape;
}


void Monstre::setPos(const Vect &_pos){
	pos.setVect(_pos);
}

void Monstre::setVitesse(const float &_vitesse){
	vitesse = _vitesse;
}

void Monstre::setVie(const int &_vie){
	vie = _vie;
}

void Monstre::setEtape(const int &_etape){
	etape = _etape;
}


void Monstre::perdreVie(const int &n){
	vie -= n;
}

bool Monstre::estMort(){
	return vie == 0;
}
bool Monstre::getSpawn()const{
	return spawn;
}
void Monstre::spawner(){
	spawn = true;
}
void Monstre::test(){
	Monstre m;
	Vect v(1.5, 6.3);
	Monstre m1(m);
	Monstre m2( 4.5, 12, 16,v);
	std::cout << m1.vie << " " << m2.etape;
	m2.perdreVie(8);
	std::cout << "\n" << m2.vie;
	do{
		m2.perdreVie(1);
		std::cout << "\n" << m2.vie;
	} while (!m2.estMort());
}


void Monstre::avancer(const Vect & v){
	if(pos == v);
	else{		
		if(avancerVers(vitesse,pos, v)){
			etape ++;	
		}
	}
}
                                                                       
void Monstre::affiche(){
	std::cout<<std::endl<<" Vie : "<< vie<<" - Position : "<< pos.getX() << "   " << pos.getY() <<" - Vitesse : "<<vitesse<<" -Etape : "<<etape <<" - numChem : "<< numChem <<" - spawner : "<< spawn<<std::endl; 
}	
	
int Monstre::getNumChem()const{
	return numChem;
}
	
	
	
	
	