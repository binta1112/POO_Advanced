#include "Graph.h"
#include <iostream>
#include <stack>
using namespace std;
void Graph::AddSommet(Sommet s, vector < pair <Sommet, int>>Voisins)
{

	Le_graph.push_back({ s, Voisins });
	this->nb_noeuds++;
}



void Graph::AddToVoisin(Sommet s, pair<Sommet, int> v)
{
	this->Le_graph[s.getID_noeud()].second.push_back(v);
}
void Graph::Affiche_graph() const
{
	cout << "Affichage du graphe" << endl;

	for (int i = 0; i < this->nb_noeuds; i++)
	{
		cout << i << ": {";
		for (pair<Sommet,int> v : this->Le_graph[i].second)
		{
			cout << " (sommet: " << v.first.getID_noeud() << ",distance: "<<v.second<<"),";
		}
		cout << "}" << endl;
	}
}

void Graph::ParcourLargeur(Sommet& depart)
{
	//on associe chaque sommet � son �tat (couleur)
	vector<string> etats(this->nb_noeuds, "blanc"); // Tous les sommets sont non visit�s au d�part


	queue<Sommet> file; // File pour g�rer les sommets � explorer
	file.push(depart);   //on  ajoute le sommet de d�part
	etats[depart.getID_noeud()] = "gris"; //on marquer comme en attente le sommet dans la file

	while (!file.empty())
	{
		Sommet& actuel = file.front(); // je r�cup�rer le sommet en t�te de file
		file.pop(); // je retirer le sommet de la file
		cout << "Visite du sommet : " << actuel.getID_noeud() << endl;

		// Parcour des voisins
		for (auto& voisin : Le_graph[actuel.getID_noeud()].second)
		{ // on acc�de � la liste des voisins
			if (etats[voisin.first.getID_noeud()] == "blanc") // Si non visit�
			{
				file.push(voisin.first);
				etats[voisin.first.getID_noeud()] = "gris"; // on marquer comme en attente le sommet dans la file
			}
		}

		etats[actuel.getID_noeud()] = "noir"; // je marque comme visit� le sommet deja defil�
	}
}

void Graph::Dijkstra(Sommet& depart) const
{
	//les distances de sommet depart au autres sommets du graphe initialis�es a l'infini
	vector<int> distances(this->nb_noeuds, numeric_limits<int>::max());
	distances[depart.getID_noeud()] = 0;
	// File de priorit� : (distance, sommet)
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> file;
	//j'inserer le sommet de depart dans la file avec comme distance 0

	file.push({0,depart.getID_noeud()});
	while (!file.empty())
	{
		pair<int, int> current_node = file.top();//on recupere le sommet avec la plus petite distance
		file.pop();//ce sommet est maintenant trait�, plus de retour
        //On parcour ces voisins
		for (auto& voisin : this->Le_graph[current_node.second].second)
		{
			int x = current_node.first + voisin.second;//la distance du sommet voisin par raport au parcour actuel
			//si cette distance est plus petite que celle deja enregistr�e pour ce sommet
			if (x < distances[voisin.first.getID_noeud()])
			{
				distances[voisin.first.getID_noeud()] = x;//on met a jour la distance
				file.push({x,voisin.first.getID_noeud() });//on insere ce sommet dans la file de priorit�
			}
		}
	}
	// Afficher les distances finales
	cout << "Distances depuis le sommet " << depart.getID_noeud() << " :" << endl;
	for (int i = 0; i < this->nb_noeuds; ++i) 
	{
		if (distances[i] == numeric_limits<int>::max())
		{
			cout << "Sommet " << i << ": INF" << endl;
		}
		else 
		{
			cout << "Sommet " << i << ": " << distances[i] << endl;
		}
	}
}
/***************************************************************************************/
void Graph::ParcourLargeur(Sommet& depart, Sommet& des)
{
	//on associe chaque sommet � son �tat (couleur)
	vector<string> etats(this->nb_noeuds, "blanc"); // Tous les sommets sont non visit�s au d�part


	queue<Sommet> file; // File pour g�rer les sommets � explorer
	file.push(depart);   //on  ajoute le sommet de d�part
	etats[depart.getID_noeud()] = "gris"; //on marquer comme en attente le sommet dans la file
	stack<int> chemin;
	// Pr�d�cesseurs pour reconstruire le chemin
	vector<int> predecessors(this->nb_noeuds, -1);
	while (!file.empty())
	{
		Sommet& actuel = file.front(); // je r�cup�rer le sommet en t�te de file
		file.pop(); // je retirer le sommet de la file
		
		if (actuel.getID_noeud() == des.getID_noeud()) break;
		int id = actuel.getID_noeud();
		// Parcour des voisins
		for (auto& voisin : Le_graph[actuel.getID_noeud()].second)
		{ // on acc�de � la liste des voisins
			if (etats[voisin.first.getID_noeud()] == "blanc") // Si non visit�
			{
				file.push(voisin.first);
				etats[voisin.first.getID_noeud()] = "gris"; // on marquer comme en attente le sommet dans la file
				
				predecessors[voisin.first.getID_noeud()] =id;//on enregistre le pere
			}
		}

		etats[actuel.getID_noeud()] = "noir"; // je marque comme visit� le sommet deja defil�
	}

	// Reconstruction du chemin 

	for (int at = des.getID_noeud(); at != -1; at = predecessors[at])
		chemin.push(at);
	cout << " chemin  de " << depart.getID_noeud() << " a " << des.getID_noeud() << endl;
	while (!chemin.empty())
	{
		cout << chemin.top() << "->";
		chemin.pop();
	}
	cout << endl;
}
void Graph::Dijkstra(Sommet& depart, Sommet& des) const
{
	//les distances de sommet depart au autres sommets du graphe initialis�es a l'infini
	vector<int> distances(this->nb_noeuds, numeric_limits<int>::max());
	distances[depart.getID_noeud()] = 0;
	// File de priorit� : (distance, sommet)
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> file;
	//j'inserer le sommet de depart dans la file avec comme distance 0
	stack<int> chemin;
	// Pr�d�cesseurs pour reconstruire le chemin
	vector<int> predecessors(this->nb_noeuds, -1);
	file.push({ 0,depart.getID_noeud() });
	while (!file.empty())
	{
		pair<int, int> current_node = file.top();//on recupere le sommet avec la plus petite distance
		file.pop();//ce sommet est maintenant trait�, plus de retour
				
		if (current_node.second == des.getID_noeud()) break;//on arrete le parcour si on atteint l destination
		//On parcour ces voisins
		for (auto& voisin : this->Le_graph[current_node.second].second)
		{
			int x = current_node.first + voisin.second;//la distance du sommet voisin par raport au parcour actuel
			//si cette distance est plus petite que celle deja enregistr�e pour ce sommet
			if (x < distances[voisin.first.getID_noeud()])
			{
				distances[voisin.first.getID_noeud()] = x;//on met a jour la distance
				file.push({ x,voisin.first.getID_noeud() });//on insere ce sommet dans la file de priorit�
				predecessors[voisin.first.getID_noeud()] = current_node.second;//on enregistre le pere
				
			}
		}
	}
	// Reconstruction du chemin 
	
	for (int at = des.getID_noeud(); at != -1; at = predecessors[at])
		chemin.push(at);
	cout << " chemin le plus court de " << depart.getID_noeud() << " a "<<des.getID_noeud() << endl;
	while (!chemin.empty())
	{
		cout << chemin.top() << "->";
		chemin.pop();
	}
	cout << endl;
}


