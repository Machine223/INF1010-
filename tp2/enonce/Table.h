/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les déclarations des fonctions implémenté dans Table.cpp
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include <vector>

const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);

	///destructeur
	~Table();

	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const; 
	bool estOccupee() const; //quand false la table est occuppee

	///setters
	void libererTable(); //rétablit le nombre de places init. de la table, et met le nombre de clients à 0.
	void placerClient(int nbClients); //met à jour la valeur de nbClientsATable_ et de nbPlaces_
	void setId(int id);

	///autres methodes
	void commander(Plat* plat); //un vecteur de pointeurs à des plats commandés
	double getChiffreAffaire() const;

	///methodes en plus affichage
	friend ostream& operator<< (ostream& flux, const Table& table);
	//L’opérateur << (remplace la méthode d’affichage), qui affiche les caractéristiques du plat.

private :
	vector<Plat*> commande_; //un vecteur de pointeurs à des plats commandés - liste de plats (la commande de la table)
	int id_;
	int nbPlaces_; //se met à jour en fonction du nombre de clients qui s’assoit à la table
	int nbClientsATable_; //un entier qui représente le nombre de clients assis à la table
};
#endif // !TABLE_H
