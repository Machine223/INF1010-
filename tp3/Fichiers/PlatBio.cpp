#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) 
		: Plat(nom,prix,cout), ecoTaxe_(ecotaxe) 
{
	type_ = Bio;
}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

ostream & operator<<(ostream & os, const PlatBio & plat)
{
	
	Plat platBio = static_cast <Plat> (plat); 
	//ici on convertie un type PlatBio en un type Plat pour utiliser la methode de l'affichage de Plat
	os << platBio << endl; //Utilise la methode de l'affichage de Plat 
	os << "\t comprend une Taxe ecologique de : " << plat.cout_ << "$" << endl;
	return os;
}
