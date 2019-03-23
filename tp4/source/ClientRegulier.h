/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientRegulier.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans clientRegulier.cpp
*/

#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
//#include "Restaurant.h"
#include "def.h"
class Restaurant;

class ClientRegulier : public Client
{
 public:
	//Constructeur
	ClientRegulier();
	ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints);// TODO
	//Destructeur
    virtual ~ClientRegulier();
	//Accesseurs
     int getNbPoints() const ;

	//Autres Methodes
	void augmenterNbPoints(int bonus);
	//Methode virtuelles
    void afficherClient(ostream & os) const override; // TODO
    double getReduction(const Restaurant & res, double montant , bool estLivraison) override;// TODO
protected:
	int nbPoints_;
};
#endif
