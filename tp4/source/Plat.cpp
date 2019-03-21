/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Plat.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
//#include "debogageMemoire.hpp"
using namespace std;

Plat::Plat(string_view nom, double prix, double cout) : nom_(nom), prix_(prix), cout_(cout) {
}
Plat::Plat(const Plat & platCopie)
{
	nom_ = platCopie.nom_;
	prix_ = platCopie.prix_;
	cout_ = platCopie.cout_;
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

// La m�thode afficherPlat() affiche les attributs 
//du plat (voir l�affichage � la fin de l��nonc�) : nom, le prix et le co�t comme pr�sent� dans l�annexe.
void Plat::afficherPlat(ostream & os) const
{ // TODO virtuel ou pas
	os << nom_ << " - " << prix_ << " $" << " (" << cout_ << "$ pour le restaurant)";
}


double Plat::getPrixRevient()
{  
	return prix_ - cout_;
}

//La m�thode clone() retourne un objet allou� dynamiquement qui est une copie de l�objet courant.
 Plat*  Plat:: clone () const
{
	 return new Plat(*this);
}
