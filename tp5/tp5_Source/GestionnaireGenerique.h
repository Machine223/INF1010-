/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const;			//TODO  retourne une copie du conteneur_.
	void ajouter(T t);				//TODO  permet d’ajouter un élément au conteneur conteneur_
	int getNombreElements() const;	//TODO  retourne la taille du conteneur_.

protected:
	C conteneur_;
};

template<typename T, typename C>
inline C GestionnaireGenerique<T, C>::getConteneur() const
{
	// retourner un conteneur
	return conteneur_;
}

template<typename T, typename C>
inline void GestionnaireGenerique<T, C>::ajouter(T t)
{
	//permet d’ajouter un élément au conteneur conteneur_ 
	conteneur_.insert(t);

}

template<typename T, typename C>
inline int GestionnaireGenerique<T, C>::getNombreElements() const
{
	
	return conteneur_.size();
}
