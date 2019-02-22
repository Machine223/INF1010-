/*
* Titre : ClientPrestige.h - Travail Pratique #3
* Date : 11  F�vrier 2019
* Auteur : Fatou S. Mounzeo
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
enum AddressCode{Zone1,Zone2,Zone3};
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige(); //Le constructeur par d�faut
	ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints,AddressCode addresse); //Le constructeur par param�tres

	//Accesseur et setter
	AddressCode getAddresseCode();
	void setAdresseCode(AddressCode zone);

	//Autres Fonctions
	friend ostream & operator<<(ostream & os, ClientPrestige client);
	string getAddressCodeString();
	   
private: 
	AddressCode addresse_; //la valeur du type �num�r� AddressCode et r�pr�sente la zone d�habitation du client

};
#endif;

