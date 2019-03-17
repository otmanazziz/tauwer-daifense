#include "Hero.h"

Hero::Hero(){

}

Hero::Hero(const Hero &_Hero){
	tabSort = _Hero.tabSort;
}

Hero::Hero(const std::vector<Sort> &_tabSort){
	tabSort = _tabSort;
}

Hero::~Hero(){
	tabSort.clear();
}

std::vector<Sort> Hero::getTabSort(){
	return tabSort;
}

void Hero::setTabSort(const std::vector<Sort> &_tabSort){
	tabSort = _tabSort;
}

void Hero::setHeroIndice(const int &indice, Sort sort){
	tabSort[indice].setNom(sort.getNom());
	tabSort[indice].setAttaque(sort.getAttaque());
}
