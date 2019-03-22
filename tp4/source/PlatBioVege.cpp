/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
	: PlatBio(nom, prix, cout, ecotaxe), Vege(nom, vitamines, proteines, mineraux) {} //TODO DONE



PlatBioVege:: ~PlatBioVege(){}

Plat * PlatBioVege::clone() const
{
	return new PlatBioVege(*this);
}

//TODO
void PlatBioVege::afficherPlat(ostream & os) const
{   //TODO
	PlatBio::afficherPlat(os);
	os << "ET PLAT VEGE " << Vege:: nom_ << "/t vitamines " << vitamines_ << " Proteines " << proteines_ << " Mineraux " << mineraux_ << endl;

}

Plat * PlatBioVege::clone() const
{ //TODO}

double PlatBioVege::calculerApportNutritif() const
{
	return Vege::calculerApportNutritif() * AVANTAGE_SANS_PESTICIDE;
}
