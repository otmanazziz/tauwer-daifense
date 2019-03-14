#ifndef BASE
#define BASE
#include "Vect.h"
class Base{
private:
	int vie;
	Vect position;
public:
	Base();
	Base(const Vect &_position);
	Base(const int &_vie, const Vect &_position);
	Base(const Base &_Base);
	~Base();

	int getVie();
	Vect getPosition();

	void setVie(const int &_vie);
	void setPosition(const Vect &_position);

	void perdreVie(const int &viePerdue);

};

#endif