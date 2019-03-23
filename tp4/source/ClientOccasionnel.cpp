/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe) :Client(nom, prenom, tailleGroupe)
{ 
}
ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{
	return 0; // Client occasionnel n a aucun point
}

void ClientOccasionnel::afficherClient(ostream & os) const
{
	Client::afficherClient(os); // Affichage de client

}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	return 0.0; // Aucune reduction au client occasionnel
}

