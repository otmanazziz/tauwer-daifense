#include "Image.cpp"

Image::Image(){

}

Image::Image(const Image &_image){
	tabCouleur = _image.tabCouleur;
	dim = _image.dim
}

Image::Image(const std::vectore<Couleur> &_tabCouleur, const Vect &_dim){
	tabCouleur = _tabCouleur;
	dim = _dim;
}

Image::~Image(){
	tabCouleur.clear();
}

std::vector<Couleur> Image::getTabCouleur(){
	return tabCouleur;
}

Vect Image::getDim(){
	return dim;
}

void Image::setTabCouleur(const std::vector<Couleur> &_tabCouleur){
	tabCouleur = _tabCouleur;
}

void Image::setDim(const Vect &_dim){
	dim = _dim;
}