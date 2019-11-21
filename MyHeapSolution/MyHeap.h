#pragma once
#include <vector>
using namespace std;

// 사용예제, MyHeap<int, less<int>> myHeap;
// CMP 는 비교함수 클래스 or 구조체
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

