/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientOccasionnel.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans clientOccasionnel.h
*/

#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
	:Client(nom, prenom, tailleGroupe) {}


ClientOccasionnel::~ClientOccasionnel(){}

// Client occasionnel n'a aucun point
int ClientOccasionnel::getNbPoints() const
{
	return 0; 
}

/**********************************************************************************
*Fonction : ClientOccasionnel::afficherClient
*Description : Methode permettant d'affiche les attributs du client Occasionnel
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void ClientOccasionnel::afficherClient(ostream & os) const
{
	Client::afficherClient(os); // Affichage de client

}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	return 0.0; // Aucune reduction au client occasionnel
}

