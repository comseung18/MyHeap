#include "MyHeap.h"
#include <iostream>
using namespace std;

template<typename T, typename Cmp>
MyHeap<T, Cmp>::MyHeap()
{
	
}

template<typename T, typename Cmp>
MyHeap<T, Cmp>::MyHeap(vector<T>& data)
{
	for (int i = 0; i < data.size(); ++i)
		push(data[i]);
}

template<typename T, typename Cmp>
MyHeap<T, Cmp>::~MyHeap()
{
}

template<typename T, typename Cmp>
bool MyHeap<T, Cmp>::empty()
{
	return heapTree.empty();
}

template<typename T, typename Cmp>
T  MyHeap<T, Cmp>::pop()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	if (empty()) return 0;

	T ret = heapTree[0];
	heapTree[0] = heapTree.back();
	heapTree.pop_back();

	
	int now = 0;
	int child1 = now * 2 + 1;
	int child2 = now * 2 + 2;
	while (child1 < size() || child2 < size()) {

		int child;
		if (child2 >= size()) child = child1;
		else {
			if (cmp(heapTree[child1], heapTree[child2])) child = child1;
			else child = child2;
		}

		if (cmp(heapTree[child], heapTree[now])) {
			swap(heapTree[child], heapTree[now]);
			now = child;
			child1 = now * 2 + 1;
			child2 = now * 2 + 2;
		}

		else break;
	}

	return ret;
}

template<typename T, typename Cmp>
void MyHeap<T, Cmp>::push(T & t)
{
	int now = heapTree.size();
	int parent = (now - 1) / 2;

	heapTree.push_back(t);

	while (now > 0 && cmp(heapTree[now], heapTree[parent])) {
		swap(heapTree[now], heapTree[parent]);
		now = parent;
		parent = (now - 1) / 2;
	}
}

template<typename T, typename Cmp>
int MyHeap<T, Cmp>::size()
{
	return heapTree.size();
}

template<typename T, typename Cmp>
void MyHeap<T, Cmp>::print()
{
	cout << "print Heap Start\n";
	for (auto t : heapTree) {
		cout << t << '\n';
	}
	cout << "print Heap End\n";
}

