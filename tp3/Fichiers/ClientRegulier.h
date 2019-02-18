#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
#include <vector>

const double TAUX_REDUC_REGULIER = 0.1;
const double TAUX_REDUC_PRESTIGE = 0.2;
const double SEUIL_DEBUT_REDUCTION = 75;
const double SEUIL_LIVRAISON_GRATUITE = 200;
class ClientRegulier : public Client
{
public:
	ClientRegulier(); //Le constructeur par d�faut
	ClientRegulier(string nom , string prenom, int tailleGroupe ,int nbPoints); //Le constructeur par param�tres


	//Accesseurs
	int getNbPoints(); //accede au nombre de points


	//Autres M�thodes
	void augmenterNbPoints(int bonus); //prend en param�tre le nombre points � ajouter au solde actuel de points.
	friend ostream & operator<<(ostream & os, const ClientRegulier& client); //affiche leurs caract�ristiques
	

protected:
	int nbPoints_;
};
#endif
