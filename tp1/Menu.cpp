/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Menu.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les implémentations des fonctions définies dans Menu.h
*/


#include "Menu.h"

Menu::Menu()
{
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type)
{
	lireMenu(fichier);
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = type;	
	
}

Menu::~Menu()
{
	for (int i = 0; i < nbPlats_; i++) // Supression des objets Plat
	{
		delete listePlats_[i];
	}
	delete[] listePlats_; // Supression du tableau
}

int Menu::getNbPlats()
{
	return nbPlats_;
}

void Menu::afficher()
{
	cout << "-" << type_ <<": "<< endl;
	for (int i=0; i < nbPlats_; i++)
		listePlats_[i]->afficher();
}

Plat * Menu::trouverPlat(string & nom)
{
	for (int i = 0; i < nbPlats_; i++)
	{
		if (nom == listePlats_[i]->getNom())
			return listePlats_[i];
	}
	return nullptr;
}

void Menu::ajouterPlat(Plat & plat)
{
	if (nbPlats_ >= capacite_)
	{
		capacite_ = MAXPLAT * 2;
		Plat** listePlats2 = new Plat*[capacite_]; //ici on double seulement de deux pour un max de 10 plats
		for (int i = 0; i < nbPlats_; i++)
		{
			listePlats2[i] = listePlats_[i];
		}
		delete[] listePlats2;
		listePlats_ = listePlats2;
	}
	listePlats_[nbPlats_] = &plat;
	nbPlats_++;
}

void Menu::ajouterPlat(string & nom, double montant, double cout)
{
	Plat* plat = new Plat(nom, montant, cout); //on fait appel du constructeur plat et on l'attribue un pointeur
	ajouterPlat(*plat); //on ajout le pointeur plat a l'aide de la fonction
	nbPlats_++; // incrémentant le nombre de plat dans le tableau
}

bool Menu::lireMenu(string & fichier)
{
	ifstream entree(fichier, ios::in); //Lecture seulement de fichier texte

	string mot ="";
	TypeMenu type;
	double prix = 0;
	double cout = 0;
	char trait = '-';
	int nb = 1;

	if (entree)
	{
		do {
			getline(entree, mot);
			if (mot[0] == trait)
			{ 
				if (mot == "-MATIN")
					type = Matin;
				if (mot == "-MIDI")
					type = Midi;
				if (mot == "-SOIR")
					type = Soir;
			}
			if (type_ == type) //vérifier qu'on est dans le bon menu
				for (int i=0 ; i< nb ; i++)
				{
					entree >> mot;
					if (mot[0] != trait)
					{
						nb--; // cette ligne sert pour sortir de la boucle
					}
					else
					{
						entree >> prix >> cout;
						ajouterPlat(mot, prix, cout);
						nb++;
					}
				}
		} while (!ws(entree).eof()); //sortir a la fin du fcihier
	entree.close();
	}
	else  // sinon
	{
		cerr << "Erreur à l'ouverture !" << endl;  //std::cerr for Error output (console error)
		return false;
	}
	return true;
}
