/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les fonctions déclarées dans Plat.h
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//getters

string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}
//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}


//methodes en plus Surchage de flux avec l'operateur "<<"
ostream & operator<<(ostream & flux, const Plat& plat)
{
	flux << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return flux;
}

bool operator<(const Plat & plat1, const Plat & plat2)
{
	if (plat1.prix_ < plat2.prix_)
		return true;
	else
		return false;
}
