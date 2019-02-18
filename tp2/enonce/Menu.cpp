/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    menu.cpp
Thème: La surcharge d’opérateurs, les vecteurs et l’utilisation du pointeur this
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les fonctions déclarées dans menu.cpp
*/

#include "Menu.h"

//constructeurs

Menu::Menu() {
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;
	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

Menu::Menu(const Menu & menu)
{
	listePlats_ = menu.listePlats_;
	type_ = menu.type_;
	for (int i = 0; i < listePlats_.size(); i++)
	{
		listePlats_[i] = new Plat(*menu.listePlats_[i]);
	}
}

//destructeur
Menu::~Menu() {
	for (int i = 0; i < listePlats_.size(); i++)
		delete listePlats_[i];
	listePlats_.clear();
}

//getters
vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;;
}

//autres methodes



bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	string type;
	switch (type_) {
	case Matin:
		type = "-MATIN";
		break;
	case Midi:
		type = "-MIDI";
		break;
	case Soir:
		type = "-SOIR";
		break;
	}
	string ligne;

	string nom;

	string prixString;
	double prix;

	string coutString;
	int cout;


	// lecture
	while (!file.eof()) {
		getline(file, ligne);
		//trouver le bon type de menu (section)
		if (ligne == type) {
			//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
			getline(file, ligne);
			int curseur;
			while (ligne[0] != '-' && !file.eof()) {
				//trouver le nom
				for (int i = 0; i < int(ligne.size()); i++) {
					if (ligne[i] == ' ') {
						curseur = i;
						break;
					}
					nom += ligne[i];
				}
				//trouver le prix

				for (int i = curseur + 1; i < int(ligne.size()); i++) {
					if (ligne[i] == ' ') {
						curseur = i;
						break;
					}
					prixString += ligne[i];

				}
				//passer le prixString en double --- indice dans l'enonce
				prix = stof(prixString.c_str());

				for (int i = curseur + 1; i < int(ligne.size()); i++) {
					if (ligne[i] == ' ')
						break;
					coutString += ligne[i];
				}

				cout = int(stof(coutString.c_str()));
				Plat* plat = new Plat(nom, prix, cout);
				*this += *plat;
				nom = "";
				prixString = "";
				coutString = "";

				getline(file, ligne);
			}
		}
	}

	file.close();
	return true;
}

//qui écrase les attributs du menu par les attributs du menu passé en paramètre et qui 
//renvoie ensuite une référence au menu
Menu & Menu::operator=(const Menu & menuSource)
{
	if (this != &menuSource) {
		listePlats_ = menuSource.listePlats_;
		type_ = menuSource.type_;
		for (int i = 0; i < listePlats_.size(); i++)
			listePlats_[i] = new Plat(*listePlats_[i]);
	}
	return *this;
}

Plat* Menu::trouverPlatMoinsCher() const
{
	Plat minimum(*listePlats_[0]);
	int found = 0; //ici c'est -1 mais cest faux ca donne un probleme si la 1er variable est la plus petite

	for (unsigned i = 0; i < listePlats_.size(); ++i)
	{
		if (*listePlats_[i] < minimum) // avec l'operateur < nous pouvons comparer deux plats
		{
			minimum = *listePlats_[i];
			found = i;
		}
	}
	return listePlats_[found];
}

Menu & Menu::operator+=(Plat & plat)
{
	listePlats_.push_back(&plat);
	return *this;
}

Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i < listePlats_.size(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}

ostream & operator<<(ostream & flux, const Menu & menu)
{
	for (int i = 0; i < menu.listePlats_.size(); i++) {
		flux << "\t";
		flux << (*(menu.listePlats_[i]));
	}
	return flux;
}

//void operator+=(Menu & menu, Plat & plat)
//{
//	menu.listePlats_.push_back(&plat);
//}
