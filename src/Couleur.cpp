#include "Couleur.h"
#include <iostream>

Couleur::Couleur(){
	r = 0;
	v = 0;
	b = 0;
	opacity = 0;
}

Couleur::Couleur(const unsigned char &_r, const unsigned char &_v, const unsigned char &_b, const float &_opacity){
	r = _r;
	v = _v;
	b = _b;
	opacity = _opacity;
}

Couleur::Couleur(const Couleur &_Couleur){
	r = _Couleur.r;
	v = _Couleur.v;
	b = _Couleur.b;
	opacity = _Couleur.opacity;
}

Couleur::~Couleur(){
	//DESTRUCTEUR
	std::cout << "La couleur a ete detruite..\n";
}

unsigned char Couleur::getR(){
	return r;
}

unsigned char Couleur::getV(){
	return v;
}

unsigned char Couleur::getB(){
	return b;
}

float Couleur::getOpacity(){
	return opacity;
}

Couleur Couleur::operator=(const Couleur &_Couleur){
	Couleur c;
	c.r = _Couleur.r;
	c.v = _Couleur.v;
	c.b = _Couleur.b;
	return c;
}

void Couleur::setR(const unsigned char &_r){
	r = _r;
}

void Couleur::setV(const unsigned char &_v){
	v = _v;
}

void Couleur::setB(const unsigned char &_b){
	b = _b;
}

void Couleur::setOpacity(const float &_opacity){
	opacity = _opacity;
}