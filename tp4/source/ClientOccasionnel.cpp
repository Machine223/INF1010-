/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe) :Client(nom, prenom, tailleGroupe)
{ 
}
ClientOccasionnel::~ClientOccasionnel(){}

// Client occasionnel n a aucun point
int ClientOccasionnel::getNbPoints() const
{
	return 0;
}

// Affichage de client
void ClientOccasionnel::afficherClient(ostream & os) const
{
	Client::afficherClient(os); 

}
// Aucune reduction au client occasionnel
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	return 0.0; 
}

