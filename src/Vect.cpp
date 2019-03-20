#include "Vect.h"
#include <iostream>
#include <math.h>

Vect::Vect(){
	x = 0;
	y = 0;
}

Vect::Vect(const Vect &vec){
	x = vec.x;
	y = vec.y;
}

Vect::Vect(const float &xV, const float &yV){
	x = xV;
	y = yV;
}

Vect::~Vect(){

}

Vect Vect::operator+(const Vect &vector2){
	Vect vRes;
	vRes.x = x + vector2.x;
	vRes.y = y + vector2.y;
	return vRes;
}

Vect Vect::operator*(const Vect &vector2){
	Vect vRes;
	vRes.x = (x * vector2.x) - (y * vector2.y);
	vRes.y = (x * vector2.y) + (vector2.x * y);
	return vRes;
}

Vect Vect::operator-(const Vect &vector2){
	Vect vRes;
	vRes.x = x - vector2.x;
	vRes.y = y - vector2.y;
	return vRes;
}

Vect Vect::operator/(const Vect &vector2){
	Vect vRes;
	vRes.x = (x + y) * (vector2.x - vector2.y);
	vRes.y = (vector2.x + vector2.y) * (vector2.x - vector2.y);
	return vRes;
}

void Vect::operator=(const Vect &vector2){
	x = vector2.x;
	y = vector2.y;
}

bool Vect::operator==(const Vect &vector2){
	
	return vector2.x == x && vector2.y == y ;
}

float Vect::getX() const{
	return x;
}

float Vect::getY() const{
	return y;
}

void Vect::setVect(const Vect &vector){
	x = vector.x;
	y = vector.y;
}

void Vect::afficheVect(){
	if (y < 0)
		std::cout << "Votre vecteur vaut: " << x << " " << y << "\n";
	else std::cout << "Votre vecteur vaut: " << x << " + " << y << "\n";
}