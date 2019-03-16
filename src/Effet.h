#ifndef EFFET
#define EFFET
class Effet{
private:
	int valeur;
	//int* ptrEffet=valeur;
public:
	Effet();
	Effet(const int &_val); //const int* &_ptrEffet);
	Effet(const Effet &_effet);
	~Effet();

	int getValeur();

	void setValeur(const int &_val);

	void afficheEffet();

};
#endif