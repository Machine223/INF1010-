/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientPrestige.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans clientPrestige.cpp
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	//Constructeur
	ClientPrestige();
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, 
		           int nbPoints, ZoneHabitation adresse);// TODO

	//Destructeur
     ~ClientPrestige(){};
	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions
    void afficherClient(ostream & os) const override;// TODO
	string getAdressCodeString() const;
    double getReduction(const Restaurant & res, double montant, bool estLivraison); //TODO

private:
	ZoneHabitation adresse_;

};

#endif

