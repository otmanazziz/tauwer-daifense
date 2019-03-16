#include "Effet.h"
#include <iostream>

	Effet::Effet(){
		valeur = 0;
		//_ptrEffet= valeur;
	}
	
	Effet::Effet(const Effet &_effet){
		valeur = _effet.valeur;
	}

	Effet::Effet(const int &_val){//const int* &_ptrEffet){
		valeur = _val;
	}

	Effet::~Effet(){
		//
	}

	int Effet::getValeur(){
		return valeur;
	}

	void Effet::setValeur(const int &_val){
		valeur = _val;
	}

	void Effet::afficheEffet(){
		std::cout << "Les effets sont de" << valeur; 
	}