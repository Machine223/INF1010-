/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 11 Fevrier 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "ClientPrestige.h"

const int NB_ZONES_LIVR = 3;
const int INDEX_TABLE_LIVRAISON = 4;


class Restaurant {
public:
	//constructeurs
	Restaurant();  //Constructeur par defaut
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment); //Constructeur par parametre
	Restaurant(const Restaurant& restau);  //Constructeur par copie

	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(const string& nom); 

	//getters
	string getNom() const;
	TypeMenu getMoment() const;
	double getFraisTransports(int index) const;

	//Autres methodes
	void lireTable(const string& fichier);
	void lireAdresses(const string& fichier);

	Restaurant& operator+=(Table* table); 
	void libererTable(int id); // Prend en compte les différents avantages(réduction) du client principal et ajuste le chiffre d'affaire
	void commanderPlat(const string& nom, int idTable, TypePlat type= Regulier,int nbIngredients = 0); //Commande le plat et qui s’adapte à l’existence des plat customisés
	bool operator < (const Restaurant& restau) const ;
	Restaurant& operator = (const Restaurant& restau); 
	void placerClients(Client* client);//Place un client et qui s’adapte à la nouvelle structure du client ( Indice : la taille du groupe).
	
	void livrerClient(Client * client, vector<string> listeDePlats);
	double calculerReduction(Client* client, double montant, bool livraison); //Applique le type de reduction au trype de client.
	friend ostream& operator<<(ostream& os, const Restaurant& restau); //affiche les caractéristiques du restaurant.

private:
	string* nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables
	vector<Table*> tables_;

	//Tarif des trois zones de livraison nouvel attribut
	double fraisTransport_[NB_ZONES_LIVR]; //contient le montant des différents frais de livraison pour les trois zones
	//Sa lecture a déjà été effectué par la méthode lireAdresses()

};
#endif // !RESTAURANT_H
