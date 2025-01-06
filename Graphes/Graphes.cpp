#pragma once 
#include <iostream>
#include <vector>
#include "Sommet.h"
#include "Graph.h"

using namespace std;

int main() {
    Sommet s1(2, "blanc");
    Sommet s2(5, "blanc");
    Sommet s3(4, "blanc");
    Sommet s4(10, "blanc");
    Sommet s5(10, "blanc");
    Sommet s6(10, "blanc");
    Sommet s7(10, "blanc");
    Graph leGrph;
    leGrph.AddSommet(s1, { {s2,1},{s4,2} });
    leGrph.AddSommet(s2, { { s3,3},{s1,1} });
    leGrph.AddSommet(s3, { {s2,3} });
    leGrph.AddSommet(s4, { {s1,2}, {s5,7} });
    leGrph.AddSommet(s5, { {s4,7},{s6,8},{s7,6} });
    leGrph.AddSommet(s6, { {s5,8},{s7,1} });
    leGrph.AddSommet(s7, { {s5,6},{s6,1} });
    //leGrph.Affiche_graph();
    cout << "Le parcour en largeur" << endl;
    //leGrph.ParcourLargeur(s1);
    cout << "Dijkstra de" << endl;
   // leGrph.Dijkstra(s1,s7);
    leGrph.ParcourLargeur(s1, s7);
    return 0;
}
 