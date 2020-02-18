#ifndef FOREST
#define FOREST
#include "string"

class Node
{
public:
	int value;
	int string_number;
	const char* name;
	char indus[10];
	bool go;
	Node* left;
	Node* right;
};

class List
{
public:
	List();
	
	void Push(Node** root, int value, const char* name, bool go);
	int FindById(Node** root, int id);
	int SaveTree(Node** root);
	int FindFromFileById(FILE* file, int id);
	
	int siz,count, num;
};

#endif