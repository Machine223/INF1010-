/*
* Titre : PlatCustom.h - Travail Pratique #2
* Date : 11 F�vrier 2019
* Auteur : Fatou S. MOUNZEO
*/

#ifndef PLAT_CUSTOM_H
#define PLAT_CUSTOM_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

const double FRAIS_CUSTOMISATION = 0.75;

class PlatCustom : public Plat {
public:
	// constructeur
	PlatCustom(string nom, double prix , double cout,int nbIngredients ); //Le constructeur par param�tres

	//getters 
	int getNbIngredients() const;
	double getSupplement()const;

	//setters 
	void setNbIngredients(int nIngredients);

	//methodes en plus 

	friend ostream& operator<<(ostream& os, const PlatCustom& plat); //Methode d'affichage

private:
	double supplement_; //suppl�ment � ajouter au prix du plat.
	int nbIngredients_; //nombre d�ingr�dients suppl�mentaires.
	double calculerSupplement() const; //permet de calculer le montant du suppl�ment.
};

#endif // !PLAT_VERT_H
