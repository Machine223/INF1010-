/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 11 F�vrier 2019
* Auteur : Fatou S. MOUNZEO
*/

#include "Restaurant.h"

//constructeurs 
Restaurant::Restaurant() {
	nom_ = new string("Inconnu"); 

	chiffreAffaire_ = 0; 
	
	momentJournee_ = Matin; 

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom); 

	chiffreAffaire_ = 0; 

	momentJournee_ = moment; 

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	lireTable(fichier); 
	lireAdresses(fichier);
}
Restaurant::Restaurant(const Restaurant & restau) : nom_(new string(*restau.nom_)),
	chiffreAffaire_(restau.chiffreAffaire_),momentJournee_(restau.momentJournee_),
	menuMatin_(new Menu(*restau.menuMatin_)),menuMidi_(new Menu(*restau.menuMidi_)),
	menuSoir_(new Menu(*restau.menuSoir_))
{
	tables_.clear();
	for (unsigned i = 0; i < restau.tables_.size(); ++i)
		tables_.push_back(new Table(*restau.tables_[i]));
	for (unsigned i = 0; i < NB_ZONES_LIVR; i++) 
		fraisTransport_[i] = restau.getFraisTransports(i);


}
//destructeur 
Restaurant::~Restaurant() {
	delete nom_; 
	delete menuMatin_; 
	delete menuMidi_; 
	delete menuSoir_; 
	for (unsigned i = 0; i < tables_.size(); ++i)
		delete tables_[i];

}


//setter 
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment; 
}
void Restaurant::setNom(const string & nom)
{
	nom_ = new string(nom);
}
//getters 
string Restaurant::getNom() const {
	return *nom_; 
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_; 
}

double Restaurant::getFraisTransports(int index) const
{
	return fraisTransport_[index];
}


//autres methodes 
//prend en compte les diff�rents avantages(r�duction) du client principal
void Restaurant::libererTable(int id) 
{
	for (unsigned i = 0; i < tables_.size(); ++i) {
		if (id == tables_[i]->getId()) {
			/*chiffreAffaire_ += tables_[i]->getChiffreAffaire(); 
			tables_[i]->libererTable(); */
			double chiffreAffaireTable = tables_[i]->getChiffreAffaire();

			// Ici, nous allons calculer le chiffre de la table moins les reduction que le client a droit.
			chiffreAffaire_ += chiffreAffaireTable - calculerReduction(tables_[i]->getCliengtPrincipal(),
			chiffreAffaireTable, tables_[i]->getCliengtPrincipal()->getStatut() == Prestige); 
			tables_[i]->libererTable(); //Fonction pour liberer la table te la commande de celle-ci
			break;
		}
	}
}


ostream& operator<<(ostream& os, const Restaurant& restaurant)
{
	os << "Le restaurant " << *restaurant.nom_;
	if (restaurant.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restaurant.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

	os << "-Voici les tables : " << endl;

	for (unsigned i = 0; i < restaurant.tables_.size(); i++) {
		os  << *restaurant.tables_[i] << endl;
	}
	os << endl;


	os << "-Voici son menu : " << endl;
	os << "Matin : " << endl
		<< *restaurant.menuMatin_<<endl << "Le plat le moins cher est : " << *restaurant.menuMatin_->trouverPlatMoinsCher()<< endl;
	os << "Midi : " << endl
		<< *restaurant.menuMidi_<<endl << "Le plat le moins cher est : " << *restaurant.menuMidi_->trouverPlatMoinsCher()<< endl;
	os << "Soir : " << endl
		<< *restaurant.menuSoir_<<endl << "Le plat le moins cher est : " << *restaurant.menuSoir_->trouverPlatMoinsCher()<< endl;

	return os;
}



void Restaurant::commanderPlat(const string& nom, int idTable,TypePlat type, int nbIngredients) 
{
	Plat* plat = nullptr; 
	int index; 
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i; 
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom); 
				break; 
			case Midi : 
				plat = menuMidi_->trouverPlat(nom); 
				break; 
			case Soir : 
				plat = menuSoir_->trouverPlat(nom); 
				break; 
			}

			break;
		}
	}

	if (plat == nullptr || !tables_[index]->estOccupee()) {

		cout << "Erreur : table vide ou plat introuvable" << endl << endl;
	}
	else if (type == Custom)
	{
		PlatCustom* platCustom = static_cast<PlatCustom*>(plat); // cast d'un plat regulier a un platCustom (downcasting)
		platCustom->setNbIngredients(nbIngredients); // definir le nombre d'ingredients dans le type plat Custom
		tables_[index]->commander(platCustom); 
	}
	else
	{
		tables_[index]->commander(plat);
	}
}



bool Restaurant::operator<(const Restaurant & restau) const 
{
	return this->chiffreAffaire_ < restau.chiffreAffaire_;
}

