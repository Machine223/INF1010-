/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    plat.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans Plat.h
*/

#include "Plat.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
#include "debogageMemoire.hpp"
using namespace std;

Plat::Plat(string_view nom, double prix, double cout) : nom_(nom), prix_(prix), cout_(cout) {
}
Plat::~Plat()
{
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

bool Plat::operator < (const Plat& plat) const
{
	return prix_ < plat.prix_;
}

/**********************************************************************************
*Fonction : afficherPlat
*Description : Methode permettant d'affiche les attributs du plat
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void Plat::afficherPlat(ostream & os) const
{ // TODO
	os << "PLAT ----" << nom_ << " " << prix_ << "$" << "("<< cout_ <<"$ pour le restaurant)" << endl;
	
}
double Plat::getPrixRevient()
{  
	return prix_ - cout_;    
}

/**********************************************************************************
*Fonction : clone
*Description : Methode permettant de de faire une copier l'objet 
*Parametres : aucun
*Retour : (Plat*) retourne un objet alloué dynamiquement 
***********************************************************************************/
 Plat *  Plat:: clone () const
{ 
	 return new Plat(nom_, prix_, cout_);
}
