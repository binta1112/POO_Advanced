#pragma once
#include <vector>
using namespace std;
template <class T>
class Heap
{
private:
	vector<T> heap;//vecteur representant le heap;
public:
	void heapify_up(int index);
	void heapify_down(int index);
	void insert(T value);
	T extract_max();
	void print_heap() const;
	bool isEmpty() const;
};

