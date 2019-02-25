/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur :Fatou S. MOUNZEO
*/

#include "Table.h"

//constructeurs
Table::Table() 
{
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces)
{
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//getters
int Table::getId() const 
{
	return id_;
}

int Table::getNbPlaces() const 
{
	return nbPlaces_;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

bool Table::estPleine() const 
{
	return nbPlaces_ == 0;
}

int Table::getNbClientsATable() const
{
	return nbClientsATable_;
}
vector<Plat*> Table::getCommande() const
{
	return commande_;
}

Client * Table::getCliengtPrincipal() const
{
	return clientPrincipal_;
}


//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::setClientPrincipal(Client * clientPrincipal)
{
	clientPrincipal_ = clientPrincipal;
}


void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
}

void Table::placerClients(int nbClient) {
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}

//autres methodes
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
	
	//Pour que le chiffre d'Affaire prend en compte le type de plat, nous verifions sont type
	double chiffre = 0;
	for (unsigned i = 0; i < commande_.size(); ++i) {
		
		Plat plat = (*commande_[i]);
		switch(plat.getType())
		{
		case Regulier:	//Calcul le prix d'un type plat 
			chiffre += plat.getPrix() - plat.getCout();
			break;
		case Bio:		//Calcul le prix d'un type platBio (downcasting)
		{
			PlatBio* platBio = static_cast <PlatBio*> (&plat);
			chiffre += (plat.getPrix()* platBio->getEcoTaxe()) - plat.getCout();
			break;
		}
		case Custom:	//Calcul le prix d'un type platCustom (downcasting) 		
			PlatCustom* platCustom = static_cast <PlatCustom*> (&plat);
			chiffre += (platCustom->getSupplement()) - plat.getCout();
			break;
		}
	}
	return chiffre;
}


//affichage

ostream& operator<<(ostream& os, const Table& table)
{
	os << "La table numero " << table.id_;
	if (table.estOccupee())
	{
		os << " est occupee. ";
		if (!table.commande_.empty())
		{
			os << "Le client principal est : " << (*table.clientPrincipal_) << " ";
			os << "Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < table.commande_.size(); ++i)
			{
				Plat plat = (*table.commande_[i]);
				switch (plat.getType())
				{
				case Regulier:	//Calcul le prix d'un type plat 
					os << "\t" << plat;
					break;
				case Bio:		//Calcul le prix d'un type platBio (downcasting)
				{
					PlatBio* platBio = static_cast <PlatBio*> (&plat);
					os << "\t" << *platBio;
					break;
				}
				case Custom:	//Calcul le prix d'un type platCustom (downcasting) 
				{
					PlatCustom* platCustom = static_cast <PlatCustom*> (&plat);
					os << "\t" << *platCustom;
					break;
				}
				default:
					break;
				}
			}
		}
		else
			os << "Mais ils n'ont rien commande pour l'instant. " << endl;
	}
	else
		os << " est vide. " << endl;
	return os;
}
