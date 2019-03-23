/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platBioVege.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans PlatBioVege.h
*/

#include "PlatBioVege.h"

//Constructeur par parametre
PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe,
							double vitamines, double proteines, double mineraux)
		: PlatBio(nom,prix,cout,ecotaxe),Vege(nom, vitamines, proteines, mineraux) {}


PlatBioVege:: ~PlatBioVege(){}

/**********************************************************************************
*Fonction : PlatBioVege::afficherPlat
*Description : Methode permettant d'affiche les attributs du plat Bio et vegetarien
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void PlatBioVege::afficherPlat(ostream & os) const
{   
	PlatBio::afficherPlat(os);
	os << "ET ";
	Vege::afficherVege(os);
}

/**********************************************************************************
*Fonction : PlatBioVege::clone
*Description : Methode permettant de faire une copier l'objet
*Parametres : aucun
*Retour : (Plat*) retourne un objet alloué dynamiquement
***********************************************************************************/
Plat * PlatBioVege::clone() const
{ //TODO
	return new PlatBioVege(PlatBio::nom_, prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_); // Est ce que ca existe des variables virtuelles
}

/**********************************************************************************
*Fonction : PlatBioVege::calculerApportNutritif
*Description : Methode permettant de calculer l'apport nutritif d'un plat bio vegetarien
*Parametres : aucun
*Retour : double
***********************************************************************************/
double PlatBioVege::calculerApportNutritif() const
{
   //TODO
	return ((vitamines_* proteines_) / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
