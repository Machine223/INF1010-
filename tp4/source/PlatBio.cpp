/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}


PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

//TODO
Plat * PlatBio:: clone () const
{
	return new PlatBio(*this);
}
double PlatBio:: getPrixDeRevient()
{ //TODO}

void PlatBio::afficherPlat(ostream& os) const
{
	Plat::afficherPlat(os);
	os << "Plat Bio \t comprend une Taxe ecologique de : " << ecoTaxe_ << "$" << endl;
}

double PlatBio::getPrixDeRevient()
{
	return Plat::getPrixRevient() + ecoTaxe_;
}
