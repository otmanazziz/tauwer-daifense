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

Vague::Vague(const float &_tempsEnnemi, const float &_tempsVague, const std::vector<Monstre> _monstres){
	tempsEnnemi = _tempsEnnemi;
	tempsVague = _tempsVague;
	monstres = _monstres;
}

Vague::~Vague(){
	tempsEnnemi = 0;
	tempsVague = 0;
	monstres.clear();
}


std::vector<Monstre> Vague::getVague(){
	return monstres;
}

float Vague::getTempsEnnemi(){
	return tempsEnnemi;
}

float Vague::getTempsVague(){
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
			/*
			if (monstres[i].estMort()){
				monstres[i].erase(i);
			}
			*/
		}
		//return true;
	} //return false;
}