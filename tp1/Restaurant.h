/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Restaurant.h
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 F�vrier 2019
Ce code contient les   fonctions d�clar�es dans Restaurant.cpp
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
	void lireTable(string& fichier); //Elle a pour but de cr�er les tables, elle est appel�e dans le constructeur par param�tres.
	void ajouterTable(int id, int nbPlaces); //utilis�e dans la m�thode lireTable().
	void libererTable(int id);  //en plus de lib�rer la table, elle devrait mettre � jour le chiffre
								//d�affaire du restaurant avec le chiffre g�n�r� par la table.
	void commanderPlat(string& nom, int idTable); //prenant en param�tre le nom d�un plat et l�id d�une table).
	void placerClients(int nbClients); //clients � placer), la m�thode devra alors placer les clients de mani�re intelligente

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
