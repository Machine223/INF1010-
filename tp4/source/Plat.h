/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"

//using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

using namespace std;

class Plat {
public:
	// constructeur
	Plat( string_view nom = "inconnu", double prix = 0, double cout = 0);
	Plat(const Plat& platCopie); //Constructeur par copie pour utiliser dans clone de plat


    // destructeur
	virtual ~Plat(); // TODO avoir un destructeur virtuel
	//getters 
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	//setters 
	void setNom(string nom);
	void setPrix(double prix);

	//methodes en plus
    double getPrixRevient() const;
    virtual Plat* clone () const; // TODO DONE
	bool operator < (const Plat& plat) const;
    virtual void afficherPlat(ostream& os) const; // TODO DONE vistual car utiliser dans les classe derivee


protected:
	string nom_;
	double prix_;
	double cout_;
};

#endif // !PLAT_H
