/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platVege.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans PlatVege.h
*/

#include "PlatVege.h"

// Constructeur par parametres
PlatVege::PlatVege(string nom, double prix, double cout, double vitamines, double proteines, double mineraux)
	: Plat(nom, prix, cout), Vege(nom,vitamines, proteines, mineraux)
{
	setTaxe();
}

//Destructeur
PlatVege::~ PlatVege(){}

/**********************************************************************************
*Fonction : PlatVege::clone
*Description : Methode permettant de faire une copier l'objet
*Parametres : aucun
*Retour : (Plat*) retourne un objet alloué dynamiquement
***********************************************************************************/
Plat* PlatVege::clone()const
{ //TODO
	return new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_);
}

/**********************************************************************************
*Fonction : PlatVege::afficherPlat
*Description : Methode permettant d'affiche les attributs du plat vegetarien
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void PlatVege::afficherPlat(ostream & os) const 
{   //TODO
	Plat::afficherPlat(os);
	Vege::afficherVege(os); 	// "PLAT VEGE" 
	os << "(Apport nutritif:" << calculerApportNutritif() << " mg)" << endl;
}

/**********************************************************************************
*Fonction : PlatVege::calculerApportNutritif
*Description : Methode permettant de calculer l'apport nutritif d'un plat vegetarien
*Parametres : aucun
*Retour : double
***********************************************************************************/
double PlatVege::calculerApportNutritif() const
{
	return (vitamines_ * proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}

// Le pourcentage de la taxe d'un plat vegetarien est de 0.07
void PlatVege::setTaxe()
{
	taxe_ = 0.07;
}

// Methode d'acces à l'attribut taxe_
double PlatVege::getTaxe() const
{
	return taxe_;
	
}
