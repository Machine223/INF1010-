/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    platBio.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans PlatBio.cpp
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"
#include "debogageMemoire.hpp"

using namespace std;

class PlatBio: public Plat {
public:
	// Constructeur par parametres
	PlatBio(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0);

	//Destructeur
	virtual ~ PlatBio();

	//getters/setters
	double getEcoTaxe() const;
	void setEcoTaxe(double ecoTaxe);

	//Autres methodes
    void afficherPlat(ostream& os) const override; // TODO
    double getPrixDeRevient(); //TODO
    Plat * clone() const override; // TODO
protected:
	double ecoTaxe_;
};

#endif // !PLAT_VERT_H
