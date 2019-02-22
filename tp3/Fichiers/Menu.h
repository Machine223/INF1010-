/*
* Titre : Menu.h - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef MENU_H
#define MENU_H 

#include <fstream>
#include <vector>
#include"PlatBio.h"
#include"PlatCustom.h"

enum TypeMenu{Matin, Midi, Soir};

class Menu {
public: 
	// constructeurs
	Menu(); 
	Menu(string fichier, TypeMenu type);
	Menu(const Menu& menu); //Un constructeur par copie


	//getters
	vector<Plat*> getListePlats() const; 
	
	//methodes en plus
	Plat* trouverPlat(const string& nom) const; 
	Menu& operator+=(const Plat& plat); 
	///TODO
	Menu& operator+=(const PlatBio& plat); 
	///TO
	Menu& operator=(const Menu& menu); ///A MODIFIER
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const;
	///TODO 
	friend ostream& operator<<(ostream& os, const Menu& menu); //affiche les caract�ristiques du menu
	
private : 
	vector<Plat*> listePlats_; //contenir des objets Plat ou PlatBio en fonction du fichier polyfood.txt.
	TypeMenu type_; //Type de menu (Matin,Midi ou Soir)
};

#endif // !MENU_H
