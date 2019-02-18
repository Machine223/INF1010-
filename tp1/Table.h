/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Table.h
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 F�vrier 2019
Ce code contient les d�claration des fonctions impl�ment� dans Table.cpp
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
	void libererTable();  //efface la commande et lib�re la table.
	void placerClient(); 
	void setId(int id); 

	//autres methodes 
	void commander(Plat* plat); //prenant en param�tre un plat qui sera plac� dans la commande.
	double getChiffreAffaire() const; //retourne le chiffre d�affaire g�n�r� par la table pour le restaurant

	//affichage
	void afficher() const;

private : 
	Plat** commande_; //tableau dynamique contenant des pointeurs vers des plats command�s.
	unsigned int capacite_; //qui repr�sente la taille du tableau commande_
	unsigned int nbPlats_; 

	int id_; 
	unsigned int nbPlaces_; 
	bool occupee_; //la valeur true indique que la table est occup�e
};
#endif // !TABLE_H
