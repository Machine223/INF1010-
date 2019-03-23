/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout, double vitamines, double proteines, double mineraux): Plat(nom, prix, cout), Vege(nom,vitamines, proteines, mineraux)
{
	setTaxe();
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ //TODO
	return new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_);
}


void PlatVege::afficherPlat(ostream & os) const
{   //TODO
	Plat::afficherPlat(os);
	// "PLAT VEGE" 
	Vege::afficherVege(os);
	os << "(Apport nutritif:" << calculerApportNutritif() << " mg)" << endl;
}

double PlatVege::calculerApportNutritif() const
{
	return (vitamines_ * proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe()
{
	taxe_ = 0.07;
}

double PlatVege::getTaxe() const
{
	return taxe_;
	
}
