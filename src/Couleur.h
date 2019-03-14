#ifndef COULEUR
#define COULEUR

class Couleur{
private:
	unsigned char r;
	unsigned char v;
	unsigned char b;
	float opacity; //opacity between 0.0 and 1.0
public:
	Couleur();
	Couleur(const unsigned char &_r, const unsigned char &_v, const unsigned char &_b, const float &_opacity);
	Couleur(const Couleur &_couleur);
	~Couleur();

	unsigned char getR();
	unsigned char getV();
	unsigned char getB();
	float getOpacity();

	Couleur operator=(const Couleur &_Couleur);

	void setR(const unsigned char &_r);
	void setV(const unsigned char &_v);
	void setB(const unsigned char &_b);
	void setOpacity(const float &_opacity);
};

#endif