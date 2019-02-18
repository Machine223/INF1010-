/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    menu.h
Thème: La surcharge d’opérateurs, les vecteurs et l’utilisation du pointeur this
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les déclarations des fonctions implémenté dans menu.cpp
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>
#include <vector>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	Menu(); //Constructeur par defaut
	Menu(string fichier, TypeMenu type); //Constructeur par parametre
	Menu(const Menu& table); //Constructeur par copie

	//destructeur
	~Menu();

	//getters
	vector<Plat*> getListePlats() const;

	//affichage
	friend ostream& operator<<(ostream& flux, const Menu& menu); // L’opérateur affiche les Menus

	//methodes en plus
	Plat* trouverPlat(const string& nom) const; // Touver un plat son le nom
	Plat* trouverPlatMoinsCher() const; // trouver le plat le mons cher
	Menu& operator+= (Plat& plat); //L’opérateur ajoute un plat a la liste de plat dans le menu
	bool lireMenu(const string& fichier);
	Menu& operator=(const Menu& menuSource);//qui écrase les attributs du menu par les attributs du 
	//menu passé en paramètre et qui renvoie ensuite une référence au menu

private :
	vector<Plat*> listePlats_; // Un vecteur de pointeur vers des plats
	TypeMenu type_;

};

#endif // !MENU_H
