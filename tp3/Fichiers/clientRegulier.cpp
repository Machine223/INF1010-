#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() : Client(), nbPoints_(0)
{
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints)
	:Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints)
{
}

int ClientRegulier::getNbPoints()
{
	return nbPoints_;
}

void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

ostream & operator<<(ostream & os, const ClientRegulier & client)
{
	Client ClientRegulier = static_cast <Client> (client);
	//ici on convertie un type ClientRegulier en un type Client pour utiliser la methode de l'affichage de Client
	os << ClientRegulier << "Possede " << client.nbPoints_ << "points."; //Utilise la methode de l'affichage de Client et on ajouter les points
	return os;
}
