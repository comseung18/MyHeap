#include <iostream>
#include <vector>
using namespace std;

template < typename T, typename Cmp>
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	MyHeap<int, less<int>> myHeap;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x != 0)
			myHeap.push(x);
		else
			cout << myHeap.pop() << '\n';
	}

	return 0;
}