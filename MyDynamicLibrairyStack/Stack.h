#pragma once
#include <stdexcept>
#include <iostream>
#include <cctype>
using namespace std;
template <class MyType>

class Stack
{
private:
	
	MyType *values;
	int sommet;
	int capacity;
public:
	Stack();
	bool isEmpty();
	bool isFull();
	void Push(MyType object);
	MyType Pop();
	void PrintStack();
	


};


template<class MyType>
inline Stack<MyType>::Stack() : sommet(-1),capacity(2)
{
	this->values = new MyType[2];
}

template<class MyType>
inline bool Stack<MyType>::isEmpty()
{
	if (sommet == -1) throw underflow_error("underflow_error");
	return true;
}

template<class MyType>
inline bool Stack<MyType>::isFull()
{
	if(this->sommet==(this->capacity-1)) throw overflow_error("overflow_error");
	
	return false;
}

template<class MyType>
inline void Stack<MyType>::Push(MyType object)
{
	try
	{
		isFull();
		//this->values[++this->sommet] = object;
	}
	catch (overflow_error e)
	{
		
		MyType* temp = new MyType[this->capacity];
		this->capacity *= 2;
		MyType* NewStack = new MyType[this->capacity];
		
		for (int i = this->sommet; i >=0; i--)
		{
			temp[i] = this->values[i];
		} 

		for (int i = this->sommet; i >=0; i--)
		{
			NewStack[i] = temp[i];
		} 
		delete [] this->values;
		delete [] temp;
		this->values = NewStack;
		
	}
	this->values[++this->sommet] = object;
	
}

template<class MyType>
inline MyType Stack<MyType>::Pop()
{
	MyType obj;
	try
	{
		this->isEmpty();
		obj = this->values[this->sommet--];

		return obj;
	}
	catch (const std:: underflow_error e)
	{
		cout << "Impossible de depiler la pile est vide" << endl;
	}
}

template<class MyType>
inline void Stack<MyType>::PrintStack()
{
	try
	{
		isEmpty();
		for (int i = this->sommet; i >=0; i--)
		{

			cout << this->values[i] << " ";
		} 
		
	}
	catch (const std::underflow_error e)
	{
		cout << e.what()<< " :la pile est vide  "<<endl;
	}
	
}



