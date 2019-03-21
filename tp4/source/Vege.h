/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#ifndef VEGE_H
#define VEGE_H
#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"
#include "def.h"


using namespace std;

class Vege
{
public:
	Vege(string nom, double vitamines, double proteines, double mineraux);
	double getVitamines();
	double getProteines();
	double getMineraux();
	void setVitamines(double vitamines);
	void setProteines(double proteines);
	void setMineraux(double mineraux);
    void afficherVege(ostream & os)const; // TODO DONE
    virtual double calculerApportNutritif() const = 0;//TODO DONE voir si mettre virtuelle pure ou pas (si oui ajouter obligatoire =0) pour etre classe abstrait

protected: 
	double vitamines_;
	double proteines_;
	double mineraux_;
    
    string nom_;
};
#endif