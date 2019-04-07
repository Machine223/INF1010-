/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

//retourne la table dans le conteneur qui porte le id spécifié
Table * GestionnaireTables::getTable(int id) const
{
	auto recherche = [&](Table* a)->bool {
		return (a->getId() == id);
	};

	set<Table*>::iterator it = find_if(conteneur_.begin(), conteneur_.end(), recherche);
	
	return *it;
}

//retourne la plus petite table pouvant contenir le groupe
Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const
{
	Table* meilleurTable = nullptr;
	int nbPlace = 100; //nombre choisi qui sera le max possible
	for (auto i : conteneur_) {
		if (tailleGroupe <= i->getNbPlaces() && !i->estOccupee() && nbPlace >= i->getNbPlaces()) {
			meilleurTable = i;
			nbPlace = i->getNbPlaces();
		}
	}
	return meilleurTable;
}

void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}
//affiche les tables en utilisant des itérateurs.
void GestionnaireTables::afficherTables(ostream & os) const
{
	for (auto it : conteneur_)
		os << it;
}

