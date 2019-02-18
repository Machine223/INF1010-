/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les déclarations des fonctions implémenté dans Plat.cpp
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

class Plat {
public:
	/// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	///getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	///setters
	void setNom(string nom);
	void setPrix(double prix);

	///methodes en plus
	friend ostream& operator << (ostream& flux, const Plat& plat); 
	//L’opérateur << (remplace la méthode d’affichage), qui affiche les caractéristiques du plat.
	friend bool operator< (const Plat& plat1, const Plat& plat2); 
	//L’opérateur < qui compare 2 plats selon leur prix de vente.
private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
