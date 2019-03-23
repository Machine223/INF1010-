/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    clientRegulier.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans clientRegulier.h
*/

#include "ClientPrestige.h"
#include "Restaurant.h"

//Constructeur par defaut
ClientPrestige::ClientPrestige()
{
	adresse_ = ZoneHabitation::Zone3;
}

// Constructeur par parametres
ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse): ClientRegulier(nom,prenom,tailleGroupe,nbPoints), adresse_(adresse)
{

}

ZoneHabitation ClientPrestige::getAdresseCode() const
{
	return adresse_;
}

/**********************************************************************************
*Fonction : ClientPrestige::afficherClient
*Description : Methode permettant d'affiche les attributs du client Prestige
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void ClientPrestige::afficherClient(ostream & os) const
{
	ClientRegulier::afficherClient(os);
	os << "Habite dans la zone: " << getAdressCodeString() << endl;
}


string ClientPrestige::getAdressCodeString() const
{
	string zone;
	switch (adresse_)
	{
	case ZoneHabitation::Zone1:
		zone = "Zone 1";
		break;
	case  ZoneHabitation::Zone2:
		zone = " Zone 2";
		break;
	case  ZoneHabitation::Zone3:
		zone = "Zone 3";
		break;

	default:
		zone = "erreur zone";
		break;
	}
	return zone;
}

/**********************************************************************************
*Fonction : ClientPrestige::getReduction
*Description : Methode qui retourne la réduction qu'un client prestige a droit
*Parametres : ostream& os
*Retour : double
***********************************************************************************/
double ClientPrestige :: getReduction(const Restaurant & res, double montant , bool estLivraison) 
{   
	if ((nbPoints_ < SEUIL_LIVRAISON_GRATUITE) && estLivraison)
			return (-montant * TAUX_REDUC_PRESTIGE + res.getFraisLivraison(adresse_));
	else
		return (-montant * TAUX_REDUC_PRESTIGE) ;
}
