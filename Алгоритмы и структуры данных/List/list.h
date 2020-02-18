#ifndef DBL_LIST
#define DBL_LIST

class Node
{
public:
	int value;
	Node* prev;
	Node* next;
};

class List
{
public:
	Node* head;
	Node* tail;
	int sizel;

	List();

	void AddToTail(int value);
	void AddToHead(int value);
	Node* GetByIndex(int index);
	void DelByIndex(int index);
	void AddToSomePlace(int index,int value);
	void Print();
};

#endif