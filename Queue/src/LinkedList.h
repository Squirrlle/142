#include <iostream>
#include <cstdlib>


template <class T>
class Node
{
public:
    Node* next;
    T data;
    Node(T e, Node n){
    	data  = e;
    	next = n;
    }
};

using namespace std;

template <class T>
class LinkedList
{
public:
	LinkedList() : size_(0), front_(NULL), back_(NULL){}
	LinkedList(const LinkedList & l);
	~LinkedList();
	int size();
	bool empty();
	T front();
	T pop();
	void push(T e);
	void clear();

private:
	int size_;
	Node<T>* front_;
	Node<T>* back_;
};

template <class T>
int LinkedList::size(){
	return size_;
}
