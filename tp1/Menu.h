/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Menu.h
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 F�vrier 2019
Ce code contient les d�claration des fonctions impl�ment� dans Menu.cpp
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
	Plat* trouverPlat(string& nom); //Une m�thode permettant de trouver un plat en passant le nom du plat, sinon pointeur nullptr.
	//Deux m�thodes d�ajout de plat : une utilisant un plat, et l�autre le nom, le prix et le cout du plat.
	void ajouterPlat(Plat& plat); 
	void ajouterPlat(string& nom, double montant, double cout); 
	bool lireMenu(string& fichier); //cette m�thode permet de remplir le menu.
	
private : 
	unsigned int capacite_; //qui repr�sente la taille du tableau listePlats _
	Plat** listePlats_;		//tableau dynamique contenant des pointeurs vers des plats.
	unsigned int nbPlats_; 
	TypeMenu type_;			//le type de menu issu de l��num�ration TypeMenu

};

#endif // !MENU_H
