/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    Restaurant.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 04 Février 2019
Ce code contient les fonctions déclarées dans Restaurant.h
*/
#include "Restaurant.h"

Restaurant::Restaurant()
{
	string inconnue = "inconnue";
	nom_ = &inconnue;
	momentJournee_ = Matin;
	chiffreAffaire_ = 0;
	menuMatin_ = nullptr;
	menuMidi_ = nullptr;
	menuSoir_ = nullptr;
	capaciteTables_ = INTTABLES;
	tables_ = nullptr;
	nbTables_ = 0;
}

Restaurant::Restaurant(string & fichier, string & nom, TypeMenu moment)
{
	lireTable(fichier);
	nom_ = &nom;
	momentJournee_ = Matin;
	chiffreAffaire_ = 0;
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	capaciteTables_ = INTTABLES;
	tables_ = nullptr;
	nbTables_ = 0;
	momentJournee_ = moment;
	lireTable(fichier);
	
}

Restaurant::~Restaurant()
{
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	for (unsigned int i = 0; i < nbTables_; i++)
	{
		delete tables_[i]; // le restaurant et ses tables sont en composition, si on delete le restaurant, il faut delete les tables aussi
	}
	delete[] tables_;
}

void Restaurant::setMoment(TypeMenu moment)
{
	momentJournee_ = moment;
}

string Restaurant::getNom()
{
	return *nom_;
}

TypeMenu Restaurant::getMoment()
{
	return momentJournee_;
}

void Restaurant::lireTable(string & fichier)
{
	ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture

	tables_ = new Table*[capaciteTables_]; // table vrs des pointeurs des tables
	string ligne = ""; // contient la ligne de debut de chaque partie
	int id = 0; // id de la table
	int  nbPlaces = 0; // nombre de place par table
	if (file)  // si l'ouverture a réussi
	{
		while (!ws(file).eof())
		{
			getline(file, ligne);
			if (ligne == "-TABLES") // on est dans la bonne partie
			{
				while (!ws(file).eof())
				{
					file >> id >> nbPlaces; // reccuerons les données
					ajouterTable(id, nbPlaces); // ajoutons la table a la liste des tables
				}
			}
		}
		file.close();  // on ferme le fichier
	}
}

void Restaurant::ajouterTable(int id, int nbPlaces)
{
	Table table(id, nbPlaces);
	if (nbTables_ >= capaciteTables_)
	{
		Table** tables = tables_;
		capaciteTables_ *= 2;
		tables_ = new Table*[capaciteTables_];
		for (int i = 0; i < nbTables_; i++)
			tables_[i] = tables[i];
		delete[] tables;
	}
	tables_[nbTables_] = &table;
	nbTables_++;
}

void Restaurant::libererTable(int id)
{
	for (int i = 0; i < nbTables_; i++)
	{
		if (tables_[i]->getId() == id)
		{
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
			nbTables_--;
		}
	}
}

void Restaurant::commanderPlat(string & nom, int idTable)
{
	Plat* plat = nullptr;  // initialisation du pointeur du plat.
	switch (momentJournee_) //Dépendant le moment de la journée, le switch aide à se situé le plat dans les Menus.
	{
	case Matin: plat = menuMatin_->trouverPlat(nom); //retourne un pointeur si le plat est trouver
		break;
	case Midi: plat = menuMidi_->trouverPlat(nom);	//retourne un pointeur si le plat est trouver
		break;
	case Soir: plat = menuSoir_->trouverPlat(nom);	//retourne un pointeur si le plat est trouver
		break;
	default: break;
	}
	//ici, puisque nous avons trouver le plat qui est dans le menu, nous allons le commander
	if(plat != nullptr)
		for (int i = 0; i < nbTables_; i++)
		{
			if (tables_[i]->getId() == idTable)
			{
				if (tables_[i]->estOccupee()) // si elle est occupée
					tables_[i]->commander(plat);
				else // elle n 'est pas occupée , les clients sont partis !
					cout << "Erreur: table non occupee" << std::endl;
			}
		}
	else
	{
		cout << "Erreur : Table non occupee ou plat introuvable." << endl;
	}
}

void Restaurant::placerClients(int nbClients)
{
	int minPlace = 1000;
	Table* table = nullptr;
	for (int i = 0; i < nbTables_; i++)
	{
		if (nbClients <= tables_[i]->getNbPlaces() && tables_[i]->estOccupee() == false)
		{
			if (minPlace > tables_[i]->getNbPlaces())
			{
				minPlace = tables_[i]->getNbPlaces();
				table = tables_[i];
			}
		}
	}
	if (table != nullptr)
		table->placerClient();
	else
		cout << "Erreur : Il n'y a plus de table disponible pour le client." << endl;
}

void Restaurant::afficher() const // Affichage de la restaurant
{
	std::cout << "Le restaurant " << *nom_; // Nom du restaurant
	if (chiffreAffaire_ == 0) // pas de chiffre d'affaire
		std::cout << " n'a pas fait de benifice ou le chiffre d'affaire n'est pas encore calcule. " << std::endl << std::endl;
	else // on a fait un chiffre d'affaire $-$
		std::cout << " a  fait un chiffre  d'affaire de : " << chiffreAffaire_ << "$" << std::endl << std::endl;
	std::cout << "-Voici les tables:" << std::endl; // Affichage des tables
	for (int i = 0; i < nbTables_; i++)
	{
		std::cout << "	";
		tables_[i]->afficher(); // appelons la methose afficher()
	}
	// Affichage des menus
	std::cout << std::endl;
	std::cout << "Voici son menu:" << std::endl;
	menuMatin_->afficher();
	std::cout << std::endl;
	menuMidi_->afficher();
	std::cout << std::endl;
	menuSoir_->afficher();
	std::cout << std::endl;
}
