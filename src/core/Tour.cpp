#include "Tour.h"
#include <iostream>

	Tour::Tour():attaque(){
		vitesseAtq = 0;
		portee = 0;
		Vect v(0, 0);
		spawn = false;
		position.setVect(v);
	}

	Tour::Tour(const Tour &_tour){
		vitesseAtq = _tour.vitesseAtq;
		portee = _tour.portee;
		position.setVect(_tour.position);
		attaque = _tour.attaque;
		spawn = _tour.spawn;
	}

	Tour::Tour(const float &_vitesseAtq, const int &_portee, const Vect &_position , const int &z , const int & d): attaque(z,d){
		vitesseAtq = _vitesseAtq;
		portee = _portee;
		position.setVect(_position);
		spawn = false;
	}

	Tour::~Tour(){
		//
	}

	bool Tour::getSpawn(){
		return spawn;
	}
	
	float Tour::getVitAtq(){
		return vitesseAtq;
	}

	int Tour::getPortee(){
		return portee;
	}

	int Tour::getDegat(){
		return attaque.getDegats();
	}

	Vect Tour::getPosition(){
		return position;
	}

	void Tour::setVitAtq(const float &_vitesseAtq){
		vitesseAtq = _vitesseAtq;
	}
	void Tour::setPortee(const float &_portee){
		portee = _portee;
	}
	void Tour::setPosition(const Vect &_position){
		position.setVect(_position);
	}

	void Tour::affiche(){
		std::cout << "Votre vitesse d'attaque est de " << vitesseAtq << "\n";
		std::cout << "Votre portee est de " << portee << "\n";
		std::cout << "Vos degat sont de " << attaque.getDegats() << "\n";
		position.afficheVect();
	}

	bool Tour::estAPortee(const Vect &pos)const {
		return (pos-position).module() <= portee;
	}

	Attaque Tour::getAttaque(){
		return attaque;
	}

	void Tour::setAAttaquer(bool b){
		aAttaquer = b;
	}
	void Tour::addDegat(int d){
		attaque.addDegat(d);
	}

	void Tour::addVitAtq(float f){
		vitesseAtq += f;
	}

	void Tour::addPortee(int p){
		portee += p;
	}

	bool Tour::peutTirer(float d){
		cooldownAtq -= d;
		if(cooldownAtq <= 0 ){
			cooldownAtq = vitesseAtq;
			return true;
		}
		else return false;
	} 