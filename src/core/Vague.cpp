#include "Vague.h"

Vague::Vague(){
	tempsEnnemi = 0;
	tempsVague = 0;
	cooldownSpawn = tempsEnnemi;
}

Vague::Vague(const Vague &v){
	tempsEnnemi = v.tempsEnnemi;
	tempsVague = v.tempsVague;
	monstres = v.monstres;
	cooldownSpawn = tempsEnnemi;
}

Vague::Vague(const float &_tempsEnnemi, const float &_tempsVague, const std::vector<Monstre> &_monstres){
	tempsEnnemi = _tempsEnnemi;
	tempsVague = _tempsVague;
	monstres = _monstres;
	cooldownSpawn = tempsEnnemi;
}

Vague::~Vague(){
	
	monstres.clear();
}


std::vector<Monstre> Vague::getVague()const{
	return monstres;
}


Monstre Vague::getIndiceMonstre(const int & n)const{
	return monstres[n];
}

Monstre * Vague::addrGetIndiceMonstre(const int & n){
	return &monstres[n];
}

float Vague::getTempsEnnemi()const{
	return tempsEnnemi;
}

float Vague::getTempsVague()const{
	return tempsVague;
}


void Vague::setVague(const std::vector<Monstre> &_monstres){
	monstres = _monstres;
}

void Vague::setTempsEnnemi(const float &_tempsEnnemi){
	tempsEnnemi = _tempsEnnemi;
}

void Vague::setTempsVague(const float &_tempsVague){
	tempsVague = _tempsVague;
}


bool Vague::vagueVide()const{
	return monstres.empty();
}
unsigned int Vague::tailleVague()const{
	return monstres.size();
}

//ON peut le switch en booléen pour plus tard, si nécessaire
int Vague::ennemiMort(const int & i){
	int o = monstres[i].getGold();
	monstres.erase(monstres.begin() + i);
	return o;
}


void Vague::avancerMonstre(const std::vector<Chemin> &tabChemin, float delta){
	for( unsigned int i = 0 ; i < monstres.size(); i++){
		if( monstres[i].getSpawn()){
			monstres[i].avancer(tabChemin[monstres[i].getNumChem()].prochaineEtape(monstres[i].getEtape()), delta);
		}
	}
}

void Vague::monstresBase(Base & b){
	for( unsigned int i = 0 ; i < monstres.size(); i++){
		if( monstres[i].getPos() == b.getPosition()){
			monstres.erase(monstres.begin()+i);
			i--;
			b.perdreVie(1);
		}
	}
}

void Vague::spawnerMonstre(float delta){
	cooldownSpawn -= delta;
	for( unsigned int i = 0 ; i < monstres.size(); i++){
		if( !monstres[i].getSpawn() && cooldownSpawn <= 0 ){
			monstres[i].spawner();
			cooldownSpawn = tempsEnnemi;
			break;
		}
	}
}

void Vague::affiche(){
	std::cout<<"Temps entre Ennemie : "<<tempsEnnemi<< " Temps de la Vague : "<<tempsVague<<std::endl;
	for (unsigned int i = 0 ; i < monstres.size();i++) monstres[i].affiche();
}

