/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO DONE
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) 
	: Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux) {}


PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ 
	return new PlatVege(*this);
}


void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	os << "PLAT VEGE " << Vege::nom_; Vege::afficherVege(os);
	os << "(Apport nutritif " << calculerApportNutritif() << "mg)" << endl;
}

double PlatVege::calculerApportNutritif() const
{
	return Vege::calculerApportNutritif();
    
}
