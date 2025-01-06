#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sommet
{
private:
	static int compter;//compter pour differencier les identifiants

	int id_noeud;//  identifiant du noeud;

	int poids;//le pois du noeud
	string couleur;// l'etat du noeud (defini par des couleurs) 
public:
	Sommet(int poids, string couleur);
	int getID_noeud() const;
	void setPoids(int new_weiht);
	void setCouleur(string couleur);
	string getCouleur();
};



