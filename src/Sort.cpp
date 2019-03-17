#include "Sort.h"
#include <iostream>

Sort::Sort(){
	//attaque = 0;
}

Sort::Sort(const Sort &_Sort){
	attaque = _Sort.attaque;
}

Sort::Sort(const std::string &_nom, const Attaque &_attaque){
	nom = _nom;
	attaque = _attaque;
}

Sort::~Sort(){
	//
}

std::string Sort::getNom(){
	return nom;
}

Attaque Sort::getAttaque(){
	return attaque;
}

void Sort::setNom(const std::string &_nom){
	nom = _nom;
}

void Sort::setAttaque(const Attaque &_attaque){
	attaque = _attaque;
}