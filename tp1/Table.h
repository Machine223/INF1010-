/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Table.h
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les déclaration des fonctions implémenté dans Table.cpp
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;
class Table {
public: 
	//constructeurs 
	Table(); 
	Table(int id, int nbPlaces);
	//Destructeur
	~Table();

	//getters 
	int getId() const;
	int getNbPlaces() const;
	bool estOccupee() const;

	//setters 
	void libererTable();  //efface la commande et libère la table.
	void placerClient(); 
	void setId(int id); 

	//autres methodes 
	void commander(Plat* plat); //prenant en paramètre un plat qui sera placé dans la commande.
	double getChiffreAffaire() const; //retourne le chiffre d’affaire généré par la table pour le restaurant

	//affichage
	void afficher() const;

private : 
	Plat** commande_; //tableau dynamique contenant des pointeurs vers des plats commandés.
	unsigned int capacite_; //qui représente la taille du tableau commande_
	unsigned int nbPlats_; 

	int id_; 
	unsigned int nbPlaces_; 
	bool occupee_; //la valeur true indique que la table est occupée
};
#endif // !TABLE_H
