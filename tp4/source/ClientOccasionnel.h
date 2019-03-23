/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientOccasionnel.h
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les déclarations des fonctions implémenté dans clientOccasionnel.cpp
*/

#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel: public Client
{
public:
	//Constructeur
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);//TODO
	//Destructeur
	virtual ~ClientOccasionnel();
	//Autres methode
	int getNbPoints() const override;// TODO
	void afficherClient(ostream & os) const;// TODO
	double getReduction(const Restaurant & res, double montant, bool estLivraison) override; // TODO
};

#endif
