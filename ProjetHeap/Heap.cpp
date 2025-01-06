#include "Heap.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
// Fonction pour "remonter" un élément pour maintenir la propriété du max-heap
template <class T>
void Heap <T>::heapify_up(int index)
{
    int racine = (index - 1) / 2;
    /*Tant qu'on a pas atteint la racine ou si l'element est superier a son noeud pere*/
    while (index > 0 && heap[racine] < heap[index]) 
    {
        swap(heap[index], heap[racine]);//on l'echange avec son pere
        index = racine; // Remonter jusqu'à ce que la propriété soit respectée
        racine = (index - 1) / 2;
    }
}

// Fonction pour "descendre" un élément pour maintenir la propriété du max-heap
template <class T>
void Heap <T>:: heapify_down(int index)
{
    int size = heap.size();
    int largest = index;// l'indice du plus grand 
    int left = 2 * index + 1;//le fils gauche du noeud
    int right = 2 * index + 2;//le fils droit du noeud

    // on cherche le plus grand parmi parent, gauche et droite
    if (left < size && heap[left] > heap[largest]) 
    {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) 
    {
        largest = right;
    }
    /*****************************************************/
    // Si le plus grand n'est pas le parent, on échange et on descend récursivement
    if (largest != index) 
    {
        swap(heap[index], heap[largest]);
        heapify_down(largest);
    }
}


// Fonction pour insérer un élément dans le max-heap
template <class T>
void Heap <T>::insert(T value)
{
    heap.push_back(value);  // on ajoute l'élément à la fin
    heapify_up(heap.size() - 1);  // on le remonte si necessaire  pour maintenir la propriété du max-heap
}
// Fonction pour extraire le maximum du max-heap
template <class T>
T Heap <T>::extract_max()
{
    if (heap.size() == 0)
    {
        throw out_of_range("Impossible : le heap est vide");//on leve une exception si le tas est vide
    }
    int max_value = heap[0];  // Le maximum est toujours à l'indice 0
    heap[0] = heap.back();    // on remplacer l'indice 0 par le dernier élément
    heap.pop_back();          // on supprimer l'élément à la fin puis qu'on l'a copié en tete
    heapify_down(0);          // on le descendre jusqu'à sa  position correcte pour maintenir l'equilibre du heap
    return max_value;
}
// Fonction pour afficher le contenu du max-heap

template <class T>
void Heap<T>::print_heap() const
{
    for (int val : heap) 
    {
        cout << val << " ";
    }
    cout << endl;
}

template<class T>
bool Heap<T>::isEmpty() const
{
    return (this->heap.size()==0);
}


