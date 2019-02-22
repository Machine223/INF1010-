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
	Menu& operator+=(const Plat& plat); //qui prend en param�tre un objet de la classe Plat
	Menu& operator+=(const PlatBio& plat); //qui prend en param�tre un objet de la classe PlatBio
	Menu& operator=(const Menu& menu); // Operateur qui �crase les attributs du menu par les attributs du menu pass� en param�tre
	// et qui renvoie ensuite une r�f�rence au menu.
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const;

	//Affichage
	friend ostream& operator<<(ostream& os, const Menu& menu); //affiche les caract�ristiques du menu
	
private : 
	vector<Plat*> listePlats_; //contenir des objets Plat ou PlatBio en fonction du fichier polyfood.txt.
	TypeMenu type_; //Type de menu (Matin,Midi ou Soir)
};

#endif // !MENU_H
