/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    restaurant.h
Thème: La surcharge d’opérateurs, les vecteurs et l’utilisation du pointeur this
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les déclarations des fonctions implémenté dans restaurant.cpp
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Menu.h"
const int INTTABLES = 6;
class Restaurant {
public:
	//constructeurs
	Restaurant(); //Constructeur par defaut
	Restaurant(const string& fichier, const string& nom, TypeMenu moment); //Constructeur par parametre
	Restaurant(const Restaurant& restaurant); //Constructeur par copie


	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(const string& nom);

	//getters
	string getNom() const;
	TypeMenu getMoment() const;

	//Autres methodes
	void lireTable(const string& fichier);
	void libererTable(int id);
	friend ostream& operator<<(ostream& flux, const Restaurant& restaurant); // affiche caractéristiques restaurant.
	void commanderPlat(const string& nom, int idTable);

	void placerClients(int nbClients); //Permet de placer un client a une table de maniere a optimiser l'espace
	Restaurant& operator+=(Table&  table); //permettant d’ajouter une table au restaurant
	Restaurant& operator=(const Restaurant& restaurant); //écrase les attributs du restaurant par les attributs du restaurant passé en paramètre
	bool operator<(const Restaurant& restaurant) const; //compare le chiffre d’affaires de deux restaurants


private:
	string* nom_;
	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables
	vector<Table*> tables_; // Un vecteur de pointeur vers des tables
};
#endif // !RESTAURANT_H
