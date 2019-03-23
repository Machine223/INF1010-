/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
: PlatBio(nom,prix,cout,ecotaxe),Vege(nom, vitamines, proteines, mineraux) {
}
PlatBioVege:: ~PlatBioVege(){}

//TODO
void PlatBioVege::afficherPlat(ostream & os) const
{   //TODO
	PlatBio::afficherPlat(os);
	os << "ET ";
	Vege::afficherVege(os);
}

Plat * PlatBioVege::clone() const
{ //TODO
	return new PlatBioVege(PlatBio::nom_, prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_); // Est ce que ca existe des variables virtuelles
}

double PlatBioVege::calculerApportNutritif() const
{
   //TODO
	return ((vitamines_* proteines_) / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
