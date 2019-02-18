/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Table.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les   fonctions déclarées dans Table.h
*/

#include "Table.h"

Table::Table()
{
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	nbPlaces_ = 0;
	occupee_ = false;
	commande_ = new Plat*[capacite_];
}

Table::Table(int id, int nbPlaces)
{
	capacite_ = MAXCAP;
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbPlaces_ = 0;
	occupee_ = false;
	commande_ = new Plat*[capacite_];
}
Table::~Table() // Destructeur
{
	delete[] commande_; // les plats vont etre detruits par la classe Menu.
}
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
	return occupee_;
}

void Table::libererTable()
{
	getChiffreAffaire();
	
	for (int i = 0; i < nbPlats_; i++)
		commande_[i] = 0;
	occupee_ = false;
	nbPlats_ = 0;
}

void Table::placerClient()
{
	occupee_ = true;
}

void Table::setId(int id)
{
	id_ = id;
}

void Table::commander(Plat * plat)
{
	if (nbPlaces_ >= capacite_)
	{
		capacite_ *= 2;
		Plat** commande = new Plat*[capacite_]; //ici on double seulement de deux pour un max de 10 commande de plats
		for (int i = 0; i < nbPlats_; i++)
		{
			commande_[i] = commande[i];
		}
		delete[] commande; // Supression de l'ancien tableau
		
	}
	commande_[nbPlats_] = plat;
	nbPlats_++;
}

double Table::getChiffreAffaire() const
{
	
	double chiffre = 0;
	for (int i = 0; i < nbPlats_; i++)
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	return chiffre;
}

void Table::afficher() const
{
	std::cout << "La table numero " << id_ << " est";
	if (occupee_) // table occupée
	{
		std::cout << " occupee. ";
		if (nbPlats_ > 0) //  ils ont déja commandé
		{
			std::cout << " Voici la commande passee par les clients : " << std::endl;
			for (int i = 0; i < nbPlats_; i++)
				commande_[i]->afficher();
			std::cout << std::endl;
		}
		else //  ils n'ont pas encore commandé
			std::cout << " Mais ils n'ont rien commande pour l'instant." << std::endl << std::endl;

	}
	else // libre
		std::cout << " libre" << std::endl;
	
}
