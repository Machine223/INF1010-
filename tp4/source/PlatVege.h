/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platVege.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans PlatVege.cpp
*/

#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :public Vege, public Plat, public Taxable
{
public:
	//Constructeur
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
	double proteines = 0, double mineraux = 0);//TODO

	//Destructeur
	virtual ~ PlatVege();

	//Autres methode
	Plat * clone()const; // TODO
	void afficherPlat(ostream & os) const;//TODO
	double calculerApportNutritif() const; // TODO

	// Heritage de Vege.h et sont modifie
	void setTaxe() override; // Avoir
	double getTaxe()const override; // A voir
protected:
	// Ajout de l'attribut taxe_
	double taxe_;

};
#endif
