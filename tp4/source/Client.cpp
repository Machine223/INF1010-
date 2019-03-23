/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 4
file:    client.cpp
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 25 mars 2019
Description : Ce code contient les fonctions déclarées dans client.h
*/

#include "Client.h"

//Constructeur par defaut
Client::Client()
{ 
	tableOccupee_ = nullptr;
}

//Constructeur par parametre
Client::Client(string_view nom, string_view prenom, int tailleGroupe) 
	: nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

string Client::getNom() const
{
	return nom_;
}

string Client::getPrenom() const
{
	return prenom_;
}
void Client:: setTable(Table * ta)
{
	tableOccupee_ = ta;
}

Table * Client:: getTable() const
{ 
	return tableOccupee_;
}

/**********************************************************************************
*Fonction : Client::afficherClient
*Description : Methode permettant d'affiche les attributs du client
*Parametres : ostream& os
*Retour : aucun
***********************************************************************************/
void Client::afficherClient(ostream & os) const
{ 
		os << "Nom " << nom_ << " Prenom " << prenom_;
		if (tableOccupee_ != nullptr)
			os << " a une place dans la table " << tableOccupee_->getId() << endl;
		else
			os << "n'a pas de place au restaurant" << endl;
}

