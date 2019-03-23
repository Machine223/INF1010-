/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platBioVege.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans PlatBioVege.cpp
*/

#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"

class PlatBioVege :	public PlatBio, public Vege
{
public:
	PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
	double vitamines = 0, double proteines = 0, double mineraux = 0);// TODO
	//Destructeur
	virtual ~PlatBioVege();
	// Autres methodes
	Plat * clone() const override; // TODO
	void afficherPlat(ostream & os) const override;// TODO
	double calculerApportNutritif() const override; // TODO

};
#endif
