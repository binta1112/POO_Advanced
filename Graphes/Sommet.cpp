
#include "Sommet.h"

int Sommet::compter = 0;

Sommet::Sommet(int poids, string couleur) //:id_noeud(compter++), poids(poids), couleur(couleur)
{
	this->id_noeud = compter++;
	this->poids = poids;
	this->couleur = couleur;
}


int Sommet::getID_noeud() const
{
	return this->id_noeud;
}


void Sommet::setPoids(int new_weiht)
{
	this->poids = new_weiht;
}


void Sommet::setCouleur(string couleur)
{
	this->couleur = couleur;
}

string Sommet::getCouleur()
{
	return this->couleur;
}
