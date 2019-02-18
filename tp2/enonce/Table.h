/*
INF1010 � PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 2
file:    main.cpp
Th�me: Allocation dynamique, composition et agr�gation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 F�vrier 2019
Ce code contient les d�clarations des fonctions impl�ment� dans Table.cpp
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include <vector>

const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);

	///destructeur
	~Table();

	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const; 
	bool estOccupee() const; //quand false la table est occuppee

	///setters
	void libererTable(); //r�tablit le nombre de places init. de la table, et met le nombre de clients � 0.
	void placerClient(int nbClients); //met � jour la valeur de nbClientsATable_ et de nbPlaces_
	void setId(int id);

	///autres methodes
	void commander(Plat* plat); //un vecteur de pointeurs � des plats command�s
	double getChiffreAffaire() const;

	///methodes en plus affichage
	friend ostream& operator<< (ostream& flux, const Table& table);
	//L�op�rateur << (remplace la m�thode d�affichage), qui affiche les caract�ristiques du plat.

private :
	vector<Plat*> commande_; //un vecteur de pointeurs � des plats command�s - liste de plats (la commande de la table)
	int id_;
	int nbPlaces_; //se met � jour en fonction du nombre de clients qui s�assoit � la table
	int nbClientsATable_; //un entier qui repr�sente le nombre de clients assis � la table
};
#endif // !TABLE_H
