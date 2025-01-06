#pragma once
#include <vector>
#include <list>
#include <utility>
#include "Sommet.h"
#include <queue>

using namespace std;
class Graph
{

private:
	int nb_noeuds = 0;
	vector < //ensemble de sommets
		pair <
		Sommet,//le sommet
		vector<pair <Sommet,int> > //ses voisins et chaques voisin avec la distance
		> 
	   >Le_graph;
public:


public:
	void AddSommet(Sommet s, vector < pair <Sommet, int>>Voisins);
	void AddToVoisin(Sommet s, pair<Sommet,int> v);
	void Affiche_graph() const;
	void ParcourLargeur(Sommet& depart);
	void ParcourLargeur(Sommet& depart, Sommet& des);
	void Dijkstra(Sommet& depart) const;
	void Dijkstra(Sommet& depart, Sommet& des) const;
};

