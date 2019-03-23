/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"

class PlatVege :
        public Vege, public Plat, public Taxable
{
public:
	// Constructeur par parametre
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
	double proteines = 0, double mineraux = 0);//TODO
	// Destructeur
	virtual ~ PlatVege();
	// Autre methodes
	Plat * clone()const; // TODO
	void afficherPlat(ostream & os) const;//TODO
	double calculerApportNutritif() const; // TODO
	void setTaxe() override; // Avoir
	double getTaxe()const override; // A voir

protected:
	// Ajout de l'attribut taxe_
	double taxe_;

};
#endif
