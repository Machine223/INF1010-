/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Menu.h
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les déclaration des fonctions implémenté dans Menu.cpp
*/

#ifndef MENU_H
#define MENU_H 

#include "Plat.h"
#include <fstream>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;

class Menu {
public: 
	// constructeurs
	Menu(); 
	Menu(string fichier, TypeMenu type); 
	~Menu();

	//getters
	int getNbPlats(); 
	
	//affichage 
	void afficher(); 

	//methodes en plus
	Plat* trouverPlat(string& nom); //Une méthode permettant de trouver un plat en passant le nom du plat, sinon pointeur nullptr.
	//Deux méthodes d’ajout de plat : une utilisant un plat, et l’autre le nom, le prix et le cout du plat.
	void ajouterPlat(Plat& plat); 
	void ajouterPlat(string& nom, double montant, double cout); 
	bool lireMenu(string& fichier); //cette méthode permet de remplir le menu.
	
private : 
	unsigned int capacite_; //qui représente la taille du tableau listePlats _
	Plat** listePlats_;		//tableau dynamique contenant des pointeurs vers des plats.
	unsigned int nbPlats_; 
	TypeMenu type_;			//le type de menu issu de l’énumération TypeMenu

};

#endif // !MENU_H
