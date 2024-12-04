#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include<map>
#include <sstream>
#include "Mot.h"
using namespace std;
int main()
{ 
   
 map < string, Mot > dictionaire;
   
    ifstream file{ "Fichier_de_text.txt" };
    string mot{}, str{};
    int index_line=1, index_in_line=1;
    
     if (file.is_open())
    {
        while (getline(file,mot))
        {
           //on remplace tous les pontuation de la ligne
            replace_if(mot.begin(), mot.end(), []( unsigned char c) 
            {
             return ispunct(c);
            }, ' ');
            istringstream word(mot);
            while (word >> str)
            {
                /*On ajoute le mot si il n'exite pas */
                if (!dictionaire.count(str))
                {
                    dictionaire[str] = Mot();
                }                
                dictionaire[str].Insert(index_line, index_in_line);//on mentionne le num de ligne et la position dans la ligne
                index_in_line++;
            }
            index_in_line = 1;
            index_line++;
        }
    }

  for (const auto& pair : dictionaire)
    {       
      cout << pair.first << " : apparait  " << pair.second.Nbre_occ() << " fois au lignes " << endl;
       pair.second.Print();
       cout << endl<<endl;
    }
   
return 0;
}

