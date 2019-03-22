/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege : public Vege, public Plat
{
public:
	// Constructeur par parametre
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
	double proteines = 0, double mineraux = 0);//TODO DONE
	// Destructeur
	~ PlatVege();
	// Autre methodes
	Plat * clone()const; // TODO DONE
	virtual void afficherPlat(ostream & os) const;//TODO DONE
	double calculerApportNutritif() const; // TODO DONE VIRTUEL OU NON

protected:

};
#endif
