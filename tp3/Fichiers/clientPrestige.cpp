#include "ClientPrestige.h"

ClientPrestige::ClientPrestige() : ClientRegulier(),addresse_(Zone3) {}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse)
		: ClientRegulier(nom,prenom,tailleGroupe, nbPoints),addresse_(addresse) {}

AddressCode ClientPrestige::getAddresseCode()
{
	return addresse_;
}

void ClientPrestige::setAdresseCode(AddressCode zone)
{
	addresse_ = zone;
}

string ClientPrestige::getAddressCodeString()
{
	string adresse;
	switch (addresse_) {
	case Zone1:
		adresse = "Zone1";
		break;
	case Zone2:
		adresse = "Zone2";
		break;
	case Zone3:
		adresse = "Zone3";
		break;
	}
	return adresse;
}

ostream & operator<<(ostream & os, ClientPrestige client)
{
	Client ClientPrestige = static_cast <Client> (client);
	//ici on convertie un type ClientRegulier en un type Client pour utiliser la methode de l'affichage de Client
	os << ClientPrestige << "Possede " << client.nbPoints_ << "points." << endl; //Utilise la methode de l'affichage de Client et on ajouter les points
	os << "Habite dans la " << client.getAddressCodeString();
	return os;
}
