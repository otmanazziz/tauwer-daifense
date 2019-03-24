#include "Vague.h"

Vague::Vague(){
	tempsEnnemi = 0;
	tempsVague = 0;
}

Vague::Vague(const Vague &v){
	tempsEnnemi = v.tempsEnnemi;
	tempsVague = v.tempsVague;
	monstres = v.monstres;
}

Vague::Vague(const float &_tempsEnnemi, const float &_tempsVague, const std::vector<Monstre> &_monstres){
	tempsEnnemi = _tempsEnnemi;
	tempsVague = _tempsVague;
	monstres = _monstres;
}

Vague::~Vague(){
	
	monstres.clear();
}


std::vector<Monstre> Vague::getVague()const{
	return monstres;
}
std::vector<Monstre> * Vague::addrGetVague(){
	return &monstres;
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


bool Vague::vagueVide(){
	return monstres.empty();
}
//ON peut le switch en booléen pour plus tard, si nécessaire
void Vague::ennemiMort(){
	if (!vagueVide()){
		for (unsigned int i = 0; i < monstres.size(); i++){
			if (monstres[i].estMort())
				monstres.erase(monstres.begin()+i);
		}
		//return true;
	} //return false;
}
/*
void Vague::avancementEtape(std::vector<Chemin> &tabChemin){
	Vect etapeMonstre;
	int valeurEtapeMonstre;
	for (unsigned int i = 0; i < monstres.size(); i++){
		etapeMonstre = monstres[i].getPos();
		valeurEtapeMonstre = monstres[i].getEtape();
		if (tabChemin[monstres[i].getChemin()].prochaineEtape(valeurEtapeMonstre) == etapeMonstre)
			monstres[i].setEtape(valeurEtapeMonstre + 1);
	}
}*/

void Vague::avancerMonstre(const std::vector<Chemin> &tabChemin){
	for( unsigned int i = 0 ; i < monstres.size(); i++){
		if( monstres[i].getSpawn() )monstres[i].avancer(tabChemin[monstres[i].getNumChem()].prochaineEtape(monstres[i].getEtape()));
	}
}

void Vague::spawnerMonstre(){
	for( unsigned int i = 0 ; i < monstres.size(); i++){
		if( !monstres[i].getSpawn() ){
			monstres[i].spawner();
			break;
		}
	}
}

void Vague::affiche(){
	std::cout<<"Temps entre Ennemie : "<<tempsEnnemi<< " Temps de la Vague : "<<tempsVague<<std::endl;
	for (unsigned int i = 0 ; i < monstres.size();i++) monstres[i].affiche();
}