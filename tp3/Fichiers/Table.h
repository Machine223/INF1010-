/*
* Titre : Table.h - Travail Pratique #3
* Date : 11 Fevrier 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
#include "PlatCustom.h"
#include "ClientPrestige.h"
#include <vector>


class Table {
public:
	//constructeurs
	Table();
	Table(int id, int nbPlaces);


	//getters
	int getId() const;
	int getNbPlaces() const;
	bool estOccupee() const;
	bool estPleine() const; 
	int getNbClientsATable() const; 
	vector<Plat*> getCommande() const;
	Client* getCliengtPrincipal() const; //Retourne le client principal
	double getChiffreAffaire() const; //Prend en compte le type de plat dans la commande dans le calcul du chiffre d’affaire
	

	//setters
	void libererTable(); 
	void placerClients(int nbClients);
	void setId(int id);
	void setClientPrincipal(Client* clientPrincipal); 
	
	//autres methodes
	void commander(Plat* plat);

	//affichage
	friend ostream& operator<<(ostream& os, const Table& table); //affiche les caractéristiques de la table

private :
	vector<Plat*> commande_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_; 
	///Nouvel attribut
	Client* clientPrincipal_;	// un pointeur sur la classe client qui représente le client principal de cette table.
								// C’est ce client qui passe les commandes et son statut sera pris en compte pour
								// appliquer les réductions.
	
};
#endif // !TABLE_H
