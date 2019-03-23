/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platBio.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans PlatBio.h
*/

#include "PlatBio.h"

//Constructeur par parametres
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe)
	: Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
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

/**********************************************************************************
*Fonction : PlatBio::clone
*Description : Methode permettant de faire une copier l'objet
*Parametres : aucun
*Retour : (PlatBio*) retourne un objet alloué dynamiquement
***********************************************************************************/
Plat * PlatBio:: clone () const
{
	return new PlatBio(nom_, cout_, prix_, ecoTaxe_);
}
/**********************************************************************************
*Fonction : PlatBio::getPrixDeRevient
*Description : Methode permettant de faire le calcule suivant :prix_ - cout_ + ecoTaxe_
*Parametres : aucun
*Retour : retourne simplement le prix - le coût + l’ecotaxe
***********************************************************************************/
double PlatBio:: getPrixDeRevient()
{ 
	 return (Plat::getPrixRevient() + ecoTaxe_); // prix_ - cout_ + ecoTaxe_
}

/**********************************************************************************
*Fonction : PlatBio::afficherPlat
*Description : Methode permettant d'affiche les attributs du platBio
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void PlatBio::afficherPlat(ostream& os) const { 
	Plat::afficherPlat(os);
	os << "Plat Bio comprend une taxe ecologique de :" << ecoTaxe_ << "$" << endl;
}
