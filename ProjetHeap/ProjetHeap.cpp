
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
int main()
{
	srand(time(NULL));
	int i = 0,temp,racine,fils;
	vector<int> V1;
	vector<int> heap;
	for (int i = 0; i < 10; i++) V1.push_back(rand() % 1000);

	clock_t start = clock();
	/*Insertion dans la heap*/
	for (auto& val : V1)
	{
		cout << val << " ";//affichage du vector 1
		heap.push_back(val);
		racine = i;
		while (racine > 0)
		{
			fils = racine;
			racine = (fils - 1) / 2;// je cherche la racine du nouveau element
			temp = heap.at(racine);
			if (temp > val)
			{
				heap.erase(heap.begin() + racine);
				heap.insert(heap.begin() + racine, val);
				heap.erase(heap.begin() + fils);
				heap.insert(heap.begin() + fils, temp);

			}
			else break;

		}

		i++;

	}
	
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	cout << endl<<"Temps d'insertion: " << duration << endl;
	
	/*Affichage du heap apres insertion*/
	/*for (auto& val : heap)
	{
		cout << val << " ";
	}*/
}

