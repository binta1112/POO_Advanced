#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include "Heap.h"
#include "Heap.cpp"
using namespace std;

int main()
{
	srand(time(NULL));
	
	vector<int> V1;
	Heap<int> heap;
	for (int i = 0; i < 10000000; i++) V1.push_back(rand() % 1000);
	
	auto start = chrono::high_resolution_clock::now();
	/*Insertion dans la heap*/
	for (int val : V1)
	{
		heap.insert(val);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	
	cout << "Temps d'insertion: " << elapsed.count() << " secondes" << endl;
	/*Tri decroissant*/
	/*try
	{
		while (!heap.isEmpty())
		{
			cout << heap.extract_max() << " ";
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}*/
}

