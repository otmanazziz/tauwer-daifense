#include "Attaque.h"
#include <iostream>

Attaque::Attaque(){
	zone = 0;
	degats = 0;	
}

Attaque::Attaque(const Attaque &_Attaque){
	zone = _Attaque.zone;
	/*effet = _Attaque.effet;*/
	degats = _Attaque.degats;
}

Attaque::Attaque(const int &_zone,  const int &_degats){
	zone = _zone;
	/*effet = _effet;*/
	degats = _degats;
}

Attaque::~Attaque(){
	zone = 0;
	degats = 0;
}

int Attaque::getZone(){
	return zone;
}

/*Effet Attaque::getEffet(){
	return effet;
}*/

int Attaque::getDegats(){
	return degats;
}

void Attaque::setZone(const int &_zone){
	zone = _zone;
}

/*void Attaque::setEffet(const Effet &_effet){
	effet = _effet;
}*/

void Attaque::setDegats(const int &_degats){
	degats = _degats;
}