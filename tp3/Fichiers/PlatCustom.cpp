#include "PlatCustom.h"

PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients)
	: Plat(nom, prix, cout), nbIngredients_(nbIngredients) 
{
	type_ = Custom;
	setNbIngredients(nbIngredients);
	supplement_ = calculerSupplement();
}

int PlatCustom::getNbIngredients() const
{
	return nbIngredients_;
}

double PlatCustom::getSupplement() const
{
	return supplement_;
}

void PlatCustom::setNbIngredients(int nIngredients)
{
	nbIngredients_ = nIngredients;
}
//En plus du prix du plat, on ajoute au plat, un supplément égal au
//nombre d’ingrédients multiplié par la constante FRAIS_CUSTOMISATION.
double PlatCustom::calculerSupplement() const
{
	double montant = 0;
	montant = Plat::getPrix() + (nbIngredients_*FRAIS_CUSTOMISATION);
	return montant;
}

ostream & operator<<(ostream & os, const PlatCustom & plat)
{
	Plat platCustom = static_cast <Plat> (plat);
	//ici on convertie un type platCustom en un type Plat pour utiliser la methode de l'affichage de Plat
	os << platCustom << endl; //Utilise la methode de l'affichage de Plat 
	return os;
}
