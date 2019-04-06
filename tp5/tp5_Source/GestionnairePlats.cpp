/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"



void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}

//Méthode qui permet d’afficher les plats du conteneur.
void GestionnairePlats::afficherPlats(ostream & os)
{
	for (auto it : conteneur_) {
		it.second->afficherPlat(os);
	}
}

GestionnairePlats::GestionnairePlats(const string & nomFichier, TypeMenu type)
	:type_{ TypeMenu::Matin }
{
	lirePlats(nomFichier, type_);
}

// deep copie de gestionnaire plat
GestionnairePlats::GestionnairePlats(GestionnairePlats * gestionnaire) : type_(gestionnaire->type_) {
	//faire la copie de gestion a nouveau gestionnaire
	// verifier que gestion != gestion
	if (this != gestionnaire) {
		for (auto it: gestionnaire->conteneur_) {
			// pour chaque creer une paire<string,plat*> cloner plat et  faire ajouter
			this->conteneur_.insert(make_pair(it.first, it.second->clone()));
		}
	}
}

GestionnairePlats::~GestionnairePlats()
{
	// iterrer dans le conteneur
	for (auto it : conteneur_) {
		// ici on veut supprime l'objet du pointeur plat
		delete it.second; // ici on supprime a la position it le secont qui est le plat on le supprime
	}
	conteneur_.clear();
}

TypeMenu GestionnairePlats::getType() const
{
	return type_;
}

Plat * GestionnairePlats::allouerPlat(Plat * plat)
{
	// pour faire une deep copie on fait un clone
	Plat* allouerPlat = plat->clone();

	return allouerPlat;
}

//En utilisant un algorithme de la STL et le foncteur FoncteurPlatMoinsCher, vous
//devez retourner le plat le moins cher du conteneur.
Plat * GestionnairePlats::trouverPlatMoinsCher() const
{
	FoncteurPlatMoinsCher fonction();
	// ceci nous renvoie le pointeur it sur l'element le plus petit
	auto it = min_element(conteneur_.begin(), conteneur_.end(),fonction); 
	
	// ou on pourrais aussi faire :
	//Plat* plat = min_element(conteneur_.begin(), conteneur_.end(), fonction)->second;
	//return plat;
	
	return it->second;
}

//En utilisant une fonction lambda et un
//algorithme de la STL, vous devez trouver le plat le plus cher du conteneur
Plat * GestionnairePlats::trouverPlatPlusCher() const
{
	auto lambda = [&](pair<string, Plat*> a, pair<string, Plat*> b)->bool{
		return (a.second->getPrix() > b.second->getPrix());
	};

	auto it = max_element(conteneur_.begin(), conteneur_.end(), lambda); // ici pas besoin de mettre "()" puisque l'algo va utiliser cette fonction
	return it->second;
}

//Retourne le plat du conteneur qui porte le nom spécifié
Plat * GestionnairePlats::trouverPlat(const string & nom) const
{
	auto recherche = [&](pair<string, Plat*> a, const string & nom)->bool {
		return (a.second->getNom() == nom);
	};

	auto it = find_if(conteneur_.begin(), conteneur_.end(), recherche);

	return it->second;
}

// En utilisant le FoncteurIntervalle, retournez les plats dont les prix sont compris entre
// la borneInf et la borneSup.
vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup)
{
	FoncteurIntervalle fonction(borneInf,borneSup);
	vector<pair<string, Plat*>> Intervalle;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(Intervalle), fonction);

	return Intervalle;
}
