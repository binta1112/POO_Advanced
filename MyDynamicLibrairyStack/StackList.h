#pragma once

template <class Mytype>
 struct Noeud
{
	Mytype value;
    Noeud<Mytype> *next;
};
template <class Mytype>
class StackList
{
private:
	Noeud<Mytype> *values;
	int taille;
public:
	StackList();
	void Push(Mytype val);
	Noeud<Mytype> *Pop();
	void Print_stack_list();
	~StackList();
};

template<class Mytype>
inline StackList<Mytype>::StackList() :values(nullptr),taille(0)
{}

template<class Mytype>
inline void StackList<Mytype>::Push(Mytype val)
{
	Noeud<Mytype>* n = new Noeud<Mytype>;
	n->value = val;
	n->next = this->values;
	this->values = n;
	this->taille++;
	
}

template<class Mytype>
inline Noeud<Mytype> *StackList<Mytype>::Pop()
{
	Noeud<Mytype>* n = nullptr;
	if (this->values)
	{
		n = this->values;
		this->values = this->values->next;
	}
	this->taille--;
	return n;
}

template<class Mytype>
inline void StackList<Mytype>::Print_stack_list() 
{
	Noeud<Mytype> *tempStack1 = nullptr, *tempStack2 = nullptr;
	while (this->values)
	{
		tempStack1 = this->values;		
		this->values = this->values->next;
		cout << tempStack1->value << " ";
		tempStack1->next = tempStack2;
		tempStack2 = tempStack1;
	}
	/*Reconstitution de la pile*/
	while (tempStack2)
	{
		tempStack1 = tempStack2;
		tempStack2 = tempStack2->next;
		
		tempStack1->next =this->values;
		this->values = tempStack1;
	}
}

template<class Mytype>
inline StackList<Mytype>::~StackList()
{
	while (this->values) delete Pop();
}


