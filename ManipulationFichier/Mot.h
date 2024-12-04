#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Mot
{
 private:
	 
	 map<int,vector<int> > index;
public:
	
	void Print()const;
	void Insert(int index_line, int pos);
	int Nbre_occ() const;
	void Supprime_point() const;
};

void Mot::Print() const
{
	for (const auto& ind : index)
	{
		cout << "ligne " << ind.first<<" position=> <";
		for (const auto& pos : ind.second)
			cout << pos<<", ";
		cout << "> " ;
	}
}

void Mot::Insert(int index_line, int pos)
{
	 index[index_line].push_back(pos);

}

inline int Mot::Nbre_occ() const
{
	int size = 0;
	for (const auto& ind : index)
	{
		size += ind.second.size();
	}
	return size;
}

inline void Mot::Supprime_point() const
{

}
