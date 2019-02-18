/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 F�vrier 2019
Ce code contient les d�clarations des fonctions impl�ment� dans Plat.cpp
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
	//L�op�rateur << (remplace la m�thode d�affichage), qui affiche les caract�ristiques du plat.
	friend bool operator< (const Plat& plat1, const Plat& plat2); 
	//L�op�rateur < qui compare 2 plats selon leur prix de vente.
private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
