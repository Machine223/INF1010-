/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Restaurant.h
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les   fonctions déclarées dans Restaurant.cpp
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include "Table.h"

const int INTTABLES = 6;
class Restaurant {
public: 
	//constructeurs 
	Restaurant(); 
	Restaurant(string& fichier, string& nom,  TypeMenu moment); 
	//Destructor
	~Restaurant();
	//setters 
	void setMoment(TypeMenu moment); 

	//getters 
	string getNom(); 
	TypeMenu getMoment(); 

	//Autres methodes 
	void lireTable(string& fichier); //Elle a pour but de créer les tables, elle est appelée dans le constructeur par paramètres.
	void ajouterTable(int id, int nbPlaces); //utilisée dans la méthode lireTable().
	void libererTable(int id);  //en plus de libérer la table, elle devrait mettre à jour le chiffre
								//d’affaire du restaurant avec le chiffre généré par la table.
	void commanderPlat(string& nom, int idTable); //prenant en paramètre le nom d’un plat et l’id d’une table).
	void placerClients(int nbClients); //clients à placer), la méthode devra alors placer les clients de manière intelligente

	//affichage 
	void afficher() const;

private: 
	string* nom_; 

	double chiffreAffaire_; 
	TypeMenu momentJournee_; 

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_; 
	Menu* menuMidi_; 
	Menu* menuSoir_; 

	//liste des tables 
	unsigned int capaciteTables_;
	Table** tables_; 
	unsigned int nbTables_; 

};
#endif // !RESTAURANT_H
