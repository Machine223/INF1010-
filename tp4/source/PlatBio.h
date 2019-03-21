/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {
public:
	// constructeurs
    PlatBio(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0); //TODO deja fait

	// destructeur
    ~ PlatBio(); //TODO
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
    void afficherPlat(ostream& os) const override; // TODO A completer
    virtual double getPrixDeRevient(); //TODO voir pourquoi on ne peux pas mettre override a la fin
    Plat * clone() const override; // TODO

protected:   // garde les carat/ristique de private mais peut être utiliser dans une classe dérivée
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