Restaurant & Restaurant::operator=(const Restaurant & restau)
{
	if (this != &restau)
	{
		chiffreAffaire_ = restau.chiffreAffaire_;
		momentJournee_ = restau.momentJournee_;
		menuMatin_ = new Menu(*restau.menuMatin_);
		menuMidi_ = new Menu(*restau.menuMidi_);
		menuSoir_ = new Menu(*restau.menuSoir_);
		for (unsigned i = 0; i < tables_.size(); ++i)
			delete tables_[i];

		tables_.clear();
		for (unsigned i = 0; i < restau.tables_.size(); ++i)
			tables_.push_back(new Table(*restau.tables_[i]));
		for (unsigned i = 0; i < NB_ZONES_LIVR; i++)
			fraisTransport_[i] = restau.getFraisTransports(i);
	}
	return *this;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in); 

	if (file) {
		string ligne; 
		
		string idString; 
		int id; 

		string nbPersonnesString; 
		int nbPersonnes; 

		int curseur; 
		while ( !file.eof()) {
			getline(file, ligne); 
			if (ligne == "-TABLES") {
					getline(file, ligne); 
				do {
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i; 
							break; 
						}
						idString += ligne[i]; 
					}

					id = stoi(idString); 

					nbPersonnesString = ligne.substr(curseur + 1); 
					nbPersonnes = stoi(nbPersonnesString); 

					*this+= new Table(id, nbPersonnes); 
					nbPersonnesString = ""; 
					idString = ""; 					
					getline(file, ligne);

				} while (ligne[0] != '-' && !file.eof());
			}
		}
		file.close(); 
	}
}

Restaurant& Restaurant::operator+=(Table* table) {
	tables_.push_back(new Table(*table)); 
	return *this;
}

void Restaurant::placerClients(Client* client) {

	/// TODO 
	///Modifier Afin qu'elle utilise un objet de la classe clients 
	///voir �nonc�
	int indexTable = -1;
	int minimum = 100;
		
	//Algorithme pour trouver la bonne table de maniere intelligente.
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= client->getTailleGroupe() && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum && i != INDEX_TABLE_LIVRAISON) {
			indexTable = i; //on enregistre le nouvel emplacement de la table.
			minimum = tables_[i]->getNbPlaces(); // on vien ajuster le minimun pour la table en fonction du nombre du groupe
		}
	}
	if (indexTable == -1) { //verification si nous n'avons pas trouver de table ad�quat pour le nombre de client. 
		cout << "Erreur : il n'y a plus/pas de table disponible pour les clients. " << endl;
	}
	else //sinon on place le client a la bonne table.
	{
		tables_[indexTable]->placerClients(client->getTailleGroupe()); 
		tables_[indexTable]->setClientPrincipal(client); //definir le client principal
	}
}

void Restaurant::livrerClient(Client * client, vector<string> listeDePlats)
{
	///TODO
	///se r�ferer � l'�nonc� 
	///v�rifier que le client a droit aux livraisons
	///Si oui lui assigner la table des livraisons 
	///Effectuer la commande
	if (client->getStatut() == Prestige) { //V�rifier que le client a droit aux livraisons
		cout << "Livraison en cours ..." << endl;
		tables_[INDEX_TABLE_LIVRAISON]->placerClients(1); //On place 1 client a l�indice INDEX_TABLE_LIVRAISON du tableau tables_.
		tables_[INDEX_TABLE_LIVRAISON]->setClientPrincipal(client); //On vient mettre le Client Principal de cette table de livraison.
		for (unsigned i = 0; i < listeDePlats.size(); i++)
			commanderPlat(listeDePlats[i], tables_[INDEX_TABLE_LIVRAISON]->getId()); //Effectuer la commande

		cout << "Statut de la table de livraison: (table numero "
			<< tables_[INDEX_TABLE_LIVRAISON]->getId() << "):"
			<< endl << *tables_[INDEX_TABLE_LIVRAISON] << "Livraison terminee" << endl;
		tables_[INDEX_TABLE_LIVRAISON]->libererTable();
	}
	else {
		cout << "Le client " << client->getNom() << " n'est pas admissible a la livraison"
			<< endl << endl;
	}
}

double Restaurant::calculerReduction(Client* client, double montant, bool livraison) {
	if (client->getStatut() == Regulier) {
		ClientRegulier* clientReg = static_cast<ClientRegulier*>(client);
		if (clientReg->getNbPoints() > SEUIL_DEBUT_REDUCTION)
			return montant * TAUX_REDUC_REGULIER;
	}

	if (client->getStatut() == Prestige) {
		ClientPrestige* clientPrest = static_cast<ClientPrestige*>(client);
		if (clientPrest->getNbPoints() < SEUIL_LIVRAISON_GRATUITE && livraison == true)
			return montant * TAUX_REDUC_PRESTIGE + getFraisTransports(clientPrest->getAddresseCode());
		else
			return montant * TAUX_REDUC_PRESTIGE;
	}
	return 0;
}

void Restaurant::lireAdresses(const string & fichier)
{
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string addresseCodeStr;
		int addressCode;

		string fraisStrg;
		double frais;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-ADDRESSES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						addresseCodeStr += ligne[i];
						addressCode = stoi(addresseCodeStr);

					}

					fraisStrg = ligne.substr(curseur + 1);
					frais = stod(fraisStrg);
					fraisTransport_[addressCode] = frais;

					addresseCodeStr = "";
					fraisStrg = "";

				}
					
			}
		}
		file.close();
	}
}


