#pragma once
#include <iostream>
using namespace std;
class Chaine
{ 
private:
	string val_chaine;
public:
	Chaine(string str);
	string Inverser_chaine();
	bool isPalindrome();
};

Chaine::Chaine(string str) :val_chaine(str)
{
}

string  Chaine::Inverser_chaine()
{
	Stack<char> pile;
	string t;
	for (int i = 0; i < this->val_chaine.length(); i++)
	{
		pile.Push(this->val_chaine[i]);
	}

	for (int i = 0; i < this->val_chaine.length(); i++)
	{
		t.push_back(pile.Pop());
	}
	return t;

}

bool Chaine::isPalindrome()
{
	string ch = this->Inverser_chaine();
	return this->val_chaine == ch;
}
