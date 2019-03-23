/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientRegulier.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans clientRegulier.h
*/

#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints)
	:Client(nom, prenom, tailleGroupe), nbPoints_(npoints){}
	

ClientRegulier::~ClientRegulier() {}


int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

/**********************************************************************************
*Fonction : ClientRegulier::afficherClient
*Description : Methode permettant d'affiche les attributs du client Regulier
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void ClientRegulier::afficherClient(ostream & os) const
{
	Client::afficherClient(os);
	os << "Il possede " << nbPoints_ << " points";
}

/**********************************************************************************
*Fonction : ClientRegulier::getReduction
*Description : Methode qui retourne la réduction si le client a depasser le seuil de reduction
*Parametres : ostream& os
*Retour : double
***********************************************************************************/
double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION)
		return (-montant * TAUX_REDUC_REGULIER);
	return 0.0;
}
