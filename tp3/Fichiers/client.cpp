#include "Client.h"

Client::Client() :nom_("inconnue"), prenom_("inconnue"), statut_(Occasionnel)
{
}

Client::Client(string nom, string prenom, int tailleGroupe, enum StatutClient statut )
		:nom_(nom),prenom_(prenom), tailleGroupe_(tailleGroupe), statut_(statut)
{
}

Client::~Client()
{
}

StatutClient Client::getStatut()
{
	return statut_;
}

int Client::getTailleGroupe()
{
	return tailleGroupe_;
}

string Client::getNom()
{
	return nom_;
}

string Client::getPrenom()
{
	return prenom_;
}

string Client::convertirStatutString() const
{
	string status;
	switch (statut_) {
	case Occasionnel:
		status = "Occasionnel";
		break;
	case Fidele:
		status = "Fidele";
		break;
	case Prestige:
		status = "Prestige";
		break;
	}
	return status;
}

ostream & operator<<(ostream & os, const Client & client)
{
	os << "-" << client.nom_ << " " << client.nom_ << " status :" << client.statut_;
	return os;
}
