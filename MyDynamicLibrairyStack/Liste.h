#pragma once
#include "pch.h"
template <class Mytype>
class Liste
{
private:
	Noeud<Mytype>* values;
	int taille;
public:
	Liste();
	void InsertInList(Mytype val);
	void DeleteFromList();
	void Print_list();
	~Liste();
};

template<class Mytype>
inline Liste<Mytype>::Liste():values(nullptr),taille(0)
{
}
/*
* Cette methode insert une valeur en tete de la liste
*/
template<class Mytype>
inline void Liste<Mytype>::InsertInList(Mytype val)
{
	Noeud<Mytype>* n = new Noeud<Mytype>;
	n->value = val;
	n->next = this->values;
	this->values = n;
	this->taille++;
}
/*
* La methode supprime en tete de la liste
*/
template<class Mytype>
inline void Liste<Mytype>::DeleteFromList()
{
	Noeud<Mytype>* n = nullptr;
	if (this->values)
	{
		n = this->values;
		this->values = this->values->next;
	}
	this->taille--;
	delete n;
}

template<class Mytype>
inline void Liste<Mytype>::Print_list()
{
	Noeud<Mytype>* tempStack1 = this->values;
	while (tempStack1)
	{
		
		cout << tempStack1->value << " ";
		tempStack1 = tempStack1->next;
		
	}
}

template<class Mytype>
inline Liste<Mytype>::~Liste()
{
	while (this->values) DeleteFromList();
}
