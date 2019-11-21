#pragma once
#include <vector>
using namespace std;

// ��뿹��, MyHeap<int, less<int>> myHeap;
// CMP �� ���Լ� Ŭ���� or ����ü
template < typename T , typename Cmp>
class MyHeap
{

private:
	vector<T> heapTree;
	Cmp cmp;
	
public:
	MyHeap();
	MyHeap(vector<T> &data);
	~MyHeap();
	bool empty();
	T pop();
	void push(T& t);
	int size();
	void print();
};

