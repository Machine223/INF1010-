/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les fonctions déclarées dans Table.h
*/

#include "Table.h"

//constructeurs
Table::Table() {
	
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	
	
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//destructeur
Table::~Table() {
	
	commande_.clear();
	
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	//A MODIFIER avec pointeur pop_back
	for (int i = 0; i < commande_.size(); i++) {
		commande_.pop_back();
	}
	
	// une autre commande pour tout enlever  lexterieur de la boucle commande_.clear();
	
}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat* plat) {
	
	commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < commande_.size(); i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

//affichage
ostream & operator<<(ostream & flux, const Table & table)
{
	flux << "La table numero " << table.id_;
	if (table.estOccupee()) {
		flux << " est occupee. ";
		if ((table.commande_.size()) != 0) {
			flux << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < table.commande_.size(); i++) {
				flux << "\t";
				flux << (*(table.commande_[i]));
			}
		}
		else
			flux << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
	}
	else {
		flux << " est libre. " << endl;
	}
	return flux;
}

