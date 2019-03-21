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
	vRes.x = (((x * vector2.x) + (y * vector2.y)) / (pow(vector2.x, 2) + pow(vector2.y, 2)));
	vRes.y = (((y * vector2.x) - (x * vector2.y)) / (pow(vector2.x, 2) + pow(vector2.y, 2)));
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

float Vect::module(){
	return sqrt((x*x)+(y*y));
}

void Vect::afficheVect(){
	if (y < 0)
		std::cout << "Votre vecteur vaut: " << x << " " << y << "\n";
	else std::cout << "Votre vecteur vaut: " << x << " + " << y << "\n";
}

void Vect::testRegression(){
	//Déclaration des vecteurs
	Vect v;
	Vect v1(12.3, 14.5);
	Vect v2(v1);
	//Premier test de régression
	assert(v.getX() == 0 && v.getX() == v.getY());
	assert(v1.getX() == v1.x && v1.getY() == v1.y);
	assert(v1 == v2);

	//Modification de certains vecteurs
	Vect v3(-15, 0.03);
	Vect v4 = v1;
	v2.setVect(v3);
	//Second test de régression
	assert(v4 == v1);
	assert(v2 == v3);
	assert(v1 - v4 == v);

	//Opérateurs
	Vect v5 = (v3 + v4 - v2) * v;
	//Troisième test de régression
	assert(v2 + v1 == v1 + v3);
	assert(v3 - v1 == v2 - v1);
	assert(v4 / v2 == v1 / v2);
	assert(v4 * v3 == v4 * v2 && v4 * v3 == v1 * v3 && v4 * v3 == v1 * v2);

	//Dernier test de régression
	assert(v5 == v);
	assert(v.module() == 0);
	assert(v1.module() > 0);
	assert(v4.module() - v2.module() - v2.module() < 0);
}