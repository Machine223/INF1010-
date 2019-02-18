/*
INF1010 – PROGRAMMATION ORIENTEE OBJET
Travail pratique No. 1
file:    main.cpp
Thème: Allocation dynamique, composition et agrégation
Auteur: ABDELKADER ZOBIRI 1891451 - Abderrahim Ammour 1924705
Date: 11 Février 2019
Ce code contient les tests de pour toutes les fonctions crées ainsi que la lecture de
fichier et la gestion des objets.

REPONSES AUX QUESTIONS

1. Quelle est l'utilite de l'operateur = et du constructeur par copie?
l'utilité des deux operateurs est de creer une copie d'un objet et de passé les parametres.
L'obejet copier aura les memes attribut que le premier.

2. Qu'est ce qui differencie l'operateur = du constructeur par copie?
La difference entre les deux c'est que le premier l'operateur = a besoin d'un objet deja existant auquel
il va ecraser les anciens attributs par les attributs de l'objet qu'on desire copier. Par contre,
le constructeur par copie va creer un nouvelle objet et celui-ci va etre une copie
de l'objet qu'on desire copier.
*/

#include "Restaurant.h"

using namespace std;

int main() {

	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir);
	///creer plusieurs clients 
	int nbclient1 = 1;
	int nbclient2 = 5;
	int nbclient3 = 15;
	int nbclient4 = 3;
	int nbclient5 = 2;


	//placer les clients 
	poly.placerClients(nbclient1);
	poly.placerClients(nbclient2);
	poly.placerClients(nbclient3);
	poly.placerClients(nbclient4);
	poly.placerClients(nbclient5);

	// commander des plats 
	poly.commanderPlat("Poisson", 1);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Pizza", 2);
	poly.commanderPlat("Poulet", 4);
	poly.commanderPlat("Muffin", 4);
	poly.commanderPlat("Oeuf", 4);


	//Creation d'une copie du poly restaurant 
	Restaurant poly2(poly);
	if (poly < poly2)
		cout << "cest bon!" << endl;
	poly2.setNom("PolyFood2");
	//Affichage du restaurant poly 
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------" << endl;


	//liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);

	cout << poly;

	cout << "====================================================================================================" << endl;

	// Le restaurant Poly2 ne doit pas encore avoir liberer ses tables
	cout << poly2;

	poly2 = poly;


	cout << "--------------------------------------------------------------------------------------------------" << endl;
	// Le restaurant Poly2 doit maintenant avoir toutes ses tables libérées
	cout << poly2;

}