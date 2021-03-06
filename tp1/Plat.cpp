/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Plat.cpp
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 F�vrier 2019
Ce code contient les   fonctions d�clar�es dans Plat.h
*/

#include "Plat.h"

Plat::Plat()
{
	nom_ = "inconnue";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string& nom, double prix, double cout)
{
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

string Plat::getNom() const
{
	return nom_;
}

double Plat::getPrix() const
{
	return prix_;
}

double Plat::getCout() const
{
	return cout_;
}

void Plat::setNom(string nom)
{
	nom_ = nom;
}

void Plat::setPrix(double prix)
{
	prix_ = prix;
}

void Plat::afficher()const
{
	std::cout << "	" << nom_ << "		" << prix_ << "$	(" << cout_ << "$	pour le restaurant)" << std::endl;
}
