#include "Couleur.h"
#include <iostream>
#include <assert.h>

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

void Couleur::testRegression(){
	Couleur c;
	Couleur c1(180, 150, 20, 10);
	Couleur c2(c1);
	int a = 180;
	assert(c1.r == a);
	assert(c1.getR() == 180 && c1.getV() == 150 && c1.getB() == 20 && c1.getOpacity() == 10 );
	assert(c2.getR() == 180 && c2.getV() == 150 && c2.getB() == 20 && c2.getOpacity() == 10);


	c.setR(c1.getR());
	c.setB(c1.getB());
	c.setV(c1.getV());
	c.setOpacity(c1.getOpacity());

	assert(c.getR() == c1.getR() && c.getV() == c1.getV() && c.getB() == c1.getB() && c.getOpacity() == c1.getOpacity());
}