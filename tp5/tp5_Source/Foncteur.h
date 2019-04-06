/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;

// Un foncteur prédicat binaire permet de comparer les
// plats deux à deux du conteneur map.
class FoncteurPlatMoinsCher
{ 
	public:
	bool operator()(pair<string, Plat*> a, pair<string, Plat*> b) 
	{
		return (a.second->getPrix() < b.second->getPrix());
	};

};

//Un foncteur prédicat unaire ayant la borne inférieure et la
//borne supérieure comme attributs.Ce foncteur prend en entrée un plat unique du
//conteneur map et vérifie si son prix est compris entre les bornes.
class FoncteurIntervalle
{
	public:
	FoncteurIntervalle(double borneI, double borneS): borneInf_(borneI), borneSup_(borneS) {}

	double operator()(pair<string, Plat*> a) {
		return (a.second->getPrix > borneInf_ && borneSup_ > a.second->getPrix);
	}

	private:
	double borneInf_;
	double borneSup_;
};

