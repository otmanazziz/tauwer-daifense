#ifndef HERO
#define HERO

#include "Sort.h"
#include <iostream>

class Hero{
private:
	std::vector<Sort> tabSort;
public:	
	Hero();
	Hero(const Hero &_Hero);
	Hero(const std::vector<Sort> &_tabSort);
	~Hero();

};

#endif